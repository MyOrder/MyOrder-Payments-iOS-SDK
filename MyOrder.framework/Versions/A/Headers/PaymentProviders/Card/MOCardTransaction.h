//
//  MOCardTransaction.h
//  MyOrder
//
//  Created by Angel Garcia on 6/3/13.
//
//

#import "MOTransaction.h"

/** MyOrder bonnus card transaction */
@interface MOCardTransaction : MOTransaction

/** MyOrder card code */
@property (nonatomic, copy) NSString *code;

@end
