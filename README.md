# cocos2d-x-extensions

## Features

-   CCCrypto: AES256, Base64, MD5
-   CCOpenFeint: OpenFeint integration
-   CCNative: show activity indicator, show alert dialog, get OpenUDID
-   CCNetwork: check network status
-   CCStore: iOS IAP support, with receipt verify
-   **100% Lua-binding compatibility**


## Setup

1.  Copy files to your project folder
2.  Add files to Xcode project
3.  Enjoy it !


## Lua-binding

1.  Copy cocos2d_x_extensions_lua.h/.cpp to your project
2.  Add code to AppDelegate.cpp, before pEngine->executeScriptFile()

        tolua_cocos2d_x_extensions_lua_open(pEngine->getLuaState());

3.  See https://github.com/dualface/cocos2d-x-lua-framework (Game Framework based cocos2d-x + lua-binding) for how to use.
