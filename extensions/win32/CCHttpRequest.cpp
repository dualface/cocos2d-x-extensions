
#include "CCHttpRequest.h"
#include "CCHttpRequest_win32.h"

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

CCHttpRequest* CCHttpRequest::createWithUrlLua(cocos2d::LUA_FUNCTION listener,
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
    m_request = new CCHttpRequest_win32(m_url.c_str(), m_method);
    return true;
}

CCHttpRequest::~CCHttpRequest(void)
{
    delete (CCHttpRequest_win32*)m_request;
}

void CCHttpRequest::addRequestHeader(const char* key, const char* value)
{
}

void CCHttpRequest::addPostValue(const char* key, const char* value)
{
    ((CCHttpRequest_win32*)m_request)->addPostValue(key, value);
}

void CCHttpRequest::setTimeout(float timeout)
{
    ((CCHttpRequest_win32*)m_request)->setTimeout(timeout);
}

bool CCHttpRequest::getIsInProgress(void)
{
    return ((CCHttpRequest_win32*)m_request)->getIsInProgress();
}

void CCHttpRequest::start(bool isCached)
{
    CCScheduler::sharedScheduler()->unscheduleUpdateForTarget(this);
    if (((CCHttpRequest_win32*)m_request)->start())
    {
        CCScheduler::sharedScheduler()->scheduleUpdateForTarget(this, 0, false);
    }
}

void CCHttpRequest::cancel(void)
{
    CCScheduler::sharedScheduler()->unscheduleUpdateForTarget(this);
}

void CCHttpRequest::clearDelegatesAndCancel(void)
{
    m_delegate = NULL;
    cancel();
}

const char* CCHttpRequest::getResponseString(void)
{
    return ((CCHttpRequest_win32*)m_request)->getResposeString().c_str();
}

const void* CCHttpRequest::getResponseData(int* dataLength)
{
    return NULL;
}

void CCHttpRequest::update(ccTime dt)
{
    if (((CCHttpRequest_win32*)m_request)->getIsCompleted())
    {
        m_delegate->requestFinished(this);
        CCScheduler::sharedScheduler()->unscheduleUpdateForTarget(this);
    }
}

NS_CC_EXT_END
