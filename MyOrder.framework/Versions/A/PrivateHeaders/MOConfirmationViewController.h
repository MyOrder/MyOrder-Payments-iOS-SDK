//
//  MOConfirmationViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 5/31/13.
//
//

#import <UIKit/UIKit.h>

@interface MOConfirmationViewController : UIViewController

@property(nonatomic, copy) NSString *header;
@property(nonatomic, copy) NSString *fieldName;

@property (nonatomic, copy) void (^completionBlock)(MOConfirmationViewController *controller, NSString *confirmationValue);

@end
