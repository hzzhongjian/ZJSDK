//
//  ZJSDKGlobalAdConfig.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/10/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 用来缓存广告全局配置数据的
 */
@interface ZJSDKGlobalAdConfig : NSObject

// ------------------输出价格的分成--------------

+ (void)setEcpmRatioValue:(NSNumber *)ecpm_radio_value platformType:(NSString *)platformType;

+ (NSNumber *)getEcpmRatioByPlatformType:(NSString *)platformType;

// -------------------比价的分成----------------
+ (void)setHBRatioValue:(NSNumber *)hb_radio platformType:(NSString *)platformType;

+ (NSNumber *)getHBRatioByPlatformType:(NSString *)platformType;

@end

NS_ASSUME_NONNULL_END
