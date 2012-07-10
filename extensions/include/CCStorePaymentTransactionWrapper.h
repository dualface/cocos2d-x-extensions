
#ifndef __EXTENSIONS_CCSTORE_PAYMENT_TRANSACTION_WRAPPER_H_
#define __EXTENSIONS_CCSTORE_PAYMENT_TRANSACTION_WRAPPER_H_

namespace extensions {
    
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
    
}

#endif // __EXTENSIONS_CCSTORE_PAYMENT_TRANSACTION_WRAPPER_H_
