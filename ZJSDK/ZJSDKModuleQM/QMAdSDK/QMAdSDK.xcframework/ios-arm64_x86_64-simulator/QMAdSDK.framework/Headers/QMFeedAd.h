//
//  QMFeedAd.h
//  QMAdSDK
//
//  Created by qusy on 2024/1/16.
//

#import <UIKit/UIKit.h>

#import <QMAdSDK/QMAdMeta.h>

NS_ASSUME_NONNULL_BEGIN

@protocol QMFeedAdDelegate;

@interface QMFeedAd : NSObject

@property (nonatomic, copy, readonly, nonnull) NSString *slotID;
@property (nonatomic, strong, readonly, nullable) UIView *feedView;
/// 自定义尺寸
@property (nonatomic, assign)CGSize customSize;

@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, strong, readonly, nullable) QMAdMeta *meta;

@property (nonatomic, weak) id<QMFeedAdDelegate> delegate;

/// 初始化
/// @param slotID  栏位id
- (instancetype)initWithSlot:(NSString *)slotID;

/// 加载广告
- (void)loadAdData;

/// 获取广告高度
- (CGFloat)handleFeedAdHeight;

/// 竞价成功
/// - Parameter auctionSecondPrice: 竞价第二名价格，单位是分
- (void)winNotice:(NSInteger)auctionSecondPrice;

/**
 竞价失败
 @param auctionPrice 胜出者价格，单位分
 @param winBidder 胜出者对应媒体
        如果需要扩展，可以直接传入自定义字符串
 @param lossReason 竞价失败原因
        如果需要扩展，可以直接传入自定义的字符串（建议字符串为 >1000 的数字）
 */
- (void)lossNotice:(NSInteger)auctionPrice
        lossReason:(QMLossReason  * _Nullable)lossReason
         winBidder:(QMWinBidder  * _Nullable)winBidder;


@end

@protocol QMFeedAdDelegate <NSObject>

@optional

/// 信息流广告加载成功
- (void)qm_feedAdLoadSuccess:(QMFeedAd *)feedAd;

/// 信息流广告加载失败
- (void)qm_feedAdLoadFail:(QMFeedAd *)feedAd error:(NSError *)error;

/// 信息流广告曝光
- (void)qm_feedAdDidShow:(QMFeedAd *)feedAd;

/// 信息流广告点击
- (void)qm_feedAdDidClick:(QMFeedAd *)feedAd;

/// 信息流广告关闭
- (void)qm_feedAdDidClose:(QMFeedAd *)feedAd;

/// 落地页关闭
- (void)qm_feedAdDidCloseOtherController:(QMFeedAd *)feedAd;

/// 信息流视频播放开始
- (void)qm_feedAdDidStart:(QMFeedAd *)feedAd;

/// 信息流视频播放暂停
- (void)qm_feedAdDidPause:(QMFeedAd *)feedAd;

/// 信息流视频播放继续
- (void)qm_feedAdDidResume:(QMFeedAd *)feedAd;

/// 信息流视频播放完成
- (void)qm_feedAdVideoDidPlayComplection:(QMFeedAd *)feedAd;

/// 信息流视频播放异常
- (void)qm_feedAdVideoDidPlayFinished:(QMFeedAd *)feedAd didFailWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
