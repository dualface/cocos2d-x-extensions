
#include "network/CCHttpRequest_impl.h"
#include "cocos2d.h"
#if CC_TARGET_PLATFORM != CC_PLATFORM_WIN32
#include <pthread.h>
#endif
#include <iostream>

NS_CC_EXT_BEGIN

CCHttpRequest_impl::CCHttpRequest_impl(const char* url, CCHttpRequestMethod method)
: m_state(STATE_IDLE)
, m_isPost(method == CCHttpRequestMethodPOST)
, m_rawResponseBuffLength(0)
, m_responseData(NULL)
, m_responseDataLength(0)
, m_responseCode(0)
, m_errorCode(CCHttpRequestErrorNone)
{
    m_curl = curl_easy_init();
    curl_easy_setopt(m_curl, CURLOPT_URL, url);
//    curl_easy_setopt(m_curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; rv:2.0.1) Gecko/20100101 Firefox/4.0.1");
    curl_easy_setopt(m_curl, CURLOPT_TIMEOUT_MS, DEFAULT_TIMEOUT * 1000);
    if (method == CCHttpRequestMethodPOST)
    {
        curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
    }
}

CCHttpRequest_impl::~CCHttpRequest_impl(void)
{
    cleanup();
    CCLOG("~~ delete CCHttpRequest_impl\n");
}

void CCHttpRequest_impl::addRequestHeader(const char* key, const char* value)
{
    std::stringbuf buff;
    buff.sputn(key, strlen(key));
    buff.sputn(": ", 2);
    buff.sputn(value, strlen(value));
    m_headers.push_back(buff.str());
}

void CCHttpRequest_impl::addPostValue(const char* key, const char* value)
{
    m_postFields[std::string(key)] = std::string(value);
}

void CCHttpRequest_impl::setPostData(const char* data)
{
    m_postFields.clear();
    m_postdata = std::string(data);
}

void CCHttpRequest_impl::setTimeout(float timeout)
{
    curl_easy_setopt(m_curl, CURLOPT_TIMEOUT_MS, timeout * 1000);
}

bool CCHttpRequest_impl::start(void)
{
    if (m_state != STATE_IDLE) return false;
    m_state = STATE_IN_PROGRESS;

    m_responseCode = 0;
    m_errorCode = CCHttpRequestErrorNone;
    m_errorMessage = "";
    
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, curlWriteData);
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, this);
    curl_easy_setopt(m_curl, CURLOPT_PROGRESSFUNCTION, curlProgress);
    curl_easy_setopt(m_curl, CURLOPT_PROGRESSDATA, this);
    
#ifdef _WINDOWS_
    CreateThread(NULL,          // default security attributes
                 0,             // use default stack size
                 curlRequest,   // thread function name
                 this,          // argument to thread function
                 0,             // use default creation flags
                 NULL);
#else
    pthread_create(&m_thread, NULL, curlRequest, this);
    pthread_detach(m_thread);
#endif
    
    return true;
}

void CCHttpRequest_impl::cancel(void)
{
    if (m_state != STATE_IN_PROGRESS) return;
    m_state = STATE_CANCELLED;
}

#ifdef _WINDOWS_
DWORD WINAPI CCHttpRequest_impl::curlRequest(LPVOID lpParam)
{
    CCHttpRequest_impl* instance = (CCHttpRequest_impl*)lpParam;
    instance->onRequest();
    return 0;
}

#else // _WINDOWS_

void* CCHttpRequest_impl::curlRequest(void *data)
{
    CCHttpRequest_impl* instance = (CCHttpRequest_impl*)data;
    instance->onRequest();
    return NULL;
}
#endif // _WINDOWS_

size_t CCHttpRequest_impl::curlWriteData(void* buffer, size_t size, size_t nmemb, void* userp)
{
    CCHttpRequest_impl* instance = (CCHttpRequest_impl*)userp;
    return instance->onWriteData(buffer, size * nmemb);
}

int CCHttpRequest_impl::curlProgress(void* userp, double dltotal, double dlnow, double ultotal, double ulnow)
{
    CCHttpRequest_impl* instance = (CCHttpRequest_impl*)userp;
    return instance->onProgress(dltotal, dlnow, ultotal, ulnow);
}

void CCHttpRequest_impl::onRequest(void)
{
    if (m_postFields.size() > 0)
    {
        curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
        std::stringbuf buf;
        PostFieldsIterator it = m_postFields.begin();
        while (it != m_postFields.end())
        {
            char* part = curl_easy_escape(m_curl, it->first.c_str(), 0);
            buf.sputn(part, strlen(part));
            buf.sputc('=');
            curl_free(part);

            part = curl_easy_escape(m_curl, it->second.c_str(), 0);
            buf.sputn(part, strlen(part));
            curl_free(part);

            ++it;
            if (it != m_postFields.end()) buf.sputc('&');
        }
        curl_easy_setopt(m_curl, CURLOPT_COPYPOSTFIELDS, buf.str().c_str());
    }
    else if (m_postdata.length() > 0)
    {
        curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
        curl_easy_setopt(m_curl, CURLOPT_COPYPOSTFIELDS, m_postdata.c_str());
    }
    else if (m_isPost)
    {
        curl_easy_setopt(m_curl, CURLOPT_COPYPOSTFIELDS, "");
    }

    struct curl_slist* chunk = NULL;
    for (HeadersIterator it = m_headers.begin(); it != m_headers.end(); ++it)
    {
        chunk = curl_slist_append(chunk, (*it).c_str());
    }

    curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, chunk);
    CURLcode code = curl_easy_perform(m_curl);
    curl_easy_getinfo(m_curl, CURLINFO_RESPONSE_CODE, &m_responseCode);
    curl_easy_cleanup(m_curl);
    m_curl = NULL;
    curl_slist_free_all(chunk);

    m_errorCode = (code == CURLE_OK) ? CCHttpRequestErrorNone : CCHttpRequestErrorUnknown;
    m_errorMessage = (code == CURLE_OK) ? "" : curl_easy_strerror(code);
    
    m_responseData = (unsigned char*)malloc(m_rawResponseBuffLength + 1);
    m_responseData[m_rawResponseBuffLength] = '\0';
    m_responseDataLength = 0;
    for (RawResponseDataBuffIterator it = m_rawResponseBuff.begin(); it != m_rawResponseBuff.end(); ++it)
    {
        CCHttpRequest_impl::Chunk* chunk = *it;
        size_t bytes = chunk->getBytes();
        memcpy(m_responseData + m_responseDataLength, chunk->getChunk(), bytes);
        m_responseDataLength += bytes;
    }
    cleanupRawResponseBuff();
    
    m_responseString = std::string(reinterpret_cast<char*>(m_responseData));
    m_state = STATE_COMPLETED;
}

size_t CCHttpRequest_impl::onWriteData(void* buffer, size_t bytes)
{
    CCHttpRequest_impl::Chunk* chunk = new CCHttpRequest_impl::Chunk(buffer, bytes);
    m_rawResponseBuff.push_back(chunk);
    m_rawResponseBuffLength += bytes;
    return bytes;
}

int CCHttpRequest_impl::onProgress(double dltotal, double dlnow, double ultotal, double ulnow)
{
    return m_state == STATE_CANCELLED ? 1: 0;
}

void CCHttpRequest_impl::cleanup(void)
{
    cleanupRawResponseBuff();
    if (m_responseData) free(m_responseData);
    m_responseData = NULL;
    m_responseDataLength = 0;
    m_responseString = "";
    if (m_curl) curl_easy_cleanup(m_curl);
    m_curl = NULL;
}

void CCHttpRequest_impl::cleanupRawResponseBuff(void)
{
    for (RawResponseDataBuffIterator it = m_rawResponseBuff.begin(); it != m_rawResponseBuff.end(); ++it)
    {
        delete (*it);
    }
    m_rawResponseBuff.clear();
    m_rawResponseBuffLength = 0;
}

NS_CC_EXT_END
