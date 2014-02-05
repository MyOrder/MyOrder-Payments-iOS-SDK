//
//  MOCreditCardTransaction.h
//  MyOrder
//
//  Created by Angel Garcia on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import "MyOrder.h"

/** Credit Card transaction */
@interface MOCreditCardTransaction : MOTransaction

/** Credit card number */
@property (nonatomic, strong) NSString *creditcardNumber;

/** Credit card date */
@property (nonatomic, strong) NSString *creditcardDate;

/** Credit card CVC */
@property (nonatomic, strong) NSString *creditcardCvc;

/** Bool number indicating if should save the credit card */
@property (nonatomic, strong) NSNumber *saveAlias;


@end
