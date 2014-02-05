//
//  MOWalletTableViewController.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>
#import "MOOrder.h"
#import "MOViewController.h"

@interface MOProvidersViewController : MOViewController

@property (nonatomic, copy) dispatch_block_t completionBlock;

- (id)initWithOrder:(MOOrder *)order;


/**
 Configures the provider list to display by default some providers open. No provider is open by default
 @param paymentProviderNames Array with the provider names to be open by default
 */
+ (void)setDefaultOpenPaymentProvider:(NSArray *)paymentProviderNames;

@end
