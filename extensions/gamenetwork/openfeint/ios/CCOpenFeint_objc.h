
#import "OpenFeintDelegate.h"
#import "OFNotificationDelegate.h"
#import "OFChallengeDelegate.h"

@class GameOFNotificationDelegate;

@interface CCOpenFeint_objc : NSObject < OpenFeintDelegate, OFChallengeDelegate, OFNotificationDelegate >
{
}

+ (CCOpenFeint_objc*)sharedInstance;
- (void)postInitWithProductKey:(NSString*)productKey
                     andSecret:(NSString*)secret
                andDisplayName:(NSString*)displayName;

#pragma mark -
#pragma mark interface

- (void)showDashboard;
- (void)showLeaderboards;
- (void)showLeaderboards:(NSString*)leaderboardId;
- (void)showAchievements;
- (void)showChallenges;
- (void)showFriends;
- (void)showPlaying;

- (NSArray*)getAchievements;
- (void)unlockAchievement:(NSString*)achievementId;

- (NSArray*)getLeaderboards;
- (void)setHighScore:(NSString*)leaderboardId
            andScore:(NSNumber*)score
      andDisplayText:(NSString*)displayText;


#pragma mark -
#pragma mark OpenFeintDelegate

- (void)dashboardWillAppear;
- (void)dashboardDidAppear;
- (void)dashboardWillDisappear;
- (void)dashboardDidDisappear;
- (void)userLoggedIn:(NSString*)userId;
- (BOOL)showCustomOpenFeintApprovalScreen;

#pragma mark -
#pragma mark OFChallengeDelegate

- (void)userLaunchedChallenge:(OFChallengeToUser*)challengeToLaunch withChallengeData:(NSData*)challengeData;
- (void)userRestartedChallenge;

#pragma mark -
#pragma mark OFNotificationDelegate

- (BOOL)isOpenFeintNotificationAllowed:(OFNotificationData*)notificationData;
- (void)handleDisallowedNotification:(OFNotificationData*)notificationData;
- (void)notificationWillShow:(OFNotificationData*)notificationData;

@end
