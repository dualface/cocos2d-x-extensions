
#ifndef __EXTENSIONS_CCSTORE_PRODUCTS_REQUEST_DELEGATE_H_
#define __EXTENSIONS_CCSTORE_PRODUCTS_REQUEST_DELEGATE_H_

#include "CCArray.h"

using namespace cocos2d;

namespace extensions {
    
    static const int CCStoreProductsRequestErrorPreviousRequestNotCompleted = -2;
    static const int CCStoreProductsRequestErrorCancelled = -1;
    
    class CCStoreProductsRequestDelegate
    {
    public:
        virtual void requestProductsCompleted(CCArray* products,
                                              CCArray* invalidProductsId = NULL) = 0;
        virtual void requestProductsFailed(int errorCode, const char* errorString) = 0;
    };
    
}

#endif // __EXTENSIONS_CCSTORE_PRODUCTS_REQUEST_DELEGATE_H_
