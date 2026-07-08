//
//  WindPlayerGestureControl.h
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

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, WindPlayerGestureType) {
    WindPlayerGestureTypeUnknown,
    WindPlayerGestureTypeSingleTap,
    WindPlayerGestureTypeDoubleTap,
    WindPlayerGestureTypePan,
    WindPlayerGestureTypePinch
};

typedef NS_ENUM(NSUInteger, WindPanDirection) {
    WindPanDirectionUnknown,
    WindPanDirectionV,
    WindPanDirectionH,
};

typedef NS_ENUM(NSUInteger, WindPanLocation) {
    WindPanLocationUnknown,
    WindPanLocationLeft,
    WindPanLocationRight,
};

typedef NS_ENUM(NSUInteger, WindPanMovingDirection) {
    WindPanMovingDirectionUnkown,
    WindPanMovingDirectionTop,
    WindPanMovingDirectionLeft,
    WindPanMovingDirectionBottom,
    WindPanMovingDirectionRight,
};

/// This enumeration lists some of the gesture types that the player has by default.
typedef NS_OPTIONS(NSUInteger, WindPlayerDisableGestureTypes) {
    WindPlayerDisableGestureTypesNone         = 0,
    WindPlayerDisableGestureTypesSingleTap    = 1 << 0,
    WindPlayerDisableGestureTypesDoubleTap    = 1 << 1,
    WindPlayerDisableGestureTypesPan          = 1 << 2,
    WindPlayerDisableGestureTypesPinch        = 1 << 3,
    WindPlayerDisableGestureTypesAll          = (WindPlayerDisableGestureTypesSingleTap | WindPlayerDisableGestureTypesDoubleTap | WindPlayerDisableGestureTypesPan | WindPlayerDisableGestureTypesPinch)
};

/// This enumeration lists some of the pan gesture moving direction that the player not support.
typedef NS_OPTIONS(NSUInteger, WindPlayerDisablePanMovingDirection) {
    WindPlayerDisablePanMovingDirectionNone         = 0,       /// Not disable pan moving direction.
    WindPlayerDisablePanMovingDirectionVertical     = 1 << 0,  /// Disable pan moving vertical direction.
    WindPlayerDisablePanMovingDirectionHorizontal   = 1 << 1,  /// Disable pan moving horizontal direction.
    WindPlayerDisablePanMovingDirectionAll          = (WindPlayerDisablePanMovingDirectionVertical | WindPlayerDisablePanMovingDirectionHorizontal)  /// Disable pan moving all direction.
};

@interface WindPlayerGestureControl : NSObject

/// Gesture condition callback.
@property (nonatomic, copy, nullable) BOOL(^triggerCondition)(WindPlayerGestureControl *control, WindPlayerGestureType type, UIGestureRecognizer *gesture, UITouch *touch);

/// Single tap gesture callback.
@property (nonatomic, copy, nullable) void(^singleTapped)(WindPlayerGestureControl *control);

/// Double tap gesture callback.
@property (nonatomic, copy, nullable) void(^doubleTapped)(WindPlayerGestureControl *control);

/// Begin pan gesture callback.
@property (nonatomic, copy, nullable) void(^beganPan)(WindPlayerGestureControl *control, WindPanDirection direction, WindPanLocation location);

/// Pan gesture changing callback.
@property (nonatomic, copy, nullable) void(^changedPan)(WindPlayerGestureControl *control, WindPanDirection direction, WindPanLocation location, CGPoint velocity);

/// End the Pan gesture callback.
@property (nonatomic, copy, nullable) void(^endedPan)(WindPlayerGestureControl *control, WindPanDirection direction, WindPanLocation location);

/// Pinch gesture callback.
@property (nonatomic, copy, nullable) void(^pinched)(WindPlayerGestureControl *control, float scale);

/// The single tap gesture.
@property (nonatomic, strong, readonly) UITapGestureRecognizer *singleTap;

/// The double tap gesture.
@property (nonatomic, strong, readonly) UITapGestureRecognizer *doubleTap;

/// The pan tap gesture.
@property (nonatomic, strong, readonly) UIPanGestureRecognizer *panGR;

/// The pinch tap gesture.
@property (nonatomic, strong, readonly) UIPinchGestureRecognizer *pinchGR;

/// The pan gesture direction.
@property (nonatomic, readonly) WindPanDirection panDirection;

/// The pan location.
@property (nonatomic, readonly) WindPanLocation panLocation;

/// The moving drection.
@property (nonatomic, readonly) WindPanMovingDirection panMovingDirection;

/// The gesture types that the player not support.
@property (nonatomic) WindPlayerDisableGestureTypes disableTypes;

/// The pan gesture moving direction that the player not support.
@property (nonatomic) WindPlayerDisablePanMovingDirection disablePanMovingDirection;

/**
 Add  all gestures(singleTap、doubleTap、panGR、pinchGR) to the view.
 */
- (void)addGestureToView:(UIView *)view;

/**
 Remove all gestures(singleTap、doubleTap、panGR、pinchGR) form the view.
 */
- (void)removeGestureToView:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
