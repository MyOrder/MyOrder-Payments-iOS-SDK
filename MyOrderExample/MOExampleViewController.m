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
#import "MOIdealTransaction.h"


@interface MOExampleViewController () <UITextFieldDelegate>

@property (strong, nonatomic) IBOutlet UIView *formView;
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

#pragma mark - IBActions shown in example

//Perform login manually
- (IBAction)loginAction:(id)sender {    
    MOLoginViewController *loginVC = [[MOLoginViewController alloc] init];
    [self.navigationController pushViewController:loginVC animated:YES];
}


//Logout
- (IBAction)logoutAction:(id)sender {
    [MOProgressHUD show];
    [[MyOrder shared] logoutOnSuccess:^{
        [MOProgressHUD dismiss];
        [self configureButtons];
    } error:^(NSError *error){
        [MOProgressHUD showError:error];
    }];
}

//Register view
- (IBAction)registerAction:(id)sender {
    UIViewController *vc = [[MORegisterViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}

//Show wallet
- (IBAction)walletAction:(id)sender {
    UIViewController *vc = [[MyOrder shared] walletViewControllerWithLogin:self.forceLoginSwitch.isOn];
    [self.navigationController pushViewController:vc animated:YES];
}


//Generic order action
- (IBAction)orderAction:(id)sender {
    //Create the order
    MOOrder *order = [MOOrder new];
    order.externalOrderId = @"123456";
    [order addItemWithName:@"MyOrder demo item" price:2.25 quantity:2];
    
    //Generic way to start payments
    UIViewController *vc = [[MyOrder shared] paymentViewControllerForOrder:order forceLogin:self.forceLoginSwitch.isOn onCompletion:^{
        [self.navigationController popToRootViewControllerAnimated:YES];
    }];
    [self.navigationController pushViewController:vc animated:YES];
}

//Custom order for a specific provider
- (IBAction)orderIdealAction:(id)sender {
    
    //Create the order
    MOOrder *order = [MOOrder new];
    order.externalOrderId = @"123456";
    [order addItemWithName:@"MyOrder ideal payment" price:2.25 quantity:2];
    
    //Custom way to start a particular payment and add blocks
    MOTransactionViewController *transactionVC = [[MyOrder shared] transactionViewControllerForProvider:[MOIdealTransaction providerName]];
    transactionVC.transaction.order = order;
    transactionVC.requiresLogin = YES;
    
    //Optional: Custom logic to control whether the transaction is ready
    transactionVC.startBlock = ^(MOTransactionViewController *vc) {
        return YES;
    };
    
    //Optional: Custom logic when transaction finishes
    transactionVC.completionBlock = ^(MOTransactionViewController *vc) {
        [[[UIAlertView alloc] initWithTitle:@"" message:@"Completed" delegate:nil cancelButtonTitle:@"close" otherButtonTitles:nil] show];
        [vc.navigationController popToRootViewControllerAnimated:YES];
    };
    
    //Optional: Custom logic when transaction is canceled
    transactionVC.cancelBlock = ^(MOTransactionViewController *vc) {
        [[[UIAlertView alloc] initWithTitle:@"" message:@"Canceled" delegate:nil cancelButtonTitle:@"close" otherButtonTitles:nil] show];
        [vc.navigationController popToRootViewControllerAnimated:YES];
    };

    //Optional: Custom logic when transaction fails
    transactionVC.errorBlock = ^(MOTransactionViewController *vc, NSError *error) {
        [[[UIAlertView alloc] initWithTitle:@"Error" message:[error localizedDescription] delegate:nil cancelButtonTitle:@"close" otherButtonTitles:nil] show];
        [vc.navigationController popToRootViewControllerAnimated:YES];
    };
    
    //Present the controller in the navigation stack (if needed, because some will not require to be presented)
    [transactionVC startInNavigationController:self.navigationController];
}

//Open receipts view
- (IBAction)receiptsAction:(id)sender {
    UIViewController *vc = [[MyOrder shared] receiptsViewController];
    [self.navigationController pushViewController:vc animated:YES];
}

//Chaneg colors to other random ones
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

#pragma mark - Other Helpers

- (void)configureButtons {
    MyOrder *myOrder = [MyOrder shared];
    self.loginButton.hidden = myOrder.isLoggedIn;
    self.registerButton.hidden = myOrder.isLoggedIn;
    self.logoutButton.hidden = !myOrder.isLoggedIn;
}

@end
