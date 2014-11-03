//
//  MOTextField.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

@interface MOTextField : UITextField

//@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, assign) UITextField *nextTextField;
@property (nonatomic, assign) CGFloat leftPadding;

- (void)sizeToFitCell:(UITableViewCell *)cell;

@end
