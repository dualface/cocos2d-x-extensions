
#ifndef cocos2dx_extensions_demo_CCNativeScene_h
#define cocos2dx_extensions_demo_CCNativeScene_h

#include "cocos2d.h"

#include "CCAlertViewDelegate.h"

using namespace cocos2d;
using namespace extensions;

class CCNativeScene : public CCScene, public CCAlertViewDelegate
{
public:
    static CCNativeScene* scene(void);
    
    void testShowActivityIndicator(CCObject* pSender);
    void testHideActivityIndicator(CCObject* pSender);
    
    void testCreateAlertView(CCObject* pSender);
    void autoCancelAlertView(ccTime dt);
    
    void testGetOpenUDID(CCObject* pSender);
    void testOpenURL(CCObject* pSender);
    
    void backToMainScene(CCObject* pSender);
    
    virtual void alertViewClickedButtonAtIndex(int buttonIndex);
    
private:
    virtual bool init(void);
};


#endif
