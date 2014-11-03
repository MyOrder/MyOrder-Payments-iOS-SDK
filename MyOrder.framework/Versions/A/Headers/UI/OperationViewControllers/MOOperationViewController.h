//
//  MOOperationViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 02/06/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import "MOViewController.h"
#import "MOPaymentOperation.h"

@interface MOOperationViewController : MOViewController

/**
 Operation attached to this controller
 */
@property (nonatomic, strong) MOPaymentOperation *operation;

/**
 Block called when the operations is completed successfully
 */
@property (nonatomic, copy) void (^completionBlock)(MOOperationViewController *controller);

/**
 Block called when the operation failed. Includes error.
 */
@property (nonatomic, copy) void (^errorBlock)(MOOperationViewController *controller, NSError *error);


/**
 Injects the controller in the navigation passed.
 @param navController Navigation controller to inject the controller in
 */
- (void)startInNavigationController:(UINavigationController *)navController;


@end
