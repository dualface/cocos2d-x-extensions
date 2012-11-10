
#ifndef __CC_EXTENSION_CCNATIVE_H_
#define __CC_EXTENSION_CCNATIVE_H_

#include "cocos2dx_extensions.h"
#include "CCAlertViewDelegate.h"

#if CC_LUA_ENGINE_ENABLED > 0
#include "CCLuaEngine.h"
#endif

#include <string>

NS_CC_EXT_BEGIN

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
#if CC_LUA_ENGINE_ENABLED > 0
    static int addAlertButtonLua(const char* buttonTitle);
#endif        
    /** @brief Show alert view */
    static void showAlert(CCAlertViewDelegate* delegate = NULL);
#if CC_LUA_ENGINE_ENABLED > 0
    static void showAlertLua(cocos2d::LUA_FUNCTION listener);
#endif        
    /** @brief Hide and remove alert view */
    static void cancelAlert(void);
    
#pragma mark -
#pragma mark OpenUDID
    
    /** @brief Get OpenUDID value */
    static const std::string getOpenUDID(void);
    
#pragma mark -
#pragma mark misc
    
    /** @brief Open a web page in the browser; create an email; or call a phone number. */
    static void openURL(const char* url);
    
	/** @brief Show alert view, and get user input */
    static const std::string getInputText(const char* title, const char* message, const char* defaultValue);
    
#pragma mark -
#pragma mark helper
    
    static const char* getDeviceName(void);
    static void vibrate();
    
private:
    CCNative(void) {}
};

NS_CC_EXT_END

#endif // __CC_EXTENSION_CCNATIVE_H_
