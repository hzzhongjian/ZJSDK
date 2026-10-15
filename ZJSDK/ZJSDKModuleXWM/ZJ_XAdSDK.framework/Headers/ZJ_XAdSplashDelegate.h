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

///请求失败
///@param error 错误信息
- (void)splashOnError:(NSError *)error;

///广告素材下载成功
- (void)splashOnAdDownloadSuccess;

///广告素材下载失败
///@param error 错误信息
- (void)splashOnAdDownloadFail:(NSError *)error;

///曝光失败
- (void)splashOnExposureFail:(NSError *)error;

///曝光
- (void)splashOnExposure;

///点击
- (void)splashOnClick;

///将要关闭
- (void)splashOnAdWillClose;

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
