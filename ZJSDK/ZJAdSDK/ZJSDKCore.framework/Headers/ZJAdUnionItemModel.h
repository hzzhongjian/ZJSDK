//
//  ZJAdUnionItemModel.h
//  ZJSDKCore
//
//  Created by Rare on 2022/2/24.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const ZJ_ADType_Splash;
FOUNDATION_EXPORT NSString * const ZJ_ADType_SplashFullVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Interstitial;
FOUNDATION_EXPORT NSString * const ZJ_ADType_NewInterstitial;
FOUNDATION_EXPORT NSString * const ZJ_ADType_RewardVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FeedFullVideo;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FullVideoAd;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Banner;
FOUNDATION_EXPORT NSString * const ZJ_ADType_News;
FOUNDATION_EXPORT NSString * const ZJ_ADType_Feed;
FOUNDATION_EXPORT NSString * const ZJ_ADType_NativeAd;
FOUNDATION_EXPORT NSString * const ZJ_ADType_ContentPage;
FOUNDATION_EXPORT NSString * const ZJ_ADType_TubePage;
FOUNDATION_EXPORT NSString * const ZJ_ADType_FeedPage;
FOUNDATION_EXPORT NSString * const ZJ_ADType_HorizontalFeed;
FOUNDATION_EXPORT NSString * const ZJ_ADType_ImageTextPage;
FOUNDATION_EXPORT NSString * const ZJ_ADType_MiniParam;
// 信息流和banner融合
FOUNDATION_EXPORT NSString * const ZJ_ADType_NativeExpress_Banner;
// 信息流实现的开屏
FOUNDATION_EXPORT NSString * const ZJ_ADType_NativeExpress_Splash;
// 信息流实现的插屏
FOUNDATION_EXPORT NSString * const ZJ_ADType_NativeExpress_Interstitial;
// 信息流实现的激励
FOUNDATION_EXPORT NSString * const ZJ_ADType_NativeExpress_RewardVideo;
// 自渲染实现的开屏
FOUNDATION_EXPORT NSString * const ZJ_ADType_Native_Splash;
// 自渲染实现的插屏
FOUNDATION_EXPORT NSString * const ZJ_ADType_Native_Interstitial;
// 自渲染实现的激励
FOUNDATION_EXPORT NSString * const ZJ_ADType_Native_RewardVideo;
// 自渲染实现的信息流
FOUNDATION_EXPORT NSString * const ZJ_ADType_Native_NativeExpress;
// 自渲染实现的Banner
FOUNDATION_EXPORT NSString * const ZJ_ADType_Native_Banner;



typedef NS_ENUM(NSInteger,ZJAdShowPriority){
    ZJAdShowPriority_normal, // 返回快
    ZJAdShowPriority_weight, // 权重
    ZJAdShowPriority_highPrice, // 更高价格
    ZJAdShowPriority_bidding,
};

@class ZJAdUnitModel;
@interface ZJAdUnionItemModel : NSObject

@property (nonatomic, assign) ZJAdShowPriority showPriority;
@property (nonatomic, assign) NSInteger show_genre;

@property (nonatomic, assign) long timeout;

@property (nonatomic, copy) NSString *pd_price;

@property (nonatomic, assign) BOOL is_service;

//@property (nonatomic, assign) BOOL is_cdn;

@property (nonatomic, assign) BOOL is_pd_cache;

@property (nonatomic, assign) BOOL is_verify_params;

@property (nonatomic, assign) NSInteger reward_ver;

@property (nonatomic, copy) NSArray <ZJAdUnitModel *>*tiers;

-(NSArray <ZJAdUnitModel *>*)parseUnionItems:(NSArray *)items;

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *zj_adID;

/// 是否为bidding广告位
@property (nonatomic, assign) BOOL is_bidding;
//辅助
@property (nonatomic, assign) NSInteger currentLevel;
@property (nonatomic, assign) NSInteger totalLevels;

/// 流量组分组
@property (nonatomic, copy) NSString *title;
/// 流量组id
@property (nonatomic, assign) long pos_template_id;

@end

@interface ZJAdUnitModel : NSObject

/// pm_id 联盟的广告id
@property (nonatomic, copy) NSString *adId;

@property (nonatomic, assign) BOOL is_enable;
/// 是否开启服务校验，0 关闭，1开启
@property (nonatomic, assign) BOOL is_service;


/// 时间戳
@property (nonatomic, copy) NSString *msel;

/// 同步校验参数
@property (nonatomic, assign) BOOL is_verify_params;

/// 请求激励版本
@property (nonatomic, assign) NSInteger reward_ver;
///当日限制次数
@property (nonatomic, assign) NSInteger limit_num;
///开始次数
@property (nonatomic, assign) NSInteger start_num;
///加载次数
@property (nonatomic, assign) NSInteger loaded_num;
///曝光次数
@property (nonatomic, assign) NSInteger exposed_num;
/// 正在被限制
@property (nonatomic, assign) BOOL is_being_limit;
/// 网络错误限制策略
@property (nonatomic, strong) NSString *error_strategy;
/// 连续加载失败限制策略
@property (nonatomic, strong) NSString *load_strategy;
/// 连续不完成限制
@property (nonatomic, strong) NSString *finish_strategy;

@property (nonatomic, assign) ZJAdPlatformType platformType;

@property (nonatomic, copy) NSString *platform;

///权重 在params中获取
@property (nonatomic, assign) NSInteger weight;

/// Bid底价 在params中获取
@property (nonatomic, assign) NSInteger bid_floor;

///其它参数
@property (nonatomic, strong) NSDictionary *params;

///摇一摇力度
@property (nonatomic, strong) NSString *shake_power;

@property (nonatomic, copy) NSString *type;

@property (nonatomic, copy) NSString *zj_adID;

@property (nonatomic, copy) NSString *pd_price;

/// 是否为bidding广告位
@property (nonatomic, assign) BOOL is_bidding;

///辅助
@property (nonatomic, copy) NSString *adType;

/// 开屏样式 原生模板 0, 自渲染 1, 全屏视频开屏 2
@property (nonatomic, assign) NSInteger splash_native;

///IPD 开屏样式：普通开屏  0，奖励式开屏 1，全屏视频开屏 2，目前使用的是这个字段
@property (nonatomic, assign) NSInteger splash_type;

/// 激励样式：激励视频 0，插屏全屏 1
@property (nonatomic, assign) NSInteger reward_type;

/// 插屏样式：插屏半屏 0，插屏全屏 1，激励视频 3
@property (nonatomic, assign) NSInteger interstitial_type;

///屏蔽开屏摇一摇  仅GDT
@property (nonatomic, copy) NSNumber* shakable;

///是否显示关闭按钮
@property (nonatomic, copy) NSNumber* is_show_close_btn;

///H5 是否跳转系统浏览器
@property (nonatomic, copy) NSNumber* is_jump_system_browse;
/**
 * 兜底视频跳转url     DSP
 *
 * 配了就加载兜底视频，小于五位加载不响应跳转，大于5位跳转
*/
@property (nonatomic, copy) NSString* lv_url;

/**
 * 兜底视频跳过时长    DSP
 *
 * 容错区间 (0-8)
 */
@property (nonatomic, copy) NSString* lv_sd;

/// 本地激励浏览广告位ID
@property (nonatomic, copy) NSString *lrp_id;

/// 本地激励浏览标题
@property (nonatomic, copy) NSString *lrp_title;

/// 流量组分组
@property (nonatomic, copy) NSString *title;
/// 流量组id
@property (nonatomic, assign) long pos_template_id;

/// 每次请求随机生成的唯一id
@property (nonatomic, copy) NSString *uniqueDeviceID;

/// 联盟提供的广告唯一标识
@property (nonatomic, copy) NSString *adn_extra;

/// 记录当前广告是否已经曝光
@property (nonatomic, assign) BOOL hasReportExposure;

@end

NS_ASSUME_NONNULL_END
