//
//  MOViewController.m
//  MyOrder
//
//  Created by Taras Kalapun on 5/22/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import "MOExampleViewController.h"
#import "MOLoginViewController.h"
#import "MyOrder.h"
#import "MOProgressHUD.h"
#import "MORegisterViewController.h"
#import "MOTransactionViewController.h"
#import "MOOrder.h"
#import "UIColor+MOAppearance.h"
#import "MOProvidersViewController.h"

//#define paymentType @"iDeal"

@interface MOExampleViewController () <UITextFieldDelegate>

@property (strong, nonatomic) IBOutlet UIView *formView;
@property (strong, nonatomic) IBOutlet UIButton *autoLoginButton;
@property (strong, nonatomic) IBOutlet UIButton *loginButton;
@property (strong, nonatomic) IBOutlet UIButton *registerButton;
@property (strong, nonatomic) IBOutlet UIButton *logoutButton;
@property (strong, nonatomic) IBOutlet UISwitch *forceLoginSwitch;

@end

@implementation MOExampleViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.title = @"Test Menu";
    ((UIScrollView *)self.view).contentSize = CGSizeMake(CGRectGetMaxX(self.formView.frame), CGRectGetMaxY(self.formView.frame));
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self configureButtons];
}

- (IBAction)loginAction:(id)sender {    
    MOLoginViewController *loginVC = [[MOLoginViewController alloc] init];
    loginVC.allowAutomaticLogin = NO;
    [self.navigationController pushViewController:loginVC animated:YES];
}


- (IBAction)autoLoginAction:(id)sender {
    [MOProgressHUD show];
    [[MyOrder shared] loginOnSuccess:^{
        [MOProgressHUD dismiss];
        [self configureButtons];
    } error:^(NSError *error){
        [MOProgressHUD showError:error];
        [self configureButtons];
    }];
}

- (IBAction)registerAction:(id)sender {
    UIViewController *vc = [[MORegisterViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

- (IBAction)walletAction:(id)sender {
    UIViewController *vc = [[MyOrder shared] walletViewControllerWithLogin:self.forceLoginSwitch.isOn];
    [self.navigationController pushViewController:vc animated:YES];    
}

- (IBAction)orderAction:(id)sender {
    MOOrder *order = [MOOrder new];
    order.externalOrderId = @"123456";
    [order addItemWithName:@"MyOrder demo item" price:2.25 quantity:2];
    
#ifndef paymentType
    //Generic way to start payments
    UIViewController *vc = [[MyOrder shared] paymentViewControllerForOrder:order forceLogin:self.forceLoginSwitch.isOn onCompletion:^{
        [self.navigationController popToRootViewControllerAnimated:YES];
    }];
    [self.navigationController pushViewController:vc animated:YES];
    
#else
    //Custom way to start a particular payment and add blocks
    MOTransactionViewController *transactionVC = [[MyOrder shared] transactionViewControllerForProvider:paymentType];
    transactionVC.transaction.order = order;
    transactionVC.startBlock = ^(MOTransactionViewController *vc) {
        //Custom logic to control whether the transaction is ready
        return YES;
    };
    transactionVC.completionBlock = ^(MOTransactionViewController *vc) {
        [[[UIAlertView alloc] initWithTitle:nil message:@"Completed" delegate:nil cancelButtonTitle:@"close" otherButtonTitles:nil] show];
        [vc.navigationController popToRootViewControllerAnimated:YES];
    };
    transactionVC.cancelBlock = ^(MOTransactionViewController *vc) {
        [[[UIAlertView alloc] initWithTitle:nil message:@"Canceled" delegate:nil cancelButtonTitle:@"close" otherButtonTitles:nil] show];
        [vc.navigationController popToRootViewControllerAnimated:YES];
    };
    transactionVC.errorBlock = ^(MOTransactionViewController *vc, NSError *error) {
        [[[UIAlertView alloc] initWithTitle:nil message:@"Error" delegate:nil cancelButtonTitle:@"close" otherButtonTitles:nil] show];
        [vc.navigationController popToRootViewControllerAnimated:YES];
    };
    [transactionVC startInNavigationController:self.navigationController];
#endif
    
}

- (IBAction)receiptsAction:(id)sender {
    UIViewController *vc = [[MyOrder shared] receiptsViewController];
    [self.navigationController pushViewController:vc animated:YES];
}


- (IBAction)walletHistoryAction:(id)sender {
//    [[MyOrder shared] loadWalletHistoryOnSuccess:^(NSDictionary *response) {
//        
//    } error:^(NSError *error) {
//        
//    }];
}

- (IBAction)logoutAction:(id)sender {
    [MOProgressHUD show];
    [[MyOrder shared] logoutOnSuccess:^{
        [MOProgressHUD dismiss];
        [self configureButtons];
    } error:^(NSError *error){
        [MOProgressHUD showError:error];
    }];
}

- (IBAction)colorValueChange:(id)sender {
    if ([sender isOn]) {
        [UIColor MO_setBackgroundColor:[UIColor brownColor]];
        [UIColor MO_setSectionBorderColor:[UIColor blackColor]];
        [UIColor MO_setTextFieldTextColor:[UIColor colorWithRed:0.8 green:0.8 blue:0 alpha:1]];
        [UIColor MO_setTextFieldBackgroundColor:[UIColor colorWithWhite:0.8 alpha:1]];
        [UIColor MO_setTextColor:[UIColor colorWithRed:0.9 green:0.8 blue:0.8 alpha:1]];
        [UIColor MO_setButtonBackgroundColor:[UIColor colorWithWhite:0.8 alpha:1]];
        [UIColor MO_setButtonTextColor:[UIColor blackColor]];
        [UIColor MO_setLinkTextColor:[UIColor orangeColor]];
    }
    else {
        [UIColor MO_setBackgroundColor:nil];
        [UIColor MO_setSectionBorderColor:nil];
        [UIColor MO_setTextFieldTextColor:nil];
        [UIColor MO_setTextFieldBackgroundColor:nil];
        [UIColor MO_setTextColor:nil];
        [UIColor MO_setButtonBackgroundColor:nil];
        [UIColor MO_setButtonTextColor:nil];
        [UIColor MO_setLinkTextColor:nil];
    }
}

- (void)configureButtons {
    MyOrder *myOrder = [MyOrder shared];
    self.autoLoginButton.hidden = myOrder.isLoggedIn;
    self.autoLoginButton.enabled = myOrder.hasSavedCredentials;
    self.loginButton.hidden = myOrder.isLoggedIn;
    self.registerButton.hidden = myOrder.isLoggedIn;
    self.logoutButton.hidden = !myOrder.isLoggedIn;
}

@end
