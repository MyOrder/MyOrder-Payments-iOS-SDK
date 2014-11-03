//
//  MOReceiptsViewController.h
//  MyOrder
//
//  Created by Taras Kalapun on 6/6/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MOViewController.h"

@interface MOReceiptsViewController : MOViewController <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) NSArray *receipts;

@property (nonatomic, strong) IBOutlet UITableView *tableView;
@property (nonatomic, strong) IBOutlet UIRefreshControl *refreshControl;

@end
