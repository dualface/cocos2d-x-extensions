
#ifndef __EXTENSIONS_CCOFACHIEVEMENT_H_
#define __EXTENSIONS_CCOFACHIEVEMENT_H_

#include "cocos2dx_extensions.h"
#include <string>
#include "cocoa/CCObject.h"

NS_CC_EXT_BEGIN

class CCOFAchievement : public CCObject
{
public:
    static CCOFAchievement* achievementWithId(const char* id,
                                              const char* title,
                                              const char* description,
                                              const char* iconUrl,
                                              int gameScore,
                                              bool isUnlocked,
                                              bool isSecret);
    
    const std::string& getId(void) {
        return m_id;
    }
    
    const std::string& getTitle(void) {
        return m_title;
    }
    
    const std::string& getDescription(void) {
        return m_description;
    }
    
    const std::string& getIconUrl(void) {
        return m_iconUrl;
    }
    
    int getGameScore(void) {
        return m_gameScore;
    }
    
    bool getIsUnlocked(void) {
        return m_isUnlocked;
    }
    
    bool getIsSecret(void) {
        return m_isSecret;
    }
    
private:
    CCOFAchievement(void) {}
    
    std::string m_id;
    std::string m_title;
    std::string m_description;
    std::string m_iconUrl;
    int         m_gameScore;
    bool        m_isUnlocked;
    bool        m_isSecret;
};

NS_CC_EXT_END

#endif // __EXTENSIONS_CCOFACHIEVEMENT_H_
