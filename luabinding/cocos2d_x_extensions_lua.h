
#ifndef __COCOS2D_X_EXTENSIONS_LUA_H_
#define __COCOS2D_X_EXTENSIONS_LUA_H_


//#define TOLUA_RELEASE

extern "C" {
#include "tolua++.h"
#include "tolua_fix.h"
}
#include "cocos2d.h"

using namespace cocos2d;

int tolua_cocos2d_x_extensions_lua_open(lua_State* tolua_S);

#endif // __COCOS2D_X_EXTENSIONS_LUA_H_
