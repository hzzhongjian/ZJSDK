//
//  ZJSDKPrivacyAuthorityModel.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/1/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
* 该类是用来控制联盟SDK获取隐私权限的，媒体可根据自己实际情况进行控制
* 默认情况下，允许所有联盟SDK可以获取的
*/

@interface ZJSDKPrivacyAuthorityModel : NSObject

/// 是否允许SDK使用定位权限，默认为YES
@property (nonatomic, assign) BOOL canUseLocation;

/// 是否允许SDK使用WiFi BSSID，默认为YES
@property (nonatomic, assign) BOOL canUseWiFiBSSID;

/// 是否允许SDK获取IDFA，默认为YES
@property (nonatomic, assign) BOOL canUseIDFA;

/// 是否允许SDK获取IDFV，默认为YES
@property (nonatomic, assign) BOOL canUseIDFV;

/// 是否允许获取手机状态信息，默认为YES
@property (nonatomic, assign) BOOL canUsePhoneStatus;

/// 收否允许获取手机DeviceId，默认为YES
@property (nonatomic, assign) BOOL canUseDeviceId;

/// 是否允许获取手机系统版本名，默认为YES
@property (nonatomic, assign) BOOL canUseOSVersionName;

/// 是否允许获取手机系统版本号，默认为YES
@property (nonatomic, assign) BOOL canUseOSVersionCode;

/// 是否允许获取手机应用包名，默认为YES
@property (nonatomic, assign) BOOL canUsePackageName;

/// 是否允许获取手机应用版本名，默认为YES
@property (nonatomic, assign) BOOL canUseAppVersionName;

/// 是否允许获取手机应用版本号，默认为YES
@property (nonatomic, assign) BOOL canUseAppVersionCode;

/// 是否允许获取手机设备品牌，默认为YES
@property (nonatomic, assign) BOOL canUseBrand;

/// 是否允许获取手机设备型号，默认为YES
@property (nonatomic, assign) BOOL canUseModel;

/// 是否允许获取手机屏幕分辨率，默认为YES
@property (nonatomic, assign) BOOL canUseScreen;

/// 是否允许获取手机屏幕方向，默认为YES
@property (nonatomic, assign) BOOL canUseOrient;

/// 是否允许获取手机网络类型，默认为YES
@property (nonatomic, assign) BOOL canUseNetworkType;

/// 是否允许获取手机移动网络代码，默认为YES
@property (nonatomic, assign) BOOL canUseMNC;

/// 是否允许获取手机移动国家代码，默认为YES
@property (nonatomic, assign) BOOL canUseMCC;

/// 是否允许获取手机系统语言，默认为YES
@property (nonatomic, assign) BOOL canUseOSLanguage;

/// 是否允许获取手机时区，默认为YES
@property (nonatomic, assign) BOOL canUseTimeZone;

/// 是否允许获取手机User Agent，默认为YES
@property (nonatomic, assign) BOOL canUseUserAgent;

/// 是否允许SDK主动使用互动组件能力（摇一摇、扭一扭等），默认为YES
@property (nonatomic, assign) BOOL isCanUseMotionManager;

/// 是否允许获取IP地址
@property (nonatomic, assign) BOOL canUseIPAddress;

@end

NS_ASSUME_NONNULL_END
