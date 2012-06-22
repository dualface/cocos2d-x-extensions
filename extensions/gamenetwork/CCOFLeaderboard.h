
#ifndef __EXTENSIONS_CCOFLEADERBOARD_H_
#define __EXTENSIONS_CCOFLEADERBOARD_H_

#include <string>
#include "CCObject.h"

using namespace std;
using namespace cocos2d;

namespace extensions {
    
    class CCOFLeaderboard : public CCObject
    {
    public:
        static CCOFLeaderboard* leaderboardWithId(const char* id,
                                                  const char* name,
                                                  bool descendingScoreOrder,
                                                  int currentUserScore,
                                                  const char* currentUserScoreDisplayText);
        
        const string& getId(void) {
            return m_id;
        }
        
        const string& getName(void) {
            return m_name;
        }
        
        int getCurrentUserScore(void) {
            return m_currentUserScore;
        }
        
        const string& getCurrentUserScoreDisplayText(void) {
            return m_currentUserScoreDisplayText;
        }
        
        bool getDescendingScoreOrder(void) {
            return m_descendingScoreOrder;
        }
        
    private:
        CCOFLeaderboard(void) {}
        
        string  m_id;
        string  m_name;
        int     m_currentUserScore;
        string  m_currentUserScoreDisplayText;
        bool    m_descendingScoreOrder;
    };
    
}

#endif // __EXTENSIONS_CCOFLEADERBOARD_H_
