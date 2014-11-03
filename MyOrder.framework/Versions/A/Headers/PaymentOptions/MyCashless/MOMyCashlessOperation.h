//
//  MOMyCashlessOperation.h
//  MyOrder
//
//  Created by Angel Garcia on 03/07/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MOPaymentOperation.h"

typedef enum {
    MOMyCashlessOptionBuyToken,
    MOMyCashlessOptionAddToken,
    MOMyCashlessOptionTransactions,
    MOMyCashlessOptionCoupons,
    MOMyCashlessOptionLoyaltyWallets
} MOMyCashlessOption;

/**
 *  Presents the list of Cashless operations (Payment link keys). The execution returns the URL to
 *  open depending on the selected option.
 */
@interface MOMyCashlessOperation : MOPaymentOperation

@property (nonatomic, assign) MOMyCashlessOption option;
@end
