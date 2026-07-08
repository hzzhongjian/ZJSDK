//
//  ZJSDKPrivacyProvider.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/1/21.
//

#ifndef ZJSDKPrivacyProvider_h
#define ZJSDKPrivacyProvider_h

@protocol ZJSDKPrivacyProvider <NSObject>

@optional

/**
 * 获取应用包名限制状态，默认不限制
 */
- (NSDictionary *)getLimitSDKPackageName;

/**
 * 获取应用名称限制状态，默认不限制
 */
- (NSDictionary *)getLimitSDKDisplayName;

/**
 * 获取应用版本号限制状态，默认不限制
 */
//- (NSDictionary *)getLimitSDKVersionName;

/**
 * 获取应用内建版本号限制状态，默认不限制
 */
- (NSDictionary *)getLimitSDKBuildVersionCode;

/**
 * 获取设备型号限制状态，默认不限制
 */
- (NSDictionary *)getLimitSDKDeviceModel;

/**
 * 获取机型限制状态，默认不限制
 */
- (NSDictionary *)getLimitSDKMachine;

/**
 * 获取设备型号限制状态，默认不限制
 */
- (NSDictionary *)getLimitSDKModel;


/**
 * 获取屏幕方向限制状态，默认不限制
 */
//- (NSDictionary *)getLimitSDKScreenOrientation;

/**
 * 获取IDFV限制状态，默认不限制
 */
- (NSDictionary *)getLimitSDKIDFV;

/**
 * 获取IDFA限制状态，默认不限制
 */
- (NSDictionary *)getLimitSDKIDFA;

/**
 * 获取UUID限制状态，默认不限制
 *
 */
//- (NSDictionary *)getLimitSDKUUID;


@end



#endif /* ZJSDKPrivacyProvider_h */


