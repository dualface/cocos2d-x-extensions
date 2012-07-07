
#ifndef __EXTENSIONS_CCALERTVIEW_DELEGATE_H_
#define __EXTENSIONS_CCALERTVIEW_DELEGATE_H_

namespace extensions {

    class CCAlertViewDelegate
    {
    public:
        virtual void alertViewClickedButtonAtIndex(int buttonIndex) = 0;
    };
    
}

#endif // __EXTENSIONS_CCALERTVIEW_DELEGATE_H_
