//
//  WanjaSplashPlayerViewController.h
//  WanjaopusAdSDK
//
//  Created by guantou on 2020/1/13.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@class WanjaSpaceInfoModel;
@class WanjaStrategyHelper;
@protocol WanjaWorkerDelegate;
@class WanjaAdRecordModel;

@interface WanjaSplashPlayerViewController : UIViewController

- (instancetype)initWithSpaceInfo:(WanjaSpaceInfoModel *)spaceInfo BottomView:(UIView *)bottomView SkipView:(UIView *)skipView;

@property (nonatomic, weak) id<WanjaWorkerDelegate> delegate;

//@property (nonatomic, weak) UIWindow *containerWindow;

@property (nonatomic, copy) NSString *randomUUID;

- (void)wanja_addCloseView;

- (void)reportDeepLink:(BOOL)isSuccess;

// 上报竞价成功
- (void)wanja_reportWinPrice:(NSString*)secondPrice;

// 上报竞价失败
- (void)wanja_reportLossPrice:(NSString*)winPrice loseReason:(NSString*)reason winBidder:(NSString *)bidder;

//- (void)isCloseAdNextButton;

@property (nonatomic, strong) WanjaStrategyHelper *strategyHelper;

@property (nonatomic, strong) WanjaAdRecordModel *adRecordModel;

@end

NS_ASSUME_NONNULL_END
