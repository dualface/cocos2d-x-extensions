
#import "CCOpenFeint.h"
#import "CCOpenFeint_objc.h"
#import "OpenFeint/OFAchievement.h"
#import "OpenFeint/OFLeaderboard.h"

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
    CCArray* arr = CCArray::arrayWithCapacity([achievements count]);
    
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
    CCArray* arr = CCArray::arrayWithCapacity([leaderboards count]);
    
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
    CCScriptValueArray achievements_;
    
    for (int i = 0; i < achievements->count(); ++i)
    {
        CCOFAchievement* ach = static_cast<CCOFAchievement*>(achievements->objectAtIndex(i));
        CCScriptValueDict ach_;
        
        ach_["id"] = CCScriptValue::stringValue(ach->getId());
        ach_["title"] = CCScriptValue::stringValue(ach->getTitle());
        ach_["description"] = CCScriptValue::stringValue(ach->getDescription());
        ach_["iconUrl"] = CCScriptValue::stringValue(ach->getIconUrl());
        ach_["gameScore"] = CCScriptValue::intValue(ach->getGameScore());
        ach_["isUnlocked"] = CCScriptValue::booleanValue(ach->getIsUnlocked());
        ach_["isSecret"] = CCScriptValue::booleanValue(ach->getIsSecret());
        
        achievements_.push_back(CCScriptValue::dictValue(ach_));
    }
    
    CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();
    engine->cleanLuaStack();
    engine->pushCCScriptValueArrayToLuaStack(achievements_);
    return 1;
}

LUA_TABLE CCOpenFeint::getLeaderboardsLua(void)
{
    CCArray* leaderboards = getLeaderboards();
    CCScriptValueArray leaderboards_;
    
    for (int i = 0; i < leaderboards->count(); ++i)
    {
        CCOFLeaderboard* board = static_cast<CCOFLeaderboard*>(leaderboards->objectAtIndex(i));
        CCScriptValueDict board_;
        
        board_["id"] = CCScriptValue::stringValue(board->getId());
        board_["name"] = CCScriptValue::stringValue(board->getName());
        board_["descendingScoreOrder"] = CCScriptValue::booleanValue(board->getDescendingScoreOrder());
        board_["currentUserScore"] = CCScriptValue::intValue(board->getCurrentUserScore());
        board_["currentUserScoreDisplayText"] = CCScriptValue::stringValue(board->getCurrentUserScoreDisplayText());
        
        leaderboards_.push_back(CCScriptValue::dictValue(board_));
    }
    
    CCScriptEngineProtocol* engine = CCScriptEngineManager::sharedManager()->getScriptEngine();
    engine->cleanLuaStack();
    engine->pushCCScriptValueArrayToLuaStack(leaderboards_);
    return 1;
}
#endif

NS_CC_EXT_END
