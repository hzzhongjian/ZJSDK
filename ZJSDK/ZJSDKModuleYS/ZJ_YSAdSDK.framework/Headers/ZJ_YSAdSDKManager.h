//
//  ZJ_YSAdSDKManager.h
//  C_YSCommonBusiLib
//  广告管理
//  Created by yanchao on 2020/6/11.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, YSTestingEnvironmentType) {
    YSTestingEnvironmentTypeRelease = 0,  //**< 正式环境  */
    YSTestingEnvironmentTypeTest = 1,     //**< 测试环境（test10: https://test10.ezv-test.com）*/
    YSTestingEnvironmentTypeTest2 = 2,    //**< 测试环境2（test12: https://test12.ezv-test.com）*/
};

typedef NS_ENUM(NSUInteger, ZJ_YSAdSDKPackageType) {
    ZJ_YSAdSDKPackageTypeChina = 0,       //**< 国内  */
    ZJ_YSAdSDKPackageTypeOther = 1,        //**< 海外  */
};

@interface ZJ_YSAdSDKManager : NSObject


/**
 * 获取 SDK 版本
 */

+ (NSString *)sdkVersion;


/**
 设置日志开关
 非必传，默认开启
 */
+ (void)setOpenLog:(BOOL)isOpenLog;


/**
 设置SDK类型国内、海外 和areaId
 第一步必须先设置SDK类型
 @param sdkType SDK类型
 @param areaId 区域id（国内可以不传,直接传@"" 海外必传）
 */
+ (void)setAdvSDKPackageType:(ZJ_YSAdSDKPackageType)sdkType andAreaId:(NSString *)areaId;

/**
 设置mediaID
 必传，要不然获取不到广告
 */
+ (void)setMediaID:(NSString *)mediaID;

/**
 设置环境 分为测试环境、线上环境
 必传，区分环境
 */
+ (void)setTestingEnvironment:(YSTestingEnvironmentType)type completion:(void(^)(BOOL success))completion;

/**
 地理位置
 非必传，为了更精准的投放广告
 */
+ (void)setLocationWithLongitude:(double)longitude andLatitude:(double)latitude;


/**
 是否屏蔽个性化广告
 非必传，默认不屏蔽
 0，屏蔽个性化推荐广告；
 1，不屏蔽个性化推荐广告；
 */
+ (void)setPersonalAdsType:(NSInteger)type;

/**
 设置用户唯一标识
 非必传，建议传UserID等，方便后续排查问题
 */
+ (void)setUserIdentifierInfo:(NSString *)userIdentifierInfo;
@end

NS_ASSUME_NONNULL_END

