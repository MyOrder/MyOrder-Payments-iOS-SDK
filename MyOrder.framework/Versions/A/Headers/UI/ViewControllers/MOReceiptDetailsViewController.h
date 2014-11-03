//
//  MOReceiptDetailsViewController.h
//  MyOrder
//
//  Created by Taras Kalapun on 6/10/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MOViewController.h"
@class MOReceipt;

@interface MOReceiptDetailsViewController : MOViewController <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, strong) IBOutlet UITableView *view;
@property (nonatomic, strong) MOReceipt *receipt;

//Override if custom header wanted
- (UIView *)tableHeaderViewForTable:(UITableView *)tableView;

@end
