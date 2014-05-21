//
//  MOPayYourFriendsOperationViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 01/04/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "MOViewController.h"
#import "MOPayYourFriendsOperation.h"

@interface MOPayYourFriendsOperationViewController : MOViewController

@property (nonatomic, copy) void (^completionBlock)(MOPayYourFriendsOperationViewController *controller);
@property (nonatomic, copy) void (^errorBlock)(MOPayYourFriendsOperationViewController *controller, NSError *error);
@property (nonatomic, strong) MOPayYourFriendsOperation *operation;

@end
