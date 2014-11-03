//
//  MOWithdrawFromWalletOperation.h
//  MyOrder
//
//  Created by Angel Vasa on 7/10/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <MyOrder/MyOrder.h>

typedef enum {
    MOWithdrawFromWalletStatusCodeComplete = 1,
    MOWithdrawFromWalletStatusCodeStarted = 2,
    MOWithdrawFromWalletStatusCodeConfirmed = 3
} MOWithdrawFromWalletStatus;


/**
 *  Performs a wallet withdraw to return money to the user's bank account. This operation requires confirmation of SMS code
 */
@interface MOWithdrawFromWalletOperation : MOPaymentOperation

@property (nonatomic, assign, readonly) MOWithdrawFromWalletStatus status;
@property (atomic, assign) CGFloat amount;

/**
 *  Finishes the operation by confirming the action with the SMS code received
 *
 *  @param code            SMS code
 *  @param completionBlock Completion block called on success
 *  @param errorBlock      Error block if fails
 */
- (void)completeWithCode:(NSString *)code onCompletion:(MOOperationBlock)completionBlock onError:(MOOperationErrorBlock)errorBlock;

@end
