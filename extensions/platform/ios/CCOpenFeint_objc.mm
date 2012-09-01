
#include "cocos2d.h"

#import "CCOpenFeint_objc.h"

// OpenFeint
#import "OpenFeint/OpenFeint.h"
//#import "OpenFeint/OpenFeint+Dashboard.h"
#import "OpenFeint/include/OFAchievement.h"
#import "OpenFeint/api/Achievement/OFAchievementService.h"
#import "OpenFeint/include/OFChallenge.h"
#import "OpenFeint/include/OFChallengeDefinition.h"
#import "OpenFeint/include/OFChallengeToUser.h"
//#import "OpenFeint/api/Invocation/OFInvocation.h"
#import "OpenFeint/include/OFLeaderboard.h"

@implementation CCOpenFeint_objc

static CCOpenFeint_objc* s_sharedInstance;

+ (CCOpenFeint_objc*)sharedInstance
{
    if (!s_sharedInstance)
    {
        s_sharedInstance = [[CCOpenFeint_objc alloc] init];
    }
    return s_sharedInstance;
}

+ (void)purgeSharedInstance
{
    if (s_sharedInstance)
    {
        [s_sharedInstance release];
        s_sharedInstance = nil;
    }
}

- (void)postInitWithProductKey:(NSString*)productKey
                     andSecret:(NSString*)secret
                andDisplayName:(NSString*)displayName
{
    OFDelegatesContainer* delegates = [OFDelegatesContainer containerWithOpenFeintDelegate:self
                                                                      andChallengeDelegate:self
                                                                   andNotificationDelegate:self];
    
    NSArray* windows = [UIApplication sharedApplication].windows;
    UIWindow* rootWindow = [windows objectAtIndex: [windows count] - 1];
    
    UIInterfaceOrientation orientation = [UIApplication sharedApplication].statusBarOrientation;
    
    NSDictionary* settings = [NSDictionary dictionaryWithObjectsAndKeys:
                              rootWindow,
                              OpenFeintSettingPresentationWindow,
                              
                              [NSNumber numberWithInt: orientation],
                              OpenFeintSettingDashboardOrientation,
                              
							  [NSNumber numberWithBool: YES],
                              OpenFeintSettingEnablePushNotifications,
                              
							  [NSNumber numberWithBool: NO],
                              OpenFeintSettingDisableUserGeneratedContent,
                              
  							  [NSNumber numberWithBool: NO],
                              OpenFeintSettingAlwaysAskForApprovalInDebug,
#ifdef _DEBUG
                              [NSNumber numberWithInt: OFDevelopmentMode_DEVELOPMENT],
                              OpenFeintSettingDevelopmentMode,
#else
                              [NSNumber numberWithInt: OFDevelopmentMode_RELEASE],
                              OpenFeintSettingDevelopmentMode,
#endif
							  nil
							  ];
    
    [OpenFeint initializeWithProductKey: productKey
							  andSecret: secret
						 andDisplayName: displayName
							andSettings: settings
						   andDelegates: delegates];
}

#pragma mark -
#pragma mark interface

- (void)showDashboard
{
    [OpenFeint launchDashboard];
}

- (void)showLeaderboards
{
    [OpenFeint launchDashboardWithListLeaderboardsPage];    
}

- (void)showLeaderboards:(NSString*)leaderboardId
{
    [OpenFeint launchDashboardWithHighscorePage: leaderboardId];
}

- (void)showAchievements
{
    [OpenFeint launchDashboardWithAchievementsPage];
}

- (void)showChallenges
{
    [OpenFeint launchDashboardWithChallengesPage];
}

- (void)showFriends
{
    [OpenFeint launchDashboardWithFindFriendsPage];    
}

- (void)showPlaying
{
    [OpenFeint launchDashboardWithWhosPlayingPage];
}

- (NSArray*)getAchievements
{
    return [OFAchievement achievements];
}

- (void)unlockAchievement:(NSString*)achievementId
{
    [OFAchievementService updateAchievement:achievementId
                         andPercentComplete:100
                        andShowNotification:YES];
}

- (NSArray*)getLeaderboards
{
    return [OFLeaderboard leaderboards];
}

- (void)setHighScore:(NSString*)leaderboardId
            andScore:(NSNumber*)score
      andDisplayText:(NSString*)displayText
{
    OFLeaderboard* board = [OFLeaderboard leaderboard:leaderboardId];
    if (board)
    {
        int64_t scoreValue = [score longLongValue];
        OFHighScore* score = [[[OFHighScore alloc] initForSubmissionWithScore:scoreValue] autorelease];
        score.displayText = displayText;
        [score submitTo: board];
    }
}


#pragma mark -
#pragma mark OpenFeintDelegate

- (void)dashboardWillAppear
{
    CCLOG("[OpenFeint] dashboardWillAppear");
    cocos2d::CCDirector::sharedDirector()->stopAnimation();
    cocos2d::CCDirector::sharedDirector()->pause();
}

- (void)dashboardDidAppear
{
    CCLOG("[OpenFeint] dashboardDidAppear");
}

- (void)dashboardWillDisappear
{
    CCLOG("[OpenFeint] dashboardWillDisappear");
}

- (void)dashboardDidDisappear
{
    CCLOG("[OpenFeint] dashboardDidDisappear");
    cocos2d::CCDirector::sharedDirector()->startAnimation();
    cocos2d::CCDirector::sharedDirector()->resume();
}

- (void)offlineUserLoggedIn:(NSString*)userId
{
	CCLOG("[OpenFeint] User logged in, but OFFLINE. UserId: %s",
                   [userId cStringUsingEncoding:NSUTF8StringEncoding]);
}

- (void)userLoggedIn:(NSString*)userId
{
	CCLOG("[OpenFeint] User logged in. UserId: %s",
                   [userId cStringUsingEncoding:NSUTF8StringEncoding]);
}

- (BOOL)showCustomOpenFeintApprovalScreen
{
    CCLOG("[OpenFeint] showCustomOpenFeintApprovalScreen");
	return NO;
}

#pragma mark -
#pragma mark OFChallengeDelegate

- (void)userLaunchedChallenge:(OFChallengeToUser*)challengeToLaunch withChallengeData:(NSData*)challengeData
{
	CCLOG("[OpenFeint] userLaunchedChallenge: %s",
                   [challengeToLaunch.challenge.challengeDefinition.title cStringUsingEncoding:NSUTF8StringEncoding]);
}

- (void)userRestartedChallenge
{
	CCLOG("[OpenFeint] userRestartedChallenge");
}

#pragma mark -
#pragma mark OFNotificationDelegate

- (BOOL)isOpenFeintNotificationAllowed:(OFNotificationData*)notificationData
{
    CCLOG("[OpenFeint] isOpenFeintNotificationAllowed: %s",
                   [notificationData.notificationText cStringUsingEncoding:NSUTF8StringEncoding]);
	return YES;
}

- (void)handleDisallowedNotification:(OFNotificationData*)notificationData
{
    CCLOG("[OpenFeint] handleDisallowedNotification");
}

- (void)notificationWillShow:(OFNotificationData*)notificationData
{
    CCLOG("[OpenFeint] notificationWillShow: %s",
                   [notificationData.notificationText cStringUsingEncoding:NSUTF8StringEncoding]);
}

@end
