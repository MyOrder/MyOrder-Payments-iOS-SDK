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

/** Issuer url to open for confirm the transaction */
@property (nonatomic, copy) NSString *issuerUrl;

/** Selected Issuer */
@property (nonatomic, strong) NSDictionary *selectedIssuer;

/** List of issuers */
@property (nonatomic, strong) NSArray *issuers;

/** Number of minutes to expire the iDeal transaction */
@property (nonatomic, strong) NSNumber *expirationMinutes;


/** Load all available issuers
 @param block Success block
 @param errorBlock Error block
 */
- (void)loadIssuersOnSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;

/** Returns the default isssuer (last selected issuer)
 @return NSDictionary with issuer information
 */
+ (NSDictionary *)defaultIssuer;


@end
