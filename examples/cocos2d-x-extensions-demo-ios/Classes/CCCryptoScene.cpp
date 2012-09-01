
#include "CCCryptoScene.h"
#include "crypto/CCCrypto.h"
#include "HelloWorldScene.h"

USING_NS_CC_EXT;

CCCryptoScene* CCCryptoScene::scene(void)
{
    CCCryptoScene* scene = new CCCryptoScene();
    scene->init();
    scene->autorelease();
    return scene;
}

bool CCCryptoScene::init(void)
{
    CCScene::init();
    
    CCLabelTTF* label = CCLabelTTF::create("encryptAES256() / decryptAES256()", "Arial", 22);
    CCMenuItemLabel* item1 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCCryptoScene::testEncryptAES256));
    
    label = CCLabelTTF::create("encodeBase64() / decodeBase64()", "Arial", 22);
    CCMenuItemLabel* item2 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCCryptoScene::testEncodeBase64));
    
    label = CCLabelTTF::create("MD5()", "Arial", 22);
    CCMenuItemLabel* item3 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCCryptoScene::testMD5));
    
    label = CCLabelTTF::create("sha1()", "Arial", 22);
    CCMenuItemLabel* item4 = CCMenuItemLabel::create(label,
                                                     this,
                                                     menu_selector(CCCryptoScene::testSha1));
    
    label = CCLabelTTF::create("- BACK -", "Arial", 22);
    CCMenuItemLabel* itemBack = CCMenuItemLabel::create(label,
                                                        this,
                                                        menu_selector(CCCryptoScene::backToMainScene));
    
	CCMenu* pMenu = CCMenu::create(item1, item2, item3, item4, itemBack, NULL);
    pMenu->alignItemsVertically();
	addChild(pMenu);
    
    return true;
}

void CCCryptoScene::testEncryptAES256(CCObject* pSender)
{
    const char* plaintext = "Show me the money";
    const char* key = "cocos2dx";
    int plaintextLength = strlen(plaintext);
    int bufferLength = plaintextLength + CCCrypto::getAES256KeyLength();
    int keyLen = strlen(key);
    void* buff = malloc(bufferLength);
    int ciphertextLength = CCCrypto::encryptAES256(plaintext, plaintextLength, buff, bufferLength, key, keyLen);
    
    printf("\n");
    printf("encryptAES256():\n");
    printf("  plaintext: %s\n", plaintext);
    printf("  plaintextLength: %d\n", plaintextLength);
    printf("  key: %s\n", key);
    printf("  ciphertextLength: %d\n", ciphertextLength);
    printf("  ciphertext:");
    for (int i = 0; i < ciphertextLength; ++i)
    {
        printf("0x%02X ", static_cast<unsigned char*>(buff)[i]);
    }
    printf("\n");
    
    
    printf("decryptAES256():\n");
    char* plaintext2 = static_cast<char*>(malloc(bufferLength));
    int plaintextLength2 = CCCrypto::decryptAES256(buff, ciphertextLength, plaintext2, bufferLength, key, keyLen);
    printf("  plaintext: %s\n", plaintext2);
    printf("  plaintextLength: %d\n", plaintextLength2);
    printf("  string compare: %s\n", strcmp(plaintext, plaintext2) == 0 ? "OK" : "ERROR");
    printf("\n\n");
}

void CCCryptoScene::testEncodeBase64(CCObject* pSender)
{
    const char* plaintext = "Show me the money";
    int plaintextLength = strlen(plaintext);
    int bufferLength = plaintextLength * 2;
    char* buffer = static_cast<char*>(malloc(bufferLength));
    int encodedTextLength = CCCrypto::encodeBase64(plaintext, plaintextLength, buffer, bufferLength);
    
    printf("\n");
    printf("encodeBase64():\n");
    printf("  plaintext: %s\n", plaintext);
    printf("  plaintextLength: %d\n", plaintextLength);
    printf("  encodedTextLength: %d\n", encodedTextLength);
    printf("  encodedText: %s\n", buffer);
    
    printf("decodeBase64():\n");
    char* plaintext2 = static_cast<char*>(malloc(encodedTextLength + 1));
    int plaintextLength2 = CCCrypto::decodeBase64(buffer, plaintext2, encodedTextLength + 1);
    printf("  plaintext: %s\n", plaintext2);
    printf("  plaintextLength: %d\n", plaintextLength2);
    printf("  string compare: %s\n", strcmp(plaintext, plaintext2) == 0 ? "OK" : "ERROR");
    printf("\n\n");
}

void CCCryptoScene::testMD5(cocos2d::CCObject *pSender)
{
    const char* plaintext = "Show me the money";
    unsigned char buffer[CCCrypto::MD5_BUFFER_LENGTH];
    CCCrypto::MD5((void*)plaintext, strlen(plaintext), buffer);
    
    printf("\n");
    printf("MD5():\n");
    printf("  input: %s\n", plaintext);
    printf("    md5:");
    dumpHex(buffer, CCCrypto::MD5_BUFFER_LENGTH);
    printf("\n\n");
}

void CCCryptoScene::testSha1(cocos2d::CCObject *pSender)
{
    const char* plaintext = "Show me the money";
    const char* key = "key123456";
    unsigned char buffer[CCCrypto::SHA1_BUFFER_LENGTH];
    CCCrypto::sha1((unsigned char*)plaintext, strlen(plaintext),
                   (unsigned char*)key, strlen(key),
                   buffer, CCCrypto::SHA1_BUFFER_LENGTH);
    
    printf("\n");
    printf("sha1():\n");
    printf("  input: %s\n", plaintext);
    printf("    key: %s\n", key);
    printf("   sha1:");
    dumpHex(buffer, CCCrypto::SHA1_BUFFER_LENGTH);
    printf("\n\n");
}

void CCCryptoScene::backToMainScene(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

void CCCryptoScene::dumpHex(unsigned char* bin, int binLength)
{
    static const char* hextable = "0123456789abcdef";
    int strLength = binLength * 2 + 1;
    char str[strLength];
    memset(str, 0, strLength);
    int ci = 0;
    for (int i = 0; i < binLength; ++i)
    {
        unsigned char c = bin[i];
        str[ci++] = hextable[(c >> 4) & 0x0f];
        str[ci++] = hextable[c & 0x0f];
    }
    printf("%s", str);
}
