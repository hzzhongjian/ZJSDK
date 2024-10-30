//
//  YKMSplashAd.h
//  YKMultipleAdSDK
//
//  Created by hary on 2023/10/18.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class YKMSplashAd;
@protocol YKMSplashAdDelegate <NSObject>

@optional
///自定义开屏底部view
- (UIView *)ykm_splashBottomView;

///广告加载成功
- (void)ykm_loadSplashSuccess:(YKMSplashAd *)splash;

///广告加载失败
- (void)ykm_loadSplashFailed:(NSError *)error splash:(YKMSplashAd *)splash;

/// 广告展示成功
- (void)ykm_showSplashSuccess:(YKMSplashAd *)splash;

///广告点击事件
- (void)ykm_clickSplash:(YKMSplashAd *)splash;

///广告关闭事件
- (void)ykm_closeSplash:(YKMSplashAd *)splash;

@end

@interface YKMSplashAd : NSObject

/**
用来接收开屏广告读取和展示状态变化通知的 delegate
*/
@property (nonatomic, weak) id<YKMSplashAdDelegate> delegate;

/// 初始化开屏广告
/// @param adid 开屏的adid
/// @param timeOut 广告加载超时时间
- (instancetype)initWithAdid:(NSString *)adid andTimeOut:(NSInteger)timeOut;

///加载广告数据,
- (void)loadSplashAd;

/// 展示广告视图 把广告视图添加在showWindow上
/// @param window 广告的父视图 用于展示 && 查找rootVC用于点击跳转
- (void)showSplashAdWithWindow:(UIWindow *)window;
@end

NS_ASSUME_NONNULL_END
