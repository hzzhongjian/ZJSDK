//
//  QMInterstitialAd.h
//  QMAdSDK
//
//  Created by qusy on 2023/12/28.
//

#import <UIKit/UIKit.h>
#import <QMAdSDK/QMAdMeta.h>

typedef NS_ENUM(NSUInteger, QMInterstitialAdCloseType) {
    QMInterstitialAdCloseTypeNormal = 0,
};

NS_ASSUME_NONNULL_BEGIN

@class QMInterstitialAd;
@protocol QMInterstitialAdDelegate <NSObject>
@optional

/// 插屏广告加载成功
- (void)qm_interstitialAdLoadSuccess:(QMInterstitialAd *)interstitialAd;

/// 插屏广告加载失败
- (void)qm_interstitialAdLoadFail:(QMInterstitialAd *)interstitialAd error:(NSError *)error;

/// 插屏广告曝光
- (void)qm_interstitialAdDidShow:(QMInterstitialAd *)interstitialAd;

/// 插屏广告点击
- (void)qm_interstitialAdDidClick:(QMInterstitialAd *)interstitialAd;

/// 插屏广告关闭
- (void)qm_interstitialAdDidClose:(QMInterstitialAd *)interstitialAd closeType:(QMInterstitialAdCloseType)type;

/// 插屏广告视频播放开始
- (void)qm_interstitialAdDidStart:(QMInterstitialAd *)rewardedVideoAd;

/// 插屏广告视频播放暂停
- (void)qm_interstitialAdDidPause:(QMInterstitialAd *)rewardedVideoAd;

/// 插屏广告视频播放继续
- (void)qm_interstitialAdDidResume:(QMInterstitialAd *)rewardedVideoAd;

/// 插屏广告视频播放完成
- (void)qm_interstitialAdVideoDidPlayComplection:(QMInterstitialAd *)interstitialAd;

/// 插屏广告视频播放异常
- (void)qm_interstitialAdVideoDidPlayFinished:(QMInterstitialAd *)interstitialAd didFailWithError:(NSError *)error;

@end



@interface QMInterstitialAd : NSObject

@property (nonatomic, weak) id <QMInterstitialAdDelegate> delegate;

/// 广告点击自动关闭
@property (nonatomic) BOOL adClickToCloseAutomatically;

/// 使用 controller present 落地页，默认使用广告 VC
@property (nonatomic, weak) UIViewController *viewController;

/// 广告物料
@property (nonatomic, strong) QMAdMeta *meta;
/// 栏位id
@property (nonatomic, readonly, copy) NSString *slotID;

/// 初始化
/// @param slotID  栏位id
- (nonnull instancetype)initWithSlot:(NSString *)slotID;

/// 加载广告
- (void)loadAdData;

/// 展示广告
- (void)showInterstitialViewInRootViewController:(UIViewController *)viewController;

/// 关闭插屏广告
- (void)closeInterstitialAd;

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
NS_ASSUME_NONNULL_END
