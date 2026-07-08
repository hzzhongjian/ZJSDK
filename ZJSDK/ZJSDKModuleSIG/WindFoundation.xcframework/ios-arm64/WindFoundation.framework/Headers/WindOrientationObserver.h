//
//  WindOrentationObserver.h
//  WindPlayer
//
// Copyright (c) 2016年 任子丰 ( http://github.com/renzifeng )
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>
#import <WindFoundation/WindPlayerView.h>

NS_ASSUME_NONNULL_BEGIN

/// Full screen mode
typedef NS_ENUM(NSUInteger, WindFullScreenMode) {
    WindFullScreenModeAutomatic,  // Determine full screen mode automatically
    WindFullScreenModeLandscape,  // Landscape full screen mode
    WindFullScreenModePortrait    // Portrait full screen Model
};

/// Portrait full screen mode.
typedef NS_ENUM(NSUInteger, WindPortraitFullScreenMode) {
    WindPortraitFullScreenModeScaleToFill,    // Full fill
    WindPortraitFullScreenModeScaleAspectFit  // contents scaled to fit with fixed aspect. remainder is transparent
};

/// Player view mode
typedef NS_ENUM(NSUInteger, WindRotateType) {
    WindRotateTypeNormal,         // Normal
    WindRotateTypeCell            // Cell
};

/**
 Rotation of support direction
 */
typedef NS_OPTIONS(NSUInteger, WindInterfaceOrientationMask) {
    WindInterfaceOrientationMaskPortrait = (1 << 0),
    WindInterfaceOrientationMaskLandscapeLeft = (1 << 1),
    WindInterfaceOrientationMaskLandscapeRight = (1 << 2),
    WindInterfaceOrientationMaskPortraitUpsideDown = (1 << 3),
    WindInterfaceOrientationMaskLandscape = (WindInterfaceOrientationMaskLandscapeLeft | WindInterfaceOrientationMaskLandscapeRight),
    WindInterfaceOrientationMaskAll = (WindInterfaceOrientationMaskPortrait | WindInterfaceOrientationMaskLandscape | WindInterfaceOrientationMaskPortraitUpsideDown),
    WindInterfaceOrientationMaskAllButUpsideDown = (WindInterfaceOrientationMaskPortrait | WindInterfaceOrientationMaskLandscape),
};

/// This enumeration lists some of the gesture types that the player has by default.
typedef NS_OPTIONS(NSUInteger, WindDisablePortraitGestureTypes) {
    WindDisablePortraitGestureTypesNone         = 0,
    WindDisablePortraitGestureTypesTap          = 1 << 0,
    WindDisablePortraitGestureTypesPan          = 1 << 1,
    WindDisablePortraitGestureTypesAll          = (WindDisablePortraitGestureTypesTap | WindDisablePortraitGestureTypesPan)
};

@protocol WindPortraitOrientationDelegate <NSObject>

- (void)wind_orientationWillChange:(BOOL)isFullScreen;

- (void)wind_orientationDidChanged:(BOOL)isFullScreen;

- (void)wind_interationState:(BOOL)isDragging;

@end

@interface WindOrientationObserver : NSObject

/// update the rotateView and containerView.
- (void)updateRotateView:(WindPlayerView *)rotateView
           containerView:(UIView *)containerView;

/// list play
- (void)updateRotateView:(WindPlayerView *)rotateView
        rotateViewAtCell:(UIView *)cell
           playerViewTag:(NSInteger)playerViewTag;

/// Container view of a full screen state player.
@property (nonatomic, strong) UIView *fullScreenContainerView;

/// Container view of a small screen state player.
@property (nonatomic, weak) UIView *containerView;

/// The block invoked When player will rotate.
@property (nonatomic, copy, nullable) void(^orientationWillChange)(WindOrientationObserver *observer, BOOL isFullScreen);

/// The block invoked when player rotated.
@property (nonatomic, copy, nullable) void(^orientationDidChanged)(WindOrientationObserver *observer, BOOL isFullScreen);

/// Full screen mode, the default landscape into full screen
@property (nonatomic) WindFullScreenMode fullScreenMode;

@property (nonatomic, assign) WindPortraitFullScreenMode portraitFullScreenMode;

/// rotate duration, default is 0.30
@property (nonatomic) NSTimeInterval duration;

/// If the full screen.
@property (nonatomic, readonly, getter=isFullScreen) BOOL fullScreen;

/// Lock screen orientation
@property (nonatomic, getter=isLockedScreen) BOOL lockedScreen;

/// The fullscreen statusbar hidden.
@property (nonatomic, assign) BOOL fullScreenStatusBarHidden;

/// default is  UIStatusBarStyleLightContent.
@property (nonatomic, assign) UIStatusBarStyle fullScreenStatusBarStyle;

/// defalut is UIStatusBarAnimationSlide.
@property (nonatomic, assign) UIStatusBarAnimation fullScreenStatusBarAnimation;

@property (nonatomic, assign) CGSize presentationSize;

/// default is WindDisablePortraitGestureTypesAll.
@property (nonatomic, assign) WindDisablePortraitGestureTypes disablePortraitGestureTypes;

/// The current orientation of the player.
/// Default is UIInterfaceOrientationPortrait.
@property (nonatomic, readonly) UIInterfaceOrientation currentOrientation;

/// Whether allow the video orientation rotate.
/// default is YES.
@property (nonatomic, assign) BOOL allowOrientationRotation;

/// The support Interface Orientation,default is WindInterfaceOrientationMaskAllButUpsideDown
@property (nonatomic, assign) WindInterfaceOrientationMask supportInterfaceOrientation;

/// Add the device orientation observer.
- (void)addDeviceOrientationObserver;

/// Remove the device orientation observer.
- (void)removeDeviceOrientationObserver;

/// Enter the fullScreen while the WindFullScreenMode is WindFullScreenModeLandscape.
- (void)rotateToOrientation:(UIInterfaceOrientation)orientation animated:(BOOL)animated;

/// Enter the fullScreen while the WindFullScreenMode is WindFullScreenModeLandscape.
- (void)rotateToOrientation:(UIInterfaceOrientation)orientation animated:(BOOL)animated completion:(void(^ __nullable)(void))completion;

/// Enter the fullScreen while the WindFullScreenMode is WindFullScreenModePortrait.
- (void)enterPortraitFullScreen:(BOOL)fullScreen animated:(BOOL)animated;

/// Enter the fullScreen while the WindFullScreenMode is WindFullScreenModePortrait.
- (void)enterPortraitFullScreen:(BOOL)fullScreen animated:(BOOL)animated completion:(void(^ __nullable)(void))completion;

/// FullScreen mode is determined by WindFullScreenMode.
- (void)enterFullScreen:(BOOL)fullScreen animated:(BOOL)animated;

/// FullScreen mode is determined by WindFullScreenMode.
- (void)enterFullScreen:(BOOL)fullScreen animated:(BOOL)animated completion:(void (^ _Nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END


