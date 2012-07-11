
#import <StoreKit/StoreKit.h>
#import "ASIHTTPRequest.h"
#import "CCStoreReceiptVerifyRequest_objc.h"

#include "CCStore.h"
#include "CCStoreProductsRequestDelegate.h"

using namespace extensions;

@interface CCStore_objc : NSObject < SKPaymentTransactionObserver, SKProductsRequestDelegate >
{
    CCStoreIsSandbox isSandbox_;
    CCStoreReceiptVerifyMode receiptVerifyMode_;
    NSString *receiptVerifyServerUrl_;

    CCStoreTransactionObserver *transactionObserver_;
    CCStoreProductsRequestDelegate *productRequestDelegate_;
    NSMutableDictionary *loadedProducts_;
    SKProductsRequest *productRequest_;
}

@property (nonatomic, assign) CCStoreIsSandbox isSandbox;
@property (nonatomic, assign) CCStoreReceiptVerifyMode receiptVerifyMode;
@property (nonatomic, retain) NSString *receiptVerifyServerUrl;

#pragma mark -
#pragma mark init

+ (CCStore_objc *)sharedStore;
+ (void)purgeSharedStore;
- (id)init;
- (void)postInitWithTransactionObserver:(CCStoreTransactionObserver *)observer;

#pragma mark -
#pragma mark Making a Purchase

- (BOOL)canMakePurchases;
- (void)purchase:(SKProduct *)product;
- (void)finishTransaction:(SKPaymentTransaction *)transaction;

#pragma mark -
#pragma mark Retrieving Product Information

- (void)requestProductData:(NSSet *)productsId andDelegate:(CCStoreProductsRequestDelegate *)delegate;
- (void)cancelRequestProductData;
- (BOOL)isProductLoaded:(NSString *)productId;
- (SKProduct *)getProduct:(NSString *)productId;
- (void)cleanCachedProducts;

- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response;
- (void)request:(SKRequest *)request didFailWithError:(NSError *)error;

#pragma mark -
#pragma mark Handling Transactions

- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions;
- (void)transactionCompleted:(SKPaymentTransaction *)transaction andReceiptVerifyStatus:(int)receiptVerifyStatus;
- (void)transactionFailed:(SKPaymentTransaction *)transaction andReceiptVerifyStatus:(int)receiptVerifyStatus;
- (void)transactionRestored:(SKPaymentTransaction *)transaction andReceiptVerifyStatus:(int)receiptVerifyStatus;

#pragma mark -
#pragma mark Verifying Store Receipts

- (void)verifyTransactionReceipt:(SKPaymentTransaction *)transaction;

/* ASIHTTPRequestDelegate */
- (void)requestFinished:(CCStoreReceiptVerifyRequest_objc *)request;
- (void)requestFailed:(CCStoreReceiptVerifyRequest_objc *)request;

#pragma mark -
#pragma mark helper

- (CCStorePaymentTransaction *)createCCStorePaymentTransaction:(SKPaymentTransaction *)transaction
                                        andReceiptVerifyStatus:(int)receiptVerifyStatus;

@end
