
#include "CCNativeScene.h"
#include "native/CCNative.h"
#include "HelloWorldScene.h"

CCNativeScene* CCNativeScene::scene(void)
{
    CCNativeScene* scene = new CCNativeScene();
    scene->init();
    scene->autorelease();
    return scene;
}

bool CCNativeScene::init(void)
{
    CCScene::init();
    
    CCLabelTTF* label = CCLabelTTF::create("showActivityIndicator()", "Arial", 22);
    CCMenuItemLabel* item1 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCNativeScene::testShowActivityIndicator));
    
    label = CCLabelTTF::create("hideActivityIndicator()", "Arial", 22);
    CCMenuItemLabel* item2 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCNativeScene::testHideActivityIndicator));
    
    label = CCLabelTTF::create("createAlertView()/showAlert()", "Arial", 22);
    CCMenuItemLabel* item3 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCNativeScene::testCreateAlertView));
    
    label = CCLabelTTF::create("getOpenUDID()", "Arial", 22);
    CCMenuItemLabel* item4 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCNativeScene::testGetOpenUDID));
    
    label = CCLabelTTF::create("openURL()", "Arial", 22);
    CCMenuItemLabel* item5 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCNativeScene::testOpenURL));
    
    
    label = CCLabelTTF::create("- BACK -", "Arial", 22);
    CCMenuItemLabel* itemBack = CCMenuItemLabel::create(label,
                                                        this,
                                                        menu_selector(CCNativeScene::backToMainScene));
    
	CCMenu* pMenu = CCMenu::create(item1, item2, item3, item4, item5, itemBack, NULL);
    pMenu->alignItemsVertically();
	addChild(pMenu);
    
    return true;
}

void CCNativeScene::testShowActivityIndicator(CCObject* pSender)
{
    CCNative::showActivityIndicator(CCActivityIndicatorViewStyleWhiteLarge);
}

void CCNativeScene::testHideActivityIndicator(CCObject* pSender)
{
    CCNative::hideActivityIndicator();
}

void CCNativeScene::testCreateAlertView(CCObject* pSender)
{
    CCNative::createAlert("This is alert view",
                          "Check console output.\nAfter 5 seconds, alert view auto cancel.",
                          "Cancel");
    CCNative::addAlertButton("More");
    CCNative::showAlert(this);
    
    CCDirector::sharedDirector()->getScheduler()->unscheduleAllSelectorsForTarget(this);
    CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(CCNativeScene::autoCancelAlertView),
                                                                   this,
                                                                   5.0f,
                                                                   false);
}

void CCNativeScene::autoCancelAlertView(float dt)
{
    CCDirector::sharedDirector()->getScheduler()->unscheduleAllSelectorsForTarget(this);
    CCNative::cancelAlert();
}

void CCNativeScene::testGetOpenUDID(CCObject* pSender)
{
    CCNative::createAlert("Your device OpenUDID",
                          CCNative::getOpenUDID(),
                          "OK");
    CCNative::showAlert();
}

void CCNativeScene::testOpenURL(CCObject* pSender)
{
    CCNative::openURL("https://github.com/dualface/cocos2d-x-extensions");
}

void CCNativeScene::backToMainScene(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

void CCNativeScene::alertViewClickedButtonAtIndex(int buttonIndex)
{
    CCDirector::sharedDirector()->getScheduler()->unscheduleAllSelectorsForTarget(this);
    printf("\n");
    printf("Alert view button [%d] selected\n", buttonIndex);
    printf("\n");
}
