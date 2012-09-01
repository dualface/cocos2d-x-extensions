
#ifndef cocos2dx_extensions_demo_CCNetworkScene_h
#define cocos2dx_extensions_demo_CCNetworkScene_h

#include "cocos2d.h"
#include "network/CCHttpRequestDelegate.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CCNetworkScene : public CCScene, public CCHttpRequestDelegate
{
public:
    static CCNetworkScene* scene(void);
    
    void testCheckNetworkStatus(CCObject* pSender);
    void testHttpRequest(CCObject* pSender);
    void backToMainScene(CCObject* pSender);
    
    virtual void requestFinished(CCHttpRequest* request);
    virtual void requestFailed(CCHttpRequest* request);
    
private:
    bool init(void);
};

#endif
