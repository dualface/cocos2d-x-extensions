#include "HelloWorldScene.h"


#include "CCCryptoScene.h"
#include "CCNativeScene.h"
#include "CCNetworkScene.h"
#include "CCStoreScene.h"
#include "CCNative.h"

HelloWorldScene* HelloWorldScene::scene(void)
{
    HelloWorldScene* scene = new HelloWorldScene();
    scene->init();
    scene->autorelease();
    return scene;
}

bool HelloWorldScene::init(void)
{
    CCScene::init();

    CCLabelTTF* label = CCLabelTTF::labelWithString("CCCrypto", "Arial", 24);
    CCMenuItemLabel* item1 = CCMenuItemLabel::itemWithLabel(label,
                                                            this,
                                                            menu_selector(HelloWorldScene::testCCCrypto));

    label = CCLabelTTF::labelWithString("CCNative", "Arial", 24);
    CCMenuItemLabel* item2 = CCMenuItemLabel::itemWithLabel(label,
                                                            this,
                                                            menu_selector(HelloWorldScene::testCCNative));
    
    label = CCLabelTTF::labelWithString("CCNetwork", "Arial", 24);
    CCMenuItemLabel* item3 = CCMenuItemLabel::itemWithLabel(label,
                                                            this,
                                                            menu_selector(HelloWorldScene::testCCNetwork));
    
    label = CCLabelTTF::labelWithString("CCStore", "Arial", 24);
    CCMenuItemLabel* item4 = CCMenuItemLabel::itemWithLabel(label,
                                                            this,
                                                            menu_selector(HelloWorldScene::testCCStore));
    
    label = CCLabelTTF::labelWithString("CCOpenFeint", "Arial", 24);
    CCMenuItemLabel* item5 = CCMenuItemLabel::itemWithLabel(label,
                                                            this,
                                                            menu_selector(HelloWorldScene::testCCOpenFeint));
    
	CCMenu* pMenu = CCMenu::menuWithItems(item1, item2, item3, item4, item5, NULL);
    pMenu->alignItemsVertically();
	addChild(pMenu);
    
	return true;
}

void HelloWorldScene::testCCCrypto(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCCryptoScene::scene());
}

void HelloWorldScene::testCCNative(CCObject *pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCNativeScene::scene());
}

void HelloWorldScene::testCCNetwork(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCNetworkScene::scene());
}

void HelloWorldScene::testCCStore(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(CCStoreScene::scene());
}

void HelloWorldScene::testCCOpenFeint(CCObject* pSender)
{
    CCNative::createAlert("INFO", "CCOpenFeint manual please see cocos2dx-extensions on github.com, open browser ?", "Cancel");
    CCNative::addAlertButton("OK");
    CCNative::showAlert(this);
}

void HelloWorldScene::alertViewClickedButtonAtIndex(int buttonIndex)
{
    if (buttonIndex == 1)
    {
        CCNative::openURL("https://github.com/dualface/cocos2d-x-extensions");
    }
}
