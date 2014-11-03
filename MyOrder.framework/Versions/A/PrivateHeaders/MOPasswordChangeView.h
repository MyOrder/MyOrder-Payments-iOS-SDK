//
//  MOPasswordChangeView.h
//  MyOrder
//
//  Created by Angel Garcia on 5/28/13.
//
//

#import <UIKit/UIKit.h>
#import "MOTextField.h"

typedef void(^MOPasswordChangeViewBlock)(NSString *password, NSString *passwordConfirm, NSString *oldPassword, NSString *email, BOOL remember);

@interface MOPasswordChangeView : UIView

@property (nonatomic, copy) MOPasswordChangeViewBlock onConfirm;

@end
