//
//  ZJFLAdSDKManager.h
//  AdDemo
//
//  Created by lurich on 2021/9/14.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>


typedef NS_ENUM(NSInteger, ZJFLGDPRConsentSet) {
    ZJFLGDPRConsentSetUnknown = 0,
    ZJFLGDPRConsentSetPersonalized,
    ZJFLGDPRConsentSetNonpersonalized
};

typedef NS_ENUM(NSInteger, ZJFLADEnvironment) {
    ZJFLADEnvironmentDebug = 0,   // 内网
    ZJFLADEnvironmentChina,
    ZJFLADEnvironmentOther,       // 海外
    ZJFLADEnvironmentAuto
};

NS_ASSUME_NONNULL_BEGIN

@interface ZJFLAdSDKManager : NSObject

@property (nonatomic, strong) NSMutableDictionary *registerDict;

@property (nonatomic, strong) id _Nullable manager;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
+ (instancetype)defaultManager;

/// 自定义设置用户的GDPR，GDPR是《通用数据保护条例》的缩写，界面仅适用于欧洲。
@property (nonatomic, readonly) ZJFLGDPRConsentSet dataConsentSet;

/// 大图片的展示样式，默认值为UIViewContentModeScaleAspectFit
@property (nonatomic) UIViewContentMode contentMode;

/// 国内注册APP id
+ (BOOL)registerAppId:(NSString *)appId;
/// 海外注册APP id
+ (BOOL)registerAppId:(NSString *)appId Environment:(ZJFLADEnvironment)environment;
/// 获取注册的APP id
+ (NSString *)appId;
///执行后需重新进行初始化
+ (void)unRegister;

/// 设置主渠道
+ (void)setChannel:(NSString *)channel;

/// 设置子渠道
+ (void)setSubChannel:(NSString *)sub_channel;

+ (void)setSourceTag:(NSString *)source_tag;

/// 是否限制个性化广告，  YES:限制   NO:不限制    默认为NO
+ (void)setPersonalizedState:(BOOL)state;

/// 是否允许sdk 获取当前设备经纬度信息  YES:允许   NO:不允许   默认NO
+ (void)getLocationInfo:(BOOL)state;

/// 设置地理位置经纬度，可提高广告填充及收益
+ (void)setGeographicLocationLongitude:(NSString *)longitude Latitude:(NSString *)latitude;

/// 获取 SDK Version 版本号
+ (NSString *)SDKVersion;

/// 开启SDK回调日志
+ (void)unionAdCallbackLog:(BOOL)open;

/**
 在播放音频时是否使用SDK内部对AVAudioSession设置的category及options，默认使用(YES)，若不使用，请在SDK初始化后调用此方法修改
 SDK内部将不做任何处理，由调用方在展示广告时自行设置；
 SDK设置的category为AVAudioSessionCategoryAmbient，options为AVAudioSessionCategoryOptionDuckOthers
 */
+ (void)enableDefaultAudioSessionSetting:(BOOL)enabled;

/// 清除广告素材缓存
+ (void)clearAdMaterialCache;

/// 欧盟GDPR合规弹窗
- (void)presentDataConsentDialogInViewController:(UIViewController *)viewController dismissalCallback:(void(^)(ZJFLGDPRConsentSet dataConsentSet))dismissCallback;

/// 定制化信息 可选
+ (void)setExtraInfo:(NSString *)extraInfo;


#pragma mark - 测试日志采集
//采集测试日志
-(void) saveTextLog: (NSString *) log;
//获取测试日志
-(NSString *) getTextLog;
-(void) deleteDebugLog;
//供测试使用的日志打印
@property (nonatomic, strong) NSMutableArray *debugLogArray;

@end

NS_ASSUME_NONNULL_END
