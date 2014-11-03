//
//  MOPaymentOperation.h
//  MyOrder
//
//  Created by Angel Garcia on 24/04/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MOPaymentOperation;

/**
 Consts used for the payment option info key
 */
extern const NSString *MOPaymentOperationName;
extern const NSString *MOPaymentOperationDescription;
extern const NSString *MOPaymentOperationCanBeOpen;
extern const NSString *MOPaymentOperationAllowsWalletOperation;
extern const NSString *MOPaymentOperationAllowsOrderOperation;
extern const NSString *MOPaymentOperationPriority;

typedef void(^MOOperationBlock)(MOPaymentOperation *operation, id response);
typedef void(^MOOperationErrorBlock)(MOPaymentOperation *operation, NSError *error);


/**
 *  Payment operations are extra actions a user can perform in his wallet. For example, setting autoloading properties
 *  or transfering money to a friend. The MyOrder engine will automatically look for any subclass of MOPaymentOperation 
 *  during startup. Note that the nature of the payment operations is very concrete to each individual case, so custom 
 *  actions will be required on each case to complete them. Check the particular subclasses for more information
 */
@interface MOPaymentOperation : NSObject

/**
 Returns the payment option info dictionary
 @return dictionary with option information (name, description, allows wallet,...)
 */
+ (NSDictionary *)info;

/**
 Returns the operation name
 @return string with provider name (ex: PayYourFriends)
 */
+ (NSString *)operationName;


/**
 Start the operation
 @param completionBlock Block that will be called on success
 @param errorBlock Block called on error
 */
- (void)executeOnCompletion:(MOOperationBlock)completionBlock onError:(MOOperationErrorBlock)errorBlock;


@end