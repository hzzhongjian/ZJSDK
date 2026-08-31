//
//  ZJFLInterstitialADConfig.h
//  ZJ_FLAdSDK
//
//  Created by Lurich on 2024/6/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJ_FLAdSDK/ZJFLBaseAdManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJFLInterstitialADConfig : NSObject

/// 获取广告的广告位ID，必传
@property (nonatomic, copy) NSString *mediaId;

/// 是否添加高斯模糊，默认添加
@property (nonatomic, assign) BOOL addBlur;

/// 插屏广告的背景图片，默认为空
@property (nonatomic, strong) UIImage *backgroundImage;

/// 插屏广告的背景色, 默认为透明色
@property (nonatomic, copy) UIColor *backgroundColor;

/// 插屏广告的背景图片的展示样式，默认为 UIViewContentModeScaleAspectFill
@property (nonatomic) UIViewContentMode contentMode;

/// 自定义请求广告超时时间，单位秒，建议至少 3 秒以上，（PS：设置请求限时，可能影响广告收益，非必要不要设置）
@property (nonatomic) double timeout;

/// 定时自动关闭插屏，默认由后台控制
@property (nonatomic) double autoCloseTime;

/// 视频相关控制，可选
@property (nonatomic, strong) ZJFLVideoConfig *videoConfig;

@end

@interface UIViewController (ZJFLInterstitialAD)

- (void)zjfl_showInterstitialADWithConfig:(void(^)(ZJFLInterstitialADConfig *config))configBlock completion:(void(^)(ZJFLADResultInfo *result))resultBlock;

@end

NS_ASSUME_NONNULL_END
