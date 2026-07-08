//
//  WindPlayerMediaControl.h
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

#import <Foundation/Foundation.h>
#import <WindFoundation/WindPlayerMediaPlayback.h>
#import <WindFoundation/WindOrientationObserver.h>
#import <WindFoundation/WindPlayerGestureControl.h>
#import <WindFoundation/WindFoundation.h>

@class WindPlayerController;

NS_ASSUME_NONNULL_BEGIN

@protocol WindPlayerMediaControl <NSObject>

@required
/// Current playerController
@property (nonatomic, weak) WindPlayerController *player;

@optional

#pragma mark - Playback state

/// When the player prepare to play the video.
- (void)videoPlayer:(WindPlayerController *)videoPlayer prepareToPlay:(NSURL *)assetURL;

/// When th player playback state changed.
- (void)videoPlayer:(WindPlayerController *)videoPlayer playStateChanged:(WindPlayerPlaybackState)state;

/// When th player loading state changed.
- (void)videoPlayer:(WindPlayerController *)videoPlayer loadStateChanged:(WindPlayerLoadState)state;

#pragma mark - progress

/**
 When the playback changed.
 
 @param videoPlayer the player.
 @param currentTime the current play time.
 @param totalTime the video total time.
 */
- (void)videoPlayer:(WindPlayerController *)videoPlayer
        currentTime:(NSTimeInterval)currentTime
          totalTime:(NSTimeInterval)totalTime;

/**
 When buffer progress changed.
 */
- (void)videoPlayer:(WindPlayerController *)videoPlayer
         bufferTime:(NSTimeInterval)bufferTime;

/**
 When you are dragging to change the video progress.
 */
- (void)videoPlayer:(WindPlayerController *)videoPlayer
       draggingTime:(NSTimeInterval)seekTime
          totalTime:(NSTimeInterval)totalTime;

/**
 When play end.
 */
- (void)videoPlayerPlayEnd:(WindPlayerController *)videoPlayer;

/**
 When play failed.
 */
- (void)videoPlayerPlayFailed:(WindPlayerController *)videoPlayer error:(id)error;

#pragma mark - lock screen

/**
 When set `videoPlayer.lockedScreen`.
 */
- (void)lockedVideoPlayer:(WindPlayerController *)videoPlayer lockedScreen:(BOOL)locked;

#pragma mark - Screen rotation

/**
 When the fullScreen maode will changed.
 */
- (void)videoPlayer:(WindPlayerController *)videoPlayer orientationWillChange:(WindOrientationObserver *)observer;

/**
 When the fullScreen maode did changed.
 */
- (void)videoPlayer:(WindPlayerController *)videoPlayer orientationDidChanged:(WindOrientationObserver *)observer;

#pragma mark - The network changed

/**
 When the network changed
 */
- (void)videoPlayer:(WindPlayerController *)videoPlayer reachabilityChanged:(WindReachabilityStatus)status;

#pragma mark - The video size changed

/**
 When the video size changed
 */
- (void)videoPlayer:(WindPlayerController *)videoPlayer presentationSizeChanged:(CGSize)size;

#pragma mark - Gesture

/**
 When the gesture condition
 */
- (BOOL)gestureTriggerCondition:(WindPlayerGestureControl *)gestureControl
                    gestureType:(WindPlayerGestureType)gestureType
              gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer
                          touch:(UITouch *)touch;

/**
 When the gesture single tapped
 */
- (void)gestureSingleTapped:(WindPlayerGestureControl *)gestureControl;

/**
 When the gesture double tapped
 */
- (void)gestureDoubleTapped:(WindPlayerGestureControl *)gestureControl;

/**
 When the gesture begin panGesture
 */
- (void)gestureBeganPan:(WindPlayerGestureControl *)gestureControl
           panDirection:(WindPanDirection)direction
            panLocation:(WindPanLocation)location;

/**
 When the gesture paning
 */
- (void)gestureChangedPan:(WindPlayerGestureControl *)gestureControl
             panDirection:(WindPanDirection)direction
              panLocation:(WindPanLocation)location
             withVelocity:(CGPoint)velocity;

/**
 When the end panGesture
 */
- (void)gestureEndedPan:(WindPlayerGestureControl *)gestureControl
           panDirection:(WindPanDirection)direction
            panLocation:(WindPanLocation)location;

/**
 When the pinchGesture changed
 */
- (void)gesturePinched:(WindPlayerGestureControl *)gestureControl
                 scale:(float)scale;

#pragma mark - scrollview

/**
 When the player will appear in scrollView.
 */
- (void)playerWillAppearInScrollView:(WindPlayerController *)videoPlayer;

/**
 When the player did appear in scrollView.
 */
- (void)playerDidAppearInScrollView:(WindPlayerController *)videoPlayer;

/**
 When the player will disappear in scrollView.
 */
- (void)playerWillDisappearInScrollView:(WindPlayerController *)videoPlayer;

/**
 When the player did disappear in scrollView.
 */
- (void)playerDidDisappearInScrollView:(WindPlayerController *)videoPlayer;

/**
 When the player appearing in scrollView.
 */
- (void)playerAppearingInScrollView:(WindPlayerController *)videoPlayer playerApperaPercent:(CGFloat)playerApperaPercent;

/**
 When the player disappearing in scrollView.
 */
- (void)playerDisappearingInScrollView:(WindPlayerController *)videoPlayer playerDisapperaPercent:(CGFloat)playerDisapperaPercent;

/**
 When the small float view show.
 */
- (void)videoPlayer:(WindPlayerController *)videoPlayer floatViewShow:(BOOL)show;

@end

NS_ASSUME_NONNULL_END

