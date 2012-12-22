
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dx_extensions
LOCAL_MODULE_FILENAME := libcocos2dx_extensions

LOCAL_SRC_FILES := ../extensions/network/CCNetwork.cpp \
    ../extensions/network/CCHttpRequest.cpp \
    ../extensions/network/CCHttpRequest_impl.cpp \
    ../extensions/luabinding/cocos2dx_extension_network_android.cpp \
    ../extensions/crypto/CCCrypto.cpp \
    ../extensions/crypto/base64/libb64.c \
    ../extensions/crypto/md5/md5.c \
    ../extensions/crypto/sha1/sha1.cpp \
    ../extensions/luabinding/cocos2dx_extension_crypto_android.cpp

LOCAL_C_INCLUDES := $(COCOS2DX_ROOT)/cocos2dx \
    $(COCOS2DX_ROOT)/cocos2dx/include \
    $(COCOS2DX_ROOT)/cocos2dx/kazmath/include \
    $(COCOS2DX_ROOT)/cocos2dx/platform \
    $(COCOS2DX_ROOT)/cocos2dx/platform/android \
    $(COCOS2DX_ROOT)/cocos2dx/platform/third_party/android/prebuilt/libcurl/include \
    $(COCOS2DX_ROOT)/CocosDenshion/include \
    $(COCOS2DX_ROOT)/scripting/lua/cocos2dx_support \
    $(COCOS2DX_ROOT)/scripting/lua/lua \
    $(COCOS2DX_ROOT)/scripting/lua/tolua \
    $(LOCAL_PATH)/../extensions \
    $(LOCAL_PATH)/../extensions/luabinding

LOCAL_WHOLE_STATIC_LIBRARIES := cocos_curl_static

LOCAL_CFLAGS += -Wno-psabi -DCC_LUA_ENGINE_ENABLED=1
LOCAL_EXPORT_CFLAGS += -Wno-psabi -DCC_LUA_ENGINE_ENABLED=1

include $(BUILD_STATIC_LIBRARY)

$(call import-module,libcurl)
