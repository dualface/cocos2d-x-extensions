
#ifndef __EXTENSIONS_CCSTORE_TRANSACTION_OBSERVER_H_
#define __EXTENSIONS_CCSTORE_TRANSACTION_OBSERVER_H_

#include "CCStorePaymentTransaction.h"

namespace extensions {

    class CCStoreTransactionObserver
    {
    public:
        virtual void transactionCompleted(CCStorePaymentTransaction* transaction) = 0;
        virtual void transactionFailed(CCStorePaymentTransaction* transaction) = 0;
        virtual void transactionRestored(CCStorePaymentTransaction* transaction) = 0;
    };

}

#endif // __EXTENSIONS_CCSTORE_TRANSACTION_OBSERVER_H_
