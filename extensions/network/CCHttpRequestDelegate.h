
#ifndef __EXTENSIONS_CCHTTP_REQUEST_DELEGATE_H_
#define __EXTENSIONS_CCHTTP_REQUEST_DELEGATE_H_

namespace extensions {
    
    class CCHttpRequest;
    
    class CCHttpRequestDelegate
    {
    public:
        virtual void requestFinished(CCHttpRequest* request) = 0;
        virtual void requestFailed(CCHttpRequest* request) {
        }
    };
    
}


#endif // __EXTENSIONS_CCHTTP_REQUEST_DELEGATE_H_
