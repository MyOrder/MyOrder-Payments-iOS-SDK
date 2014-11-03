//
//  MOIdealTransaction.h
//  MyOrder
//
//  Created by Angel Garcia on 5/22/13.
//
//

#import <Foundation/Foundation.h>
#import "MOApiConnection.h"
#import "MOOrder.h"

@protocol MOTransactionProtocol;

typedef void(^MOPluginBlock)(id<MOTransactionProtocol>plugin);
typedef void(^MOPluginErrorBlock)(id<MOTransactionProtocol>plugin, NSError *error);

typedef enum {
    MOTransactionStatusNotStarted,
    MOTransactionStatusInProgress,
    MOTransactionStatusConfirmed,
    MOTransactionStatusFinished,
    MOTransactionStatusCanceled,
    MOTransactionStatusError,
} MOTransactionStatus;


/**
 * Const in provider info for name. Example: @"iDeal"
 */
extern const NSString *MOTransactionProviderName;

/**
 * Const in provider info for open feature. If open, the transaction does not require login. Currently all providers set it to NO
 */
extern const NSString *MOTransactionCanBeOpen;

/**
 * Const in provider info for wallet support. If YES, the transaction can be used to fill the wallet
 */
extern const NSString *MOTransactionAllowsWalletOperation;

/**
 * Const in provider info for order support. If YES, the transaction can be used to pay an order
 */
extern const NSString *MOTransactionAllowsOrderOperation;

/**
 * Const in provider info for priority. Returns a number that will be used in the payment list as sorting index
 */
extern const NSString *MOTransactionPriority;

/**
 * Const in provider info for description. Returns text with provider details
 */
extern const NSString *MOTransactionProviderDescription;


/**
 *  All Transaction providers must implement this protocol. MyOrder class will look on app bundle classes implementing this protocol to
 *  automatically load them on startup as any other MyOrder payment provider.
 *  Transactions are always designed in a 2-step process, even if some of them can be performed in a single step. This abstraction provides 
 *  a common scenario for all of them, no matter of the internal implementation details. The flow is as follows:
 *  1. Create transaction and assign order/wallet amount
 *  2. Call placeOrder/fillWallet methods with confirmation, completion and error blocks
 *  3. Confirmation block is executed, call `confirm` to proceed if everything is ready. Some transactions might require additional steps like opening a browser at this step with an external URL (like iDeal)
 *  4. Success/error block executed with transaction detail and error
 */
@protocol MOTransactionProtocol <NSObject>

/**
 The ammount to charge in a wallet operation in euros
 */
@property (nonatomic, assign) double walletAmmount;

/**
 MOOrder to use for placing order. Required when placeOrder method called
 */
@property (nonatomic, strong) MOOrder *order;


/**
 Returns the transaction info dictionary
 @return dictionary with provider information (name, description, allows wallet,...)
 */
+ (NSDictionary *)info;

/**
 Returns the transaction provider name
 @return string with provider name (ex: PayPal)
 */
+ (NSString *)providerName;


/**
 Confirms the transaction in the two phase payment methods
 */
- (void)confirm;

/**
 Finish the transaction in the two phase payment methods
 */
- (void)finish;

/**
 Cancels the transaction in any moment
 */
- (void)cancel;

/**
 Retrieves the current state
 @return status of the transaction
 */
- (MOTransactionStatus)status;

/**
 Start payment transaction to fill your wallet. (ChargeXXX)
 @param confirmationBlock Block that will be called on intermediate process (confirmation)
 @param block Sucess Block
 @param errorBlock Error Block
 */
- (void)fillWalletOnConfirmation:(MOPluginBlock)confirmationBlock onSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;

/**
 Start payment transaction with MOOrder object to make a payment (placeOrder)
 @param confirmationBlock Block that will be called on intermediate process (confirmation)
 @param block Sucess Block
 @param errorBlock Error Block
 */
- (void)placeOrderOnConfirmation:(MOPluginBlock)confirmationBlock onSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;

/**
 Returns a BOOL indicating if the URL has been handled by the transaction. By default returns NO.
 @param url NSURL to handle.
 @returns BOOL YES if the URL has been handled
 */
- (BOOL)handleURL:(NSURL *)url;


/** Check with server side the current transaction status and refreshes internally
 @param block Success block
 @param errorBlock Error block
 */
- (void)loadStatusOnSuccess:(MOPluginBlock)block error:(MOPluginErrorBlock)errorBlock;


@end


/** Generic transaction that all MyOrder providers extend. Do not use directly, treat it as an abstract class */
@interface MOTransaction : NSObject<MOTransactionProtocol>

/** Description to use in the receipt details. Only used by some transactions (iDeal) */
@property (nonatomic, copy) NSString *description;

/** Transaction ID */
@property (nonatomic, copy) NSString *transactionId;

/** Return url to use on the external party service as callback */
@property (nonatomic, copy) NSString *returnUrl;


@end
