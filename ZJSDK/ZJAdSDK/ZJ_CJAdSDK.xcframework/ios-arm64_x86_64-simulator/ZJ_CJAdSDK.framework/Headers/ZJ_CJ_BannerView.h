//
//  ZJ_CJ_BannerView.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/8.
//

#import <UIKit/UIKit.h>

@class ZJ_CJ_BannerAd;
@class ZJ_CJ_AdMetaData;

NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_CJ_BannerViewDelegate <NSObject>

/**
 * 广告展示
 * @param item  广告数据
 */
- (void)onBannerAdShow;

/**
 * 广告点击
 */
- (void)onBannerAdClickedPoint:(CGPoint)point
                      accX:(NSInteger)accX accY:(NSInteger)accY accZ:(NSInteger)accZ
                     size:(CGSize)size;
/**
 * 广告关闭
 */
- (void)onBannerAdClosed;

@end

@interface ZJ_CJ_BannerView : UIView


@property (nonatomic,   weak) id <ZJ_CJ_BannerViewDelegate> delegate;

/**
 * @brief 初始化view
 */
- (instancetype)initWithConfigAdObject:(ZJ_CJ_BannerAd *)bannerAd
                                adData:(ZJ_CJ_AdMetaData *)adData;

/**
 * @brief 渲染广告内容
 */
- (NSError *)renderViewsUI;

@end

NS_ASSUME_NONNULL_END
