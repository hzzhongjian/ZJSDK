//
//  JLNativeAdView.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/4/21.
//

#import <UIKit/UIKit.h>
#import "JLNativeAdDataObject.h"

NS_ASSUME_NONNULL_BEGIN

@class JLNativeAdView;

@protocol JLNativeAdViewDelegate <NSObject>

@optional

- (void)jl_nativeAdViewDidExpose:(JLNativeAdView *)nativeAdView;
- (void)jl_nativeAdViewDidClick:(JLNativeAdView *)nativeAdView;
- (void)jl_nativeAdViewDidCloseOtherController:(JLNativeAdView *)nativeAdView;
- (void)jl_nativeAdViewDidPresentFullScreenModal:(JLNativeAdView *)nativeAdView;
- (void)jl_nativeAdViewMediaDidPlayFinish:(JLNativeAdView *)nativeAdView;
- (void)jl_nativeAdViewDislike:(JLNativeAdView *)nativeAdView;

@end

@interface JLNativeAdView : UIView

@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, weak, nullable) id<JLNativeAdViewDelegate> delegate;
@property (nonatomic, weak, readonly) UIView *mediaView;
@property (nonatomic, weak, readonly) UIImageView *logoView;

@property (nonatomic, assign, readonly) CGFloat logoImageViewDefaultWidth;
@property (nonatomic, assign, readonly) CGFloat logoImageViewDefaultHeight;

@property (nonatomic, weak, readonly) UIView *realAdView;
@property (nonatomic, assign) BOOL autoLayout;

- (void)refreshData:(JLNativeAdDataObject *)nativeAdDataObject;
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
