
#include "CCHttpRequest.h"

#import "ASIHTTPRequest.h"
#import "ASIFormDataRequest.h"

namespace extensions {
    
    CCHttpRequest* CCHttpRequest::createWithUrl(CCHttpRequestDelegate* delegate,
                                                const char* url,
                                                CCHttpRequestMethod method,
                                                bool isAutoReleaseOnFinish)
    {
        CCHttpRequest* request = new CCHttpRequest(delegate, method, isAutoReleaseOnFinish);
        request->initWithUrl(url);
        request->autorelease();
        if (isAutoReleaseOnFinish)
        {
            request->retain();
        }
        return request;
    }
    
    bool CCHttpRequest::initWithUrl(const char *url)
    {
        NSURL *nsurl = [NSURL URLWithString:[NSString stringWithCString:url encoding:NSUTF8StringEncoding]];

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
        CCLOG("~~ delete CCHttpRequest");
    }
    
    void CCHttpRequest::addRequestHeader(const char* key, const char* value)
    {
        [(ASIHTTPRequest *)m_request addRequestHeader:[NSString stringWithCString:key encoding:NSUTF8StringEncoding]
                                                value:[NSString stringWithCString:value encoding:NSUTF8StringEncoding]];
    }
    
    void CCHttpRequest::addPostValue(const char* key, const char* value)
    {
        if (m_method != CCHttpRequestMethodPOST) return;
        
        [(ASIFormDataRequest *)m_request addPostValue:[NSString stringWithCString:value encoding:NSUTF8StringEncoding]
                                               forKey:[NSString stringWithCString:key encoding:NSUTF8StringEncoding]];
    }
    
    void CCHttpRequest::setTimeout(float timeout)
    {
        ((ASIHTTPRequest *)m_request).timeOutSeconds = timeout;
    }
    
    float CCHttpRequest::getTimeout(void)
    {
        return ((ASIHTTPRequest *)m_request).timeOutSeconds;
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
            if (m_isAutoReleaseOnFinish) release();
        }];
        
        [(ASIHTTPRequest *)m_request setFailedBlock:^{
            if (m_delegate) m_delegate->requestFailed(this);
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
    
    const char* CCHttpRequest::getResponseString(void)
    {
        return [[(ASIHTTPRequest*)m_request responseString] cStringUsingEncoding:NSUTF8StringEncoding];
    }
    
    const void* CCHttpRequest::getResponseData(int* dataLength)
    {
        *dataLength = [[(ASIHTTPRequest*)m_request responseData] length];
        return [[(ASIHTTPRequest*)m_request responseData] bytes];
    }
    
}
