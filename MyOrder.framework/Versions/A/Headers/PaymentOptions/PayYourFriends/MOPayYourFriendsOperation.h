//
//  MOPayYourFriendsOperation.h
//  MyOrder
//
//  Created by Angel Garcia on 24/04/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import "MOPaymentOperation.h"


typedef enum {
    MOPayYourFriendsOperationStatusCodeComplete = 1,
    MOPayYourFriendsOperationStatusCodeStarted = 2,
    MOPayYourFriendsOperationStatusCodeConfirmed = 3
} MOPayYourFriendsOperationStatus;

/**
 *  Makes a payment to a friend. This operation requires confirmation of SMS code
 */
@interface MOPayYourFriendsOperation : MOPaymentOperation

@property (nonatomic, copy) NSString *mobileNumber;
@property (nonatomic, assign) CGFloat amount;
@property (nonatomic, copy) NSString *details;

@property (nonatomic, assign, readonly) MOPayYourFriendsOperationStatus status;

/**
 *  Finishes the operation by confirming the action with the SMS code received
 *
 *  @param code            SMS code
 *  @param completionBlock Completion block called on success
 *  @param errorBlock      Error block if fails
 */
- (void)completeWithCode:(NSString *)code onCompletion:(MOOperationBlock)completionBlock onError:(MOOperationErrorBlock)errorBlock;

@end
