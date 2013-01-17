/*
** Lua binding: cocos2dx_extension_network_ios
** Generated automatically by tolua++-1.0.92 on Thu Jan 17 16:11:20 2013.
*/

#include "cocos2dx_extension_network_ios.h"



#include "network/CCNetwork.h"
using namespace cocos2d::extension;

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 
 tolua_usertype(tolua_S,"CCHttpRequest");
 tolua_usertype(tolua_S,"CCNetwork");
 tolua_usertype(tolua_S,"CCObject");
}

/* method: createWithUrlLua of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_createWithUrlLua00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_createWithUrlLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LUA_FUNCTION listener = (  toluafix_ref_function(tolua_S,2,0));
  const char* url = ((const char*)  tolua_tostring(tolua_S,3,0));
  CCHttpRequestMethod method = ((CCHttpRequestMethod) (int)  tolua_tonumber(tolua_S,4,CCHttpRequestMethodGET));
  {
   CCHttpRequest* tolua_ret = (CCHttpRequest*)  CCHttpRequest::createWithUrlLua(listener,url,method);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCHttpRequest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithUrlLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addRequestHeader of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_addRequestHeader00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_addRequestHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addRequestHeader'", NULL);
#endif
  {
   self->addRequestHeader(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addRequestHeader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addPostValue of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_addPostValue00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_addPostValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addPostValue'", NULL);
#endif
  {
   self->addPostValue(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addPostValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPostData of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_setPostData00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_setPostData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPostData'", NULL);
#endif
  {
   self->setPostData(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPostData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTimeout of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_setTimeout00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_setTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  float timeout = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTimeout'", NULL);
#endif
  {
   self->setTimeout(timeout);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTimeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIsInProgress of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_getIsInProgress00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_getIsInProgress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIsInProgress'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIsInProgress();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIsInProgress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_start00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  bool isCached = ((bool)  tolua_toboolean(tolua_S,2,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   self->start(isCached);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cancel of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_cancel00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_cancel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cancel'", NULL);
#endif
  {
   self->cancel();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cancel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearDelegatesAndCancel of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_clearDelegatesAndCancel00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_clearDelegatesAndCancel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearDelegatesAndCancel'", NULL);
#endif
  {
   self->clearDelegatesAndCancel();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearDelegatesAndCancel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResponseStatusCode of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseStatusCode00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseStatusCode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResponseStatusCode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getResponseStatusCode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResponseStatusCode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResponseString of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseString00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResponseString'", NULL);
#endif
  {
    const char* tolua_ret = (  const char*)  self->getResponseString();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResponseString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResponseData of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseData00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  int dataLength = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResponseData'", NULL);
#endif
  {
   const void* tolua_ret = (const void*)  self->getResponseData(&dataLength);
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)dataLength);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResponseData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResponseDataLength of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseDataLength00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseDataLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResponseDataLength'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getResponseDataLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResponseDataLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveResponseData of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_saveResponseData00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_saveResponseData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveResponseData'", NULL);
#endif
  {
   int tolua_ret = (int)  self->saveResponseData(filename);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveResponseData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getErrorCode of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_getErrorCode00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_getErrorCode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getErrorCode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getErrorCode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getErrorCode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getErrorMessage of class  CCHttpRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCHttpRequest_getErrorMessage00
static int tolua_cocos2dx_extension_network_ios_CCHttpRequest_getErrorMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHttpRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHttpRequest* self = (CCHttpRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getErrorMessage'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getErrorMessage();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getErrorMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isLocalWiFiAvailable of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCNetwork_isLocalWiFiAvailable00
static int tolua_cocos2dx_extension_network_ios_CCNetwork_isLocalWiFiAvailable00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCNetwork_isInternetConnectionAvailable00
static int tolua_cocos2dx_extension_network_ios_CCNetwork_isInternetConnectionAvailable00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCNetwork_isHostNameReachable00
static int tolua_cocos2dx_extension_network_ios_CCNetwork_isHostNameReachable00(lua_State* tolua_S)
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
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCNetwork_getInternetConnectionStatus00
static int tolua_cocos2dx_extension_network_ios_CCNetwork_getInternetConnectionStatus00(lua_State* tolua_S)
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

/* method: httpRequestLua of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extension_network_ios_CCNetwork_httpRequestLua00
static int tolua_cocos2dx_extension_network_ios_CCNetwork_httpRequestLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LUA_FUNCTION listener = (  toluafix_ref_function(tolua_S,2,0));
  const char* url = ((const char*)  tolua_tostring(tolua_S,3,0));
  CCHttpRequestMethod method = ((CCHttpRequestMethod) (int)  tolua_tonumber(tolua_S,4,CCHttpRequestMethodGET));
  {
   CCHttpRequest* tolua_ret = (CCHttpRequest*)  CCNetwork::httpRequestLua(listener,url,method);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCHttpRequest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'httpRequestLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_cocos2dx_extension_network_ios_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"CCNetworkStatusNotReachable",CCNetworkStatusNotReachable);
  tolua_constant(tolua_S,"CCNetworkStatusReachableViaWiFi",CCNetworkStatusReachableViaWiFi);
  tolua_constant(tolua_S,"CCNetworkStatusReachableViaWWAN",CCNetworkStatusReachableViaWWAN);
  tolua_constant(tolua_S,"CCHttpRequestMethodGET",CCHttpRequestMethodGET);
  tolua_constant(tolua_S,"CCHttpRequestMethodPOST",CCHttpRequestMethodPOST);
  tolua_constant(tolua_S,"CCHttpRequestErrorNone",CCHttpRequestErrorNone);
  tolua_constant(tolua_S,"CCHttpRequestErrorConnectionFailure",CCHttpRequestErrorConnectionFailure);
  tolua_constant(tolua_S,"CCHttpRequestErrorTimeout",CCHttpRequestErrorTimeout);
  tolua_constant(tolua_S,"CCHttpRequestErrorAuthentication",CCHttpRequestErrorAuthentication);
  tolua_constant(tolua_S,"CCHttpRequestErrorCancelled",CCHttpRequestErrorCancelled);
  tolua_constant(tolua_S,"CCHttpRequestErrorUnknown",CCHttpRequestErrorUnknown);
  tolua_cclass(tolua_S,"CCHttpRequest","CCHttpRequest","CCObject",NULL);
  tolua_beginmodule(tolua_S,"CCHttpRequest");
   tolua_function(tolua_S,"createWithUrlLua",tolua_cocos2dx_extension_network_ios_CCHttpRequest_createWithUrlLua00);
   tolua_function(tolua_S,"addRequestHeader",tolua_cocos2dx_extension_network_ios_CCHttpRequest_addRequestHeader00);
   tolua_function(tolua_S,"addPostValue",tolua_cocos2dx_extension_network_ios_CCHttpRequest_addPostValue00);
   tolua_function(tolua_S,"setPostData",tolua_cocos2dx_extension_network_ios_CCHttpRequest_setPostData00);
   tolua_function(tolua_S,"setTimeout",tolua_cocos2dx_extension_network_ios_CCHttpRequest_setTimeout00);
   tolua_function(tolua_S,"getIsInProgress",tolua_cocos2dx_extension_network_ios_CCHttpRequest_getIsInProgress00);
   tolua_function(tolua_S,"start",tolua_cocos2dx_extension_network_ios_CCHttpRequest_start00);
   tolua_function(tolua_S,"cancel",tolua_cocos2dx_extension_network_ios_CCHttpRequest_cancel00);
   tolua_function(tolua_S,"clearDelegatesAndCancel",tolua_cocos2dx_extension_network_ios_CCHttpRequest_clearDelegatesAndCancel00);
   tolua_function(tolua_S,"getResponseStatusCode",tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseStatusCode00);
   tolua_function(tolua_S,"getResponseString",tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseString00);
   tolua_function(tolua_S,"getResponseData",tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseData00);
   tolua_function(tolua_S,"getResponseDataLength",tolua_cocos2dx_extension_network_ios_CCHttpRequest_getResponseDataLength00);
   tolua_function(tolua_S,"saveResponseData",tolua_cocos2dx_extension_network_ios_CCHttpRequest_saveResponseData00);
   tolua_function(tolua_S,"getErrorCode",tolua_cocos2dx_extension_network_ios_CCHttpRequest_getErrorCode00);
   tolua_function(tolua_S,"getErrorMessage",tolua_cocos2dx_extension_network_ios_CCHttpRequest_getErrorMessage00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CCNetwork","CCNetwork","",NULL);
  tolua_beginmodule(tolua_S,"CCNetwork");
   tolua_function(tolua_S,"isLocalWiFiAvailable",tolua_cocos2dx_extension_network_ios_CCNetwork_isLocalWiFiAvailable00);
   tolua_function(tolua_S,"isInternetConnectionAvailable",tolua_cocos2dx_extension_network_ios_CCNetwork_isInternetConnectionAvailable00);
   tolua_function(tolua_S,"isHostNameReachable",tolua_cocos2dx_extension_network_ios_CCNetwork_isHostNameReachable00);
   tolua_function(tolua_S,"getInternetConnectionStatus",tolua_cocos2dx_extension_network_ios_CCNetwork_getInternetConnectionStatus00);
   tolua_function(tolua_S,"httpRequestLua",tolua_cocos2dx_extension_network_ios_CCNetwork_httpRequestLua00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_cocos2dx_extension_network_ios (lua_State* tolua_S) {
 return tolua_cocos2dx_extension_network_ios_open(tolua_S);
};
#endif

