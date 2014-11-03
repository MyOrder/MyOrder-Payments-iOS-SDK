//
//  NSDictionary+MOUtils.h
//  MyOrder
//
//  Created by Angel Garcia on 27/08/14.
//  Copyright (c) 2014 Xaton. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (MOUtils)

- (NSNumber *)MO_numberForKey:(NSString *)key;
- (NSString *)MO_stringForKey:(NSString *)key;
- (NSNumber *)MO_booleanForKey:(NSString *)key;
- (NSArray *)MO_arrayForKey:(NSString *)key;
- (NSDictionary *)MO_dictionaryForKey:(NSString *)key;
@end
