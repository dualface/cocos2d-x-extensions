
#ifndef __EXTENSIONS_CCOFLEADERBOARD_H_
#define __EXTENSIONS_CCOFLEADERBOARD_H_

#include "cocos2dx_extensions.h"
#include <string>
#include "cocoa/CCObject.h"

NS_CC_EXT_BEGIN

class CCOFLeaderboard : public CCObject
{
public:
    static CCOFLeaderboard* leaderboardWithId(const char* id,
                                              const char* name,
                                              bool descendingScoreOrder,
                                              int currentUserScore,
                                              const char* currentUserScoreDisplayText);
    
    const std::string& getId(void) {
        return m_id;
    }
    
    const std::string& getName(void) {
        return m_name;
    }
    
    int getCurrentUserScore(void) {
        return m_currentUserScore;
    }
    
    const std::string& getCurrentUserScoreDisplayText(void) {
        return m_currentUserScoreDisplayText;
    }
    
    bool getDescendingScoreOrder(void) {
        return m_descendingScoreOrder;
    }
    
private:
    CCOFLeaderboard(void) {}
    
    std::string m_id;
    std::string m_name;
    int         m_currentUserScore;
    std::string m_currentUserScoreDisplayText;
    bool        m_descendingScoreOrder;
};

NS_CC_EXT_END

#endif // __EXTENSIONS_CCOFLEADERBOARD_H_
