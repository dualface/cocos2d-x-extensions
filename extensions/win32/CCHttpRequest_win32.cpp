
#include "CCHttpRequest_win32.h"

NS_CC_EXT_BEGIN

CCHttpRequest_win32::CCHttpRequest_win32(const char* url, CCHttpRequestMethod method)
: m_state(STATE_IDLE)
{
    m_curl = curl_easy_init();
    curl_easy_setopt(m_curl, CURLOPT_URL, url);
    curl_easy_setopt(m_curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; rv:2.0.1) Gecko/20100101 Firefox/4.0.1");
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, writeData);
    curl_easy_setopt(m_curl, CURLOPT_TIMEOUT_MS, DEFAULT_TIMEOUT * 1000);
}

CCHttpRequest_win32::~CCHttpRequest_win32(void)
{
    printf("~~ delete CCHttpRequest_win32\n");
}

void CCHttpRequest_win32::setTimeout(float timeout)
{
    curl_easy_setopt(m_curl, CURLOPT_TIMEOUT_MS, timeout * 1000);
}

bool CCHttpRequest_win32::start(void)
{
    if (m_state == STATE_IN_PROGRESS) return false;
    m_state = STATE_IN_PROGRESS;

    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, this);

    CreateThread(
        NULL,           // default security attributes
        0,              // use default stack size
        request,        // thread function name
        this,           // argument to thread function
        0,              // use default creation flags
        NULL);

    return true;
}

DWORD WINAPI CCHttpRequest_win32::request(LPVOID lpParam)
{
    CCHttpRequest_win32* instance = (CCHttpRequest_win32*)lpParam;
    curl_easy_perform(instance->m_curl);
    curl_easy_cleanup(instance->m_curl);
    instance->m_curl = NULL;
    instance->m_responseString = instance->m_responseStringBuff.str();
    instance->m_state = STATE_COMPLETED;
    printf("completed\n");
    return 0;
}

size_t CCHttpRequest_win32::writeData(void *buffer, size_t size, size_t nmemb, void *userp)
{
    CCHttpRequest_win32* instance = (CCHttpRequest_win32*)userp;
    size_t bytes = size * nmemb;
    printf("writeData %d bytes\n", bytes);
    instance->m_responseStringBuff.sputn((char*)buffer, bytes);
    return size * nmemb;
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
