#ifndef cocos2dx_extensions_demo_CCCryptoScene_h
#define cocos2dx_extensions_demo_CCCryptoScene_h

#include "cocos2d.h"

using namespace cocos2d;

class CCCryptoScene : public CCScene
{
public:
    static CCCryptoScene* scene(void);
    
    void testEncryptAES256(CCObject* pSender);
    void testEncodeBase64(CCObject* pSender);
    void testMD5(CCObject* pSender);
    void backToMainScene(CCObject* pSender);
    
private:
    virtual bool init(void);
};

#endif
