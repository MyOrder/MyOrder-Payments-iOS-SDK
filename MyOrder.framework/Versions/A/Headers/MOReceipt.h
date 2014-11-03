//
//  MOReceipt.h
//  MyOrder
//
//  Created by Angel Garcia on 10/03/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    MOReceiptStatusSuccess,
    MOReceiptStatusPending,
    MOReceiptStatusOnHold,
    MOReceiptStatusError,
    MOReceiptStatusInvalid,
    MOReceiptStatusUndefined
} MOReceiptStatus;

@interface MOReceipt : NSObject

@property (nonatomic, copy) NSString *orderId;
@property (nonatomic, strong) NSArray *fields;
@property (nonatomic, strong) NSDate *creationDate;
@property (nonatomic, copy) NSString *merchantName;
@property (nonatomic, copy) NSString *socialMessage;

@property (nonatomic, assign) NSInteger statusCode;
@property (nonatomic, copy) NSString *statusDescription;
@property (nonatomic, assign) MOReceiptStatus status;
@property (nonatomic, copy) NSString *takeAwayTime;

@property (nonatomic, strong) NSArray *products;

- (id)initWithData:(NSDictionary *)data;

@end


@interface MOReceiptProduct : NSObject

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *details;
@property (nonatomic, assign) NSInteger quantity;
@property (nonatomic, assign) double price;
@property (nonatomic, copy) NSString *imageUrl;

- (id)initWithData:(NSDictionary *)data;

@end