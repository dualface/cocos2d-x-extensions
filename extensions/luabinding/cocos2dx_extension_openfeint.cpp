/*
** Lua binding: cocos2dx_extension_openfeint
** Generated automatically by tolua++-1.0.92 on Fri Jul 13 18:37:17 2012.
*/

#include "cocos2dx_extension_openfeint.h"



#include "CCOpenFeint.h"
using namespace cocos2d::extension;

/* function to release collected object via destructor */
#ifdef __cplusplus


#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 
 tolua_usertype(tolua_S,"CCOpenFeint");
}

/* method: postInitWithProductKey of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_postInitWithProductKey00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_postInitWithProductKey00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_showDashboard00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_showDashboard00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_showLeaderboards00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_showLeaderboards00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_showLeaderboards01
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_showLeaderboards01(lua_State* tolua_S)
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
 return tolua_cocos2dx_extension_openfeint_CCOpenFeint_showLeaderboards00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: showAchievements of class  CCOpenFeint */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_showAchievements00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_showAchievements00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_showChallenges00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_showChallenges00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_showFriends00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_showFriends00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_showPlaying00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_showPlaying00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_getAchievementsLua00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_getAchievementsLua00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_unlockAchievement00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_unlockAchievement00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_getLeaderboardsLua00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_getLeaderboardsLua00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_openfeint_CCOpenFeint_setHighScore00
static int tolua_cocos2dx_extension_openfeint_CCOpenFeint_setHighScore00(lua_State* tolua_S)
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

/* Open function */
TOLUA_API int tolua_cocos2dx_extension_openfeint_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"CCOpenFeint","CCOpenFeint","",NULL);
  tolua_beginmodule(tolua_S,"CCOpenFeint");
   tolua_function(tolua_S,"postInitWithProductKey",tolua_cocos2dx_extension_openfeint_CCOpenFeint_postInitWithProductKey00);
   tolua_function(tolua_S,"showDashboard",tolua_cocos2dx_extension_openfeint_CCOpenFeint_showDashboard00);
   tolua_function(tolua_S,"showLeaderboards",tolua_cocos2dx_extension_openfeint_CCOpenFeint_showLeaderboards00);
   tolua_function(tolua_S,"showLeaderboards",tolua_cocos2dx_extension_openfeint_CCOpenFeint_showLeaderboards01);
   tolua_function(tolua_S,"showAchievements",tolua_cocos2dx_extension_openfeint_CCOpenFeint_showAchievements00);
   tolua_function(tolua_S,"showChallenges",tolua_cocos2dx_extension_openfeint_CCOpenFeint_showChallenges00);
   tolua_function(tolua_S,"showFriends",tolua_cocos2dx_extension_openfeint_CCOpenFeint_showFriends00);
   tolua_function(tolua_S,"showPlaying",tolua_cocos2dx_extension_openfeint_CCOpenFeint_showPlaying00);
   tolua_function(tolua_S,"getAchievementsLua",tolua_cocos2dx_extension_openfeint_CCOpenFeint_getAchievementsLua00);
   tolua_function(tolua_S,"unlockAchievement",tolua_cocos2dx_extension_openfeint_CCOpenFeint_unlockAchievement00);
   tolua_function(tolua_S,"getLeaderboardsLua",tolua_cocos2dx_extension_openfeint_CCOpenFeint_getLeaderboardsLua00);
   tolua_function(tolua_S,"setHighScore",tolua_cocos2dx_extension_openfeint_CCOpenFeint_setHighScore00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_cocos2dx_extension_openfeint (lua_State* tolua_S) {
 return tolua_cocos2dx_extension_openfeint_open(tolua_S);
};
#endif

