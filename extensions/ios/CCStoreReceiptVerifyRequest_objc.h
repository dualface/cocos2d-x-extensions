
#import <StoreKit/StoreKit.h>
#import "ASIHTTPRequest.h"

@interface CCStoreReceiptVerifyRequest_objc : ASIHTTPRequest
{
	NSString *productIdentifier_;
    SKPaymentTransaction *transaction_;
}

@property (nonatomic, retain) NSString *productIdentifier;
@property (nonatomic, retain) SKPaymentTransaction *transaction;

@end
