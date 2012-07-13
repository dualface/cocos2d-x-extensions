
#ifndef __CC_EXTENSION_CCHTTP_REQUEST_WIN32_H_
#define __CC_EXTENSION_CCHTTP_REQUEST_WIN32_H_

#include <Windows.h>
#include <vector>
#include <map>
#include "CCHttpRequest.h"
#include "curl.h"

NS_CC_EXT_BEGIN

class CCHttpRequest_win32
{
public:
    CCHttpRequest_win32(const char* url, CCHttpRequestMethod method);
    virtual ~CCHttpRequest_win32(void);

    void setTimeout(float timeout);
    void addPostValue(const char* key, const char* value);

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

    const void* getResponseData(void) {
        return m_responseData;
    }

    int getResponseDataLength(void) {
        return m_responseDataLength;
    }
    
private:
    enum {
        DEFAULT_TIMEOUT = 10, // 10 seconds
    };

    typedef enum {
        STATE_IDLE,
        STATE_IN_PROGRESS,
        STATE_COMPLETED
    } State;

    class Chunk
    {
    public:
        Chunk(const void* source, size_t bytes)
        : m_bytes(bytes)
        {
            m_chunk = malloc(bytes);
            memcpy_s(m_chunk, bytes, source, bytes);
        }
        ~Chunk(void) {
            free(m_chunk);
        }

        void* getChunk(void) {
            return m_chunk;
        }
        size_t getBytes(void) {
            return m_bytes;
        }

    private:
        void*   m_chunk;
        size_t  m_bytes;
    };

    typedef std::vector<Chunk*>                 RawResponseDataBuff;
    typedef RawResponseDataBuff::iterator       RawResponseDataBuffIterator;

    typedef std::map<std::string, std::string>  PostFields;
    typedef PostFields::iterator                PostFieldsIterator;

    CURL*               m_curl;
    State               m_state;
    PostFields          m_postFields;
    RawResponseDataBuff m_rawResponseBuff;
    size_t              m_rawResponseBuffLength;

    std::string         m_responseString;
    BYTE*               m_responseData;
    int                 m_responseDataLength;

    static DWORD WINAPI request(LPVOID lpParam);
    static size_t writeData(void* buffer, size_t size, size_t nmemb, void *userp);

    void onRequest(void);
    size_t onWriteData(void* buffer, size_t bytes);

    void cleanup(void);
    void cleanupRawResponseBuff(void);
    const std::wstring cstr2wstring(const char* source);
};

NS_CC_EXT_END

#endif // __CC_EXTENSION_CCHTTP_REQUEST_WIN32_H_
