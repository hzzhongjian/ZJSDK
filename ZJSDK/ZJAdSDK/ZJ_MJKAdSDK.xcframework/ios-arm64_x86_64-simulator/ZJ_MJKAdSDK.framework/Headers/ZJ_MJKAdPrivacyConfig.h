//
//  ZJ_MJKAdPrivacyConfig.h
//  ZJ_MJKAdSDK
//

#ifndef ZJ_MJKAdPrivacyConfig_h
#define ZJ_MJKAdPrivacyConfig_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** 开发者提供给 SDK 的位置信息。 */
@interface ZJ_MJKAdPrivacyLocation : NSObject

@property (nonatomic, assign) double latitude;
@property (nonatomic, assign) double longitude;

- (instancetype)initWithLatitude:(double)latitude longitude:(double)longitude;

@end

/**
 SDK 隐私及交互能力配置。传 nil 给初始化接口时，所有能力均默认开启。
 */
@interface ZJ_MJKAdPrivacyConfig : NSObject

/** 是否允许 SDK 获取网络类型，默认 YES。 */
@property (nonatomic, assign) BOOL isCanReadNetType;

/** 是否允许 SDK 获取定位信息，默认 YES。 */
@property (nonatomic, assign) BOOL isCanReadLocal;

/** 开发者自行获取的定位信息；未设置时为 nil。 */
@property (nonatomic, strong, nullable) ZJ_MJKAdPrivacyLocation *location;

/** 是否允许 SDK 获取 IDFA，默认 YES。 */
@property (nonatomic, assign) BOOL isCanReadIDFA;

/** 开发者自行获取的 IDFA；未设置时为 nil。 */
@property (nonatomic, copy, nullable) NSString *idfa;

/** 是否支持广告摇一摇交互，默认 YES。 */
@property (nonatomic, assign) BOOL isSupportShake;

@end

NS_ASSUME_NONNULL_END

#endif /* ZJ_MJKAdPrivacyConfig_h */
