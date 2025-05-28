
//  WanjaBusinessReport.h
//  WanjaCore
//
//  Created by ZY on 2019/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

//0:默认值可不传 1:调起 5:apk安装成功 6:apk下载成功 7:摇一摇灵敏度0时上报 8:回调 9:自动点击 10:补量 11:曝光回调 12:触摸点击 2:关闭触发点击 4:广告过期 13:dp拦截(调起)
//所有的优先级排序 广告过期>补量>调起>回调>自动点击>摇一摇灵敏度>曝光回调>触摸点击
typedef NS_ENUM(NSUInteger, WanjaAdClickType) {
    WanjaAdClickDefaut = 0,
    WanjaAdClickStart = 1,
    WanjaAdClickShakefor0 = 7,
    WanjaAdClickCallBack = 8,
    WanjaAdClickAutoClick = 9,
    WanjaAdClickBoost = 10,
    WanjaAdExposeCallback = 11,
    WanjaAdTouchClick = 12,
    WanjaAdCloseClick = 2,
    WanjaAdTimeInvalid = 4,
    WanjaAdDeeplinkStart = 13
};

typedef enum : NSUInteger {
    WanjaTrackersNone,
    WanjaTrackersThreeQuarter,
    WanjaTrackersExit,
    WanjaTrackersHalf,
    WanjaTrackersStart,
    WanjaTrackersComplete,
    WanjaTrackersPause,
    WanjaTrackersQuarter,
} WanjaVideoTrackersType;

@class WanjaVideoTrackersModel;

@protocol WanjaBusinessReportDelegate <NSObject>

// 上报结果
- (void)wanjaad_businessReportState:(BOOL)isSuccess;

@end

@interface WanjaBusinessReport : NSObject
//
@property (nonatomic, weak) id<WanjaBusinessReportDelegate> delegate;

//
@property (nonatomic, assign, readonly) BOOL isReportShow;
@property (nonatomic, assign, readonly) BOOL isReportClick;

//  上报点击时，获取点击位置，赋值点击Point。
@property (nonatomic, assign) CGPoint adClickPoint;
@property (nonatomic, assign) CGPoint srClickPoint;

//  随机uuid
@property (nonatomic, copy) NSString *randomUUID;

//  上报的广告展示的View
@property (nonatomic, strong) UIView *adView;

//  上报的URL
@property (nonatomic, strong) NSArray *reportURLArray;

//
@property (nonatomic, copy) NSString *slotId;
//
@property (nonatomic, copy) NSString *biddingSuccessUrl;
@property (nonatomic, copy) NSString *biddingFailUrl;
@property (nonatomic, copy) NSString *closeSkipUrl;
@property (nonatomic, copy) NSString *exposeRetryUrl;
//
@property (nonatomic, strong) NSArray<WanjaVideoTrackersModel *> *videoTarckers;

//  上报展示
- (void)wanja_reportShowView:(WanjaAdClickType)clickType;
- (void)wanja_reportBackgroundShowView:(WanjaAdClickType)clickType;
//  上报点击
- (void)wanja_reportClickView:(WanjaAdClickType)clickType reportParams:(nullable NSDictionary*)reportParams;
- (void)wanja_reportDeepLink:(WanjaAdClickType)clickType result:(BOOL)isSuccess;
// 上报竞价成功
- (void)wanja_reportWinPrice:(NSString*)secondPrice;
// 上报竞价失败
- (void)wanja_reportLossPrice:(NSString*)winPrice loseReason:(NSString*)reason winBidder:(NSString *)bidder;
//  上报关闭
- (void)wanja_reportCloseView:(WanjaAdClickType)clickType;
//  上报视频进度
- (void)wanja_reportVideoProgress:(WanjaVideoTrackersType)type videoStartTime:(NSString*)videoStartTime videoEndTime:(NSString*)videoEndTime;


//  刷新上报状态
- (void)wanja_refreshReportStatus;

@end

NS_ASSUME_NONNULL_END
