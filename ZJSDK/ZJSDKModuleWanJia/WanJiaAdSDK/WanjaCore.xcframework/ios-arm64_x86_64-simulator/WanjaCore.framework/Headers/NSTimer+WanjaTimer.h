//
//  NSTimer+WanjaTimer.h
//  WanjaCore
//
//  Created by ZY on 2019/4/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSTimer (WanjaTimer)

+ (NSTimer *)wanjaScheduledWeakTimerWithTimeInterval:(NSTimeInterval)ti target:(id)aTarget selector:(SEL)aSelector userInfo:(nullable id)userInfo repeats:(BOOL)yesOrNo;

@end

NS_ASSUME_NONNULL_END
