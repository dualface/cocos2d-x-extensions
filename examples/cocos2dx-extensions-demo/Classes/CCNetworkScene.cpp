
#include "CCNetworkScene.h"
#include "CCNetwork.h"
#include "HelloWorldScene.h"

using namespace extensions;

CCNetworkScene* CCNetworkScene::scene(void)
{
    CCNetworkScene* scene = new CCNetworkScene();
    scene->init();
    scene->autorelease();
    return scene;
}

bool CCNetworkScene::init(void)
{
    CCScene::init();
    
    CCLabelTTF* label = CCLabelTTF::labelWithString("check network status", "Arial", 22);
    CCMenuItemLabel* item1 = CCMenuItemLabel::itemWithLabel(label,
                                                            this,
                                                            menu_selector(CCNetworkScene::testCheckNetworkStatus));
    
    label = CCLabelTTF::labelWithString("- BACK -", "Arial", 22);
    CCMenuItemLabel* itemBack = CCMenuItemLabel::itemWithLabel(label,
                                                               this,
                                                               menu_selector(CCNetworkScene::backToMainScene));
    
	CCMenu* pMenu = CCMenu::menuWithItems(item1, itemBack, NULL);
    pMenu->alignItemsVertically();
	addChild(pMenu);
    
    return true;
}

void CCNetworkScene::testCheckNetworkStatus(CCObject* pSender)
{
    bool isLocalWiFiAvailable = CCNetwork::isLocalWiFiAvailable();
    bool isInternetConnectionAvailable = CCNetwork::isInternetConnectionAvailable();
    bool isHostNameReachable = CCNetwork::isHostNameReachable("github.com");
    CCNetworkStatus ns = CCNetwork::getInternetConnectionStatus();
    
    printf("\n");
    printf("isLocalWiFiAvailable: %s\n", isLocalWiFiAvailable ? "YES" : "NO");
    printf("isInternetConnectionAvailable: %s\n", isInternetConnectionAvailable ? "YES" : "NO");
    printf("isHostNameReachable(\"github.com\"): %s\n", isHostNameReachable ? "YES" : "NO");
    
    const char* nsString[] = {
        "CCNetworkStatusNotReachable",
        "CCNetworkStatusReachableViaWiFi",
        "CCNetworkStatusReachableViaWWAN"
    };
    printf("getInternetConnectionStatus(): %s\n", nsString[ns]);
    
    printf("\n");
    
}

void CCNetworkScene::backToMainScene(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(HelloWorldScene::scene());
}
