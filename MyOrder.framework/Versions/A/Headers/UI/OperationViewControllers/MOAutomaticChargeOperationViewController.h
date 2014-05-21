//
//  MOAutomaticChargeOperationViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 06/05/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import "MOAutomaticChargeOperation.h"
#import "MOViewController.h"

@interface MOAutomaticChargeOperationViewController : MOViewController

@property (nonatomic, copy) void (^completionBlock)(MOAutomaticChargeOperationViewController *controller);
@property (nonatomic, copy) void (^errorBlock)(MOAutomaticChargeOperationViewController *controller, NSError *error);
@property (nonatomic, strong) MOAutomaticChargeOperation *operation;

@end
