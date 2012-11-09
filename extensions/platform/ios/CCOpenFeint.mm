
#import "CCOpenFeint.h"
#import "CCOpenFeint_objc.h"
#import "OpenFeint/include/OFAchievement.h"
#import "OpenFeint/include/OFLeaderboard.h"

#include "CCOFAchievement.h"
#include "CCOFLeaderboard.h"

NS_CC_EXT_BEGIN

void CCOpenFeint::postInitWithProductKey(const char* productKey, const char* secret, const char* displayName)
{
    NSString* _productKey = [NSString stringWithUTF8String:productKey ? productKey : ""];
    NSString* _secret = [NSString stringWithUTF8String:secret ? secret : ""];
    NSString* _displayName = [NSString stringWithUTF8String:displayName ? displayName : ""];
    [[CCOpenFeint_objc sharedInstance] postInitWithProductKey:_productKey
                                                    andSecret:_secret
                                               andDisplayName:_displayName];
}

void CCOpenFeint::showDashboard(void)
{
    [[CCOpenFeint_objc sharedInstance] showDashboard];
}

void CCOpenFeint::showLeaderboards(void)
{
    [[CCOpenFeint_objc sharedInstance] showLeaderboards];
}

void CCOpenFeint::showLeaderboards(const char* leaderboardId)
{
    if (!leaderboardId) leaderboardId = "";
    [[CCOpenFeint_objc sharedInstance] showLeaderboards:[NSString stringWithUTF8String:leaderboardId]];
}

void CCOpenFeint::showAchievements(void)
{
    [[CCOpenFeint_objc sharedInstance] showAchievements];
}

void CCOpenFeint::showChallenges(void)
{
    [[CCOpenFeint_objc sharedInstance] showChallenges];
}

void CCOpenFeint::showFriends(void)
{
    [[CCOpenFeint_objc sharedInstance] showFriends];
}

void CCOpenFeint::showPlaying(void)
{
    [[CCOpenFeint_objc sharedInstance] showPlaying];
}

CCArray* CCOpenFeint::getAchievements(void)
{
    NSArray* achievements = [[CCOpenFeint_objc sharedInstance] getAchievements];
    CCArray* arr = CCArray::createWithCapacity([achievements count]);
    
    for (int i = 0; i < [achievements count]; ++i)
    {
        OFAchievement* ach = [achievements objectAtIndex:i];
        const char* achievementId = [ach.resourceId cStringUsingEncoding:NSUTF8StringEncoding];
        const char* title = [ach.title cStringUsingEncoding:NSUTF8StringEncoding];
        const char* description = [ach.description cStringUsingEncoding:NSUTF8StringEncoding];
        const char* iconUrl = [ach.iconUrl cStringUsingEncoding:NSUTF8StringEncoding];
        CCOFAchievement* ccach = CCOFAchievement::achievementWithId(achievementId,
                                                                    title,
                                                                    description,
                                                                    iconUrl,
                                                                    ach.gamerscore,
                                                                    ach.isUnlocked,
                                                                    ach.isSecret);
        arr->addObject(ccach);
    }
    
    return arr;
}

void CCOpenFeint::unlockAchievement(const char* achievementId)
{
    if (!achievementId) achievementId = "";
    [[CCOpenFeint_objc sharedInstance] unlockAchievement:[NSString stringWithUTF8String:achievementId]];
}

CCArray* CCOpenFeint::getLeaderboards(void)
{
    NSArray* leaderboards = [[CCOpenFeint_objc sharedInstance] getLeaderboards];
    CCArray* arr = CCArray::createWithCapacity([leaderboards count]);
    
    for (int i = 0; i < [leaderboards count]; ++i)
    {
        OFLeaderboard* board = [leaderboards objectAtIndex:i];
        const char* leaderboardId = [board.leaderboardId cStringUsingEncoding:NSUTF8StringEncoding];
        const char* name = [board.name cStringUsingEncoding:NSUTF8StringEncoding];
        const char* currentUserScoreDisplayText = [board.currentUserScore.displayText
                                                   cStringUsingEncoding:NSUTF8StringEncoding];
        CCOFLeaderboard* ccboard = CCOFLeaderboard::leaderboardWithId(leaderboardId,
                                                                      name,
                                                                      board.descendingScoreOrder,
                                                                      board.currentUserScore.score,
                                                                      currentUserScoreDisplayText);
        arr->addObject(ccboard);
    }
    
    return arr;
}

void CCOpenFeint::setHighScore(const char* leaderboardId, int score, const char* displayText)
{
    if (!leaderboardId) leaderboardId = "";
    if (!displayText) displayText = "";
    [[CCOpenFeint_objc sharedInstance] setHighScore:[NSString stringWithUTF8String:leaderboardId]
                                           andScore:[NSNumber numberWithInt:score]
                                     andDisplayText:[NSString stringWithUTF8String:displayText]];
}

#if CC_LUA_ENGINE_ENABLED > 0
LUA_TABLE CCOpenFeint::getAchievementsLua(void)
{
    CCArray* achievements = getAchievements();
    CCLuaValueArray achievements_;
    
    for (int i = 0; i < achievements->count(); ++i)
    {
        CCOFAchievement* ach = static_cast<CCOFAchievement*>(achievements->objectAtIndex(i));
        CCLuaValueDict ach_;
        
        ach_["id"] = CCLuaValue::stringValue(ach->getId());
        ach_["title"] = CCLuaValue::stringValue(ach->getTitle());
        ach_["description"] = CCLuaValue::stringValue(ach->getDescription());
        ach_["iconUrl"] = CCLuaValue::stringValue(ach->getIconUrl());
        ach_["gameScore"] = CCLuaValue::intValue(ach->getGameScore());
        ach_["isUnlocked"] = CCLuaValue::booleanValue(ach->getIsUnlocked());
        ach_["isSecret"] = CCLuaValue::booleanValue(ach->getIsSecret());
        
        achievements_.push_back(CCLuaValue::dictValue(ach_));
    }
    
    CCLuaEngine* engine = CCLuaEngine::defaultEngine();
    engine->cleanStack();
    engine->pushCCLuaValueArray(achievements_);
    return 1;
}

LUA_TABLE CCOpenFeint::getLeaderboardsLua(void)
{
    CCArray* leaderboards = getLeaderboards();
    CCLuaValueArray leaderboards_;
    
    for (int i = 0; i < leaderboards->count(); ++i)
    {
        CCOFLeaderboard* board = static_cast<CCOFLeaderboard*>(leaderboards->objectAtIndex(i));
        CCLuaValueDict board_;
        
        board_["id"] = CCLuaValue::stringValue(board->getId());
        board_["name"] = CCLuaValue::stringValue(board->getName());
        board_["descendingScoreOrder"] = CCLuaValue::booleanValue(board->getDescendingScoreOrder());
        board_["currentUserScore"] = CCLuaValue::intValue(board->getCurrentUserScore());
        board_["currentUserScoreDisplayText"] = CCLuaValue::stringValue(board->getCurrentUserScoreDisplayText());
        
        leaderboards_.push_back(CCLuaValue::dictValue(board_));
    }
    
    CCLuaEngine* engine = CCLuaEngine::defaultEngine();
    engine->cleanStack();
    engine->pushCCLuaValueArray(leaderboards_);
    return 1;
}
#endif

NS_CC_EXT_END
