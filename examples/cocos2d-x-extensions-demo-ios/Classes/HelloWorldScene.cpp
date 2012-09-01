
#include "HelloWorldScene.h"

#include "native/CCNative.h"

#include "CCCryptoScene.h"
#include "CCNativeScene.h"
#include "CCNetworkScene.h"
#include "CCStoreScene.h"

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCLabelTTF* label = CCLabelTTF::create("CCCrypto", "Arial", 24);
    CCMenuItemLabel* item1 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(HelloWorld::testCCCrypto));
    
    label = CCLabelTTF::create("CCNative", "Arial", 24);
    CCMenuItemLabel* item2 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(HelloWorld::testCCNative));
    
    label = CCLabelTTF::create("CCNetwork", "Arial", 24);
    CCMenuItemLabel* item3 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(HelloWorld::testCCNetwork));
    
    label = CCLabelTTF::create("CCStore", "Arial", 24);
    CCMenuItemLabel* item4 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(HelloWorld::testCCStore));
    
    label = CCLabelTTF::create("CCOpenFeint", "Arial", 24);
    CCMenuItemLabel* item5 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(HelloWorld::testCCOpenFeint));
    
	CCMenu* pMenu = CCMenu::create(item1, item2, item3, item4, item5, NULL);
    pMenu->alignItemsVertically();
	addChild(pMenu);
    
	return true;
}

void HelloWorld::testCCCrypto(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCCryptoScene::scene());
}

void HelloWorld::testCCNative(CCObject *pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCNativeScene::scene());
}

void HelloWorld::testCCNetwork(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCNetworkScene::scene());
}

void HelloWorld::testCCStore(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCStoreScene::scene());
}

void HelloWorld::testCCOpenFeint(CCObject* pSender)
{
    CCNative::createAlert("INFO", "CCOpenFeint manual please see cocos2dx-extensions on github.com, open browser ?",
                          "Cancel");
    CCNative::addAlertButton("OK");
    CCNative::showAlert(this);
}

void HelloWorld::alertViewClickedButtonAtIndex(int buttonIndex)
{
    if (buttonIndex == 1)
    {
        CCNative::openURL("https://github.com/dualface/cocos2d-x-extensions");
    }
}
