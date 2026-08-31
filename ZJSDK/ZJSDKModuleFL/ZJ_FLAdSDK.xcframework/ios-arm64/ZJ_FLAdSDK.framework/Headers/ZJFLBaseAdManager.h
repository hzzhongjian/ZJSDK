//
//  ZJFLBaseAdManager.h
//  ZJ_FLAdSDK
//
//  Created by lurich on 2022/11/8.
//

#import <Foundation/Foundation.h>
#import <ZJ_FLAdSDK/ZJFLVideoConfig.h>
#import "ZJFLMediaInfo.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ZJFLADResultTypeStart,
    ZJFLADResultTypeRequestAD,
    ZJFLADResultTypeLoadAD,
    ZJFLADResultTypeFail,
    ZJFLADResultTypeShow,
    ZJFLADResultTypeClick,
    ZJFLADResultTypeClose,
    ZJFLADResultTypeShowFail
} ZJFLADResultType;

typedef enum : NSUInteger {
    // 100 价格与竞价类
    /// 竞价低于底价
    ZJFLADBidLoss_BID_BELOW_FLOOR = 101,
    /// 竞价被击败
    ZJFLADBidLoss_LOST_TO_HIGHER_BID = 102,
    /// 优先交易拦截
    ZJFLADBidLoss_LOST_TO_PMP = 103,
    ///价格单位换算异常
    ZJFLADBidLoss_UNIT_MISMATCH = 104,
    
    // 200 超时与网络类
    /// SDK请求超时
    ZJFLADBidLoss_REQUEST_TIMEOUT = 201,
    /// 网络连接异常
    ZJFLADBidLoss_CONNECTION_ERROR = 202,
    /// 渲染/物料下载超时
    ZJFLADBidLoss_CACHE_TIMEOUT = 203,
    
    // 300 技术与规范类
    /// 响应解析失败
    ZJFLADBidLoss_PARSE_ERROR = 301,
    /// 缺少关键字段
    ZJFLADBidLoss_MISSING_FIELDS = 302,
    /// 尺寸/模板不匹配
    ZJFLADBidLoss_SIZE_MISMATCH = 303,
    /// 鉴权校验失败
    ZJFLADBidLoss_AUTH_INVALID = 304,
    
    // 400 质量与合规类
    ///素材审核拦截
    ZJFLADBidLoss_CREATIVE_REJECTED = 401,
    /// 行业/广告主屏蔽
    ZJFLADBidLoss_CATEGORY_BLOCKED = 402,
    /// 合规标识限制
    ZJFLADBidLoss_COMPLIANCE_BLOCKED = 403,
    
    // 500 策略与频控类
    /// 触发频次控制
    ZJFLADBidLoss_FREQUENCY_CAPPED = 501,
    /// A/B测试分流丢弃
    ZJFLADBidLoss_DROPPED_BY_AB = 502,
    /// 预加载废弃
    ZJFLADBidLoss_PRELOAD_DISCARDED = 503,
    
} ZJFLADBidLossReason;


@interface ZJFLADInfo : NSObject

/// 广告主名称
@property (nonatomic, copy) NSString *adnName;

/// 广告主APPID
@property (nonatomic, copy) NSString *adnAppID;

/// 广告位ID
@property (nonatomic, copy) NSString *adnPlaceID;

/// 最佳ECPM
@property (nonatomic) double ecpm;

/// 当前平台的APPID
@property (nonatomic, copy) NSString *appID;

/// 当前平台的广告位ID
@property (nonatomic, copy) NSString *placeID;

/// 广告加载ID
@property (nonatomic, copy) NSString *requestID;

/// 1、开屏、2、 插屏、3、 信息流（31：自渲染；32：模板）、4、 激励视频、5、 横幅
@property (nonatomic, assign) NSInteger adType;

/**
 * 返回广告是否可展示
 * @return 当广告已经加载完成&&未曝光&&未过期时，为YES，否则为NO
 */
@property (nonatomic, assign) BOOL isAdValid;

/// 初始化时传入的自定义信息
@property (nonatomic, strong) NSMutableDictionary *userInfo;

/// 媒体素材信息
@property (nonatomic, strong, nullable) ZJFLMediaInfo *mediaInfo;

@end

@interface ZJFLBaseAdManager : NSObject

/// 获取广告的广告位ID，必传
@property (nonatomic, copy) NSString *mediaId;

/// 视频相关控制，可选
@property (nonatomic, strong) ZJFLVideoConfig *videoConfig;

/// 自定义请求广告超时时间，可选，单位秒，建议至少 3 秒以上，（PS：设置请求限时，可能影响广告收益，非必要不要设置）
@property (nonatomic) double timeout;

/// 使用广告位ID初始化。
- (instancetype)initWithSlotId:(NSString *)slotId;

/// 是否可以请求广告数据
- (BOOL)isCanLoadAD;

/// 加载广告数据
- (void)loadAdData;

/// 填充后可调用，返回当前最佳广告的信息
- (ZJFLADInfo *)getCurrentBaseEcpmInfo;

/// 用户传入的自定义信息
-(NSMutableDictionary *) getUserInfoDic;

/// 自定义请求广告超时可调用，调用后可立即获得当前请求结果（成功 or 失败）
- (void)getCurrentBaseEcpmAD;

/// 获取广告ID列表
- (NSArray *) getADIDList;


/// ** 媒体竞价展示广告时需要上报，需要在调用广告 show 之前调用 **
/**
 *  ======= 我方竞胜后需要回传第二价 =======
 * @param secondPrice 媒体二价  (单位: 分)
 */
- (void)sendWinNotificationWithPrice:(CGFloat)secondPrice;
/**
 * ======= 我方竞败后需要回传最高价以及竞败原因 =======
 * @param firstPrice 媒体一价  (单位: 分)
 */
- (void)sendLossNotificationWithPrice:(CGFloat)firstPrice DEPRECATED_MSG_ATTRIBUTE("已弃用  使用sendLossNotificationWithPrice:(CGFloat)firstPrice andLossReason:(ZJFLADBidLossReason)reason替代");
/**
 * ======= 我方竞败后需要回传最高价以及竞败原因 =======
 * @param firstPrice 媒体一价  (单位: 分)
 * @param reason 失败原因
 */
- (void)sendLossNotificationWithPrice:(CGFloat)firstPrice andLossReason:(ZJFLADBidLossReason)reason;



@end

@interface ZJFLADResultInfo : NSObject

/// 广告信息
@property (nonatomic, strong) ZJFLADInfo *info;

/// 广告填充失败时的错误信息
@property (nonatomic, copy, nullable) NSError *error;;

/// 开屏广告流程状态
@property (nonatomic, assign) ZJFLADResultType type;

@end

NS_ASSUME_NONNULL_END
