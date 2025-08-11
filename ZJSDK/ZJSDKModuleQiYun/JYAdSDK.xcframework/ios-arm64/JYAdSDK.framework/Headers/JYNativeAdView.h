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
@property (nonatomic, weak, readonly) UIImageView *logoView;

@property (nonatomic, assign, readonly) CGFloat logoImageViewDefaultWidth;
@property (nonatomic, assign, readonly) CGFloat logoImageViewDefaultHeight;

@property (nonatomic, weak, readonly) UIView *realAdView;
@property (nonatomic, assign) BOOL autoLayout;

- (void)refreshData:(JYNativeAdDataObject *)nativeAdDataObject;
- (void)registerDataObjectWithClickableViews:(NSArray<UIView *> *)clickableViews;

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
