
#ifndef cocos2dx_extensions_demo_CCNetworkScene_h
#define cocos2dx_extensions_demo_CCNetworkScene_h

#include "cocos2d.h"

using namespace cocos2d;

class CCNetworkScene : public CCScene
{
public:
    static CCNetworkScene* scene(void);
    
    void testCheckNetworkStatus(CCObject* pSender);
    void backToMainScene(CCObject* pSender);
    
private:
    bool init(void);
};

#endif
