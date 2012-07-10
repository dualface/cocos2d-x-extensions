
#ifndef __EXTENSIONS_CCHTTP_REQUEST_H_
#define __EXTENSIONS_CCHTTP_REQUEST_H_

#include "CCObject.h"
#include "CCHttpRequestDelegate.h"

#if CC_LUA_ENGINE_ENABLED > 0
#include "CCScriptSupport.h"
#endif

using namespace cocos2d;

namespace extensions {
    
    typedef enum {
        CCHttpRequestMethodGET = 0,
        CCHttpRequestMethodPOST,
    } CCHttpRequestMethod;
    
    class CCHttpRequest : public CCObject
    {
    public:
        static CCHttpRequest* createWithUrl(CCHttpRequestDelegate* delegate,
                                            const char* url,
                                            CCHttpRequestMethod method = CCHttpRequestMethodGET,
                                            bool isAutoReleaseOnFinish = true);
        
#if CC_LUA_ENGINE_ENABLED > 0
        static CCHttpRequest* createWithUrlLua(LUA_FUNCTION listener,
                                               const char* url,
                                               CCHttpRequestMethod method = CCHttpRequestMethodGET);
#endif
        
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
        const char* getResponseString(void);
        
        /** @brief Response data. */
        const void* getResponseData(int* dataLength);
        
    private:
        CCHttpRequest(CCHttpRequestDelegate* delegate, CCHttpRequestMethod method, bool isAutoReleaseOnFinish)
        : m_delegate(delegate)
        , m_method(method)
        , m_request(NULL)
        , m_isAutoReleaseOnFinish(isAutoReleaseOnFinish)
#if CC_LUA_ENGINE_ENABLED > 0
        , m_luaListener(0)
#endif
        {
        }
        bool initWithUrl(const char* url);
        
        CCHttpRequestDelegate*  m_delegate;
        CCHttpRequestMethod     m_method;
        void*                   m_request;
        bool                    m_isAutoReleaseOnFinish;        
#if CC_LUA_ENGINE_ENABLED > 0
        LUA_FUNCTION            m_luaListener;
#endif
    };
    
}

#endif // __EXTENSIONS_CCHTTP_REQUEST_H_
