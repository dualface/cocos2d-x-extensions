
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "native/CCAlertViewDelegate.h"

USING_NS_CC;
USING_NS_CC_EXT;

class HelloWorld : public CCLayer, public CCAlertViewDelegate
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static CCScene* scene();

    void testCCCrypto(CCObject* pSender);
    void testCCNative(CCObject* pSender);
    void testCCNetwork(CCObject* pSender);
    void testCCStore(CCObject* pSender);
    void testCCOpenFeint(CCObject* pSender);

    virtual void alertViewClickedButtonAtIndex(int buttonIndex);

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
