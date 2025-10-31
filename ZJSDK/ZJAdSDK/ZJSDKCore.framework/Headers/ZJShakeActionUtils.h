//
//  ZJShakeActionUtils.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/10/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJShakeActionUtilsDelegate <NSObject>

- (void)shakeActionTriggered;

@end

@interface ZJShakeActionUtils : NSObject

// 设置摇一摇力度
@property (nonatomic, strong) NSString *shake_power;

// 设置摇一摇执行次数
@property (nonatomic, assign) NSInteger limit_times;

@property (nonatomic, assign) id <ZJShakeActionUtilsDelegate> delegate;

// 添加摇一摇事件监听
- (void)addShakeAction;

// 移除摇一摇事件
- (void)removeShakeAction;

@end

NS_ASSUME_NONNULL_END
