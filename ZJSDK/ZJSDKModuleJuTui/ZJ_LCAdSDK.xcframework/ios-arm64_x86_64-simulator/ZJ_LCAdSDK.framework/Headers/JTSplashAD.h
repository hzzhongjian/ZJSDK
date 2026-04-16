//
//  JTSplashAD.h
//  JTAdSDK
//
//  Created by Frank on 2025/6/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, JTSplashAdCloseType) {
    JTSplashAdCloseType_Unknow = 0,             // unknow
    JTSplashAdCloseType_ClickSkip = 1,          // click skip
    JTSplashAdCloseType_CountdownToZero = 2,    // countdown
    JTSplashAdCloseType_ClickAd = 3,            // click Ad
};

@class JTSplashAD,JTAdSlot;

/// 聚推开屏广告事件回调协议
@protocol JTSplashADDelegate <NSObject>

@optional

/// 开屏广告拉取成功
/// - Parameter splashAd: 开屏广告模型
- (void)jtSplashAdLoadSuccess:(JTSplashAD *)splashAd;

/// 开屏广告拉取失败
/// - Parameters:
///   - splashAd: 开屏广告模型
///   - error: 失败原因
- (void)jtSplashAdLoadFail:(JTSplashAD *)splashAd error:(NSError *_Nullable)error;

/// 开屏广告展示成功
/// - Parameter splashAd: 开屏广告模型
- (void)jtSplashAdDidExposureSuccess:(JTSplashAD *)splashAd;

/// 开屏广告展示失败
/// - Parameter splashAd: 开屏广告模型
/// - error: 失败原因
- (void)jtSplashAdDidExposureFail:(JTSplashAD *)splashAd error:(NSError *_Nullable)error;

/// 开屏广告点击事件
/// - Parameter splashAd: 开屏广告模型
- (void)jtSplashAdDidClick:(JTSplashAD *)splashAd;

/// 开屏广告点击关闭
/// - Parameters:
///   - splashAd: 开屏广告模型
///   - closeType: 关闭类型
- (void)jtSplashAdDidClose:(JTSplashAD *)splashAd closeType:(JTSplashAdCloseType)closeType;

@end

/// 聚推开屏广告模型
@interface JTSplashAD : JTBaseAdModel

/// 开屏广告事件回调
@property (nonatomic, weak, nullable) id<JTSplashADDelegate> delegate;

/// 广告位模型
@property (nonatomic, strong, readonly) JTAdSlot *slot;

/// 根控制器
@property (nonatomic, weak, readonly, nullable) UIViewController *rootViewController;

/// 是否开启摇一摇，默认是YES。
@property (nonatomic, assign) BOOL shakable;

- (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// 通过Slot ID初始化开屏广告
/// - Parameters:
///   - itemId: 广告位模型
///   - adSize: 广告内容尺寸，如果底部有View可减去对应高度。单位：pt
- (instancetype)initWithSlotID:(NSString *)itemId
                        adSize:(CGSize)adSize;

/// 装载广告
- (void)loadAdData;

/// 展示开屏广告
/// - Parameters:
///   - rootVC: 根控制器
///   - bottomView: 底部View，可选。
- (void)showSplashViewInRootViewController:(UIViewController *)rootVC
                                bottomView:(UIView * _Nullable)bottomView;

@end

NS_ASSUME_NONNULL_END
