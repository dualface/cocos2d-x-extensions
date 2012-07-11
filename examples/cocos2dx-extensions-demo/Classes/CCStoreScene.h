
#ifndef cocos2dx_extensions_demo_CCStoreScene_h
#define cocos2dx_extensions_demo_CCStoreScene_h

#include "cocos2d.h"
#include "CCStoreTransactionObserver.h"
#include "CCStoreProductsRequestDelegate.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CCStoreScene : public CCScene, public CCStoreTransactionObserver, public CCStoreProductsRequestDelegate
{
public:
    static const int MENU_TAG = 123;
    
    static CCStoreScene* scene(void);
    
    void testLoadProducts(CCObject* pSender);
    void testPurchase(CCObject* pSender);
    void backToMainScene(CCObject* pSender);
        
#pragma mark -
#pragma mark CCStoreTransactionObserver
    
    virtual void transactionCompleted(CCStorePaymentTransaction* transaction);
    virtual void transactionFailed(CCStorePaymentTransaction* transaction);
    virtual void transactionRestored(CCStorePaymentTransaction* transaction);

#pragma mark -
#pragma mark CCStoreProductsRequestDelegate
    
    virtual void requestProductsCompleted(CCArray* products, CCArray* invalidProductsId = NULL);
    virtual void requestProductsFailed(int errorCode, const char* errorString);

    
#pragma mark -
#pragma mark helper
    
private:
    bool init(void);
    
    CCString* newCCString(const char* string);
};

#endif
