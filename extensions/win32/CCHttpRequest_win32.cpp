
#include "CCHttpRequest_win32.h"
#include <iostream>

NS_CC_EXT_BEGIN

CCHttpRequest_win32::CCHttpRequest_win32(const char* url, CCHttpRequestMethod method)
: m_state(STATE_IDLE)
, m_rawResponseBuffLength(0)
, m_responseData(NULL)
, m_responseDataLength(0)
, m_responseCode(0)
, m_errorCode(CCHttpRequestErrorNone)
{
    m_curl = curl_easy_init();
    curl_easy_setopt(m_curl, CURLOPT_URL, url);
    curl_easy_setopt(m_curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; rv:2.0.1) Gecko/20100101 Firefox/4.0.1");
    curl_easy_setopt(m_curl, CURLOPT_TIMEOUT_MS, DEFAULT_TIMEOUT * 1000);
    if (method == CCHttpRequestMethodPOST)
    {
        curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
    }
}

CCHttpRequest_win32::~CCHttpRequest_win32(void)
{
    cleanup();
    CCLOG("~~ delete CCHttpRequest_win32\n");
}

void CCHttpRequest_win32::addRequestHeader(const char* key, const char* value)
{
    std::stringbuf buff;
    buff.sputn(key, strlen(key));
    buff.sputn(": ", 2);
    buff.sputn(value, strlen(value));
    m_headers.push_back(buff.str());
}

void CCHttpRequest_win32::addPostValue(const char* key, const char* value)
{
    m_postFields[std::string(key)] = std::string(value);
}

void CCHttpRequest_win32::setTimeout(float timeout)
{
    curl_easy_setopt(m_curl, CURLOPT_TIMEOUT_MS, timeout * 1000);
}

bool CCHttpRequest_win32::start(void)
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
    
    CreateThread(NULL,          // default security attributes
                 0,             // use default stack size
                 curlRequest,   // thread function name
                 this,          // argument to thread function
                 0,             // use default creation flags
                 NULL);
    
    return true;
}

void CCHttpRequest_win32::cancel(void)
{
    m_state = STATE_CANCELLED;
}

DWORD WINAPI CCHttpRequest_win32::curlRequest(LPVOID lpParam)
{
    CCHttpRequest_win32* instance = (CCHttpRequest_win32*)lpParam;
    instance->onRequest();
    return 0;
}

size_t CCHttpRequest_win32::curlWriteData(void* buffer, size_t size, size_t nmemb, void* userp)
{
    CCHttpRequest_win32* instance = (CCHttpRequest_win32*)userp;
    return instance->onWriteData(buffer, size * nmemb);
}

int CCHttpRequest_win32::curlProgress(void* userp, double dltotal, double dlnow, double ultotal, double ulnow)
{
    CCHttpRequest_win32* instance = (CCHttpRequest_win32*)userp;
    return instance->onProgress(dltotal, dlnow, ultotal, ulnow);
}

void CCHttpRequest_win32::onRequest(void)
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
    
    m_responseData = (BYTE*)malloc(m_rawResponseBuffLength + 1);
    m_responseData[m_rawResponseBuffLength] = '\0';
    m_responseDataLength = 0;
    for (RawResponseDataBuffIterator it = m_rawResponseBuff.begin(); it != m_rawResponseBuff.end(); ++it)
    {
        CCHttpRequest_win32::Chunk* chunk = *it;
        size_t bytes = chunk->getBytes();
        memcpy_s(m_responseData + m_responseDataLength, bytes, chunk->getChunk(), bytes);
        m_responseDataLength += bytes;
    }
    cleanupRawResponseBuff();
    
    m_responseString = std::string(reinterpret_cast<char*>(m_responseData));
    m_state = STATE_COMPLETED;
}

size_t CCHttpRequest_win32::onWriteData(void* buffer, size_t bytes)
{
    CCHttpRequest_win32::Chunk* chunk = new CCHttpRequest_win32::Chunk(buffer, bytes);
    m_rawResponseBuff.push_back(chunk);
    m_rawResponseBuffLength += bytes;
    return bytes;
}

int CCHttpRequest_win32::onProgress(double dltotal, double dlnow, double ultotal, double ulnow)
{
    return m_state == STATE_CANCELLED ? 1: 0;
}

void CCHttpRequest_win32::cleanup(void)
{
    cleanupRawResponseBuff();
    if (m_responseData) free(m_responseData);
    m_responseData = NULL;
    m_responseDataLength = 0;
    m_responseString = "";
    if (m_curl) curl_easy_cleanup(m_curl);
    m_curl = NULL;
}

void CCHttpRequest_win32::cleanupRawResponseBuff(void)
{
    for (RawResponseDataBuffIterator it = m_rawResponseBuff.begin(); it != m_rawResponseBuff.end(); ++it)
    {
        delete (*it);
    }
    m_rawResponseBuff.clear();
    m_rawResponseBuffLength = 0;
}

const std::wstring CCHttpRequest_win32::cstr2wstring(const char* source)
{
    int bufflen = MultiByteToWideChar(CP_UTF8, 0, source, -1, NULL, 0);
    wchar_t* buff = new wchar_t[bufflen];
    memset(buff, 0, bufflen * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, source, -1, buff, bufflen);
    std::wstring result = std::wstring(buff);
    delete buff;
    return result;
}

NS_CC_EXT_END
