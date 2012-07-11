
#ifndef __EXTENSIONS_CCALERTVIEW_DELEGATE_H_
#define __EXTENSIONS_CCALERTVIEW_DELEGATE_H_

#include "cocos2dx_extensions.h"

NS_CC_EXT_BEGIN

class CCAlertViewDelegate
{
public:
    virtual void alertViewClickedButtonAtIndex(int buttonIndex) = 0;
};

NS_CC_EXT_END

#endif // __EXTENSIONS_CCALERTVIEW_DELEGATE_H_
