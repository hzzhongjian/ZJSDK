//
//  JYNativeAdView.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/4/21.
//

#import <UIKit/UIKit.h>
#import "JYNativeAdDataObject.h"

NS_ASSUME_NONNULL_BEGIN

@class JYNativeAdView;

@protocol JYNativeAdViewDelegate <NSObject>

@optional

- (void)jy_nativeAdViewDidExpose:(JYNativeAdView *)nativeAdView;
- (void)jy_nativeAdViewDidClick:(JYNativeAdView *)nativeAdView;
- (void)jy_nativeAdViewDidCloseOtherController:(JYNativeAdView *)nativeAdView;
- (void)jy_nativeAdViewDidPresentFullScreenModal:(JYNativeAdView *)nativeAdView;
- (void)jy_nativeAdViewMediaDidPlayFinish:(JYNativeAdView *)nativeAdView;
- (void)jy_nativeAdViewDislike:(JYNativeAdView *)nativeAdView;

@end

@interface JYNativeAdView : UIView

@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, weak, nullable) id<JYNativeAdViewDelegate> delegate;
@property (nonatomic, weak, readonly) UIView *mediaView;
@property (nonatomic, strong, readonly) UIImageView *logoView;

@property (nonatomic, assign, readonly) CGFloat logoImageViewDefaultWidth;
@property (nonatomic, assign, readonly) CGFloat logoImageViewDefaultHeight;

@property (nonatomic, weak, readonly) UIView *realAdView;
@property (nonatomic, assign) BOOL autoLayout;

- (void)refreshData:(JYNativeAdDataObject *)nativeAdDataObject;
- (void)registerDataObjectWithClickableViews:(NSArray<UIView *> *)clickableViews;

/// 解除当前广告数据与视图的绑定。
///
/// 当广告视图不再使用或 Cell 准备复用时调用。调用后仍可通过
/// `refreshData:` 和 `registerDataObjectWithClickableViews:` 重新绑定广告。
- (void)unregisterDataObject;

- (CGFloat)mediaVideoDuration;
- (CGFloat)mediaVideoPlayTime;
- (void)mediaVideoPlay;
- (void)mediaVideoPause;
- (void)mediaVideoStop;
- (void)mediaVideoMuteEnable:(BOOL)flag;
- (void)setMediaVideoPlayButtonImage:(UIImage *)image size:(CGSize)size;

- (NSInteger)eCPM;

@end

NS_ASSUME_NONNULL_END
