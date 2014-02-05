//
//  MOOrder.h
//  MyOrder
//
//  Created by Taras Kalapun on 5/29/13.
//
//

#import <Foundation/Foundation.h>

@interface MOOrder : NSObject

/**
 The price of the order, must correspond with the total price of the given items in euros
 If not set, will return `totalPriceForItems`
 */
@property (nonatomic, assign) CGFloat price;

// Place order params
// price, listed above
@property (nonatomic, strong) NSString *externalOrderId;

/**
 The items to be ordered. Array of dictionaries with keys:
 - Name – The name of the item
 - Price – The price of the item in cents
 - Quantity – The quantity of the item
 */
@property (nonatomic, strong, readonly) NSMutableArray *items;

/**
 Add an item to the order
 @param name Name of the item
 @param price Price of the item in euros
 @param quantity Number of items
 */
- (void)addItemWithName:(NSString *)name price:(CGFloat)price quantity:(NSUInteger)quantity;

@end
