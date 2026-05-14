//
//  ZJ_XAdNativeExpressDelegete.h
//  ZJ_AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_XAdNativeExpressDelegete <NSObject>

/// 发起请求
/// @param adTag 广告标记
- (void)nativeExpressOnAdRequest:(NSString *)adTag;

/// 请求成功
/// @param isVideoAd 是否是视频广告  部分平台不支持获取
/// @param adTag 广告标记
- (void)nativeExpressOnAdReady:(BOOL)isVideoAd adTag:(NSString *)adTag;

/// 失败
/// @param error 错误信息
/// 广告标记
- (void)nativeExpressOnError:(NSError *)error adTag:(NSString *)adTag;

/// 曝光
/// @param adTag 广告标记
- (void)nativeExpressOnExposure:(NSString *)adTag;

/// 点击
/// @param adTag 广告标记
- (void)nativeExpressOnClick:(NSString *)adTag;

/// 关闭
/// @param adTag 广告标记
- (void)nativeExpressOnAdClose:(NSString *)adTag;


@end

NS_ASSUME_NONNULL_END
