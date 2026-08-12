//
//  JYAdSDKPrivacyConfig.h
//  JYAdSDK
//
//  Created by jyad110 on 2022/5/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JYAdSDKLocation : NSObject

@property (nonatomic, assign) double latitude;
@property (nonatomic, assign) double longitude;

/**
 * 返回当前位置信息的属性值字典
 *
 * @return 包含当前实例所有属性值的 NSDictionary 对象
 */
- (NSDictionary *)toDictionary;

@end

@interface JYAdSDKPrivacyConfig : NSObject
/**
 * 仅对，广点通、穿山甲、快手、爱奇艺、京东、百度，有效
 * 默认YES，既允许获取IDFA
 */
@property (nonatomic, assign) BOOL canUseIDFA;
/**
 * 仅对，快手、爱奇艺、京东，有效
 * 默认YES，既允许获取位置
 */
@property (nonatomic, assign) BOOL canUseLocation;
/**
 * 个性化推荐开关。
 * 默认YES；设置为NO后，支持该能力的广告联盟将不再根据个性化能力推荐广告。
 */
@property (nonatomic, assign) BOOL enablePersonalized;
/**
 * 是否允许广告联盟获取 IDFV。
 * 默认YES。
 */
@property (nonatomic, assign) BOOL IDFV;
/**
 * 自定义 IDFV。
 * 当IDFV为NO时，由支持该能力的广告联盟使用。
 */
@property (nonatomic, copy, nullable) NSString *customIDFV;
/**
 * 是否允许广告联盟获取运营商信息。
 * 默认YES。
 */
@property (nonatomic, assign) BOOL carrier;
/**
 * 自定义运营商信息，格式为 MCC 拼接 MNC，例如 46000。
 * 当carrier为NO时，由支持该能力的广告联盟使用。
 */
@property (nonatomic, copy, nullable) NSString *customCarrier;
/**
 * 仅对，穿山甲、快手、爱奇艺、京东，有效
 * 当canUseIDFA为NO时customIDFA生效
 */
@property (nonatomic, strong, nullable) NSString * customIDFA;
/**
 * 仅对，快手、爱奇艺、京东，有效
 */
@property (nonatomic, strong, nullable) JYAdSDKLocation * location;

/**
 * 添加各广告联盟的自定义扩展参数。例如 IQY 支持以下键：
 * ItunesAppleId（NSString，App Store Apple ID）、AppMode（NSNumber，0 至 4）、
 * TestMode（NSNumber/NSString，BOOL）、ChannelId（NSString）、
 * AppOrientation（NSNumber，UIInterfaceOrientation）和 AudioMix（NSNumber/NSString，BOOL）。
 */
@property (nonatomic, strong, nullable) NSDictionary *extraUserData;

/**
 * 返回当前隐私配置的属性值字典
 *
 * @return 包含当前实例所有属性值的 NSDictionary 对象
 */
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
