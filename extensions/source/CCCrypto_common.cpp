
#include "CCCrypto.h"

extern "C" {
#include "libb64.h"
#include "md5.h"
}

#if CC_LUA_ENGINE_ENABLED > 0
extern "C" {
#include "lua.h"
#include "lapi.h"
#include "tolua_fix.h"
}
#endif

NS_CC_EXT_BEGIN

int CCCrypto::encodeBase64(const void* input,
                           int inputLength,
                           char* output,
                           int outputBufferLength)
{
    int bufferSize = 2 * inputLength;
    char* buffer = (char*)malloc(bufferSize);
    memset(buffer, 0, bufferSize);
    
    base64_encodestate state;
    base64_init_encodestate(&state);
    int r1 = base64_encode_block(static_cast<const char*>(input), inputLength, buffer, &state);
    int r2 = base64_encode_blockend(buffer+ r1, &state);
    
    int dataUsed = r1 + r2;
    memset(output, 0, outputBufferLength);
    int cp = dataUsed < outputBufferLength ? dataUsed : outputBufferLength - 1;
    memcpy(output, buffer, cp);
    free(buffer);
    return cp;
}

int CCCrypto::decodeBase64(const char* input,
                           void* output,
                           int outputBufferLength)
{
    int bufferSize = strlen(input) + 1;
    char* buffer = (char*)malloc(bufferSize);
    memset(buffer, 0, bufferSize);
    base64_decodestate state;
    base64_init_decodestate(&state);
    int r1 = base64_decode_block(input, bufferSize - 1, buffer, &state);
    
    memset(output, 0, outputBufferLength);
    int cp = r1 < outputBufferLength ? r1 : outputBufferLength - 1;
    memcpy(output, buffer, cp);
    free(buffer);
    return cp;
}

void CCCrypto::MD5(void* input, int inputLength, unsigned char* output)
{
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, input, inputLength);
    MD5_Final(output, &ctx);
}

#if CC_LUA_ENGINE_ENABLED > 0

LUA_STRING CCCrypto::encodingBase64Lua(bool isDecoding,
                                       const char* input,
                                       int inputLength)
{
    CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();
    engine->cleanLuaStack();
    lua_State* L = engine->getLuaState();
    
    int outputLength = inputLength * 2;
    char* output = static_cast<char*>(malloc(outputLength));
    int dataUsed = -1;
    
    if (isDecoding)
    {
        dataUsed = decodeBase64(input, output, outputLength);
    }
    else
    {
        dataUsed = encodeBase64(input, inputLength, output, outputLength);
    }
    if (dataUsed > 0 && dataUsed < outputLength)
    {
        lua_pushlstring(L, output, dataUsed);
    }
    else
    {
        lua_pushnil(L);
    }
    free(output);
    return 1;
}

LUA_STRING CCCrypto::MD5Lua(char* input, int inputLength, bool isRawOutput)
{
    static const char* hextable = "0123456789abcdef";
    
    unsigned char buffer[16];
    MD5(static_cast<void*>(input), inputLength, buffer);
    
    CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();
    engine->cleanLuaStack();
    lua_State* L = engine->getLuaState();
    
    if (isRawOutput)
    {
        lua_pushlstring(L, (char*)buffer, 16);
    }
    else
    {
        char md5str[33];
        md5str[32] = 0;
        int ci = 0;
        for (int i = 0; i < 16; ++i)
        {
            unsigned char c = buffer[i];
            md5str[ci++] = hextable[(c >> 4) & 0x0f];
            md5str[ci++] = hextable[c & 0x0f];
        }
        lua_pushstring(L, md5str);
    }
    
    return 1;
}

#endif

NS_CC_EXT_END
