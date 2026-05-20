//
//  WanjaopusBaseAd.h
//  WanjaopusAdSDK
//
//  Created by guantou on 2023/10/24.
//

#import <Foundation/Foundation.h>
#import <WanjaCore/WanjaAdShakeConfigModel.h>

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
     * WANJAOPUS 章鱼
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
/**控制视频的音量控制按钮是否展示（默认显示），请注意：针对信息流广告时，该属性对信息流模版有效，自渲染是无效的*/
@property (nonatomic, assign) BOOL isHiddenVoiceButton;
/**请求超时时长*/
@property (nonatomic, assign) double timeoutInterval;
/**广告是否有效*/
@property (nonatomic, readonly) BOOL isValidAdvert;
/**是否是CPA广告*/
@property (nonatomic, readonly) BOOL isCPAAdvert;

/**
 媒体需要的素材信息反馈, key的定义如下：
 素材ID:id，类型:imageMode(0或1)
 标题:title，描述:description，
 图片地址:imageUrl，视频地址:videoUrl,
 广告主品牌lcon:iconUrl
 //
 唤起链接：deepLink
 ulk (ios调起链接)：universalLink
 落地页：landingPageUrl
 包名：packageName
 //
 视频封面图字段：cover
 广告主品牌名字段：dspName
 拉新转化要求时长：cpaDelay
 */
@property (nonatomic, readonly) NSDictionary *mediaExtraInfoDict;

/**
 摇一摇基本返回参数 key的定义如下：
 加速度:acceleration
 角度：angle
 时间:time
 */
@property (nonatomic, readonly) NSDictionary *shakeParamInfoDict;

/**
摇一摇是否可用， 默认YES
 */
@property (nonatomic, assign) BOOL isCanShake;
/**
摇一摇相关参数配置
 */
@property (nonatomic, strong) WanjaAdShakeConfigModel *shakeConfigModel;

//竞价成功时上报接口 secondWinPrice竞价第二名价格，单位是分
- (void)sendWinNotice:(NSInteger)secondWinPrice;
//竞价失败时上报接口 winPrice 胜出者价格 单位分 lossReason 竞价失败原因 winBidder 胜出者 （非必填）
- (void)sendLossNotice:(WanjaAdBiddingFailReason)lossReason winnerPirce:(NSInteger)winPrice winBidder:(NSString * _Nullable )bidder;
//获取requestId
- (NSString*)getRequestId;
//
- (NSString*)getTagId;
// 仅限sdk内部使用
- (NSDictionary *)appendToDictionary:(NSDictionary*)toDict fromDict:(NSDictionary*)fromDict;
@end

NS_ASSUME_NONNULL_END
