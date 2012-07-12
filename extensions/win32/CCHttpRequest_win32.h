
#ifndef __CC_EXTENSION_CCHTTP_REQUEST_WIN32_H_
#define __CC_EXTENSION_CCHTTP_REQUEST_WIN32_H_

#include <Windows.h>
#include "CCHttpRequest.h"
#include "curl.h"

NS_CC_EXT_BEGIN

class CCHttpRequest_win32
{
public:
    CCHttpRequest_win32(const char* url, CCHttpRequestMethod method);
    virtual ~CCHttpRequest_win32(void);

    void setTimeout(float timeout);

    bool start(void);
    
    bool getIsInProgress(void) {
        return m_state == STATE_IN_PROGRESS;
    }
    
    bool getIsCompleted(void) {
        return m_state == STATE_COMPLETED;
    }
    
    const std::string& getResposeString(void) {
        return m_responseString;
    }
    
private:
    enum {
        DEFAULT_TIMEOUT = 30, // 30 seconds
    };

    typedef enum {
        STATE_IDLE,
        STATE_IN_PROGRESS,
        STATE_COMPLETED
    } State;

    CURL*               m_curl;
    State               m_state;
    std::stringbuf      m_responseStringBuff;
    std::string         m_responseString;

    static DWORD WINAPI request(LPVOID lpParam);
    static size_t writeData(void *buffer, size_t size, size_t nmemb, void *userp);

    const std::wstring cstr2wstring(const char* source);
};

NS_CC_EXT_END

#endif // __CC_EXTENSION_CCHTTP_REQUEST_WIN32_H_
