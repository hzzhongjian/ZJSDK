//
//  WindPlayerConst.h
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

typedef NS_ENUM(NSUInteger, WindPlayerPlaybackState) {
    WindPlayerPlayStateUnknown,
    WindPlayerPlayStatePlaying,
    WindPlayerPlayStatePaused,
    WindPlayerPlayStatePlayFailed,
    WindPlayerPlayStatePlayStopped
};

typedef NS_OPTIONS(NSUInteger, WindPlayerLoadState) {
    WindPlayerLoadStateUnknown        = 0,
    WindPlayerLoadStatePrepare        = 1 << 0,
    WindPlayerLoadStatePlayable       = 1 << 1,
    WindPlayerLoadStatePlaythroughOK  = 1 << 2, // Playback will be automatically started.
    WindPlayerLoadStateStalled        = 1 << 3, // Playback will be automatically paused in this state, if started.
};

typedef NS_ENUM(NSInteger, WindPlayerScalingMode) {
    WindPlayerScalingModeNone,       // No scaling.
    WindPlayerScalingModeAspectFit,  // Uniform scale until one dimension fits.
    WindPlayerScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents.
    WindPlayerScalingModeFill        // Non-uniform scale. Both render dimensions will exactly match the visible bounds.
};

/**
 Synthsize a weak or strong reference.
 
 Example:
 @wind_weakify(self)
 [self doSomething^{
 @wind_strongify(self)
 if (!self) return;
 ...
 }];
 
 */
#ifndef sig_player_weakify
#if DEBUG
#if __has_feature(objc_arc)
#define wind_weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define wind_weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define wind_weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define wind_weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

#ifndef sig_player_strongify
#if DEBUG
#if __has_feature(objc_arc)
#define wind_strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define wind_strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define wind_strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define wind_strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif

// Screen width
#define WindPlayerScreenWidth     [[UIScreen mainScreen] bounds].size.width
// Screen height
#define WindPlayerScreenHeight    [[UIScreen mainScreen] bounds].size.height


