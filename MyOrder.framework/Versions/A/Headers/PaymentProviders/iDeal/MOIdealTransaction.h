//
//  MOIdealTransaction.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/23/13.
//
//

#import "MOTransaction.h"

/** iDeal transaction */
@interface MOIdealTransaction : MOTransaction

/** Selected Issuer Id */
@property (nonatomic, strong) NSString *issuerId;

/** Bool number indicating if is ment to be an order or a wallet operation */
@property (nonatomic, strong) NSNumber *isOrder;

/** Return url to use on the external party service as callback */
@property (nonatomic, strong) NSString *returnUrl;

/** Issuer url to open for confirm the transaction */
@property (nonatomic, strong) NSString *issuerUrl;

/** Transaction ID */
@property (nonatomic, strong) NSString *transactionId;

/** List of issuers */
@property (nonatomic, strong) NSArray *issuers;

/** Number of minutes to expire the iDeal transaction */
@property (nonatomic, strong) NSNumber *expirationMinutes;

/** Dictionary with payment parameters retrieved from iDeal */
@property (nonatomic, strong) NSDictionary *paymentParams;

/** Load all available issuers
 @param block Success block
 @param errorBlock Error block
 */
- (void)loadIssuersOnSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;


@end
