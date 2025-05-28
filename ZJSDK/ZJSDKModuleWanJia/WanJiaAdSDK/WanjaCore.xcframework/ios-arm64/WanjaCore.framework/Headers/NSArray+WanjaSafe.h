//
//  NSArray+WanjaSafe.h
//  WanjaCore
//
//  Created by ZY on 2018/12/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (WanjaSafe)

- (id)wanja_safe_objectAtIndex:(NSUInteger)index;
+ (BOOL)wanja_isEmptyArray:(NSMutableArray *)array;

@end

@interface NSMutableArray (WanjaSafe)

- (id)wanja_safe_objectAtIndex:(NSUInteger)index;
+ (BOOL)wanja_isEmptyArray:(NSMutableArray *)array;

@end

NS_ASSUME_NONNULL_END
