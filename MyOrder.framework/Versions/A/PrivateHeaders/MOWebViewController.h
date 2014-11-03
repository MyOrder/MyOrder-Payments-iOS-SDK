//
//  MOWebViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 03/07/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import "MOViewController.h"

@interface MOWebViewController : MOViewController

@property (nonatomic, strong) NSURL *URL;
@property (nonatomic, copy) void (^completionBlock)(MOWebViewController *controller);
@property (nonatomic, copy) void (^errorBlock)(MOWebViewController *controller, NSError *error);
@property (nonatomic, assign) BOOL useHTMLTitle;

@end
