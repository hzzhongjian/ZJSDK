//
//  ZJ_XAdInterstitialAd.h
//  ZJ_AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ZJ_XAdInterstitialDelegate;

@interface ZJ_XAdInterstitialAd : NSObject

/// 代理
@property (weak, nonatomic) id<ZJ_XAdInterstitialDelegate>delegate;

/// 是否需要满足HTTPS  [可选] 默认为NO
@property (nonatomic,assign) BOOL secure;

/// 是否屏蔽摇一摇，NO或者不赋值，不屏蔽，YES屏蔽
@property (nonatomic, assign) BOOL disableShake;

/// 是否屏蔽扭一扭，NO或者不赋值，不屏蔽，YES屏蔽
@property (nonatomic, assign) BOOL disableTwist;

/// 视频类型时，是否静音。默认 NO。loadAdData 前设置。
@property (nonatomic, assign) BOOL videoMuted;

/// 初始化广告
/// - Parameter adSlotId: 广告ID
- (instancetype)initWithAdSlotId:(NSString *)adSlotId;

/// 请求广告
- (void)loadAdData;

/**
 广告是否有效
 @return 广告有效返回YES  广告无效返回NO
 */
- (BOOL)isReady;

/// 展示插屏广告
/// @param controller 控制器
- (void)showAd:(UIViewController *)controller;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

/// 竞价成功上报，脉盟平台竞胜之后调用，需要在广告请求成功之后,展示之前调用，winInfo脉盟平台竞价获胜信息，可为nil。
/// @param winInfo 竞胜信息 字典类型
- (void)sendWinNotificationWithInfo:(NSDictionary *_Nullable)winInfo;

/// 获取当前广告物料
// material_url: 素材 url 数组
// adTitle: 标题
// adDescription:描述
// crid:素材id/创意id
- (NSDictionary *)getCurrentAdMaterialsInfo;

@end

NS_ASSUME_NONNULL_END
