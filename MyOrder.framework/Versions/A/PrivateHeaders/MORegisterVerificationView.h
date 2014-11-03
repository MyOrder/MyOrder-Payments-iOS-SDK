//
//  MORegisterVerificationView.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

typedef void(^MORegisterVerificationBlock)(NSString *activationCode);

@interface MORegisterVerificationView : UIView

@property (nonatomic, copy) MORegisterVerificationBlock onConfirm;

- (id)initWithPhone:(NSString *)phone;

@end
