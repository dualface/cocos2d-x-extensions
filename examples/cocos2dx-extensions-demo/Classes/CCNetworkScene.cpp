
#include "CCNetworkScene.h"
#include "CCNetwork.h"
#include "CCNative.h"
#include "CCHttpRequest.h"
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
    
    label = CCLabelTTF::labelWithString("send synchronous HTTP request", "Arial", 22);
    CCMenuItemLabel* item2 = CCMenuItemLabel::itemWithLabel(label,
                                                            this,
                                                            menu_selector(CCNetworkScene::testHttpRequest));
    
    label = CCLabelTTF::labelWithString("- BACK -", "Arial", 22);
    CCMenuItemLabel* itemBack = CCMenuItemLabel::itemWithLabel(label,
                                                               this,
                                                               menu_selector(CCNetworkScene::backToMainScene));
    
	CCMenu* pMenu = CCMenu::menuWithItems(item1, item2, itemBack, NULL);
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

void CCNetworkScene::testHttpRequest(CCObject* pSender)
{
    CCNetwork::httpRequest(this, "http://www.cocos2d-x.org/projects.json", CCHttpRequestMethodGET);
    CCNative::createAlert("CCNetwork::httpRequest",
                          "Get http://www.cocos2d-x.org/projects.json contents, check console output.",
                          NULL);
    CCNative::showAlert();
}

void CCNetworkScene::backToMainScene(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(HelloWorldScene::scene());
}

void CCNetworkScene::requestFinished(CCHttpRequest* request)
{
    CCLOG("http request response string length: %d", strlen(request->getResponseString()));
    printf("----------------------------------------\n");
    puts(request->getResponseString());
    printf("----------------------------------------\n");
    CCNative::cancelAlert();
    CCNative::createAlert("Http Request Completed", "Request completed, check console output.", "OK");
    CCNative::showAlert();
}

void CCNetworkScene::requestFailed(CCHttpRequest* request)
{
    CCNative::cancelAlert();
    CCNative::createAlert("Http Request Failed", "Request failed, check console output.", "OK");
    CCNative::showAlert();
}
