# cocos2d-x-extensions

## 主要特征

-   CCCrypto: AES256 对称加密, Base64 编码和解码, MD5 计算
-   CCOpenFeint: OpenFeint 集成（目前支持 2.12.8，包括国内九城的汉化版）
-   CCNative: 显示活动指示器（菊花），显示提示对话框，获取 OpenUDID，在浏览器中打开指定 URL
-   CCNetwork: 检查网络状态
-   CCStore: Apple 应用商店 IAP，并支持收据验证（目前仅限从设备验证收据）
-   **所有功能都可以通过 Lua 脚本调用**

## iOS 示例（不含 Lua）

1.  从 https://github.com/cocos2d/cocos2d-x/tree/master 下载 cocos2d-x 1.x 版源文件
2.  将解压缩后的 cocos2dx 文件夹复制到 examples/cocos2dx-extensions-demo/libs 目录中
3.  打开 examples/cocos2dx-extensions-demo.xcodeproj 项目
4.  修改 examples/cocos2dx-extensions-demo/Classes/CCStoreScene.cpp 文件，设置好你应用程序商店中的 IAP 产品 ID
5.  **修改应用程序的 Bundle identifier，否则 IAP 无法正常工作**
6.  运行！

## iOS 示例（Lua 版）

即将到来。


## iOS 设置

1.  修改应用程序设置，添加以下 framework:
    -   MobileCoreService.framework
    -   Security.framework
    -   StoreKit.framework
    -   SystemConfiguration.framework
    -   CFNetwork.framework

2.  将需要的模块（子目录）复制到项目中
3.  搞定。

**启用 Lua 脚本支持**:

1.  确保项目已经能够正常运行 Lua 脚本
2.  从 extensions/luabinding 目录中复制用到的模块文件到项目中
3.  修改 AppDelegate.cpp，按照用到的模块添加代码：

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

4.  Lua 的调用方法可以参考 https://github.com/dualface/cocos2d-x-lua-framework (Game Framework based cocos2d-x + lua-binding)。


## CCOpenFeint 设置

1.  将 OpenFeint 加入项目，并确保编译通过
2.  复制 gamenetwork/openfeint 目录到项目中
3.  检查 CCOpenFeint.h 文件中定义的方法，因为 OpenFeint 太过复杂，所以就没有专门写示例程序了



