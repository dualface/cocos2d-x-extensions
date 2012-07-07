
#ifndef  __EXTENSIONS_CCOPENFEINT_H_
#define  __EXTENSIONS_CCOPENFEINT_H_

#include "CCScriptSupport.h"
#include "CCArray.h"

using namespace cocos2d;

namespace extensions {
    
    class CCOpenFeint
    {
    public:
        // 初始化
        static void postInitWithProductKey(const char* productKey, const char* secret, const char* displayName);
        
        // 显示仪表盘
        static void showDashboard(void);
        // 显示排行榜列表
        static void showLeaderboards(void);
        // 显示指定的排行榜
        static void showLeaderboards(const char* leaderboardId);
        // 显示成就列表
        static void showAchievements(void);
        // 显示挑战列表
        static void showChallenges(void);
        // 显示好友面板
        static void showFriends(void);
        // 显示正在玩这个游戏的好友
        static void showPlaying(void);
        
        // 取得所有成就的信息，返回 array of CCOFAchievement
        static CCArray* getAchievements(void);
        // 以 lua table 的形式返回所有成就的信息
        static LUA_TABLE getAchievementsLua(void);
        // 解锁指定的成就
        static void unlockAchievement(const char* achievementId);
        
        // 取得所有排行榜的信息，返回 array of CCOFLeaderboard
        static CCArray* getLeaderboards(void);
        // 以 lua table 的形式返回所有排行榜的信息
        static LUA_TABLE getLeaderboardsLua(void);
        // 设置指定排行榜上，当前玩家的高分
        static void setHighScore(const char* leaderboardId, int score, const char* displayText = NULL);
        
    private:
        CCOpenFeint(void) {}
    };
    
}

#endif // __EXTENSIONS_CCOPENFEINT_H_
