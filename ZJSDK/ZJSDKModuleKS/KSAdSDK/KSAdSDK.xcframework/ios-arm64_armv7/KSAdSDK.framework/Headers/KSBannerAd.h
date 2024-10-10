//
//  KSBannerAd.h
//  KSUBannerAd-KSUBannerAdResource
//
//  Created by 崔婉莹 on 2024/5/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KSAd.h"
#import "KSAdInteractionType.h"

NS_ASSUME_NONNULL_BEGIN

@class KSBannerAd;

@protocol KSBannerAdDelegate <NSObject>
@optional
/**
 * banner 广告请求完成
 */
- (void)ksad_bannerAdViewDidLoad:(KSBannerAd *)bannerAdView;
/**
 * banner 广告请求失败
 */
- (void)ksad_bannerAdView:(KSBannerAd *)bannerAdView didFailWithError:(NSError *_Nullable)error;
/**
 * banner 广告渲染成功
 */
- (void)ksad_bannerAdViewRenderSuccess:(KSBannerAd *)bannerAd;
/**
 * banner 广告曝光
 */
- (void)ksad_bannerAdViewBecomVisible:(KSBannerAd *)bannerAd;
/**
 * banner 广告点击
 */
- (void)ksad_bannerAdViewDidClick:(KSBannerAd *)bannerAd;
/**
 * banner 广告关闭
 */
- (void)ksad_bannerAdViewDidClose:(KSBannerAd *)bannerAd;
/**
 * banner 广告打开详情页
 */
- (void)ksad_bannerAdViewDidShowOtherController:(KSBannerAd *)bannerAd interactionType:(KSAdInteractionType)interactionType;
/**
 * banner 广告关闭详情页
 */
- (void)ksad_bannerAdViewDidCloseOtherController:(KSBannerAd *)bannerAd interactionType:(KSAdInteractionType)interactionType;

@end

@interface KSBannerAd : KSAd

@property (nonatomic, weak) id<KSBannerAdDelegate> delegate;

@property (nonatomic, strong) UIView *bannerAdView;
// 广告渲染成功标识
@property (nonatomic, assign) BOOL adReady;

- (id)initWithPosId:(NSString *)posId;
/// 请求广告
- (void)loadAdData;
/// 服务端竞价请求广告
- (void)loadAdDataWithResponse:(NSDictionary *)response;
/**
 服务端竞价请求广告V2
 */
- (void)loadAdDataWithResponseV2:(NSDictionary *)response;
- (void)showFromViewController:(UIViewController *)viewController;
//是否开启声音
- (void)setVideoSoundEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
