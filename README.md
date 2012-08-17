# cocos2d-x-extensions

## Features

-   CCCrypto: AES256, Base64, MD5, SHA1
-   CCOpenFeint: OpenFeint integration
-   CCNative: show activity indicator, show alert dialog, get OpenUDID, open url
-   CCNetwork: async http request(GET/POST), check network status
-   CCStore: iOS IAP support, with receipt verify
-   **100% Lua-binding compatibility**

## Example - iOS (without Lua)

1.  Download cocos2d-x 1.x sources from https://github.com/cocos2d/cocos2d-x/tree/master
2.  Copy cocos2dx to examples/cocos2dx-extensions-demo/libs
3.  Open examples/cocos2dx-extensions-demo.xcodeproj
4.  Change examples/cocos2dx-extensions-demo/Classes/CCStoreScene.cpp, SET YOUR IAP PRODUCTS ID
5.  **!!! CHANGE Bundle identifier FOR IAP !!!**
6.  Run!

## Example - iOS (Lua)

Coming soon.


## iOS Setup

1.  Add frameworks:
    -   MobileCoreService.framework
    -   Security.framework
    -   StoreKit.framework
    -   SystemConfiguration.framework
    -   CFNetwork.framework

2.  Copy files (required modules) to your project folder, add files to Xcode project


**Luabinding**:

1.  Copy luabinding files (required modules), add to Xcode
2.  Add code to AppDelegate.cpp:

        #include "cocos2dx_extension_crypto.h"          // CCCrypto
        #include "cocos2dx_extension_native.h"          // CCNative
        #include "cocos2dx_extension_network.h"         // CCNetwork
        #include "cocos2dx_extension_store.h"           // CCStore
        #include "cocos2dx_extension_openfeint.h"       // CCOpenFeint
        #include "cocos2dx_extension_gamecenter.h"      // CCGameCenter
    
        lua_State* L = CCScriptEngineManager::sharedManager()->getScriptEngine()->getLuaState();
        tolua_cocos2dx_extension_crypto_open(L);        // CCCrypto
        tolua_cocos2dx_extension_native_open(L);        // CCNative
        tolua_cocos2dx_extension_network_open(L);       // CCNetwork
        tolua_cocos2dx_extension_store_open(L);         // CCStore
        tolua_cocos2dx_extension_openfeint_open(L);     // CCOpenFeint
        tolua_cocos2dx_extension_gamecenter_open(L);    // CCGameCenter

3.  See https://github.com/dualface/cocos2d-x-lua-framework (Game Framework based cocos2d-x + lua-binding) for how to use.


## CCOpenFeint Setup

1.  Add OpenFeint to your project
2.  Copy gamenetwork/openfeint to your project folder, add files to Xcode project
3.  Check CCOpenFeint.h interface

