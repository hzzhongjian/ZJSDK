//
//  WanjaAdManager.h
//  FBSnapshotTestCase
//
//  Created by guantou on 2023/10/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class WanjaUserProfileModel;
@interface WanjaPrivacyModel : NSObject<NSCopying>

/**  是否允许sdk内部获取IDFA 默认允许 0 允许，1 不允许  **/
@property (nonatomic, assign) BOOL isLimitPersonalAds;

/**  是否允许sdk内部获取iosid  默认允许 0 允许，1 不允许,  目前不允许设置为1  **/
@property (nonatomic, readonly) BOOL isLimitSdidAds;

/**  是否允许sdk内部修改AVAudioSession 的 AVAudioSession.Category   默认允许 0 允许，1 不允许,  **/
@property (nonatomic, assign) BOOL isLimitAudioSessionCategory;

/**  是否允许摇一摇   默认允许 0 允许，1 不允许,  **/
@property (nonatomic, assign) BOOL isLimitShake;

/**  是否允许sdk内部获取位置信息  默认允许 0 允许，1 不允许  **/
@property (nonatomic, assign) BOOL isLimitLocationAds;
/**isLimitLocationAds=0时，该属性有效，默认值0：允许内部获取定位权限，然后获取位置；否则：内部不获取定位权限，只在外部开启定位权限后， 才会获取位置
 从2.6.1.1版本开始，该属性将失效
 */
@property (nonatomic, assign) BOOL isOnlyLocation;
//-------------如果isLimitLocationAds=1， 那么需要传入位置参数-------------------------
//type为坐标系，默认 0:WGS-84(GPS)    1:GCJ-02 (高德) 2:BAIDU（百度）
@property (nonatomic, assign) NSInteger type;
//获取位置的时间戳，单位ms
@property (nonatomic, assign) uint64_t time;
//纬度
@property (nonatomic, assign) double lat;
//经度
@property (nonatomic, assign) double lng;
//--------------位置参数-------------------------

/**  userAgent的回调， 如果设置了， 那么sdk内部将不再将通过webview获取UA  **/
@property (nonatomic, copy) NSString *(^userAgentBlock)(void);

// 用户画像， 默认nil，非必传
@property (nonatomic, strong) WanjaUserProfileModel *userProfile;

// 是否隐藏反馈按钮, 默认NO
@property (nonatomic, assign) BOOL isHiddenFeedbackButton;
@end


@interface WanjaAdManager : NSObject

/** 预安装隐私配置, 最好在 configureWithApplicationID方法之前调用*/
+ (void)preSetupPrivacyConfig:(WanjaPrivacyModel*)privacyModel;

/**  初始化SDK  **/
+ (void)configureWithApplicationID:(NSString *)appId;

/**  初始化SDK，并配置隐设置  **/
+ (void)configureWithApplicationID:(NSString *)appId andPrivacy:(nullable WanjaPrivacyModel *)model;

/**  初始化SDK，并配置隐设置,  有完成回调  **/
+ (void)configureWithApplicationID:(NSString *)appId andPrivacy:(WanjaPrivacyModel *)model complete:(nullable void (^)(BOOL success)) complete;

/**  初始化SDK，并配置隐设置,  有完成回调,   增加了https选项  **/
+ (void)configureWithApplicationID:(NSString *)appId andPrivacy:(WanjaPrivacyModel *)model complete:(nullable void (^)(BOOL success)) complete isUseHttps:(BOOL)isUseHttps;

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

//如果不允许sdk内部获取位置， 可以在初始化sdk后， 通过这个方法设置位置信息
+ (void)setupLocation:(double)lat lng:(double)lng type:(NSInteger)type time:(uint64_t)time;

/**
 如果在初始化时，关闭了定位权限， 那么可以通过这个方法， 主动打开SDK定位。
 isOnlyLocation： YES，SDK不主动开启定位权限，只在外部开启定位权限后， 才会获取位置；反之，SDK先开启定位权限，然后获取位置
 */
+ (void)startSDKLocation:(BOOL)isOnlyLocation;

/**
 配置用户画像，非必选项
 */
+ (void)configUserProfile:(WanjaUserProfileModel *)userProfile;

/**
 控制反馈按钮显示，默认显示反馈按钮
 */
+ (void)hiddenFeedbackButton:(BOOL)isHidden;

/**
 设置IDFV， 建议在configureWithApplicationID方法之前， 就要设置上， 以保持数据的一致性
 */
+ (void)setupIDFV:(NSString *)idfv;

@end

NS_ASSUME_NONNULL_END
