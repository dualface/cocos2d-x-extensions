
#ifndef __EXTENSIONS_CCNATIVE_H_
#define __EXTENSIONS_CCNATIVE_H_

#include "CCAlertViewDelegate.h"
#include "CCScriptSupport.h"

using namespace cocos2d;

namespace extensions {
    
    /** @brief Activity indicator style */
    typedef enum {
        CCActivityIndicatorViewStyleWhiteLarge,
        CCActivityIndicatorViewStyleWhite,
        CCActivityIndicatorViewStyleGray,
    } CCActivityIndicatorViewStyle;
    
    class CCNative
    {
    public:
        
#pragma mark -
#pragma mark activity indicator
        
        /** @brief Show activity indicator */
        static void showActivityIndicator(CCActivityIndicatorViewStyle style = CCActivityIndicatorViewStyleWhiteLarge);
        
        /** @brief Hide activity indicator */
        static void hideActivityIndicator(void);
        
#pragma mark -
#pragma mark alert view
        
        /** @brief Create alert view */
        static void createAlert(const char* title,
                                const char* message,
                                const char* cancelButtonTitle);
        
        /** @brief Add button to alert view, return button index */
        static int addAlertButton(const char* buttonTitle);
        static int addAlertButtonLua(const char* buttonTitle);
        
        /** @brief Show alert view */
        static void showAlert(CCAlertViewDelegate* delegate = NULL);
        static void showAlertLua(LUA_FUNCTION listener);
        
        /** @brief Hide and remove alert view */
        static void cancelAlert(void);
        
#pragma mark -
#pragma mark OpenUDID
        
        /** @brief Get OpenUDID value */
        static const char* getOpenUDID(void);
        
#pragma mark -
#pragma mark misc
        
        /** @brief Open a web page in the browser; create an email; or call a phone number. */
        static void openURL(const char* url);
        
#pragma mark -
#pragma mark helper
        
    private:
        CCNative(void) {}
    };
    
}

#endif // __EXTENSIONS_CCNATIVE_H_
