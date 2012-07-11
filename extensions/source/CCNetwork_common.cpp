
#include "CCNetwork.h"

using namespace cocos2d;

namespace extensions {
    
    CCHttpRequest* CCNetwork::httpRequest(CCHttpRequestDelegate* delegate,
                                          const char* url,
                                          CCHttpRequestMethod method)
    {
        CCHttpRequest* request = CCHttpRequest::createWithUrl(delegate, url, method);
        request->start();
        return request;
    }
    
#if CC_LUA_ENGINE_ENABLED > 0
    CCHttpRequest* CCNetwork::httpRequestLua(LUA_FUNCTION listener,
                                             const char* url,
                                             CCHttpRequestMethod method)
    {
        CCHttpRequest* request = CCHttpRequest::createWithUrlLua(listener, url, method);
        request->start();
        return request;
    }
#endif
    
}
