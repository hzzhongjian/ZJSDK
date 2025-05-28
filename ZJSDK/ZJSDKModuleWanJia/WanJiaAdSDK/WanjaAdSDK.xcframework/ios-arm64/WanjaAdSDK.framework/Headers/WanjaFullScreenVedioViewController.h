//
//  WanjaFullScreenVedioViewController.h
//  WanjaAdSDK
//
//  Created by guantou on 2023/11/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WanjaDisposeResponseModel;
@class WanjaAdRecordModel;
@class WanjaBusinessReport;
@class WanjaStrategyHelper;
@class WanjaBuyerModel;

@protocol WanjaFullScreenVedioVCDelegate <NSObject>

// 插屏展示页被曝光
- (void)wanja_fullScreenVedioVCDidExpose;

// 插屏展示页被点击
- (void)wanja_fullScreenVedioVCDidClick;

// 插屏展示页被关闭
- (void)wanja_fullScreenVedioVCDidClose;

// 插屏落地页被关闭
- (void)wanja_fullScreenVedioVCDidCloseOtherViewController;

/**
资源加载状态
 */
- (void)wanja_fullScreenVedioDownloadState:(BOOL)isSuccess;

@end

@interface WanjaFullScreenVedioViewController : UIViewController

@property (nonatomic, weak)id<WanjaFullScreenVedioVCDelegate> delegate;

@property (nonatomic, strong) WanjaDisposeResponseModel *disposeModel;

@property (nonatomic, strong) WanjaAdRecordModel *adRecordModel;

@property (nonatomic, strong) WanjaBusinessReport *businessReport;

@property (nonatomic, strong) WanjaStrategyHelper *strategyHelper;

@property (nonatomic, strong) WanjaBuyerModel *buyerModel;
//是否是视频广告
@property (nonatomic, assign) BOOL isVideoAd;
/**控制视频的音量控制按钮是否展示（默认显示）*/
@property (nonatomic, assign) BOOL isHiddenVoiceButton;

- (void)setupAutoClick;

@end

NS_ASSUME_NONNULL_END
