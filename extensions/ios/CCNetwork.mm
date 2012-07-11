
#include "CCScriptSupport.h"
#include "CCNetwork.h"

#import "ASIHTTPRequest.h"
#import "Reachability_objc.h"

using namespace cocos2d;

namespace extensions {
    
#pragma mark -
#pragma mark Reachability
    
    bool CCNetwork::isLocalWiFiAvailable(void)
    {
        return [[Reachability_objc reachabilityForLocalWiFi] currentReachabilityStatus] != NotReachable;
    }
    
    bool CCNetwork::isInternetConnectionAvailable(void)
    {
        return [[Reachability_objc reachabilityForInternetConnection] currentReachabilityStatus] != NotReachable;
    }
    
    bool CCNetwork::isHostNameReachable(const char* hostName)
    {
        NSString *hostName_ = [NSString stringWithUTF8String:hostName];
        return [[Reachability_objc reachabilityWithHostName:hostName_] currentReachabilityStatus] != NotReachable;
    }
    
    CCNetworkStatus CCNetwork::getInternetConnectionStatus(void)
    {
        NetworkStatus status = [[Reachability_objc reachabilityForInternetConnection] currentReachabilityStatus];
        if (status == ReachableViaWiFi) return CCNetworkStatusReachableViaWiFi;
        if (status == ReachableViaWWAN) return CCNetworkStatusReachableViaWWAN;
        return CCNetworkStatusNotReachable;
    }
    
}
