MyOrder-Payments-iOS-SDK
========================

Public iOS framework for the [MyOrder payments SDK](http://myorder.nl/sdk). Check the online [API documentation here](http://htmlpreview.github.io/?https://github.com/MyOrder/MyOrder-Payments-iOS-SDK/blob/master/docs/html/index.html)

## Installation guide

The iOS SDK is delivered as a compiled framework. It can be installed by manually adding the framework and its dependencies to your project or by the use of CocoaPods.


### Cocoapods installation

Add the following to your Podfile
```
pod "MyOrder"
```

and optionally (if PayPal or CreditCard options in use)

```
pod 'PayPalMPL'
pod 'CardIO'
```

And run `pod install` in your project.


### Manual installation

CocoaPods is preferred as it is lot easier to install. However if you prefer a manual installation then do:

1. Download the iOS SDK, drag and drop the `MyOrder.framework` folder into your Frameworks project group and make sure that the copy option is marked.
2. Open your project Build Settings, look for "Header Search Paths" and add "${SRCROOT}/MyOrder.framework" recursive.
3. Add the MyOrder.bundle folder contained inside the MyOrder.framework into your project tree.

Additionally, make sure that the following Apple frameworks are included in your project: 

* `AddressBook` (Required)
* `AddressBookUI` (Required)
* `Security` (Required)

And these third party dependencies:

* [SVProgressHUD](https://github.com/samvermette/SVProgressHUD) (Required)
* [TPKeyboardAvoiding](https://github.com/michaeltyson/TPKeyboardAvoiding) (Required)
* [PayPalMPL](https://developer.paypal.com/webapps/developer/docs/classic/mobile/gs_MPL/) (Only required when PayPal is used as a payment method)
* [CardIO](https://www.card.io/) (Optional, adds a camera card reader to the credit card payments)

Instructions on how to install the previous libraries can be found in their webpages.


## Project setup

### Configure the SDK

Before using the MyOrderSDK, you need to set up the credentials. You can do it by placing the following code before its use (typically in your `AppDelegate application:didFinishLaunchingWithOptions` method):

```
    MyOrder *myOrder = [MyOrder shared];
    myOrder.apiKey = @"d712d563-d5ed-4826-8920-1b2c2b743ba9";
    myOrder.apiSecret = @"hH3#1PxxS";
    myOrder.URLScheme = @"myapp-scheme";
```

Please, note that you will need your own `apiKey` and `apiSecret`. You can get request them on the [Official MyOrder developers portal](http://myorder.nl/sdk). 

Your URL Scheme is used to open the app after an iDeal transaction has been made, and therefore it is required when iDeal is active. Set a URL Type in your project Info settings and use the same for the lib `URLScheme`, and implement this method in your delegate:

```
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    return [[MyOrder shared] handleURL:url];
}
```

Additionally, you can customize other MyOrder properties depending on your project needs:

* `environment`: use `MyOrderEnvironmentLive` for real money operations or `MyOrderEnvironmentSandbox` for testing purposes.
* `defaultMerchantDescription`: Customize the description that some services like iDeal will show in the bank description receipt.
* Available payment providers can be changed by using the `configureWithPaymentProviders` method. Example:
```
[myOrder configureWithPaymentProviders:@[@"iDeal", @"MiniTix"]];
```
* Available payment operations can be changed by using the `configureWithPaymentOperations` method. Example:
```
[myOrder configureWithPaymentOperations:@[@"PayYourFriends", @"AutomaticCharge"]];
```

### Present the wallet

Wallet can be presented by the use of `walletViewControllerWithLogin` method. Example:

```
UIViewController *vc = [[MyOrder shared] walletViewControllerWithLogin:YES];
[self.navigationController pushViewController:vc animated:YES];    
```

Note that if login is required but the user is not logged in yet, then the SDK will return a Login UI controller instead of the wallet one, and will automatically redirect to the wallet when login is performed by changing the `navigationController` stack.


### Present payment screen with list of methods

Payments can be easily performed by using the `paymentViewControllerForOrder` method. Note that you need to create a `MOOrder` with the order information. Example:

```
MOOrder *order = [MOOrder new];
order.externalOrderId = @"12345";
[order addItemWithName:@"MyOrder demo item" price:5.5 quantity:2];
    
UIViewController *vc = [[MyOrder shared] paymentViewControllerForOrder:order forceLogin:YES onCompletion:nil];
[self.navigationController pushViewController:vc animated:YES];
```

Similarly to the wallet method, making a payment does not necessarily require login. However, If the user is not logged in, some payment methods will not be presented. If login is required, then this method could potentially return a controller for login in, already set up for continuing with the payment when successfully logged in.

### Make a payment with a specific payment method

If you know which payment method to use (for example if you customize the UI for selecting payments in your app), then you can open an specific payment method screen by using:

```
//Custom way to start a particular payment and add blocks
MOTransactionViewController *transactionVC = [[MyOrder shared] transactionViewControllerForProvider:@"iDeal"];
transactionVC.transaction.order = order;
[transactionVC startInNavigationController:self.navigationController];
```

Additionally, this way gives you some extra blocks to perform custom actions when the transaction has an error, is completed or started. Example:

```
    transactionVC.startBlock = ^(MOTransactionViewController *vc) {
        //Custom logic to control whether the transaction is ready. Return YES to allow start
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
```

Note that if you use the library this way you need to be sure the user is logged in properly for those methods that require a login. You can do that by using the login methods in 'MyOrder` class or by creating a `MOLoginViewController` controller. And example is provided in the Example project.


### Customize UI appearance

MyOrder comes with a set of appearance methods to customize the UI according to your app main color schemas and fonts. You can find them in the `UIColor+MOAppearance.h` and `UIFont+MOAppearance.h` files. Example:

```
[UIColor MO_setBackgroundColor:[UIColor brownColor]];
[UIFont MO_setRegularFontName:@"Arial"];
```



## Final notes

This guide presents some of the most useful and common integration methods. However, the SDK comes with many other options that allow third party developers to make advanced integrations where the UI can be fully customized, new payment methods can be added, etc.
Please, check the [API documentation](http://htmlpreview.github.io/?https://github.com/MyOrder/MyOrder-Payments-iOS-SDK/blob/master/docs/html/index.html) to get more details of all options available

