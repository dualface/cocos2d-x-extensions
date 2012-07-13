
#include "CCHttpRequest_win32.h"

NS_CC_EXT_BEGIN

CCHttpRequest_win32::CCHttpRequest_win32(const char* url, CCHttpRequestMethod method)
: m_state(STATE_IDLE)
, m_rawResponseBuffLength(0)
, m_responseData(NULL)
, m_responseDataLength(0)
{
    m_curl = curl_easy_init();
    curl_easy_setopt(m_curl, CURLOPT_URL, url);
    curl_easy_setopt(m_curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; rv:2.0.1) Gecko/20100101 Firefox/4.0.1");
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, writeData);
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

void CCHttpRequest_win32::setTimeout(float timeout)
{
    curl_easy_setopt(m_curl, CURLOPT_TIMEOUT_MS, timeout * 1000);
}

void CCHttpRequest_win32::addPostValue(const char* key, const char* value)
{
    m_postFields[std::string(key)] = std::string(value);
}

bool CCHttpRequest_win32::start(void)
{
    if (m_state != STATE_IDLE) return false;
    m_state = STATE_IN_PROGRESS;
    
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, this);
    
    CreateThread(NULL,          // default security attributes
                 0,             // use default stack size
                 request,        // thread function name
                 this,           // argument to thread function
                 0,              // use default creation flags
                 NULL);
    
    return true;
}

DWORD WINAPI CCHttpRequest_win32::request(LPVOID lpParam)
{
    CCHttpRequest_win32* instance = (CCHttpRequest_win32*)lpParam;
    instance->onRequest();
    return 0;
}

size_t CCHttpRequest_win32::writeData(void* buffer, size_t size, size_t nmemb, void* userp)
{
    CCHttpRequest_win32* instance = (CCHttpRequest_win32*)userp;
    return instance->onWriteData(buffer, size * nmemb);
}

void CCHttpRequest_win32::onRequest(void)
{
    struct curl_httppost *post=NULL;
    struct curl_httppost *last=NULL;
    
    for (PostFieldsIterator it = m_postFields.begin(); it != m_postFields.end(); ++it)
    {
        curl_formadd(&post, &last,
                     CURLFORM_COPYNAME, it->first.c_str(),
                     CURLFORM_COPYCONTENTS, it->second.c_str(),
                     CURLFORM_END);
    }
    if (post)
    {
        curl_easy_setopt(m_curl, CURLOPT_HTTPPOST, post); 
    }
    curl_easy_perform(m_curl);
    curl_easy_cleanup(m_curl);
    curl_formfree(post);
    m_curl = NULL;
    
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
    
    m_responseString = string(reinterpret_cast<char*>(m_responseData));
    m_state = STATE_COMPLETED;
    CCLOG("completed\n");
}

size_t CCHttpRequest_win32::onWriteData(void* buffer, size_t bytes)
{
    CCHttpRequest_win32::Chunk* chunk = new CCHttpRequest_win32::Chunk(buffer, bytes);
    m_rawResponseBuff.push_back(chunk);
    m_rawResponseBuffLength += bytes;
    CCLOG("writeData %d bytes\n", bytes);
    return bytes;
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
    std::wstring result = wstring(buff);
    delete buff;
    return result;
}

NS_CC_EXT_END
