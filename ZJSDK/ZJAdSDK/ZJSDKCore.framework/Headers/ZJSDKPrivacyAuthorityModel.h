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


@end

NS_ASSUME_NONNULL_END
