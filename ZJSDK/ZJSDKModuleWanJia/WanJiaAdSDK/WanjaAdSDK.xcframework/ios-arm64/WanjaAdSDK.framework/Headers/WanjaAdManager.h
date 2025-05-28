//
//  WanjaAdManager.h
//  FBSnapshotTestCase
//
//  Created by guantou on 2023/10/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WanjaPrivacyModel : NSObject

/**  是否允许sdk内部获取IDFA 默认允许 0 允许，1 不允许  **/
@property (nonatomic, assign) BOOL isLimitPersonalAds;
/**  是否允许sdk内部获取caid  默认允许 0 允许，1 不允许,  目前不允许设置为1  **/
@property (nonatomic, readonly) BOOL isLimitSdidAds;

@end


@interface WanjaAdManager : NSObject

/**  初始化SDK  **/
+ (void)configureWithApplicationID:(NSString *)appId;

/**  初始化SDK，并配置隐设置  **/
+ (void)configureWithApplicationID:(NSString *)appId andPrivacy:(WanjaPrivacyModel *)model;

/**  设置idfa
 idfa="C1717E80-F120-4947-BAD5-2695E0161D7F"
 **/
+ (void)setupIDFA:(NSString *)idfa;

/**  SDK版本号  **/
+ (NSString *)sdkVersion;

/**  IDFA **/
+ (NSString *)getIdfa;

/**  deviceid  **/
+ (NSString *)getDeviceid;

/**  打开调试开关,  默认是关闭， 如果需要调试将其设置成YES， 但是发布上线时一定要记得关掉这个开关  **/
+ (void)openDebugModel:(BOOL)isOpen;

//如果App启动后，动态改变了隐私配置，那么可以通过这个接口来更新隐私设置
+ (void)updatePersonalPrivacyAds:(WanjaPrivacyModel*)privacyModel;


@end

NS_ASSUME_NONNULL_END
