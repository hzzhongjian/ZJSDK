//
//  ZJ_SSFWNativeExpressAd.h
//  ZJ_SSFWAdSDK
//
//  Created by admin on 2021/1/18.
//

#import <UIKit/UIKit.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWSourceAdType.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWNativeAdData.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWNativeAdObject.h>
#import <ZJ_SSFWAdSDK/ZJ_SSFWAdMaterial.h>
@class ZJ_SSFWNativeExpressAd;

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_SSFWNativeExpressAd : NSObject

// 自渲染广告对象
@property(nonatomic,strong) ZJ_SSFWNativeAdObject *adObject;
// 模板视图
@property(nonatomic,strong,readonly) UIView *nativeExpressAdView;
/// 是否是模板广告 false 为自渲染
@property(nonatomic,assign)BOOL isNativeExpress;
/// 广告是否有效（展示前请务必判断）
/// 如不严格按照此方法对接，将导致因曝光延迟时间造成的双方消耗gap过大，请开发人员谨慎对接
@property(nonatomic,assign,readonly)BOOL isReady;
/// 是否是视频广告 针对自渲染生效 模板暂未提供
@property(nonatomic, assign, readonly)BOOL isVideoAd;
/// 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property(nonatomic, weak)UIViewController *controller;
/// 价格 单位分
@property(nonatomic,assign)NSInteger price;
/// 消耗方类型
@property(nonatomic,assign)ZJ_SSFWAdSourceType sourceType;
/// [必选]原生模板广告渲染
- (void)render;
/// 移除注册视图
- (void)darwUnregisterView;

/// 广告素材 可能为空  自渲染时请使用PTGNativeAdObject
@property(nullable,nonatomic,strong)ZJ_SSFWAdMaterial *adMaterial;


@end

NS_ASSUME_NONNULL_END
