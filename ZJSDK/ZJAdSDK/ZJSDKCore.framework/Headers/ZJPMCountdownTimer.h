//
//  ZJPMCountdownTimer.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2026/7/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef void (^CountdownUpdateHandler)(NSInteger remainingSeconds);
typedef void (^CountdownCompletionHandler)(void);

/**
 * 纯后台倒计时管理类（基于 GCD dispatch_source）
 * 特点：
 * 1. 无主线程绑定：回调在定时器创建队列中执行
 * 2. 高性能：避免线程切换开销
 * 3. 完全线程控制权交给调用方
 * 4. 严格遵循 GCD 生命周期规则
 */

@interface ZJPMCountdownTimer : NSObject

/// 当前剩余秒数（只读）
@property (nonatomic, readonly) NSInteger remainingSeconds;

/**
 * 初始化倒计时
 * @param totalSeconds 总秒数 (>0)
 * @param queue 定时器执行队列 (传nil则使用默认并发队列)
 */
- (instancetype)initWithTotalSeconds:(NSInteger)totalSeconds
                               queue:(nullable dispatch_queue_t)queue;

/**
 * 开始倒计时
 * @param updateHandler 每秒回调 (remainingSeconds >= 0)
 * @param completionHandler 结束回调 (remainingSeconds = -1)
 */
- (void)startWithUpdateHandler:(CountdownUpdateHandler)updateHandler
             completionHandler:(nullable CountdownCompletionHandler)completionHandler;

- (void)pause;   // 暂停 (保留剩余时间)

- (void)resume;  // 恢复

- (void)cancel;  // 取消并清理资源

@end

NS_ASSUME_NONNULL_END
