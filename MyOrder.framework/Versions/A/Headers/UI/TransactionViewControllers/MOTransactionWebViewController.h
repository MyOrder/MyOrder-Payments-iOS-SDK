//
//  MOTransactionWebViewController.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/30/13.
//
//

#import <UIKit/UIKit.h>

@interface MOTransactionWebViewController : UIViewController <UIWebViewDelegate>

@property (nonatomic, strong) UIWebView *webView;
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *callbackUrl;


//TODO: Or delegates would be better?
@property (nonatomic, copy) void (^completionBlock)(MOTransactionWebViewController *controller, NSDictionary *responseParams);

@end
