
#ifndef __EXTENSIONS_CCOFACHIEVEMENT_H_
#define __EXTENSIONS_CCOFACHIEVEMENT_H_

#include <string>
#include "CCObject.h"

using namespace std;
using namespace cocos2d;

namespace extensions {
    
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
        
        const string& getId(void) {
            return m_id;
        }
        
        const string& getTitle(void) {
            return m_title;
        }
        
        const string& getDescription(void) {
            return m_description;
        }
        
        const string& getIconUrl(void) {
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
        
        string  m_id;
        string  m_title;
        string  m_description;
        string  m_iconUrl;
        int     m_gameScore;
        bool    m_isUnlocked;
        bool    m_isSecret;
    };
    
}

#endif // __EXTENSIONS_CCOFACHIEVEMENT_H_
