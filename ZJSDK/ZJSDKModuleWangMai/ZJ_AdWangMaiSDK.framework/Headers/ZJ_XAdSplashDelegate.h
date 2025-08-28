//
//  ZJ_XAdSplashDelegate.h
//  WangMaiAdSDK
//
//  Created by 周泽浩 on 2023/2/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_XAdSplashDelegate <NSObject>

@optional

///发起请求
- (void)splashOnAdRequest;

///加载成功
- (void)splashAdOnAdReadyHasMiniView:(UIView *)splashMiniView;

///曝光
- (void)splashOnExposure;

///请求失败
///@param error 错误信息
- (void)splashOnError:(NSError *)error;

///点击
- (void)splashOnClick;

///关闭
- (void)splashOnAdClose;

/// 关闭其他控制器
- (void)splashAdCloseOtherController;

///缩小视图点击
- (void)splashZoomOutViewDidClick:(UIView *)splashMiniView;

/// 缩小视图关闭
- (void)splashZoomOutViewAdDidClose:(UIView *)splashMiniView;

@end

NS_ASSUME_NONNULL_END
