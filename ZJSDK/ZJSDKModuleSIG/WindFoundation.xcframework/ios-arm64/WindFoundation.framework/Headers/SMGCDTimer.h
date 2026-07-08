//
//  SMGCDTimer.h
//  WindSDK
//
//  Created by happyelements on 2018/9/4.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMGCDTimer : NSObject

/// 调用时间间隔
@property (readonly) NSTimeInterval interval;

/// 用户信息
@property (readonly) NSDictionary *userInfo;

/// 容忍度，单位秒，默认为 0.1；即便设置为 0.0 仍然存在误差
@property (atomic, assign) NSTimeInterval tolerance;

/// 前后台切换，是否主动暂停定时器；default：NO 不暂停
@property (nonatomic, assign) BOOL pauseByEvent;


/// 创建一个定时器
/// @param interval 调用的时间间隔
/// @param aTarget 对象
/// @param aSelector 方法选择器
/// @param userInfo 用户信息
/// @param repeats 是否重复
/// @param dispatchQueue 派发事件的队列，可以是串行队列或并发队列
+ (instancetype)timerWithTimeInterval:(NSTimeInterval)interval
                                       target:(id)aTarget
                                     selector:(SEL)aSelector
                                     userInfo:(nullable NSDictionary *)userInfo
                                      repeats:(BOOL)repeats
                                dispatchQueue:(dispatch_queue_t)dispatchQueue;

/// 创建一个定时器
/// @param interval 调用的时间间隔
/// @param userInfo 用户信息
/// @param repeats 是否重复
/// @param dispatchQueue 派发事件的队列，可以是串行队列或并发队列
/// @param block 定时器事件
+ (instancetype)timerWithTimeInterval:(NSTimeInterval)interval
                             userInfo:(nullable NSDictionary *)userInfo
                                      repeats:(BOOL)repeats
                                dispatchQueue:(dispatch_queue_t)dispatchQueue
                                        block:(void (^)(SMGCDTimer *timer))block;

/// 启用定时器
- (void)fire;

/// 无效定时器
/// @note 调用该方法之后，将无法重启定时器
/// @note 如果是用 target selector 方式启用的定时器，target 销毁之后的第一次调用 selector 的时机会自动调用本方法
- (void)invalidate;

/// 暂停定时器
/// @note 调用本方法之后，可以用 resume 恢复定时器
- (void)pause;

/// 恢复定时器
/// @note 调用本方法之后，可以用 fire 重启定时器
- (void)resume;

@end

NS_ASSUME_NONNULL_END
