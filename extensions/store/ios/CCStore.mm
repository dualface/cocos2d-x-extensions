
#include "CCStore.h"
#include "CCString.h"
#include "CCSet.h"

#import "CCStore_objc.h"
#import "libb64.h"

extern "C" {
#include "lua.h"
#include "tolua_fix.h"
}

namespace extensions {
    
    CCStore* CCStore::s_sharedStore = NULL;
        
    CCStore* CCStore::sharedStore(void)
    {
        if (!s_sharedStore)
        {
            s_sharedStore = new CCStore();
            s_sharedStore->init();
        }
        return s_sharedStore;
    }
    
    CCStore::~CCStore(void)
    {
        if (m_listener)
        {
            CCScriptEngineManager::sharedManager()->getScriptEngine()->removeLuaHandler(m_listener);
        }
        for (CCStorePaymentTransactionsIterator it = m_transactions.begin(); it != m_transactions.end(); ++it)
        {
            it->second->release();
        }
    }
    
    bool CCStore::init(void)
    {
        return true;
    }
    
    void CCStore::purgeSharedStore(void)
    {
        [CCStore_objc purgeSharedStore];
        if (s_sharedStore)
        {
            delete s_sharedStore;
            s_sharedStore = NULL;
        }
    }
    
    void CCStore::postInitWithTransactionObserver(CCStoreTransactionObserver* observer)
    {
        m_observer = observer;
        [[CCStore_objc sharedStore] postInitWithTransactionObserver:this];
    }
    
    void CCStore::postInitWithTransactionListenerLua(LUA_FUNCTION listener)
    {
        if (m_listener)
        {
            CCScriptEngineManager::sharedManager()->getScriptEngine()->removeLuaHandler(m_listener);
        }
        m_listener = listener;
        [[CCStore_objc sharedStore] postInitWithTransactionObserver:this];
    }
    
    bool CCStore::canMakePurchases(void)
    {
        return [[CCStore_objc sharedStore] canMakePurchases];
    }
    
    void CCStore::loadProducts(CCSet* productsId, CCStoreProductsRequestDelegate* delegate)
    {
        NSMutableSet* set = [NSMutableSet set];
        for (CCSetIterator it = productsId->begin(); it != productsId->end(); ++it)
        {
            CCString* productId = static_cast<CCString*>(*it);
            [set addObject:[NSString stringWithUTF8String: productId->m_sString.c_str()]];
        }
        [[CCStore_objc sharedStore] requestProductData:set andDelegate:delegate];
    }
    
    void CCStore::loadProductsLua(LUA_TABLE __LUA_TABLE__, LUA_FUNCTION callback)
    {
        CC_UNUSED_PARAM(__LUA_TABLE__);
        if (m_isLoadProductsLuaNotCompleted) return;
        
        CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();
        lua_State* L = engine->getLuaState();
        if (!lua_isfunction(L, -1) || !lua_istable(L, -2)) return;
        
        NSMutableSet* set = [NSMutableSet set];
        
                                                    /* L: this table function */
        
        lua_pushnil(L);                             /* L: this table function query_key */
        /* lua_next() remove 'query_key', push 'next_key' */
        while (lua_next(L, -3) != 0)                /* L: this table function next_key value */
        {
            if (lua_isstring(L, -1))
            {
                const char* productId = lua_tostring(L, -1);
                if (productId)
                {
                    [set addObject:[NSString stringWithUTF8String:productId]];
                }
            }
            /* removes 'value'; keeps 'key' for next iteration */
            lua_pop(L, 1);                          /* this table function next_key */
        }
        
        lua_pop(L, 1);                              /* this table function */
        
        m_isLoadProductsLuaNotCompleted = true;
        m_loadProductsCallback = callback;
        [[CCStore_objc sharedStore] requestProductData:set andDelegate:this];
    }
    
    void CCStore::cancelLoadProducts(void)
    {
        [[CCStore_objc sharedStore] cancelRequestProductData];
    }
    
    bool CCStore::isProductLoaded(const char* productId)
    {
        if (!productId) return false;
        return [[CCStore_objc sharedStore] isProductLoaded:[NSString stringWithUTF8String:productId]];
    }
    
    bool CCStore::purchase(const char* productId)
    {
        if (!productId) return false;
        SKProduct *product = [[CCStore_objc sharedStore] getProduct:[NSString stringWithUTF8String:productId]];
        if (product)
        {
            [[CCStore_objc sharedStore] purchase:product];
            return true;
        }
        return false;
    }
    
    void CCStore::finishTransaction(CCStorePaymentTransaction *transaction)
    {
        CCStorePaymentTransactionWrapper* wrapper = transaction->getTransactionWrapper();
        [[CCStore_objc sharedStore] finishTransaction:(SKPaymentTransaction *)wrapper->getTransactionObj()];
        CCStorePaymentTransactionsIterator it = m_transactions.find(transaction->getTransactionIdentifier());
        if (it != m_transactions.end())
        {
            it->second->release();
            m_transactions.erase(it);
        }
    }
    
    void CCStore::finishTransactionLua(const char* transactionIdentifier)
    {
        for (CCStorePaymentTransactionsIterator it = m_transactions.begin(); it != m_transactions.end(); ++it)
        {
            CCLOG("[CCStore] finishTransactionLua() exists tid: %s", it->first.c_str());
        }
        
        CCStorePaymentTransactionsIterator it = m_transactions.find(transactionIdentifier);
        if (it != m_transactions.end())
        {
            finishTransaction(it->second);
        }
        else
        {
            CCLOG("[CCStore] ERR, finishTransactionLua() invalid tid: %s", transactionIdentifier);
        }
    }
    
    CCStoreReceiptVerifyMode CCStore::getReceiptVerifyMode(void)
    {
        return [CCStore_objc sharedStore].receiptVerifyMode;
    }
    
    void CCStore::setReceiptVerifyMode(CCStoreReceiptVerifyMode mode, CCStoreIsSandbox isSandbox)
    {
        [CCStore_objc sharedStore].receiptVerifyMode = mode;
        [CCStore_objc sharedStore].isSandbox = isSandbox;
    }
    
    const char* CCStore::getReceiptVerifyServerUrl(void)
    {
        return [[CCStore_objc sharedStore].receiptVerifyServerUrl cStringUsingEncoding:NSUTF8StringEncoding];
    }
    
    void CCStore::setReceiptVerifyServerUrl(const char* url)
    {
        [CCStore_objc sharedStore].receiptVerifyServerUrl = [NSString stringWithUTF8String:url];
    }
    
#pragma mark -
#pragma mark delegates
    
    void CCStore::transactionCompleted(CCStorePaymentTransaction* transaction)
    {
        m_transactions[transaction->getTransactionIdentifier()] = transaction;
        transaction->retain();
        
        if (m_observer)
        {
            m_observer->transactionCompleted(transaction);
        }
        if (m_listener)
        {
            passCCStorePaymentTransactionToLuaListener(transaction);
        }
    }
    
    void CCStore::transactionFailed(CCStorePaymentTransaction* transaction)
    {
        m_transactions[transaction->getTransactionIdentifier()] = transaction;
        transaction->retain();
        
        if (m_observer)
        {
            m_observer->transactionFailed(transaction);
        }
        if (m_listener)
        {
            passCCStorePaymentTransactionToLuaListener(transaction);
        }
    }
    
    void CCStore::transactionRestored(CCStorePaymentTransaction* transaction)
    {
        m_transactions[transaction->getTransactionIdentifier()] = transaction;
        transaction->retain();
        
        if (m_observer)
        {
            m_observer->transactionRestored(transaction);
        }
        if (m_listener)
        {
            passCCStorePaymentTransactionToLuaListener(transaction);
        }
    }
    
    void CCStore::requestProductsCompleted(CCArray* products, CCArray* invalidProductsId)
    {
        CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();
        
        CCLuaTableDict event;
        CCLuaTableArray products_;
        
        for (int i = 0; i < products->count(); ++i)
        {
            CCStoreProduct* product = static_cast<CCStoreProduct*>(products->objectAtIndex(i));
            CCLuaTableDict product_;
            product_["productIdentifier"]    = CCLuaValue::valueWithString(product->getProductIdentifier());
            product_["localizedTitle"]       = CCLuaValue::valueWithString(product->getLocalizedTitle());
            product_["localizedDescription"] = CCLuaValue::valueWithString(product->getLocalizedDescription());
            product_["priceLocale"]          = CCLuaValue::valueWithString(product->getPriceLocale());
            product_["price"]                = CCLuaValue::valueWithFloat(product->getPrice());
            products_.push_back(CCLuaValue::valueWithCCLuaTableDict(product_));
        }
        event["products"] = CCLuaValue::valueWithCCLuaTableArray(products_);
        
        if (invalidProductsId)
        {
            CCLuaTableArray invalidProductsId_;
            for (int i = 0; i < invalidProductsId->count(); ++i)
            {
                CCString* ccid = static_cast<CCString*>(invalidProductsId->objectAtIndex(i));
                invalidProductsId_.push_back(CCLuaValue::valueWithString(ccid->toStdString()));
            }            
            event["invalidProductsId"] = CCLuaValue::valueWithCCLuaTableArray(invalidProductsId_);
        }
        
        engine->pushCCLuaTableDictToLuaStack(&event);
        engine->executeFunctionByHandler(m_loadProductsCallback, 1);
        
        m_loadProductsCallback = 0;
        m_isLoadProductsLuaNotCompleted = false;
    }
    
    void CCStore::requestProductsFailed(int errorCode, const char* errorString)
    {
        CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();
        
        CCLuaTableDict event;
        event["errorCode"] = CCLuaValue::valueWithInt(errorCode);
        event["errorString"] = CCLuaValue::valueWithString(errorString);
        
        engine->pushCCLuaTableDictToLuaStack(&event);
        engine->executeFunctionByHandler(m_loadProductsCallback, 1);
        
        m_loadProductsCallback = 0;
        m_isLoadProductsLuaNotCompleted = false;
    }
    
#pragma mark -
#pragma mark helper
    
    void CCStore::passCCStorePaymentTransactionToLuaListener(CCStorePaymentTransaction* transaction)
    {
        CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();

        CCLuaTableDict event;
        event["transaction"] = CCLuaValue::valueWithCCLuaTableDict(transaction->convertToLuaTable());
        
        engine->pushCCLuaTableDictToLuaStack(&event);
        engine->executeFunctionByHandler(m_listener, 1);
    }
    
} // namespace store
