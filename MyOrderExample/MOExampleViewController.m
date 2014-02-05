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
#import "SVProgressHUD.h"
#import "MORegisterViewController.h"
#import "MOTransactionViewController.h"
#import "MOOrder.h"
#import "UIColor+MOAppearance.h"
#import "SVProgressHUD+MOAppearance.h"
#import "MOProvidersViewController.h"

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
    [SVProgressHUD show];
    [[MyOrder shared] loginOnSuccess:^{
        [SVProgressHUD dismiss];
        [self configureButtons];
    } error:^(NSError *error){
        [SVProgressHUD MO_showError:error];
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
    order.externalOrderId = @"12345";
    [order addItemWithName:@"MyOrder demo item" price:5.5 quantity:2];
    
    UIViewController *vc = [[MyOrder shared] paymentViewControllerForOrder:order forceLogin:self.forceLoginSwitch.isOn onCompletion:^{
        [self.navigationController popToRootViewControllerAnimated:YES];
    }];
    [self.navigationController pushViewController:vc animated:YES];
}

- (IBAction)logoutAction:(id)sender {
    [SVProgressHUD show];
    [[MyOrder shared] logoutOnSuccess:^{
        [SVProgressHUD dismiss];
        [self configureButtons];
    } error:^(NSError *error){
        [SVProgressHUD MO_showError:error];
    }];
}

- (IBAction)colorValueChange:(id)sender {
    if ([sender isOn]) {
        [UIColor MO_setBackgroundColor:[UIColor brownColor]];
        [UIColor MO_setSectionBorderColor:[UIColor blackColor]];
        [UIColor MO_setTextFieldTitleColor:[UIColor colorWithRed:0.8 green:0.8 blue:0 alpha:1]];
        [UIColor MO_setTextColor:[UIColor colorWithRed:0.9 green:0.8 blue:0.8 alpha:1]];
        [UIColor MO_setButtonTextColor:[UIColor redColor]];
        [UIColor MO_setLinkTextColor:[UIColor orangeColor]];
    }
    else {
        [UIColor MO_setBackgroundColor:nil];
        [UIColor MO_setSectionBorderColor:nil];
        [UIColor MO_setTextFieldTitleColor:nil];
        [UIColor MO_setTextColor:nil];
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
