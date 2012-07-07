
#ifndef __EXTENSIONS_CCCRYPTO_H_
#define __EXTENSIONS_CCCRYPTO_H_

#include "CCScriptSupport.h"

using namespace cocos2d;

namespace extensions {
    
    class CCCrypto
    {
    public:
        
        /** @brief Return AES256 key length */
        static int getAES256KeyLength(void);
        
        /** @brief Encrypt data with AES256 algorithm, return ciphertext length */
        static int encryptAES256(const void* plaintext,
                                 int plaintextLength,
                                 void* ciphertext,
                                 int ciphertextBufferLength,
                                 const void* key,
                                 int keyLength)
        {
            return cryptAES256(false, plaintext, plaintextLength, ciphertext, ciphertextBufferLength, key, keyLength);
        }
        
        /** @brief Decrypt data with AES256 algorithm, return plaintext length */
        static int decryptAES256(const void* ciphertext,
                                 int ciphertextLength,
                                 void* plaintext,
                                 int plaintextBufferLength,
                                 const void* key,
                                 int keyLength)
        {
            return cryptAES256(true, ciphertext, ciphertextLength, plaintext, plaintextBufferLength, key, keyLength);
        }
        
        /** @brief Encoding data with Base64 algorithm, return encoded string length */
        static int encodeBase64(const void* input,
                                int inputLength,
                                char* output,
                                int outputBufferLength);
        
        
        /** @brief Decoding Base64 string to data, return decoded data length */
        static int decodeBase64(const char* input,
                                void* output,
                                int outputBufferLength);
        
        /** @brief Calculate MD5, get MD5 code (not string) */
        static void MD5(void* input, int inputLength, unsigned char* output);
        
        
#pragma mark -
#pragma mark for Lua
        
#if CC_LUA_ENGINE_ENABLED > 0

        /** @brief Encrypt data with AES256 algorithm, return ciphertext string, return nil if failed */
        static LUA_STRING encryptAES256Lua(const char* plaintext,
                                           int plaintextLength,
                                           const char* key,
                                           int keyLength)
        {
            return cryptAES256Lua(false, plaintext, plaintextLength, key, keyLength);
        }
        
        /** @brief Decrypt data with AES256 algorithm, return plaintext string, return nil if failed */
        static LUA_STRING decryptAES256Lua(const char* ciphertext,
                                           int ciphertextLength,
                                           const char* key,
                                           int keyLength)
        {
            return cryptAES256Lua(true, ciphertext, ciphertextLength, key, keyLength);
        }
        
        /** @brief Encoding data with Base64 algorithm, return encoded string */
        static LUA_STRING encodeBase64Lua(const char* input, int inputLength)
        {
            return encodingBase64Lua(false, input, inputLength);
        }
        
        /** @brief Decoding Base64 string to data, return decoded data length */
        static LUA_STRING decodeBase64Lua(const char* input)
        {
            return encodingBase64Lua(true, input, strlen(input));
        }
        
        /** @brief Calculate MD5, return MD5 string */
        static LUA_STRING MD5Lua(char* input, int inputLength, bool isRawOutput);
        
#endif
        
#pragma mark -
#pragma mark private methods
        
    private:
        CCCrypto(void) {}
        
        static int cryptAES256(bool isDecrypt,
                               const void* input,
                               int inputLength,
                               void* output,
                               int outputBufferLength,
                               const void* key,
                               int keyLength);
        
        static LUA_STRING cryptAES256Lua(bool isDecrypt,
                                         const void* input,
                                         int inputLength,
                                         const void* key,
                                         int keyLength);
        
        static LUA_STRING encodingBase64Lua(bool isDecoding,
                                            const char* input,
                                            int inputLength);
    };
    
}

#endif // __EXTENSIONS_CCCRYPTO_H_
