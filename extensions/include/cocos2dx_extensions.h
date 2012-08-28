
#ifndef __COCOS2DX_EXTMACROS_H_
#define __COCOS2DX_EXTMACROS_H_

#include "cocos2d.h"

#if CC_LUA_ENGINE_ENABLED > 0
#include "script_support/CCScriptSupport.h"
#endif

#include <map>
#include <string>

#ifndef NS_CC_EXT_BEGIN
#define NS_CC_EXT_BEGIN                 namespace cocos2d { namespace extension {
#define NS_CC_EXT_END                   }}
#define USING_NS_CC_EXT                 using namespace cocos2d::extension
#endif

#endif // __COCOS2DX_EXTMACROS_H_
