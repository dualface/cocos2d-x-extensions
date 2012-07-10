
#ifndef __EXTENSIONS_CCSTORE_PRODUCT_H_
#define __EXTENSIONS_CCSTORE_PRODUCT_H_

#include <string>
#include "CCObject.h"

using namespace std;
using namespace cocos2d;

namespace extensions {
    
#pragma mark -
#pragma mark CCStoreProduct
    
    class CCStoreProduct : public CCObject
    {
    public:
        static CCStoreProduct* productWithId(const char* productIdentifier,
                                             const char* localizedTitle,
                                             const char* localizedDescription,
                                             float price,
                                             const char* priceLocale);
        
        const string& getProductIdentifier(void)
        {
            return m_productIdentifier;
        }
        
        const string& getLocalizedTitle(void)
        {
            return m_localizedTitle;
        }
        
        const string& getLocalizedDescription(void)
        {
            return m_localizedDescription;
        }
        
        float getPrice(void)
        {
            return m_price;
        }
        
        const string& getPriceLocale(void)
        {
            return m_priceLocale;
        }
        
    private:
        CCStoreProduct(void) {}
        bool initWithId(const char* productIdentifier,
                        const char* localizedTitle,
                        const char* localizedDescription,
                        float price,
                        const char* priceLocale);
        
        string m_productIdentifier;
        string m_localizedTitle;
        string m_localizedDescription;
        float  m_price;
        string m_priceLocale;
    };
    
} // namespace store

#endif // __EXTENSIONS_CCSTORE_PRODUCT_H_
