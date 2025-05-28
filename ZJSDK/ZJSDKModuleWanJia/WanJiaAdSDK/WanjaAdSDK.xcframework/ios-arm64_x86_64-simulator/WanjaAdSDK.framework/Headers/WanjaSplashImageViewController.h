//
//  WanjaSplashImageViewController.h
//  WanjaopusAdSDK
//
//  Created by guantou on 2020/1/13.
//

#import <UIKit/UIKit.h>
#import <WanjaCore/WanjaBaseViewController.h>
#import <WanjaCore/WanjaAdvertisingType.h>

NS_ASSUME_NONNULL_BEGIN

@class WanjaSpaceInfoModel;
@protocol WanjaWorkerDelegate;
@class WanjaBuyerModel;
@class WanjaStrategyHelper;
@class WanjaAdRecordModel;
@class WanjaBusinessReport;
@class WanjaAdSplash;

@interface WanjaSplashImageViewController : WanjaBaseViewController

- (instancetype)initWithSpaceInfo:(WanjaSpaceInfoModel *)spaceInfo BottomView:(UIView *)bottomView SkipView:(UIView *)skipView isVedio:(BOOL)isVedio;

@property (nonatomic, strong) WanjaBuyerModel *buyerModel;
@property (nonatomic, weak) id<WanjaWorkerDelegate> delegate;
//特殊处理， 临时保留广告对象, 在广告关闭时， 需要主动置nil
@property (nonatomic, strong, nullable) WanjaAdSplash *adSplash;
//从落地页回到广告页时， 如果此时倒计时还未结束，是否关闭广告
@property (nonatomic, assign) BOOL isCloseAfterBackToAdvert;

//@property (nonatomic, weak) UIWindow *containerWindow;

@property (nonatomic, copy) NSString *randomUUID;

@property (nonatomic, strong) WanjaStrategyHelper *strategyHelper;

@property (nonatomic, strong) WanjaAdRecordModel *adRecordModel;

@property (nonatomic, strong, readonly) WanjaBusinessReport *businessReport;

/**控制视频的音量控制按钮是否展示（默认显示）*/
@property (nonatomic, assign) BOOL isHiddenVoiceButton;

- (void)addCloseView;

- (void)reportDeepLink:(BOOL)isSuccess;

// 上报竞价成功
- (void)wanja_reportWinPrice:(NSString*)secondPrice;

// 上报竞价失败
- (void)wanja_reportLossPrice:(NSString*)winPrice loseReason:(NSString*)reason winBidder:(NSString *)bidder;

//控制倒计时开启
- (void)startCountDown:(BOOL)isStart;

@end

NS_ASSUME_NONNULL_END
