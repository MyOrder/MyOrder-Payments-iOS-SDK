//
//  MOHistoryViewController.h
//  MyOrder
//
//  Created by Taras Kalapun on 6/6/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MOViewController.h"

@interface MOHistoryViewController : MOViewController

@property (nonatomic, assign, getter = isWalletHistory, readonly) BOOL walletHistory;


@end