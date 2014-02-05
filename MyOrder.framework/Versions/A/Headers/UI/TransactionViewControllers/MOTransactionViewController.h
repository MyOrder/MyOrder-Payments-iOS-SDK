//
//  MOTransactionViewController.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/29/13.
//
//

#import <UIKit/UIKit.h>
#import "MOTransactionView.h"
#import "MyOrder.h"
#import "MOOrder.h"
#import "MOViewController.h"

@interface MOTransactionViewController : MOViewController

@property (nonatomic, strong) MOTransactionView *view;

@property (nonatomic, strong, readonly) MOTransaction *transaction;

@property (nonatomic, copy) void (^completionBlock)(MOTransactionViewController *controller);
@property (nonatomic, copy) void (^errorBlock)(MOTransactionViewController *controller, NSError *error);

- (NSString *)providerName;

- (void)startProcess;
- (void)startProcessFillWallet;
- (void)startProcessPlaceOrder;

// private
- (void)willStartTransaction;
- (void)confirmTransaction;
- (void)finishedTransaction;
- (void)finishedTransactionWithError:(NSError *)error;

- (void)startInNavigationController:(UINavigationController *)navController;


@end
