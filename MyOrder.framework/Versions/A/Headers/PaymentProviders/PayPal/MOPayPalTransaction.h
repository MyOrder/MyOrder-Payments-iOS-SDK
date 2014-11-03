//
//  MOPayPalTransaction.h
//  MyOrder
//
//  Created by Angel Garcia on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import "MyOrder.h"

/** Paypal transaction */
@interface MOPayPalTransaction : MOTransaction

/** Confirmation key from the PayPal SDK */
@property (nonatomic, copy) NSString *confirmationKey;

/** Return url to use on the external party service as callback */
@property (nonatomic, copy) NSString *returnUrl;

/** Issuer url to open for confirm the transaction */
@property (nonatomic, copy) NSString *issuerUrl;


@end
