//
//  KSAdSDKConfiguration.h
//  KSUAdSDKManager
//
//  Created by mohao on 2023/12/7.
//

#import <Foundation/Foundation.h>

#if __has_include(<KSUDefine/KSAdSDKLogLevelDefine.h>)
#import <KSUDefine/KSAdSDKLogLevelDefine.h>
#else
#import "KSAdSDKLogLevelDefine.h"
#endif

#if __has_include(<KSUSDKInfo/KSAdUserInfo.h>)
#import <KSUSDKInfo/KSAdUserInfo.h>
#else
#import "KSAdUserInfo.h"
#endif

#if __has_include(<KSUPermission/KSAdPermission.h>)
#import <KSUPermission/KSAdPermission.h>
#else
#import "KSAdPermission.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface KSAdSDKConfiguration : NSObject

+ (instancetype)configuration NS_SWIFT_NAME(configuration());

@property (nonatomic, copy) NSString *appId;

@property (nonatomic, copy, nullable) NSString *appName;
// optional
@property (nonatomic, copy, nullable) NSString *appTag;
// optional
- (void)setUserInfoBlock:(void(^)(KSAdUserInfo *))userInfoBlock;
// optional, enable personalized recommendation, default is YES
- (void)setEnablePersonalRecommend:(BOOL)enable;
// optional, enable programmatic recommendation, default is YES
- (void)setEnableProgrammaticRecommend:(BOOL)enable;

/// Configure user info.
/// @param age optional 年龄段
/// @param gender optional 性别
/// @param interest optional 兴趣标签
- (void)setUserAge:(KSAdUserInfoThirdAgeType)age
            gender:(KSAdUserInfoThirdGengerType)gender
          interest:(NSString *_Nullable)interest;
/// Configure appInfo content.
/// @param prevTitle optional 内容标签（广告展示前文章标题）
/// @param postTitle optional 内容标签（广告展示后文章标题）
/// @param historyTitle optional 内容标签（用户最近浏览文章标题）
/// @param channel optional 频道标签
- (void)setContentPrevTitle:(NSString *_Nullable)prevTitle
                  postTitle:(NSString *_Nullable)postTitle
               historyTitle:(NSString *_Nullable)historyTitle
                    channel:(NSString *_Nullable)channel;
// optional 媒体底价
- (void)setCpmBidFloor:(NSInteger)cpmBidFloor;
/**
 Configure development mode.
 @param level : default KSAdSDKLogLevelNone
 */
// optional
- (void)setLoglevel:(KSAdSDKLogLevel)level;

// optional, disable use location status, default is NO
- (void)setDisableUseLocationStatus:(BOOL)disable;

- (void)setLocationBlock:(LocationBlock)locationBlock;

// optional, disable use phone status, default is NO
- (void)setDisableUsePhoneStatus:(BOOL)disable;
// optional, 设置idfa，请传原始值，不需要加密
- (void)setIdfaBlock:(IdfaBlock)idfaBlock;
// optional, 设置idfv，请传原始值，不需要加密
- (void)setIdfvBlock:(IdfvBlock)idfvBlock;
// optional, 设置接入方deviceId
- (void)setDeviceIdBlock:(DeviceIdBlock)deviceIdBlock;

@end

NS_ASSUME_NONNULL_END
