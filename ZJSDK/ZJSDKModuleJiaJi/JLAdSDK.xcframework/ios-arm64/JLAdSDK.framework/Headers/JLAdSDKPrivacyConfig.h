//
//  JLAdSDKPrivacyConfig.h
//  JLAdSDK
//
//  Created by jlad110 on 2022/5/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface JLAdSDKLocation : NSObject

@property (nonatomic, assign) double latitude;
@property (nonatomic, assign) double longitude;

@end

@interface JLAdSDKPrivacyConfig : NSObject
/**
 * 仅对，广点通、穿山甲、快手、京东、百度，有效
 * 默认YES，既允许获取IDFA
 */
@property (nonatomic, assign) BOOL canUseIDFA;
/**
 * 仅对，快手、京东，有效
 * 默认YES，既允许获取位置
 */
@property (nonatomic, assign) BOOL canUseLocation;
/**
 * 仅对，穿山甲、快手、京东，有效
 * 当canUseIDFA为NO时customIDFA生效
 */
@property (nonatomic, strong, nullable) NSString * customIDFA;
/**
 * 仅对，快手、京东，有效
 */
@property (nonatomic, strong, nullable) JLAdSDKLocation * location;

@end

NS_ASSUME_NONNULL_END
