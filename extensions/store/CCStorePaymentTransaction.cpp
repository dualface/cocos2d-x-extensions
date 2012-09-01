
#include "store/CCStorePaymentTransaction.h"

NS_CC_EXT_BEGIN

CCStorePaymentTransaction*
CCStorePaymentTransaction::transactionWithState(CCStorePaymentTransactionWrapper* transactionWapper,
                                                CCStorePaymentTransactionState state,
                                                const char* transactionId,
                                                const char* productId,
                                                int quantity,
                                                double dateTime,
                                                int receiptDataLength,
                                                const void* receiptData,
                                                int errorCode,
                                                const char* errorDescription,
                                                CCStorePaymentTransaction* originalTransaction,
                                                CCStoreReceiptVerifyMode receiptVerifyMode,
                                                CCStoreReceiptVerifyStatus receiptVerifyStatus)
{
    CCStorePaymentTransaction* transaction = new CCStorePaymentTransaction();
    transaction->initWithState(transactionWapper,
                               state,
                               transactionId,
                               productId,
                               quantity,
                               dateTime,
                               receiptDataLength,
                               receiptData,
                               errorCode,
                               errorDescription,
                               originalTransaction,
                               receiptVerifyMode,
                               receiptVerifyStatus);
    transaction->autorelease();
    return transaction;
}

CCStorePaymentTransaction::~CCStorePaymentTransaction(void)
{
    CC_SAFE_RELEASE(m_originalTransaction);
    if (m_receiptData)
    {
        free(m_receiptData);
    }
    if (m_transactionWapper)
    {
        delete m_transactionWapper;
    }
    
    CCLOG("~~ CCStorePaymentTransaction::~CCStorePaymentTransaction()");
}

bool CCStorePaymentTransaction::initWithState(CCStorePaymentTransactionWrapper* transactionWapper,
                                              CCStorePaymentTransactionState state,
                                              const char* transactionId,
                                              const char* productId,
                                              int quantity,
                                              double dateTime,
                                              int receiptDataLength,
                                              const void* receiptData,
                                              int errorCode,
                                              const char* errorDescription,
                                              CCStorePaymentTransaction* originalTransaction,
                                              CCStoreReceiptVerifyMode receiptVerifyMode,
                                              CCStoreReceiptVerifyStatus receiptVerifyStatus)
{
    m_transactionWapper = transactionWapper;
    m_transactionState = state;
    m_transactionIdentifier = transactionId;
    m_productIdentifier = productId;
    m_quantity = quantity;
    m_dateTime = dateTime;
    m_receiptDataLength = receiptDataLength;
    if (receiptDataLength > 0)
    {
        m_receiptData = malloc(receiptDataLength);
        memcpy(m_receiptData, receiptData, receiptDataLength);
    }
    else
    {
        m_receiptData = NULL;
    }
    m_errorCode = errorCode;
    m_errorDescription = errorDescription ? errorDescription : "";
    m_originalTransaction = originalTransaction;
    if (m_originalTransaction)
    {
        m_originalTransaction->retain();
    }
    
    m_receiptVerifyMode = receiptVerifyMode;
    m_receiptVerifyStatus = receiptVerifyStatus;
    
    return true;
}

#if CC_LUA_ENGINE_ENABLED > 0
const CCScriptValueDict CCStorePaymentTransaction::convertToLuaTable(void)
{
    CCScriptValueDict transaction_;
    
    transaction_["state"] = CCScriptValue::stringValue(CCStorePaymentTransactionStateNames[m_transactionState]);
    transaction_["transactionIdentifier"] = CCScriptValue::stringValue(m_transactionIdentifier);
    transaction_["productIdentifier"] = CCScriptValue::stringValue(m_productIdentifier);
    transaction_["quantity"] = CCScriptValue::intValue(m_quantity);
    transaction_["date"] = CCScriptValue::floatValue(m_dateTime);
    transaction_["errorCode"] = CCScriptValue::intValue(m_errorCode);
    transaction_["errorString"] = CCScriptValue::stringValue(m_errorDescription);
    transaction_["receiptVerifyMode"] = CCScriptValue::intValue(m_receiptVerifyMode);
    transaction_["receiptVerifyStatus"] = CCScriptValue::intValue(m_receiptVerifyStatus);
    
    if (m_receiptDataLength > 0)
    {
        transaction_["receipt"] = CCScriptValue::stringValue((const char*)(m_receiptData));
    }
    
    if (m_originalTransaction)
    {
        const CCScriptValueDict originalTransaction_ = m_originalTransaction->convertToLuaTable();
        transaction_["originalTransaction"] = CCScriptValue::dictValue(originalTransaction_);
    }
    
    return transaction_;
}
#endif

NS_CC_EXT_END
