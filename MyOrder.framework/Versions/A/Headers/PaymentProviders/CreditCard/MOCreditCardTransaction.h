//
//  MOCreditCardTransaction.h
//  MyOrder
//
//  Created by Angel Garcia on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import "MyOrder.h"

/** Credit Card transaction */
@interface MOCreditCardTransaction : MOTransaction

/** Credit card number */
@property (nonatomic, copy) NSString *creditcardNumber;

/** Credit card date */
@property (nonatomic, copy) NSString *creditcardDate;

/** Credit card CVC */
@property (nonatomic, copy) NSString *creditcardCvc;

/** Bool number indicating if should save the credit card */
@property (nonatomic, strong) NSNumber *saveAlias;

/** String indicating the last saved alias laoded with loadSavedAliasOnSuccess:error: */
@property (nonatomic, copy) NSString *savedAlias;


/** Load a previously saved card
 @param block Success block
 @param errorBlock Error block
 */
- (void)loadSavedAliasOnSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;


@end
