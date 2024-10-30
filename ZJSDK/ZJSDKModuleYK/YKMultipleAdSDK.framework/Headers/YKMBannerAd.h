//
//  YKMBannerAd.h
//  YKMultipleAdSDK
//
//  Created by hary on 2024/3/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class YKMBannerAd;
@protocol YKMBannerAdDelegate <NSObject>

@optional
///广告加载成功
- (void)ykm_loadBannerSuccess:(YKMBannerAd *)banner;

///广告加载失败
- (void)ykm_loadBannerFailed:(NSError *)error banner:(YKMBannerAd *)banner;

/// 广告展示成功
- (void)ykm_showBannerSuccess:(YKMBannerAd *)banner;

///广告点击事件
- (void)ykm_clickBanner:(YKMBannerAd *)banner;

///广告关闭事件
- (void)ykm_closeBanner:(YKMBannerAd *)banner;

@end

@interface YKMBannerAd : UIView

/**
用来接收Banner广告获取状态变化通知的 delegate
*/
@property (nonatomic, weak) id<YKMBannerAdDelegate> delegate;

/**
 bannerViewController 展示view的控制器或者弹出落地页的需要的控制器，此参数不能为空
 */
@property (nonatomic, weak) UIViewController *bannerViewController;

/// 初始化Banner广告
/// @param frame Banner的frame
/// @param adid Banner的adid
/// @param timeOut 广告加载超时时间
-(instancetype)initWithFrame:(CGRect)frame
                    andAdid:(NSString *)adid
                 andTimeOut:(NSInteger)timeOut;

/// 加载Banner广告
- (void)loadBannerAd;

@end

NS_ASSUME_NONNULL_END
