//
//  YKMInterstitialAd.h
//  YKMultipleAdSDK
//
//  Created by hary on 2024/2/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class YKMInterstitialAd;
@protocol YKMInterstitialAdDelegate <NSObject>

@optional
///广告加载成功
- (void)ykm_loadInterstitialSuccess:(YKMInterstitialAd *)interstitial;

///广告加载失败
- (void)ykm_loadInterstitialFailed:(NSError *)error interstitial:(YKMInterstitialAd *)interstitial;

/// 广告展示成功
- (void)ykm_showInterstitialSuccess:(YKMInterstitialAd *)interstitial;

///广告点击事件
- (void)ykm_clickInterstitial:(YKMInterstitialAd *)interstitial;

///广告关闭事件
- (void)ykm_closeInterstitial:(YKMInterstitialAd *)interstitial;

@end

@interface YKMInterstitialAd : NSObject

/**
用来接收插屏广告读取和展示状态变化通知的 delegate
*/
@property (nonatomic, weak) id<YKMInterstitialAdDelegate> delegate;

/// 初始化插屏广告
/// @param adid 插屏的adid
/// @param timeOut 广告加载超时时间
- (instancetype)initWithAdid:(NSString *)adid andTimeOut:(NSInteger)timeOut;

///加载广告数据,
- (void)loadInterstitialAd;

/// 展示广告视图 把广告视图添加在rootViewController上
/// @param rootViewController 广告的父控制器 用于展示 && 点击跳转
- (void)showInterstitialAdWithRootViewController:(UIViewController *)rootViewController;
@end

NS_ASSUME_NONNULL_END
