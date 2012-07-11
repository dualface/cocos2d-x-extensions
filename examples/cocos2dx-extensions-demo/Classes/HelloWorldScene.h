#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CCAlertViewDelegate.h"

USING_NS_CC;
USING_NS_CC_EXT;

class HelloWorldScene : public CCScene, public CCAlertViewDelegate
{
public:
    static HelloWorldScene* scene(void);
	
    void testCCCrypto(CCObject* pSender);
    void testCCNative(CCObject* pSender);
    void testCCNetwork(CCObject* pSender);
    void testCCStore(CCObject* pSender);
    void testCCOpenFeint(CCObject* pSender);

    virtual void alertViewClickedButtonAtIndex(int buttonIndex);
    
private:
	virtual bool init(void);
};

#endif // __HELLOWORLD_SCENE_H__
