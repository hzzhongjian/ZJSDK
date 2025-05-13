//
//  QMNativeAd.h
//  QMAdSDK
//
//  Created by qusy on 2023/12/28.
//

#import <UIKit/UIKit.h>

#import <QMAdSDK/QMAdMeta.h>

NS_ASSUME_NONNULL_BEGIN

@protocol QMNativeAdDelegate;

@interface QMNativeAd : NSObject

@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
@property (nonatomic, strong, readonly, nullable) QMAdMeta *meta;
@property (nonatomic, weak) UIViewController *viewController;

@property (nonatomic, weak) id<QMNativeAdDelegate> delegate;

@property (nonatomic, strong, readonly, nullable) UIView *videoView;

/// 初始化
/// @param slotID  栏位id
- (instancetype)initWithSlot:(NSString *)slotID;

/// 加载广告
- (void)loadAdData;

/// 注册可点击区域
/// @param containerView :  requried  广告展示区域
/// @param clickableViews : optional  其他可点击区域
- (void)registerContainer:(__kindof UIView *)containerView withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;

/// Unregister ad view from the native ad.
- (void)unregisterView;

/// 竞价成功
/// - Parameter auctionSecondPrice: 竞价第二名价格，单位是分
- (void)winNotice:(NSInteger)auctionSecondPrice;

/**
 竞价失败
 @param auctionPrice 胜出者价格，单位分
 @param winBidder 胜出者对应媒体
        如果需要扩展，可以直接传入自定义字符串。
 @param lossReason 竞价失败原因
        如果需要扩展，可以直接传入自定义的字符串（建议字符串为 >1000 的数字）
 */
- (void)lossNotice:(NSInteger)auctionPrice
        lossReason:(QMLossReason  * _Nullable)lossReason
         winBidder:(QMWinBidder  * _Nullable)winBidder;

@end

@protocol QMNativeAdDelegate <NSObject>

@optional

/// 自渲染广告加载成功
- (void)qm_nativeAdLoadSuccess:(QMNativeAd *)nativeAd;

/// 自渲染广告加载失败
- (void)qm_nativeAdLoadFail:(QMNativeAd *)nativeAd error:(NSError *)error;

/// 自渲染广告曝光
- (void)qm_nativeAdDidShow:(QMNativeAd *)nativeAd;

/// 自渲染广告点击
- (void)qm_nativeAdDidClick:(QMNativeAd *)nativeAd;

/// 自渲染落地页关闭
- (void)qm_nativeAdDidCloseOtherController:(QMNativeAd *)nativeAd;

/// 自渲染视频播放开始
- (void)qm_nativeAdDidStart:(QMNativeAd *)nativeAd;

/// 自渲染视频播放暂停
- (void)qm_nativeAdDidPause:(QMNativeAd *)nativeAd;

/// 自渲染视频播放继续
- (void)qm_nativeAdDidResume:(QMNativeAd *)nativeAd;

/// 自渲染视频播放完成
- (void)qm_nativeAdVideoDidPlayComplection:(QMNativeAd *)nativeAd;

/// 自渲染视频播放异常
- (void)qm_nativeAdVideoDidPlayFinished:(QMNativeAd *)nativeAd didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
