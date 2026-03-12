//
//  ZJ_XAdInterstitialDelegate.h
//  ZJ_AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_XAdInterstitialDelegate <NSObject>

@optional

/// 发起请求
- (void)interstitialOnAdRequest;

///  请求成功
- (void)interstitialOnAdReady;

/// 失败
/// - Parameter error: 错误信息
- (void)interstitialOnError:(NSError *)error;

/// 曝光
- (void)interstitialOnExposure;

/// 点击
- (void)interstitialOnClick;


/// 关闭
- (void)interstitialOnAdClose;

@end

NS_ASSUME_NONNULL_END
