//
//  SMThreadSafeArray.h
//  WindSDK
//
//  Created by Codi on 2020/5/19.
//  Copyright © 2020 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SMThreadSafeArray<ObjectType> : NSMutableArray

- (void)removeObjectsPassingTest:(BOOL (^)(id obj))predicate;

#pragma mark - ⚠️ Dangerous APIs (禁用)

- (void)removeObjectsAtIndexes:(NSIndexSet *)indexes NS_DEPRECATED(10_0, 10_0, 2_0, 2_0, "Use removeObjectsPassingTest:");
@end
