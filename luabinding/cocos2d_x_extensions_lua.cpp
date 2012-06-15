/*
** Lua binding: cocos2d_x_extensions_lua
** Generated automatically by tolua++-1.0.92 on Fri Jun 15 14:46:04 2012.
*/





#include "cocos2d_x_extensions_lua.h"
#include "CCCrypto.h"
#include "CCOpenFeint.h"
#include "CCNative.h"
#include "CCNetwork.h"
#include "CCStore.h"
using namespace extensions;

/* function to release collected object via destructor */
#ifdef __cplusplus




#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCStore");
 tolua_usertype(tolua_S,"CCNetwork");
 
 tolua_usertype(tolua_S,"CCOpenFeint");
 tolua_usertype(tolua_S,"CCNative");
 
 tolua_usertype(tolua_S,"CCCrypto");
 
}

/* method: getAES256KeyLength of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCCrypto_getAES256KeyLength00
static int tolua_cocos2d_x_extensions_lua_CCCrypto_getAES256KeyLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  CCCrypto::getAES256KeyLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAES256KeyLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: encryptAES256Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCCrypto_encryptAES256Lua00
static int tolua_cocos2d_x_extensions_lua_CCCrypto_encryptAES256Lua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* plaintext = ((const char*)  tolua_tostring(tolua_S,2,0));
  int plaintextLength = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,4,0));
  int keyLength = ((int)  tolua_tonumber(tolua_S,5,0));
  {
     CCCrypto::encryptAES256Lua(plaintext,plaintextLength,key,keyLength);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'encryptAES256Lua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decryptAES256Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCCrypto_decryptAES256Lua00
static int tolua_cocos2d_x_extensions_lua_CCCrypto_decryptAES256Lua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* ciphertext = ((const char*)  tolua_tostring(tolua_S,2,0));
  int ciphertextLength = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,4,0));
  int keyLength = ((int)  tolua_tonumber(tolua_S,5,0));
  {
     CCCrypto::decryptAES256Lua(ciphertext,ciphertextLength,key,keyLength);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decryptAES256Lua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: encodeBase64Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCCrypto_encodeBase64Lua00
static int tolua_cocos2d_x_extensions_lua_CCCrypto_encodeBase64Lua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* input = ((const char*)  tolua_tostring(tolua_S,2,0));
  int inputLength = ((int)  tolua_tonumber(tolua_S,3,0));
  {
     CCCrypto::encodeBase64Lua(input,inputLength);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'encodeBase64Lua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decodeBase64Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCCrypto_decodeBase64Lua00
static int tolua_cocos2d_x_extensions_lua_CCCrypto_decodeBase64Lua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* input = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
     CCCrypto::decodeBase64Lua(input);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decodeBase64Lua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MD5Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCCrypto_MD5Lua00
static int tolua_cocos2d_x_extensions_lua_CCCrypto_MD5Lua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* input = ((char*)  tolua_tostring(tolua_S,2,0));
  int inputLength = ((int)  tolua_tonumber(tolua_S,3,0));
  bool isRawOutput = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
     CCCrypto::MD5Lua(input,inputLength,isRawOutput);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5Lua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: postInitWithProductKey of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_postInitWithProductKey00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_postInitWithProductKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* productKey = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* secret = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* displayName = ((const char*)  tolua_tostring(tolua_S,4,0));
  {
   CCOpenFeint::postInitWithProductKey(productKey,secret,displayName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'postInitWithProductKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showDashboard of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_showDashboard00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_showDashboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCOpenFeint::showDashboard();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showDashboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showLeaderboards of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_showLeaderboards00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_showLeaderboards00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCOpenFeint::showLeaderboards();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showLeaderboards'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showLeaderboards of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_showLeaderboards01
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_showLeaderboards01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* leaderboardId = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   CCOpenFeint::showLeaderboards(leaderboardId);
  }
 }
 return 0;
tolua_lerror:
 return tolua_cocos2d_x_extensions_lua_CCOpenFeint_showLeaderboards00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: showAchievements of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_showAchievements00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_showAchievements00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCOpenFeint::showAchievements();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showAchievements'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showChallenges of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_showChallenges00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_showChallenges00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCOpenFeint::showChallenges();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showChallenges'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showFriends of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_showFriends00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_showFriends00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCOpenFeint::showFriends();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showFriends'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showPlaying of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_showPlaying00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_showPlaying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCOpenFeint::showPlaying();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showPlaying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAchievementsLua of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_getAchievementsLua00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_getAchievementsLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
     CCOpenFeint::getAchievementsLua();
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAchievementsLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unlockAchievement of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_unlockAchievement00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_unlockAchievement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* achievementId = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   CCOpenFeint::unlockAchievement(achievementId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unlockAchievement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLeaderboardsLua of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_getLeaderboardsLua00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_getLeaderboardsLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
     CCOpenFeint::getLeaderboardsLua();
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLeaderboardsLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHighScore of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCOpenFeint_setHighScore00
static int tolua_cocos2d_x_extensions_lua_CCOpenFeint_setHighScore00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCOpenFeint",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* leaderboardId = ((const char*)  tolua_tostring(tolua_S,2,0));
  int score = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* displayText = ((const char*)  tolua_tostring(tolua_S,4,NULL));
  {
   CCOpenFeint::setHighScore(leaderboardId,score,displayText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHighScore'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showActivityIndicator of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNative_showActivityIndicator00
static int tolua_cocos2d_x_extensions_lua_CCNative_showActivityIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCActivityIndicatorViewStyle style = ((CCActivityIndicatorViewStyle) (int)  tolua_tonumber(tolua_S,2,CCActivityIndicatorViewStyleWhiteLarge));
  {
   CCNative::showActivityIndicator(style);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showActivityIndicator'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hideActivityIndicator of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNative_hideActivityIndicator00
static int tolua_cocos2d_x_extensions_lua_CCNative_hideActivityIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCNative::hideActivityIndicator();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hideActivityIndicator'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createAlert of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNative_createAlert00
static int tolua_cocos2d_x_extensions_lua_CCNative_createAlert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* title = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* message = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* cancelButtonTitle = ((const char*)  tolua_tostring(tolua_S,4,0));
  {
   CCNative::createAlert(title,message,cancelButtonTitle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createAlert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAlertButton of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNative_addAlertButton00
static int tolua_cocos2d_x_extensions_lua_CCNative_addAlertButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* buttonTitle = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   int tolua_ret = (int)  CCNative::addAlertButton(buttonTitle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAlertButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showAlertLua of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNative_showAlertLua00
static int tolua_cocos2d_x_extensions_lua_CCNative_showAlertLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LUA_FUNCTION listener = (  toluafix_ref_function(tolua_S,2,0));
  {
   CCNative::showAlertLua(listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showAlertLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cancelAlert of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNative_cancelAlert00
static int tolua_cocos2d_x_extensions_lua_CCNative_cancelAlert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCNative::cancelAlert();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cancelAlert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpenUDID of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNative_getOpenUDID00
static int tolua_cocos2d_x_extensions_lua_CCNative_getOpenUDID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const char* tolua_ret = (const char*)  CCNative::getOpenUDID();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpenUDID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isLocalWiFiAvailable of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNetwork_isLocalWiFiAvailable00
static int tolua_cocos2d_x_extensions_lua_CCNetwork_isLocalWiFiAvailable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  CCNetwork::isLocalWiFiAvailable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isLocalWiFiAvailable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isInternetConnectionAvailable of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNetwork_isInternetConnectionAvailable00
static int tolua_cocos2d_x_extensions_lua_CCNetwork_isInternetConnectionAvailable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  CCNetwork::isInternetConnectionAvailable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isInternetConnectionAvailable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isHostNameReachable of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNetwork_isHostNameReachable00
static int tolua_cocos2d_x_extensions_lua_CCNetwork_isHostNameReachable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* hostName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  CCNetwork::isHostNameReachable(hostName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isHostNameReachable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInternetConnectionStatus of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCNetwork_getInternetConnectionStatus00
static int tolua_cocos2d_x_extensions_lua_CCNetwork_getInternetConnectionStatus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCNetworkStatus tolua_ret = (CCNetworkStatus)  CCNetwork::getInternetConnectionStatus();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInternetConnectionStatus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedStore of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_sharedStore00
static int tolua_cocos2d_x_extensions_lua_CCStore_sharedStore00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCStore* tolua_ret = (CCStore*)  CCStore::sharedStore();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCStore");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedStore'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: purgeSharedStore of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_purgeSharedStore00
static int tolua_cocos2d_x_extensions_lua_CCStore_purgeSharedStore00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCStore::purgeSharedStore();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'purgeSharedStore'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: postInitWithTransactionListenerLua of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_postInitWithTransactionListenerLua00
static int tolua_cocos2d_x_extensions_lua_CCStore_postInitWithTransactionListenerLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION listener = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'postInitWithTransactionListenerLua'", NULL);
#endif
  {
   self->postInitWithTransactionListenerLua(listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'postInitWithTransactionListenerLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: canMakePurchases of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_canMakePurchases00
static int tolua_cocos2d_x_extensions_lua_CCStore_canMakePurchases00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'canMakePurchases'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->canMakePurchases();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'canMakePurchases'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadProductsLua of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_loadProductsLua00
static int tolua_cocos2d_x_extensions_lua_CCStore_loadProductsLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_istable(tolua_S,2,"LUA_TABLE",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !toluafix_isfunction(tolua_S,3,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
  LUA_TABLE __LUA_TABLE__ = (  toluafix_totable(tolua_S,2,0));
  LUA_FUNCTION callback = (  toluafix_ref_function(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'loadProductsLua'", NULL);
#endif
  {
   self->loadProductsLua(__LUA_TABLE__,callback);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadProductsLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cancelLoadProducts of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_cancelLoadProducts00
static int tolua_cocos2d_x_extensions_lua_CCStore_cancelLoadProducts00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cancelLoadProducts'", NULL);
#endif
  {
   self->cancelLoadProducts();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cancelLoadProducts'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isProductLoaded of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_isProductLoaded00
static int tolua_cocos2d_x_extensions_lua_CCStore_isProductLoaded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
  const char* productId = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isProductLoaded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isProductLoaded(productId);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isProductLoaded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: purchase of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_purchase00
static int tolua_cocos2d_x_extensions_lua_CCStore_purchase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
  const char* productId = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'purchase'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->purchase(productId);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'purchase'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: finishTransactionLua of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_finishTransactionLua00
static int tolua_cocos2d_x_extensions_lua_CCStore_finishTransactionLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
  const char* transactionIdentifier = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'finishTransactionLua'", NULL);
#endif
  {
   self->finishTransactionLua(transactionIdentifier);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'finishTransactionLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getReceiptVerifyMode of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_getReceiptVerifyMode00
static int tolua_cocos2d_x_extensions_lua_CCStore_getReceiptVerifyMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getReceiptVerifyMode'", NULL);
#endif
  {
   CCStoreReceiptVerifyMode tolua_ret = (CCStoreReceiptVerifyMode)  self->getReceiptVerifyMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getReceiptVerifyMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setReceiptVerifyMode of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_setReceiptVerifyMode00
static int tolua_cocos2d_x_extensions_lua_CCStore_setReceiptVerifyMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
  CCStoreReceiptVerifyMode mode = ((CCStoreReceiptVerifyMode) (int)  tolua_tonumber(tolua_S,2,0));
   bool isSandbox = ((  bool)  tolua_toboolean(tolua_S,3,true));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setReceiptVerifyMode'", NULL);
#endif
  {
   self->setReceiptVerifyMode(mode,isSandbox);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setReceiptVerifyMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getReceiptVerifyServerUrl of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_getReceiptVerifyServerUrl00
static int tolua_cocos2d_x_extensions_lua_CCStore_getReceiptVerifyServerUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getReceiptVerifyServerUrl'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getReceiptVerifyServerUrl();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getReceiptVerifyServerUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setReceiptVerifyServerUrl of class  CCStore */
#ifndef TOLUA_DISABLE_tolua_cocos2d_x_extensions_lua_CCStore_setReceiptVerifyServerUrl00
static int tolua_cocos2d_x_extensions_lua_CCStore_setReceiptVerifyServerUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCStore",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCStore* self = (CCStore*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setReceiptVerifyServerUrl'", NULL);
#endif
  {
   self->setReceiptVerifyServerUrl(url);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setReceiptVerifyServerUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_cocos2d_x_extensions_lua_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"CCCrypto","CCCrypto","",NULL);
  tolua_beginmodule(tolua_S,"CCCrypto");
   tolua_function(tolua_S,"getAES256KeyLength",tolua_cocos2d_x_extensions_lua_CCCrypto_getAES256KeyLength00);
   tolua_function(tolua_S,"encryptAES256Lua",tolua_cocos2d_x_extensions_lua_CCCrypto_encryptAES256Lua00);
   tolua_function(tolua_S,"decryptAES256Lua",tolua_cocos2d_x_extensions_lua_CCCrypto_decryptAES256Lua00);
   tolua_function(tolua_S,"encodeBase64Lua",tolua_cocos2d_x_extensions_lua_CCCrypto_encodeBase64Lua00);
   tolua_function(tolua_S,"decodeBase64Lua",tolua_cocos2d_x_extensions_lua_CCCrypto_decodeBase64Lua00);
   tolua_function(tolua_S,"MD5Lua",tolua_cocos2d_x_extensions_lua_CCCrypto_MD5Lua00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CCOpenFeint","CCOpenFeint","",NULL);
  tolua_beginmodule(tolua_S,"CCOpenFeint");
   tolua_function(tolua_S,"postInitWithProductKey",tolua_cocos2d_x_extensions_lua_CCOpenFeint_postInitWithProductKey00);
   tolua_function(tolua_S,"showDashboard",tolua_cocos2d_x_extensions_lua_CCOpenFeint_showDashboard00);
   tolua_function(tolua_S,"showLeaderboards",tolua_cocos2d_x_extensions_lua_CCOpenFeint_showLeaderboards00);
   tolua_function(tolua_S,"showLeaderboards",tolua_cocos2d_x_extensions_lua_CCOpenFeint_showLeaderboards01);
   tolua_function(tolua_S,"showAchievements",tolua_cocos2d_x_extensions_lua_CCOpenFeint_showAchievements00);
   tolua_function(tolua_S,"showChallenges",tolua_cocos2d_x_extensions_lua_CCOpenFeint_showChallenges00);
   tolua_function(tolua_S,"showFriends",tolua_cocos2d_x_extensions_lua_CCOpenFeint_showFriends00);
   tolua_function(tolua_S,"showPlaying",tolua_cocos2d_x_extensions_lua_CCOpenFeint_showPlaying00);
   tolua_function(tolua_S,"getAchievementsLua",tolua_cocos2d_x_extensions_lua_CCOpenFeint_getAchievementsLua00);
   tolua_function(tolua_S,"unlockAchievement",tolua_cocos2d_x_extensions_lua_CCOpenFeint_unlockAchievement00);
   tolua_function(tolua_S,"getLeaderboardsLua",tolua_cocos2d_x_extensions_lua_CCOpenFeint_getLeaderboardsLua00);
   tolua_function(tolua_S,"setHighScore",tolua_cocos2d_x_extensions_lua_CCOpenFeint_setHighScore00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"CCActivityIndicatorViewStyleWhiteLarge",CCActivityIndicatorViewStyleWhiteLarge);
  tolua_constant(tolua_S,"CCActivityIndicatorViewStyleWhite",CCActivityIndicatorViewStyleWhite);
  tolua_constant(tolua_S,"CCActivityIndicatorViewStyleGray",CCActivityIndicatorViewStyleGray);
  tolua_cclass(tolua_S,"CCNative","CCNative","",NULL);
  tolua_beginmodule(tolua_S,"CCNative");
   tolua_function(tolua_S,"showActivityIndicator",tolua_cocos2d_x_extensions_lua_CCNative_showActivityIndicator00);
   tolua_function(tolua_S,"hideActivityIndicator",tolua_cocos2d_x_extensions_lua_CCNative_hideActivityIndicator00);
   tolua_function(tolua_S,"createAlert",tolua_cocos2d_x_extensions_lua_CCNative_createAlert00);
   tolua_function(tolua_S,"addAlertButton",tolua_cocos2d_x_extensions_lua_CCNative_addAlertButton00);
   tolua_function(tolua_S,"showAlertLua",tolua_cocos2d_x_extensions_lua_CCNative_showAlertLua00);
   tolua_function(tolua_S,"cancelAlert",tolua_cocos2d_x_extensions_lua_CCNative_cancelAlert00);
   tolua_function(tolua_S,"getOpenUDID",tolua_cocos2d_x_extensions_lua_CCNative_getOpenUDID00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"CCNetworkStatusNotReachable",CCNetworkStatusNotReachable);
  tolua_constant(tolua_S,"CCNetworkStatusReachableViaWiFi",CCNetworkStatusReachableViaWiFi);
  tolua_constant(tolua_S,"CCNetworkStatusReachableViaWWAN",CCNetworkStatusReachableViaWWAN);
  tolua_cclass(tolua_S,"CCNetwork","CCNetwork","",NULL);
  tolua_beginmodule(tolua_S,"CCNetwork");
   tolua_function(tolua_S,"isLocalWiFiAvailable",tolua_cocos2d_x_extensions_lua_CCNetwork_isLocalWiFiAvailable00);
   tolua_function(tolua_S,"isInternetConnectionAvailable",tolua_cocos2d_x_extensions_lua_CCNetwork_isInternetConnectionAvailable00);
   tolua_function(tolua_S,"isHostNameReachable",tolua_cocos2d_x_extensions_lua_CCNetwork_isHostNameReachable00);
   tolua_function(tolua_S,"getInternetConnectionStatus",tolua_cocos2d_x_extensions_lua_CCNetwork_getInternetConnectionStatus00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"CCStoreReceiptVerifyModeNone",CCStoreReceiptVerifyModeNone);
  tolua_constant(tolua_S,"CCStoreReceiptVerifyModeDevice",CCStoreReceiptVerifyModeDevice);
  tolua_constant(tolua_S,"CCStoreReceiptVerifyModeServer",CCStoreReceiptVerifyModeServer);
  tolua_constant(tolua_S,"CCStoreReceiptVerifyStatusUnknownError",CCStoreReceiptVerifyStatusUnknownError);
  tolua_constant(tolua_S,"CCStoreReceiptVerifyStatusInvalidReceipt",CCStoreReceiptVerifyStatusInvalidReceipt);
  tolua_constant(tolua_S,"CCStoreReceiptVerifyStatusRequestFailed",CCStoreReceiptVerifyStatusRequestFailed);
  tolua_constant(tolua_S,"CCStoreReceiptVerifyStatusInvalidResult",CCStoreReceiptVerifyStatusInvalidResult);
  tolua_constant(tolua_S,"CCStoreReceiptVerifyStatusNone",CCStoreReceiptVerifyStatusNone);
  tolua_constant(tolua_S,"CCStoreReceiptVerifyStatusOK",CCStoreReceiptVerifyStatusOK);
  tolua_cclass(tolua_S,"CCStore","CCStore","",NULL);
  tolua_beginmodule(tolua_S,"CCStore");
   tolua_function(tolua_S,"sharedStore",tolua_cocos2d_x_extensions_lua_CCStore_sharedStore00);
   tolua_function(tolua_S,"purgeSharedStore",tolua_cocos2d_x_extensions_lua_CCStore_purgeSharedStore00);
   tolua_function(tolua_S,"postInitWithTransactionListenerLua",tolua_cocos2d_x_extensions_lua_CCStore_postInitWithTransactionListenerLua00);
   tolua_function(tolua_S,"canMakePurchases",tolua_cocos2d_x_extensions_lua_CCStore_canMakePurchases00);
   tolua_function(tolua_S,"loadProductsLua",tolua_cocos2d_x_extensions_lua_CCStore_loadProductsLua00);
   tolua_function(tolua_S,"cancelLoadProducts",tolua_cocos2d_x_extensions_lua_CCStore_cancelLoadProducts00);
   tolua_function(tolua_S,"isProductLoaded",tolua_cocos2d_x_extensions_lua_CCStore_isProductLoaded00);
   tolua_function(tolua_S,"purchase",tolua_cocos2d_x_extensions_lua_CCStore_purchase00);
   tolua_function(tolua_S,"finishTransactionLua",tolua_cocos2d_x_extensions_lua_CCStore_finishTransactionLua00);
   tolua_function(tolua_S,"getReceiptVerifyMode",tolua_cocos2d_x_extensions_lua_CCStore_getReceiptVerifyMode00);
   tolua_function(tolua_S,"setReceiptVerifyMode",tolua_cocos2d_x_extensions_lua_CCStore_setReceiptVerifyMode00);
   tolua_function(tolua_S,"getReceiptVerifyServerUrl",tolua_cocos2d_x_extensions_lua_CCStore_getReceiptVerifyServerUrl00);
   tolua_function(tolua_S,"setReceiptVerifyServerUrl",tolua_cocos2d_x_extensions_lua_CCStore_setReceiptVerifyServerUrl00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_cocos2d_x_extensions_lua (lua_State* tolua_S) {
 return tolua_cocos2d_x_extensions_lua_open(tolua_S);
};
#endif

