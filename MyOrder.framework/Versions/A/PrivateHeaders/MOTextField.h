//
//  MOTextField.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

@interface MOTextField : UITextField

@property (nonatomic, strong) UILabel *titleLabel;
@property(nonatomic, assign) UITextField *nextTextField;

- (void)sizeToFitCell:(UITableViewCell *)cell;

@end
