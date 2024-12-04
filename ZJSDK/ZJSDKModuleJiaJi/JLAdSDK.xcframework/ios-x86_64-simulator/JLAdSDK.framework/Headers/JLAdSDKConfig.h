//
//  JLAdSDKConfig.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/4/30.
//

#import <Foundation/Foundation.h>
#import <JLAdSDK/JLAdSDKPrivacyConfig.h>

NS_ASSUME_NONNULL_BEGIN

#define JL_M_W_E_COST_PRICE @"expectCostPrice" \
    _Pragma("message(\"警告：JL_M_W_E_COST_PRICE已经过时，不必再传入，将在之后的版本删除。\")") \

#define JL_M_W_H_LOSS_PRICE @"highestLossPrice"
#define JL_M_L_WIN_PRICE @"winPrice"
#define JL_M_L_LOSS_REASON @"lossReason"
#define JL_M_ADN_TYPE @"adnType"
#define JL_M_ADN_IS_BID @"adnIsBid" \
    _Pragma("message(\"警告：JL_M_ADN_IS_BID已经过时，不必再传入，将在之后的版本删除。\")") \

#define JL_M_ADN_NAME @"adnName" \
    _Pragma("message(\"警告：JL_M_ADN_NAME已经过时，不必再传入，将在之后的版本删除。\")") \

typedef NS_ENUM(NSInteger, JLAdBiddingLossReason) {
    JLAdBiddingLossReasonOther                   = 10001,    // 其他
    JLAdBiddingLossReasonLowPrice                = 1,        // 竞争力不足
    JLAdBiddingLossReasonLoadTimeout             = 2,        // 返回超时
    JLAdBiddingLossReasonNoAd                    = 3,        // 媒体屏蔽-竞品相关 (部分开发者有做竞品相关屏蔽，包括但不限于：竞品包名屏蔽、竞品关键词屏蔽、竞品url屏蔽，物料屏蔽等)
    JLAdBiddingLossReasonAdDataError __attribute__((deprecated("Use JLAdBiddingLossReasonNoAd instead")))                 = 4,        // 回包不合法
    JLAdBiddingLossReasonAdSuccNoBid __attribute__((deprecated("Use JLAdBiddingLossReasonLowPrice instead")))             = 5,        // 有回包但未竞价
    JLAdBiddingLossReasonMediaBasePriceFilter __attribute__((deprecated("Use JLAdBiddingLossReasonLowPrice instead")))    = 6,        // 媒体侧底价过滤
    JLAdBiddingLossReasonCacheInvalid __attribute__((deprecated("Use JLAdBiddingLossReasonOther instead")))               = 7,        // 缓存失效
    JLAdBiddingLossReasonExposurePriorityReduce __attribute__((deprecated("Use JLAdBiddingLossReasonLowPrice instead")))  = 8,        // 曝光优先级降低
};

typedef NS_ENUM(NSInteger, JLAdAdnType) {
    JLAdAdnTypeSelfSale         = -1,    // 输给自售广告主
    JLAdAdnTypeOther            = 0,
    JLAdAdnTypeZSMOB            = 1,
    JLAdAdnTypeGDT              = 2,
    JLAdAdnTypeCSJ              = 3,    // 穿山甲/Gromore
    JLAdAdnTypeBaidu            = 8,
    JLAdAdnTypeKS               = 10,
    JLAdAdnTypeSIG              = 12,
    JLAdAdnTypeJD               = 14,
};

typedef NS_ENUM(NSUInteger, JLAdSdkUnionType) {
    JLAdSdkUnionTypeUnknown = 0,
    JLAdSdkUnionTypeADX = 1,
    JLAdSdkUnionTypeGDT = 2,
    JLAdSdkUnionTypeCSJ = 3,
    JLAdSdkUnionTypeBaidu = 8,
    JLAdSdkUnionTypeKS = 10,
    JLAdSdkUnionTypeSIG = 12, //sig
    JLAdSdkUnionTypeIQY = 13, //爱奇艺
    JLAdSdkUnionTypeJD = 14, //京东
    JLAdSdkUnionTypeKLN = 17, //游可赢
    JLAdSdkUnionTypeGromore = 18, //Gromore
};

@protocol JLAdProtocol <NSObject>

/**
 *  竞胜之后调用, 需要在调用广告 show 之前调用
 *
 *  @param winInfo 竞胜信息 字典类型，支持的key为以下，注：key是个宏，在JLAdSDKConfig.h中有定义，可以参考demo中的使用方法

 *  JL_M_W_H_LOSS_PRICE：最高失败出价，值类型为NSNumber  *
 *
 */
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;

/**
 *  竞败之后或未参竞调用
 *
 *  @pararm lossInfo 竞败信息，字典类型，注：key是个宏，在JLAdSDKConfig.h中有定义，可以参考demo中的使用方法
 *  JL_M_L_WIN_PRICE ：竞胜价格 (单位: 分)，值类型为NSNumber *，选填
 *  JL_M_L_LOSS_REASON ：JL广告竞败原因，竞败原因参考枚举JLAdBiddingLossReason中的定义，值类型为NSNumber *，必填
 *  JL_M_ADN_TYPE  ：竞胜方渠类型，参考枚举JLAdAdnType定义，需转为NSNumber *，必填
 */
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

@interface JLAdSDKConfig : NSObject
+ (void)initAppId:(NSString *)appId;
+ (void)initAppId:(NSString *)appId privacy:(JLAdSDKPrivacyConfig * _Nullable) privacy;
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
 是否屏蔽摇⼀摇，false或者不赋值，不屏蔽，true屏蔽
 */
+ (void)disableSplashAdShake:(BOOL)enabled;
@end

NS_ASSUME_NONNULL_END
