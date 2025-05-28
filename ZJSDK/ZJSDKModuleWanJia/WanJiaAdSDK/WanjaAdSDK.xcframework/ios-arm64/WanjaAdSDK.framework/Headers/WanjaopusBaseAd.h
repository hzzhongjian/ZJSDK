//
//  WanjaopusBaseAd.h
//  WanjaopusAdSDK
//
//  Created by guantou on 2023/10/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
     * 竞价失败原因
     * 1001 底价过滤
     * 1002 bid价格低于最高价
     * 1003 素材黑名单过滤
     * 1004 竞品过滤
     * 1005 超时过滤
     * 1006 其它过滤
     */

typedef NS_ENUM(NSInteger, WanjaAdBiddingFailReason) {
    WanjaAdBiddingLossReasonPriceFilter = 1001,
    WanjaAdBiddingLossReasonLowFilter = 1002,
    WanjaAdBiddingLossReasonBlacklistFilter = 1003,
    WanjaAdBiddingLossReasonCompeteFilter = 1004,
    WanjaAdBiddingLossReasonTimeoutFilter = 1005,
    WanjaAdBiddingLossReasonOther = 1006
};

/**
     * 竞价胜出者
     * CSJ 穿山甲/头条
     * GDT 优量汇/广点通
     * KUAISHOU 快手
     * BAIDU 百青藤/百度
     * SIGMOB sigmob
     * OPPO oppo
     * VIVO vivo
     * HUAWEI 华为
     * XIAOMI 小米
     * WanjaOPUS 章鱼
     * JD 京东
     * QM 趣盟
     * ONEWAY 万唯
     * OTHER 其他家
     */
extern NSString *const kWanjaWinBidderCSJ;
extern NSString *const kWanjaWinBidderGDT;
extern NSString *const kWanjaWinBidderKUAISHOU;
extern NSString *const kWanjaWinBidderBAIDU;
extern NSString *const kWanjaWinBidderSIGMOB;
extern NSString *const kWanjaWinBidderOPPO;
extern NSString *const kWanjaWinBidderVIVO;
extern NSString *const kWanjaWinBidderHUAWEI;
extern NSString *const kWanjaWinBidderXIAOMI;
extern NSString *const kWanjaWinBidderWanjaOPUS;
extern NSString *const kWanjaWinBidderJD;
extern NSString *const kWanjaWinBidderQM;
extern NSString *const kWanjaWinBidderONEWAY;
extern NSString *const kWanjaWinBidderOTHER;

@interface WanjaopusBaseAd : NSObject

////  请求广告
//- (void)requestAds;

/**开屏广告需要方法及其变量*/
@property (nonatomic, strong) UIView *bottomView;
@property (nonatomic, strong) UIView *skipView;
/**控制视频的音量控制按钮是否展示（默认显示）*/
@property (nonatomic, assign) BOOL isHiddenVoiceButton;
/**请求超时时长*/
@property (nonatomic, assign) double timeoutInterval;

/**
 媒体需要的素材信息反馈, key的定义如下：
 素材ID:id，类型:imageMode(0或1)
 标题:title，描述:description，
 图片地址:imageUrl，视频地址:videoUrl,
 广告主品牌lcon:iconUrl
 */
@property (nonatomic, readonly) NSDictionary *mediaExtraInfoDict;

//竞价成功时上报接口 secondWinPrice竞价第二名价格，单位是分
- (void)sendWinNotice:(NSInteger)secondWinPrice;
//竞价失败时上报接口 winPrice 胜出者价格 单位分 lossReason 竞价失败原因 winBidder 胜出者 （非必填）
- (void)sendLossNotice:(WanjaAdBiddingFailReason)lossReason winnerPirce:(NSInteger)winPrice winBidder:(NSString * _Nullable )bidder;
//获取requestId
- (NSString*)getRequestId;
//
- (NSString*)getTagId;

@end

NS_ASSUME_NONNULL_END
