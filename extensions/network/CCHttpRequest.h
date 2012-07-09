
#ifndef __EXTENSIONS_CCHTTP_REQUEST_H_
#define __EXTENSIONS_CCHTTP_REQUEST_H_

#include <string>
#include <map>
#include "CCObject.h"
#include "CCHttpRequestDelegate.h"

using namespace std;
using namespace cocos2d;

namespace extensions {
    
    typedef enum {
        CCHttpRequestMethodGET = 0,
        CCHttpRequestMethodPOST,
    } CCHttpRequestMethod;
    
    typedef map<string, string>             CCHttpRequestHeaders;
    typedef CCHttpRequestHeaders::iterator  CCHttpRequestHeadersIterator;
    
    class CCHttpRequest : public CCObject
    {
    public:
        static CCHttpRequest* createWithUrl(CCHttpRequestDelegate* delegate,
                                            const char* url,
                                            CCHttpRequestMethod method = CCHttpRequestMethodGET,
                                            bool isAutoReleaseOnFinish = true);
        ~CCHttpRequest(void);
        
        /** @brief Add a custom header to the request. */
        void addRequestHeader(const char* key, const char* value);
        
        /** @brief Add a POST variable to the request, POST only. */
        void addPostValue(const char* key, const char* value);
        
        /** @brief Number of seconds to wait before timing out - default is 10. */
        void setTimeout(float timeout);
        float getTimeout(void);
        
        /** @brief True when the request hasn't finished yet. */
        bool getIsInProgress(void);
        
        /** @brief Eexecute an asynchronous request
         
         If isCached set to false, it will force request not to be cached.        
         Setting isCache to false also appends a query string parameter, "_=[TIMESTAMP]", to the URL.
         */
        void start(bool isCached = false);
        
        /** @brief Cancel an asynchronous request. */
        void cancel(void);
        
        /** @brief Cancel an asynchronous request, clearing all delegates first. */
        void clearDelegatesAndCancel(void);
        
        /** @brief Returns the contents of the result. */
        const const char* getResponseString(void);
        
        /** @brief Response data. */
        const void* getResponseData(int* dataLength);
        
    private:
        CCHttpRequest(CCHttpRequestDelegate* delegate, CCHttpRequestMethod method, bool isAutoReleaseOnFinish)
        : m_delegate(delegate)
        , m_method(method)
        , m_request(NULL)
        , m_isAutoReleaseOnFinish(isAutoReleaseOnFinish)
        {
        }
        bool initWithUrl(const char* url);
        
        CCHttpRequestDelegate*  m_delegate;
        CCHttpRequestMethod     m_method;
        void*                   m_request;
        bool                    m_isAutoReleaseOnFinish;
    };
    
}

#endif // __EXTENSIONS_CCHTTP_REQUEST_H_
