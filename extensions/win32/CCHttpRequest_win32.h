
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
    
    void addRequestHeader(const char* key, const char* value);
    void addPostValue(const char* key, const char* value);
    void setTimeout(float timeout);
    
    bool start(void);
    void cancel(void);
    
    bool getIsInProgress(void) {
        return m_state == STATE_IN_PROGRESS;
    }
    
    bool getIsCompleted(void) {
        return m_state == STATE_COMPLETED;
    }

    bool getIsCancelled(void) {
        return m_state == STATE_CANCELLED;
    }

    int getResponseStatusCode(void) {
        return m_responseCode;
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

    CCHttpRequestError getErrorCode(void) {
        return m_errorCode;
    }
    
    const char* getErrorMessage(void) {
        return m_errorMessage.c_str();
    }
    
private:
    enum {
        DEFAULT_TIMEOUT = 10, // 10 seconds
    };
    
    typedef enum {
        STATE_IDLE,
        STATE_IN_PROGRESS,
        STATE_COMPLETED,
        STATE_CANCELLED
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

    typedef std::vector<std::string>            Headers;
    typedef Headers::iterator                   HeadersIterator;
    
    CURL*               m_curl;
    State               m_state;
    PostFields          m_postFields;
    Headers             m_headers;
    RawResponseDataBuff m_rawResponseBuff;
    size_t              m_rawResponseBuffLength;
    long                m_responseCode;
    CCHttpRequestError  m_errorCode;
    std::string         m_errorMessage;
    
    std::string         m_responseString;
    BYTE*               m_responseData;
    int                 m_responseDataLength;
    
    static DWORD WINAPI curlRequest(LPVOID lpParam);
    static size_t curlWriteData(void* buffer, size_t size, size_t nmemb, void *userp);
    static int curlProgress(void* userp, double dltotal, double dlnow, double ultotal, double ulnow);
    
    void onRequest(void);
    size_t onWriteData(void* buffer, size_t bytes);
    int onProgress(double dltotal, double dlnow, double ultotal, double ulnow);
    
    void cleanup(void);
    void cleanupRawResponseBuff(void);
    const std::wstring cstr2wstring(const char* source);
};

NS_CC_EXT_END

#endif // __CC_EXTENSION_CCHTTP_REQUEST_WIN32_H_
