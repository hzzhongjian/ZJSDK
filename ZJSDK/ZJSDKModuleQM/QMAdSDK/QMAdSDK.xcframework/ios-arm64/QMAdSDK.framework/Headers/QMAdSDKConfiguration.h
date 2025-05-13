//
//  QMAdSDKConfiguration.h
//  QMAdSDK
//
//  Created by qusy on 2023/12/29.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface QMAdSDKConfiguration : NSObject

+ (instancetype)shareConfiguration;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
+ (instancetype)alloc NS_UNAVAILABLE;

/// 应用id
@property (nonatomic, copy, nonnull) NSString *appId;

/// 用户id
@property (nonatomic, copy, nullable) NSString *userId;

/// 是否开启个性化推荐
@property (nonatomic, assign) BOOL isEnablePersonalAds;

/// 自定义IDFA
@property (nonatomic, copy, nullable) NSString *customIdfa;

/// qmcds
@property (nonatomic, copy) NSArray *qmcds;

/// 经度
@property (nonatomic, copy, nullable) NSString *longitude;
/// 纬度
@property (nonatomic, copy, nullable) NSString * latitude;

/// 检查 Scheme 列表 默认 YES
@property (nonatomic, assign) BOOL canSniffingInstalls;


/// 是否开启 SDK 的播放器配置
/// 在播放音频时是否使用 SDK 内部对 AVAudioSession 设置的 category 及 options，默认（YES）使用，若不使用，SDK 内部不做任何处理，由调用方在展示广告时自行设置；
/// SDK 默认设置的 category 为 AVAudioSessionCategoryAmbient，options 为 AVAudioSessionCategoryOptionDuckOthers
@property (nonatomic, assign) BOOL enableDefaultAudioSessionSetting;

@end

NS_ASSUME_NONNULL_END
