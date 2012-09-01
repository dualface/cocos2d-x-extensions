
#include "CCStoreScene.h"
#include "cocoa/CCArray.h"
#include "store/CCStore.h"
#include "store/CCStoreProduct.h"
#include "store/CCStorePaymentTransaction.h"
#include "native/CCNative.h"
#include "HelloWorldScene.h"

CCStoreScene* CCStoreScene::scene(void)
{
    CCStoreScene* scene = new CCStoreScene();
    scene->init();
    scene->autorelease();
    return scene;
}

bool CCStoreScene::init(void)
{
    CCScene::init();
    const char* contents = "1. TEST ON DEVICE\n2. CHANGE PROJECT INFO, SET BUNDLE IDENTIFIER\n3. CHANGE CCStoreScene::testLoadProducts(), SET PRODUCTS ID";
    const CCSize& winSize = CCDirector::sharedDirector()->getWinSize();
    CCLabelTTF* label = CCLabelTTF::create(contents,
                                           "Arial",
                                           14,
                                           CCSize(winSize.width, 0),
                                           kCCTextAlignmentCenter);
    label->setPosition(ccp(winSize.width / 2, winSize.height - 60));
    addChild(label);
    
    label = CCLabelTTF::create("loadProducts()", "Arial", 22);
    CCMenuItemLabel* item1 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCStoreScene::testLoadProducts));
    
    label = CCLabelTTF::create("purchase()", "Arial", 22);
    CCMenuItemLabel* item2 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCStoreScene::testPurchase));
    
    label = CCLabelTTF::create("- BACK -", "Arial", 22);
    CCMenuItemLabel* itemBack = CCMenuItemLabel::create(label,
                                                        this,
                                                        menu_selector(CCStoreScene::backToMainScene));
    
	CCMenu* pMenu = CCMenu::create(item1, item2, itemBack, NULL);
    pMenu->alignItemsVertically();
    pMenu->setTag(MENU_TAG);
	addChild(pMenu);
    
    CCStore::sharedStore()->postInitWithTransactionObserver(this);
    
    // for product release, uncomment this
    // CCStore::sharedStore()->setReceiptVerifyMode(CCStoreReceiptVerifyModeDevice);
    
    return true;
}

void CCStoreScene::testLoadProducts(CCObject* pSender)
{
    CCArray* productsId = new CCArray();
    productsId->autorelease();
    
    CCNative::createAlert("Waiting", "Retrieving Product Information", NULL);
    CCNative::showAlert();
    
    // SET IAP PRODUCTS ID
    productsId->addObject(newCCString("org.cocos2d-x.games.demo.iap01"));
    productsId->addObject(newCCString("org.cocos2d-x.games.demo.iap02"));
    productsId->addObject(newCCString("org.cocos2d-x.games.demo.iap03"));
    CCStore::sharedStore()->loadProducts(productsId, this);
}

void CCStoreScene::testPurchase(CCObject* pSender)
{
    if (CCStore::sharedStore()->purchase("com.qeeplay.games.killfruitcn.iap.buycoins03"))
    {
        CCNative::createAlert("Waiting", "Purchase IAP Product, please wait.", NULL);
        CCNative::showAlert();
    }
    else
    {
        CCNative::createAlert("ERROR", "Load products first.", "OK");
        CCNative::showAlert();
    }
}

void CCStoreScene::backToMainScene(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

#pragma mark -
#pragma mark CCStoreTransactionObserver

void CCStoreScene::transactionCompleted(CCStorePaymentTransaction* transaction)
{
    CCNative::cancelAlert();
    CCNative::createAlert("TRANSACTION COMPLETED", "Transaction completed. Check console output.", "OK");
    CCNative::showAlert();
    
    printf("\n");
    printf("TransactionIdentifier: %s\n", transaction->getTransactionIdentifier().c_str());
    printf("\n");
    
    CCStore::sharedStore()->finishTransaction(transaction);
}

void CCStoreScene::transactionFailed(CCStorePaymentTransaction* transaction)
{
    CCNative::cancelAlert();
    CCNative::createAlert("TRANSACTION FAILED", transaction->getErrorDescription().c_str(), "OK");
    CCNative::showAlert();
    
    CCStore::sharedStore()->finishTransaction(transaction);
}

void CCStoreScene::transactionRestored(CCStorePaymentTransaction* transaction)
{
    CCNative::cancelAlert();
    CCNative::createAlert("TRANSACTION RESTORED", "Transaction restored. Check console output.", "OK");
    CCNative::showAlert();
    
    printf("\n");
    printf("TransactionIdentifier: %s\n", transaction->getTransactionIdentifier().c_str());
    printf("OriginTransactionIdentifier: %s\n",
           transaction->getOriginalTransaction()->getTransactionIdentifier().c_str());
    printf("\n");
    
    CCStore::sharedStore()->finishTransaction(transaction);
}

#pragma mark -
#pragma mark CCStoreProductsRequestDelegate

void CCStoreScene::requestProductsCompleted(CCArray* products, CCArray* invalidProductsId)
{
    CCNative::cancelAlert();
    CCNative::createAlert("LOAD PRODUCTS COMPLETED", "Load products completed. Check console output", "OK");
    CCNative::showAlert();
    
    printf("\n");
    for (int i = 0; i < products->count(); ++i)
    {
        CCStoreProduct* product = static_cast<CCStoreProduct*>(products->objectAtIndex(i));
        printf("PRODUCT ID: %s\n",              product->getProductIdentifier().c_str());
        printf("  localizedTitle: %s\n",        product->getLocalizedTitle().c_str());
        printf("  localizedDescription: %s\n",  product->getLocalizedDescription().c_str());
        printf("  priceLocale: %s\n",           product->getPriceLocale().c_str());
        printf("  price: %0.2f\n",              product->getPrice());
    }
    printf("\n");
    
    if (invalidProductsId && invalidProductsId->count() > 0)
    {
        printf("FOUND INVALID PRODUCTS ID\n");
        for (int i = 0; i < invalidProductsId->count(); ++i)
        {
            CCString* ccid = static_cast<CCString*>(invalidProductsId->objectAtIndex(i));
            printf("  %s\n", ccid->getCString());
        }
    }
    
    printf("\n");
}

void CCStoreScene::requestProductsFailed(int errorCode, const char* errorString)
{
    CCNative::cancelAlert();
    CCNative::createAlert("ERROR", errorString, "OK");
    CCNative::showAlert();
}


#pragma mark -
#pragma mark helper

CCString* CCStoreScene::newCCString(const char* string)
{
    CCString* str = new CCString(string);
    str->autorelease();
    return str;
}
