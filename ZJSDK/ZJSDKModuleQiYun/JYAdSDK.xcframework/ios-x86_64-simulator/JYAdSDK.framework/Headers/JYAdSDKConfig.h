//
//  JYAdSDKConfig.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/4/30.
//

#import <Foundation/Foundation.h>
#import <JYAdSDK/JYAdSDKPrivacyConfig.h>

NS_ASSUME_NONNULL_BEGIN

#define JY_M_W_E_COST_PRICE @"expectCostPrice" \
    _Pragma("message(\"警告：JY_M_W_E_COST_PRICE已经过时，不必再传入，将在之后的版本删除。\")") \

#define JY_M_W_H_LOSS_PRICE @"highestLossPrice"
#define JY_M_L_WIN_PRICE @"winPrice"
#define JY_M_L_LOSS_REASON @"lossReason"
#define JY_M_ADN_TYPE @"adnType"
#define JY_M_ADN_IS_BID @"adnIsBid" \
    _Pragma("message(\"警告：JY_M_ADN_IS_BID已经过时，不必再传入，将在之后的版本删除。\")") \

#define JY_M_ADN_NAME @"adnName" \
    _Pragma("message(\"警告：JY_M_ADN_NAME已经过时，不必再传入，将在之后的版本删除。\")") \

typedef NS_ENUM(NSInteger, JYAdBiddingLossReason) {
    JYAdBiddingLossReasonOther                   = 10001,    // 其他
    JYAdBiddingLossReasonLowPrice                = 1,        // 竞争力不足
    JYAdBiddingLossReasonLoadTimeout             = 2,        // 返回超时
    JYAdBiddingLossReasonNoAd                    = 3,        // 媒体屏蔽-竞品相关 (部分开发者有做竞品相关屏蔽，包括但不限于：竞品包名屏蔽、竞品关键词屏蔽、竞品url屏蔽，物料屏蔽等)
    JYAdBiddingLossReasonAdDataError __attribute__((deprecated("Use JYAdBiddingLossReasonNoAd instead")))                 = 4,        // 回包不合法
    JYAdBiddingLossReasonAdSuccNoBid __attribute__((deprecated("Use JYAdBiddingLossReasonLowPrice instead")))             = 5,        // 有回包但未竞价
    JYAdBiddingLossReasonMediaBasePriceFilter __attribute__((deprecated("Use JYAdBiddingLossReasonLowPrice instead")))    = 6,        // 媒体侧底价过滤
    JYAdBiddingLossReasonCacheInvalid __attribute__((deprecated("Use JYAdBiddingLossReasonOther instead")))               = 7,        // 缓存失效
    JYAdBiddingLossReasonExposurePriorityReduce __attribute__((deprecated("Use JYAdBiddingLossReasonLowPrice instead")))  = 8,        // 曝光优先级降低
};

typedef NS_ENUM(NSInteger, JYAdAdnType) {
    JYAdAdnTypeSelfSale         = -1,    // 输给自售广告主
    JYAdAdnTypeOther            = 0,
    JYAdAdnTypeZSMOB            = 1,
    JYAdAdnTypeGDT              = 2,
    JYAdAdnTypeCSJ              = 3,    // 穿山甲/Gromore
    JYAdAdnTypeBaidu            = 8,
    JYAdAdnTypeKS               = 10,
    JYAdAdnTypeSIG              = 12,
    JYAdAdnTypeJD               = 14,
};

typedef NS_ENUM(NSUInteger, JYAdSdkUnionType) {
    JYAdSdkUnionTypeUnknown = 0,
    JYAdSdkUnionTypeADX = 1,
    JYAdSdkUnionTypeGDT = 2,
    JYAdSdkUnionTypeCSJ = 3,
    JYAdSdkUnionTypeBaidu = 8,
    JYAdSdkUnionTypeKS = 10,
    JYAdSdkUnionTypeSIG = 12, //sig
    JYAdSdkUnionTypeIQY = 13, //爱奇艺
    JYAdSdkUnionTypeJD = 14, //京东
    JYAdSdkUnionTypeKLN = 17, //游可赢
    JYAdSdkUnionTypeGromore = 18, //Gromore
};

@protocol JYAdProtocol <NSObject>

/**
 *  竞胜之后调用, 需要在调用广告 show 之前调用
 *
 *  @param winInfo 竞胜信息 字典类型，支持的key为以下，注：key是个宏，在JYAdSDKConfig.h中有定义，可以参考demo中的使用方法

 *  JY_M_W_H_LOSS_PRICE：最高失败出价，值类型为NSNumber  *
 *
 */
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;

/**
 *  竞败之后或未参竞调用
 *
 *  @pararm lossInfo 竞败信息，字典类型，注：key是个宏，在JYAdSDKConfig.h中有定义，可以参考demo中的使用方法
 *  JY_M_L_WIN_PRICE ：竞胜价格 (单位: 分)，值类型为NSNumber *，选填
 *  JY_M_L_LOSS_REASON ：JY广告竞败原因，竞败原因参考枚举JYAdBiddingLossReason中的定义，值类型为NSNumber *，必填
 *  JY_M_ADN_TYPE  ：竞胜方渠类型，参考枚举JYAdAdnType定义，需转为NSNumber *，必填
 */
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

@interface JYAdSDKConfig : NSObject
+ (void)initAppId:(NSString *)appId;
+ (void)initAppId:(NSString *)appId privacy:(JYAdSDKPrivacyConfig * _Nullable) privacy;
+ (NSString *)getAppId;
+ (BOOL)handleOpenUniversalLink:(NSUserActivity *)userActivity;
+ (void)setUserId:(NSString *)userId;
+ (NSString *)getUserId;
+ (NSString *)sdkVersion;
/**
 在播放音频时是否使用SDK内部对AVAudioSession设置的category及options，默认使用，若不使用，SDK内部不做任何处理，由调用方在展示广告时自行设置；
 SDK设置的category为AVAudioSessionCategoryAmbient，options为AVAudioSessionCategoryOptionDuckOthers
 */
+ (void)enableDefaultAudioSessionSetting:(BOOL)enabled;
/**
 是否屏蔽摇⼀摇，false 不屏蔽，true 屏蔽，默认不屏蔽
 */
+ (void)disableSplashAdShake:(BOOL)enabled __deprecated_msg("Use disableAdShake instead");

/**
 是否屏蔽摇一摇，false 不屏蔽，true 屏蔽，默认不屏蔽
 */
+ (void)disableAdShake:(BOOL)enabled;

/**
 是否屏蔽扭一扭，false 不屏蔽，true 屏蔽，默认不屏蔽
 */
+ (void)disableAdRotate:(BOOL)enabled;

@end

NS_ASSUME_NONNULL_END
