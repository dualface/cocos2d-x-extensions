
#include "CCStorePaymentTransactionWrapper.h"
#import <StoreKit/StoreKit.h>

namespace extensions {
    
    CCStorePaymentTransactionWrapper* CCStorePaymentTransactionWrapper::createWithTransaction(void* transactionObj)
    {
        CCStorePaymentTransactionWrapper* transaction = new CCStorePaymentTransactionWrapper();
        transaction->m_transactionObj = transactionObj;
        [(SKPaymentTransaction *)transactionObj retain];
        return transaction;
    }
    
    CCStorePaymentTransactionWrapper::~CCStorePaymentTransactionWrapper(void)
    {
        [(SKPaymentTransaction *)m_transactionObj release];
    }
    
}
