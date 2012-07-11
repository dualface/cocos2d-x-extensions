
#ifndef __EXTENSIONS_CCSTORE_PAYMENT_TRANSACTION_WRAPPER_H_
#define __EXTENSIONS_CCSTORE_PAYMENT_TRANSACTION_WRAPPER_H_

#include "cocos2dx_extensions.h"

NS_CC_EXT_BEGIN

class CCStorePaymentTransactionWrapper
{
public:
    static CCStorePaymentTransactionWrapper* createWithTransaction(void* transactionObj);
    ~CCStorePaymentTransactionWrapper(void);
    
    void* getTransactionObj(void)
    {
        return m_transactionObj;
    }
    
private:
    CCStorePaymentTransactionWrapper(void)
    : m_transactionObj(NULL)
    {
    }
    
    void* m_transactionObj;
};

NS_CC_EXT_END

#endif // __EXTENSIONS_CCSTORE_PAYMENT_TRANSACTION_WRAPPER_H_
