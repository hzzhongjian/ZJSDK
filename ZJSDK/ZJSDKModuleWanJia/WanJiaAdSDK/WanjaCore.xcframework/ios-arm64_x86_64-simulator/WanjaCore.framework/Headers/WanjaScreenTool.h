//
//  WanjaScreenTool.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  关于屏幕内容
 */
@interface WanjaScreenTool : NSObject

/**
 缓存屏幕方向+添加改变方向监听
 */
+ (void)getScreenDirection;

//获取屏幕方向，json串格式
+ (NSString*)getScreenSpaceParam;

/**
 获取屏幕方向
 @return 1为竖屏，2为横屏
 */
+ (double)screenStatus;

/**
 获取当前控制器
 @return 返回当前控制器
 */
+ (UIViewController *)getCurrentVC;

@end

NS_ASSUME_NONNULL_END
