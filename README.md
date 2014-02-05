MyOrder-Payments-iOS-SDK
========================

Public iOS framework for the MyOrder payments SDK

## Installation guide

The iOS SDK is delivered as a compiled framework. It can be installed by manually adding the framework and its dependencies to your project or by the use of CocoaPods.


### Cocoapods installation

Add the following to your Podfile
```
pod "MyOrder"
```

and run `pod install` in your project.


### Manual installation

Download the iOS SDK and drag and drop the `MyOrder.framework` folder into your project and make sure that the copy option is marked

Additionally, make sure that the following third party dependencies are included in your project:

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
```

Please, note that you will need your own `apiKey` and `apiSecret`.

Additionally, you can customize other MyOrder properties depending on your project needs:

* `environment`: use `MyOrderEnvironmentLive` for real money operations or `MyOrderEnvironmentSandbox` for testing purposes.
* `defaultMerchantDescription`: Customize the description that some services like iDeal will show in the bank description receipt.
* Available payment providers can be changed by using the configureWithPaymentProviders method. Example:
```
[myOrder configureWithPaymentProviders:@[@"iDeal", @"MiniTix"]];
```


### Present the wallet

Wallet can be presented by the use of `walletViewControllerWithLogin` method. Example:

```
UIViewController *vc = [[MyOrder shared] walletViewControllerWithLogin:YES];
[self.navigationController pushViewController:vc animated:YES];    
```

Note that if login is required but the user is not logged in yet, then the SDK will return a Login UI controller instead of the wallet one, and will automatically redirect to the wallet when login is performed by changing the `navigationController` stack.


### Make a payment

Payments can be easily performed by using the `paymentViewControllerForOrder` method. Note that you need to create a `MOOrder` with the order information. Example:

```
MOOrder *order = [MOOrder new];
order.externalOrderId = @"12345";
[order addItemWithName:@"MyOrder demo item" price:5.5 quantity:2];
    
UIViewController *vc = [[MyOrder shared] paymentViewControllerForOrder:order forceLogin:YES onCompletion:nil];
[self.navigationController pushViewController:vc animated:YES];
```

Similarly to the wallet method, making a payment does not necessarily require login. However, If the user is not logged in, some payment methods will not be presented. If login is required, then this method could potentially return a controller for login in, already set up for continuing with the payment when successfully logged in.


### Customize UI appearance

MyOrder comes with a set of appearance methods to customize the UI according to your app main color schemas and fonts. You can find them in the `UIColor+MOAppearance.h` and `UIFont+MOAppearance.h` files. Example:

```
[UIColor MO_setBackgroundColor:[UIColor brownColor]];
[UIFont MO_setRegularFontName:@"Arial"];
```



## Final notes

This guide presents some of the most useful and common integration methods. However, the SDK comes with many other options that allow third party developers to make advanced integrations where the UI can be fully customized, new payment methods can be added, etc.
Please, check the API documentation to get more details of all options available

