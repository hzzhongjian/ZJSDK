//
//  ZJSDKInitConfig.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/9/10.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
#import <ZJSDKCore/ZJSDKInitModel.h>
#import <ZJSDKCore/ZJSDKPrivacyAuthorityModel.h>
#import <ZJSDKCore/ZJSDKPrivacyProvider.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 此类配置需要再初始化sdk之前设置
 */

@interface ZJSDKInitConfig : NSObject


+ (instancetype)sharedInstance;

@property (nonatomic, strong) ZJSDKInitModel *sdkInitModel;

// 个性化推荐
@property (nonatomic, assign) ZJSDKPersionalizedState persionalizedState;

// 程序化推荐开关
@property (nonatomic, assign) ZJSDKProgrammaticRecommend programmaticRecommend;

/**
 * 用户控制聚合SDK隐私权限
 */
@property (nonatomic, strong) ZJSDKPrivacyAuthorityModel *privacyAuthorityModel;

/**
 * 用户控制ZJSDK隐私权限
 */
@property (nonatomic, strong, nullable) id <ZJSDKPrivacyProvider> privacyProvider;

/**
 * 是否需要接口支持https请求，由媒体自己设置，默认是NO不支持，YES是支持
 */
@property (nonatomic, assign) BOOL isSupportHttps;

@end

NS_ASSUME_NONNULL_END
