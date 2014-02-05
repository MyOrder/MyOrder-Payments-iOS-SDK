//
//  MOPaymentProviderCell.h
//  MyOrder
//
//  Created by Angel Garcia on 5/28/13.
//
//

#import <UIKit/UIKit.h>

@interface MOPaymentProviderCell : UITableViewCell

@property (nonatomic, strong) NSDictionary *providerInfo;
@property (nonatomic, assign) BOOL isExpanded;
@property (nonatomic, strong) NSNumber *walletAmount;

+ (CGFloat)heightOfCell:(BOOL)isExpanded;

@end