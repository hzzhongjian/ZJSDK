//
//  WanjaSplashWebViewController.h
//  WanjaopusAdSDK
//
//  Created by guantou on 2020/1/13.
//

#import <UIKit/UIKit.h>

@protocol WanjaWorkerDelegate;

NS_ASSUME_NONNULL_BEGIN

@class WanjaSpaceInfoModel;
@class WanjaStrategyHelper;
@class WanjaAdRecordModel;

@interface WanjaSplashWebViewController : UIViewController

- (instancetype)initWithSpaceInfo:(WanjaSpaceInfoModel *)spaceInfo BottomView:(UIView *)bottomView SkipView:(UIView *)skipView;

@property (nonatomic, weak) id<WanjaWorkerDelegate> delegate;

//@property (nonatomic, weak) UIWindow *containerWindow;

@property (nonatomic, copy) NSString *randomUUID;

@property (nonatomic, strong) WanjaStrategyHelper *strategyHelper;

@property (nonatomic, strong) WanjaAdRecordModel *adRecordModel;

- (void)wanja_addCloseView;

//- (void)isCloseAdNextButton;

- (void)reportDeepLink:(BOOL)isSuccess;

// 上报竞价成功
- (void)wanja_reportWinPrice:(NSString*)secondPrice;

// 上报竞价失败
- (void)wanja_reportLossPrice:(NSString*)winPrice loseReason:(NSString*)reason winBidder:(NSString *)bidder;

@end

NS_ASSUME_NONNULL_END
