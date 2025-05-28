//
//  WanjaGcdTimer.h
//  WanjaCore
//
//  Created by hongji cai on 2024/3/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WanjaGcdTimer : NSObject

//方法一
//立刻执行
+ (NSString *)exeTask:(void(^)(void))task
             interval:(NSTimeInterval)interval
               leeway:(NSTimeInterval)leeway
              repeats:(BOOL)repeats async:(BOOL)async;
//
+ (NSString *)exeTask:(void(^)(void))task
        start:(NSTimeInterval)start
        interval:(NSTimeInterval)interval
        leeway:(NSTimeInterval)leeway
              repeats:(BOOL)repeats async:(BOOL)async;

//方法二
+ (NSString *)exeTask:(id)target
             selector:(SEL)selector
             interval:(NSTimeInterval)interval
               leeway:(NSTimeInterval)leeway
              repeats:(BOOL)repeats async:(BOOL)async;

+ (void)cancelTask:(NSString *)taskName;


@end

NS_ASSUME_NONNULL_END
