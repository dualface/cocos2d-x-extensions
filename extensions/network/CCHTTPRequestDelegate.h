
#ifndef __CC_EXTENSION_CCHTTP_REQUEST_DELEGATE_H_
#define __CC_EXTENSION_CCHTTP_REQUEST_DELEGATE_H_

#include "cocos2dx_extensions.h"

NS_CC_EXT_BEGIN

class CCHTTPRequest;

class CCHTTPRequestDelegate
{
public:
    virtual void requestFinished(CCHTTPRequest* request) = 0;
    virtual void requestFailed(CCHTTPRequest* request) {
    }
};

NS_CC_EXT_END

#endif // __CC_EXTENSION_CCHTTP_REQUEST_DELEGATE_H_
