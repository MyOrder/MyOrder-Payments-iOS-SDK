//
//  MOAutomaticChargeOperation.h
//  MyOrder
//
//  Created by Angel Garcia on 06/05/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MOPaymentOperation.h"

/**
 *  Sets automatic charge properties for the MiniTix account. Note that this operation
 *  requires a MiniTix mandate to be approved first before execution
 */
@interface MOAutomaticChargeOperation : MOPaymentOperation

@property (nonatomic, copy) NSString *bankAccount;
@property (nonatomic, assign) BOOL active;
@property (nonatomic, copy) NSString *period;
@property (nonatomic, strong) NSNumber *amount;

@property (readonly) BOOL requiresConfirmation;
@property (readonly) NSString *confirmationRequestId;

@end
