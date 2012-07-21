
#include "CCHttpRequest.h"

#import "ASIHTTPRequest.h"
#import "ASIFormDataRequest.h"

USING_NS_CC;

NS_CC_EXT_BEGIN

CCHttpRequest* CCHttpRequest::createWithUrl(CCHttpRequestDelegate* delegate,
                                            const char* url,
                                            CCHttpRequestMethod method,
                                            bool isAutoReleaseOnFinish)
{
    CCHttpRequest* request = new CCHttpRequest(delegate, url, method, isAutoReleaseOnFinish);
    request->initHttpRequest();
    request->autorelease();
    if (isAutoReleaseOnFinish)
    {
        request->retain();
    }
    return request;
}

#if CC_LUA_ENGINE_ENABLED > 0
CCHttpRequest* CCHttpRequest::createWithUrlLua(LUA_FUNCTION listener,
                                               const char* url,
                                               CCHttpRequestMethod method)
{
    CCHttpRequest* request = new CCHttpRequest(NULL, url, method, true);
    request->m_luaListener = listener;
    request->initHttpRequest();
    request->autorelease();
    request->retain();
    return request;
}
#endif

bool CCHttpRequest::initHttpRequest(void)
{
    NSURL *nsurl = [NSURL URLWithString:[NSString stringWithCString:m_url.c_str() encoding:NSUTF8StringEncoding]];
    
    ASIHTTPRequest *request;
    if (m_method != CCHttpRequestMethodPOST)
    {
        request = [ASIHTTPRequest requestWithURL:nsurl];
    }
    else
    {
        request = [ASIFormDataRequest requestWithURL:nsurl];
    }
    
    const char* methods[] = {"GET", "POST"};
    [request setRequestMethod:[NSString stringWithCString:methods[m_method] encoding:NSUTF8StringEncoding]];
    
    [request retain];
    m_request = request;
    
    return true;
}

CCHttpRequest::~CCHttpRequest(void)
{
    [(ASIHTTPRequest *)m_request release];
    
#if CC_LUA_ENGINE_ENABLED > 0
    if (m_luaListener)
    {
        CCScriptEngineManager::sharedManager()->getScriptEngine()->removeLuaHandler(m_luaListener);
    }
#endif
    CCLOG("~~ delete CCHttpRequest");
}

void CCHttpRequest::addRequestHeader(const char* key, const char* value)
{
    [(ASIHTTPRequest *)m_request addRequestHeader:[NSString stringWithCString:key encoding:NSUTF8StringEncoding]
                                            value:[NSString stringWithCString:value encoding:NSUTF8StringEncoding]];
}

void CCHttpRequest::addPostValue(const char* key, const char* value)
{
    if (m_method != CCHttpRequestMethodPOST || !key) return;
    NSString *value_ = [NSString stringWithCString:value ? value : "" encoding:NSUTF8StringEncoding];
    NSString *key_ = [NSString stringWithCString:key encoding:NSUTF8StringEncoding];
    [(ASIFormDataRequest *)m_request addPostValue:value_ forKey:key_];
}

void CCHttpRequest::addPostData(const void* data, const unsigned int uiLength)
{
    if (m_method != CCHttpRequestMethodPOST) return;
    
    [(ASIFormDataRequest *)m_request appendPostData:[NSData dataWithBytes:data length:uiLength]];
}

void CCHttpRequest::setTimeout(float timeout)
{
    ((ASIHTTPRequest *)m_request).timeOutSeconds = timeout;
}

bool CCHttpRequest::getIsInProgress(void)
{
    return [(ASIHTTPRequest *)m_request inProgress];
}

void CCHttpRequest::start(bool isCached)
{
    if (getIsInProgress()) return;
    
    [(ASIHTTPRequest *)m_request setCompletionBlock:^{
        if (m_delegate) m_delegate->requestFinished(this);
#if CC_LUA_ENGINE_ENABLED > 0
        if (m_luaListener)
        {
            CCScriptValueDict dict;
            dict["name"] = CCScriptValue::stringValue("completed");
            dict["request"] = CCScriptValue::ccobjectValue(this, "CCHttpRequest");
            CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();
            engine->pushCCScriptValueDictToLuaStack(dict);
            engine->executeFunctionByHandler(m_luaListener, 1);
        }
#endif
        if (m_isAutoReleaseOnFinish) release();
    }];
    
    [(ASIHTTPRequest *)m_request setFailedBlock:^{
        NSError *nserror = [(ASIHTTPRequest *)m_request error];
        switch ([nserror code])
        {
            case ASIConnectionFailureErrorType:
                m_errorCode = CCHttpRequestErrorConnectionFailure;
                break;
            
            case ASIRequestTimedOutErrorType:
                m_errorCode = CCHttpRequestErrorTimeout;
                break;
                
            case ASIAuthenticationErrorType:
                m_errorCode = CCHttpRequestErrorAuthentication;
                break;
            
            case ASIRequestCancelledErrorType:
                m_errorCode = CCHttpRequestErrorCancelled;
                break;
                
            default:
                m_errorCode = CCHttpRequestErrorUnknown;
        }
        m_errorMessage = [[nserror localizedDescription] cStringUsingEncoding:NSUTF8StringEncoding];
        
        if (m_delegate) m_delegate->requestFailed(this);
#if CC_LUA_ENGINE_ENABLED > 0
        if (m_luaListener)
        {
            CCScriptValueDict dict;
            dict["name"] = CCScriptValue::stringValue("failed");
            dict["request"] = CCScriptValue::ccobjectValue(this, "CCHttpRequest");
            CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();
            engine->pushCCScriptValueDictToLuaStack(dict);
            engine->executeFunctionByHandler(m_luaListener, 1);
        }
#endif
        if (m_isAutoReleaseOnFinish) release();
    }];
    
    [(ASIHTTPRequest *)m_request startAsynchronous];
}

void CCHttpRequest::cancel(void)
{
    [(ASIHTTPRequest *)m_request cancel];
}

void CCHttpRequest::clearDelegatesAndCancel(void)
{
    m_delegate = NULL;
    cancel();
}

int CCHttpRequest::getResponseStatusCode(void)
{
    return [(ASIHTTPRequest*)m_request responseStatusCode];
}

const char* CCHttpRequest::getResponseString(void)
{
    return [[(ASIHTTPRequest*)m_request responseString] cStringUsingEncoding:NSUTF8StringEncoding];
}

const void* CCHttpRequest::getResponseData(int* dataLength)
{
    *dataLength = [[(ASIHTTPRequest*)m_request responseData] length];
    return [[(ASIHTTPRequest*)m_request responseData] bytes];
}

CCHttpRequestError CCHttpRequest::getErrorCode(void)
{
    return m_errorCode;
}

const char* CCHttpRequest::getErrorMessage(void)
{
    return m_errorMessage.c_str();
}

void CCHttpRequest::update(float dt)
{
}

NS_CC_EXT_END
