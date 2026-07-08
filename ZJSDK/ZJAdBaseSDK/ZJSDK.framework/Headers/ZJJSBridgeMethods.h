//
//  ZJJSBridgeMethods.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/8/22.
//  Copyright © 2025 zj. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZJJSBridgeMethod) {
    /**
     * 移除监听
     */
    ZJJSBridgeMethodRemoveListener = -1,
    /**
     * 设置监听
     */
    ZJJSBridgeMethodSetListener = 0,
    
    /**
     * 激励视频
     */
    ZJJSBridgeMethodRewardVideo = 1,
    
    /**
     * 插屏
     */
    ZJJSBridgeMethodInterstitial = 2,
    
    /**
     * 全屏视频
     */
    ZJJSBridgeMethodFullScreenVideo = 3,
    
    /**
     * 视频内容
     */
    ZJJSBridgeMethodContentAd = 4,
    
    /**
     * 视频内容视图
     */
    ZJJSBridgeMethodContentView = 5,
    
    /**
     * H5插件
     */
    ZJJSBridgeMethodH5Ad = 6,
    
    /**
     * 微信小程序
     */
    ZJJSBridgeMethodWxMiniProgram = 7,
    
    /**
     * 小说
     */
    ZJJSBridgeMethodNovel = 8,
    
    /**
     * 新闻广告
     */
    ZJJSBridgeMethodNewsAd = 9,
    
    /**
     * 新闻视图
     */
    ZJJSBridgeMethodNewsView = 10,
    
    /**
     * 悬浮广告
     */
    ZJJSBridgeMethodFloatView = 11,
    
    /**
     * 任务墙广告
     */
    ZJJSBridgeMethodTaskAd = 12,
    
    /**
     * 任务墙视图
     */
    ZJJSBridgeMethodTaskView = 13
};

@interface ZJJSBridgeMethods : NSObject

/**
 * 支持的方法列表
 */
+ (NSArray<NSNumber *> *)supportAdMethods;

@end

NS_ASSUME_NONNULL_END
