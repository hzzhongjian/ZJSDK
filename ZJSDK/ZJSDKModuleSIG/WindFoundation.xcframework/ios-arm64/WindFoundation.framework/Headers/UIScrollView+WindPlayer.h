//
//  UIScrollView+WindPlayer.h
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

/*
 * The scroll direction of scrollView.
 */
typedef NS_ENUM(NSUInteger, WindPlayerScrollDirection) {
    WindPlayerScrollDirectionNone,
    WindPlayerScrollDirectionUp,         // Scroll up
    WindPlayerScrollDirectionDown,       // Scroll Down
    WindPlayerScrollDirectionLeft,       // Scroll left
    WindPlayerScrollDirectionRight       // Scroll right
};

/*
 * The scrollView direction.
 */
typedef NS_ENUM(NSInteger, WindPlayerScrollViewDirection) {
    WindPlayerScrollViewDirectionVertical,
    WindPlayerScrollViewDirectionHorizontal
};

/*
 * The player container type
 */
typedef NS_ENUM(NSInteger, WindPlayerContainerType) {
    WindPlayerContainerTypeView,
    WindPlayerContainerTypeCell
};

typedef NS_ENUM(NSInteger , WindPlayerScrollViewScrollPosition) {
    WindPlayerScrollViewScrollPositionNone,
    /// Apply to UITableView and UICollectionViewDirection is vertical scrolling.
    WindPlayerScrollViewScrollPositionTop,
    WindPlayerScrollViewScrollPositionCenteredVertically,
    WindPlayerScrollViewScrollPositionBottom,
    
    /// Only apply to UICollectionViewDirection is horizontal scrolling.
    WindPlayerScrollViewScrollPositionLeft,
    WindPlayerScrollViewScrollPositionCenteredHorizontally,
    WindPlayerScrollViewScrollPositionRight
};

@interface UIScrollView (WindPlayer)

/// When the WindPlayerScrollViewDirection is WindPlayerScrollViewDirectionVertical,the property has value.
@property (nonatomic, readonly) CGFloat wind_lastOffsetY;

/// When the WindPlayerScrollViewDirection is WindPlayerScrollViewDirectionHorizontal,the property has value.
@property (nonatomic, readonly) CGFloat wind_lastOffsetX;

/// The scrollView scroll direction, default is WindPlayerScrollViewDirectionVertical.
@property (nonatomic) WindPlayerScrollViewDirection wind_scrollViewDirection;

/// The scroll direction of scrollView while scrolling.
/// When the WindPlayerScrollViewDirection is WindPlayerScrollViewDirectionVertical，this value can only be WindPlayerScrollDirectionUp or WindPlayerScrollDirectionDown.
/// When the WindPlayerScrollViewDirection is WindPlayerScrollViewDirectionHorizontal，this value can only be WindPlayerScrollDirectionLeft or WindPlayerScrollDirectionRight.
@property (nonatomic, readonly) WindPlayerScrollDirection wind_scrollDirection;

/// Get the cell according to indexPath.
- (UIView *)wind_getCellForIndexPath:(NSIndexPath *)indexPath;

/// Get the indexPath for cell.
- (NSIndexPath *)wind_getIndexPathForCell:(UIView *)cell;

/**
Scroll to indexPath with position.
 
@param indexPath scroll the  indexPath.
@param scrollPosition  scrollView scroll position.
@param animated animate.
@param completionHandler  Scroll completion callback.
*/
- (void)wind_scrollToRowAtIndexPath:(NSIndexPath *)indexPath
                 atScrollPosition:(WindPlayerScrollViewScrollPosition)scrollPosition
                         animated:(BOOL)animated
                completionHandler:(void (^ __nullable)(void))completionHandler;

/**
Scroll to indexPath with position.
 
@param indexPath scroll the  indexPath.
@param scrollPosition  scrollView scroll position.
@param duration animate duration.
@param completionHandler  Scroll completion callback.
*/
- (void)wind_scrollToRowAtIndexPath:(NSIndexPath *)indexPath
                 atScrollPosition:(WindPlayerScrollViewScrollPosition)scrollPosition
                  animateDuration:(NSTimeInterval)duration
                completionHandler:(void (^ __nullable)(void))completionHandler;

///------------------------------------
/// The following method must be implemented in UIScrollViewDelegate.
///------------------------------------

- (void)wind_scrollViewDidEndDecelerating;

- (void)wind_scrollViewDidEndDraggingWillDecelerate:(BOOL)decelerate;

- (void)wind_scrollViewDidScrollToTop;

- (void)wind_scrollViewDidScroll;

- (void)wind_scrollViewWillBeginDragging;

///------------------------------------
/// end
///------------------------------------


@end

@interface UIScrollView (WindPlayerCannotCalled)

/// The block invoked When the player appearing.
@property (nonatomic, copy, nullable) void(^wind_playerAppearingInScrollView)(NSIndexPath *indexPath, CGFloat playerApperaPercent);

/// The block invoked When the player disappearing.
@property (nonatomic, copy, nullable) void(^wind_playerDisappearingInScrollView)(NSIndexPath *indexPath, CGFloat playerDisapperaPercent);

/// The block invoked When the player will appeared.
@property (nonatomic, copy, nullable) void(^wind_playerWillAppearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did appeared.
@property (nonatomic, copy, nullable) void(^wind_playerDidAppearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player will disappear.
@property (nonatomic, copy, nullable) void(^wind_playerWillDisappearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did disappeared.
@property (nonatomic, copy, nullable) void(^wind_playerDidDisappearInScrollView)(NSIndexPath *indexPath);

/// The block invoked When the player did stop scroll.
@property (nonatomic, copy, nullable) void(^wind_scrollViewDidEndScrollingCallback)(NSIndexPath *indexPath);

/// The block invoked When the player did  scroll.
@property (nonatomic, copy, nullable) void(^wind_scrollViewDidScrollCallback)(NSIndexPath *indexPath);

/// The block invoked When the player should play.
@property (nonatomic, copy, nullable) void(^wind_playerShouldPlayInScrollView)(NSIndexPath *indexPath);

/// The current player scroll slides off the screen percent.
/// the property used when the `stopWhileNotVisible` is YES, stop the current playing player.
/// the property used when the `stopWhileNotVisible` is NO, the current playing player add to small container view.
/// 0.0~1.0, defalut is 0.5.
/// 0.0 is the player will disappear.
/// 1.0 is the player did disappear.
@property (nonatomic) CGFloat wind_playerDisapperaPercent;

/// The current player scroll to the screen percent to play the video.
/// 0.0~1.0, defalut is 0.0.
/// 0.0 is the player will appear.
/// 1.0 is the player did appear.
@property (nonatomic) CGFloat wind_playerApperaPercent;

/// The current player controller is disappear, not dealloc
@property (nonatomic) BOOL wind_viewControllerDisappear;

/// Has stopped playing
@property (nonatomic, assign) BOOL wind_stopPlay;

/// The currently playing cell stop playing when the cell has out off the screen，defalut is YES.
@property (nonatomic, assign) BOOL wind_stopWhileNotVisible;

/// The indexPath is playing.
@property (nonatomic, nullable) NSIndexPath *wind_playingIndexPath;

/// The indexPath should be play while scrolling.
@property (nonatomic, nullable) NSIndexPath *wind_shouldPlayIndexPath;

/// WWANA networks play automatically,default NO.
@property (nonatomic, getter=wind_isWWANAutoPlay) BOOL wind_WWANAutoPlay;

/// The player should auto player,default is YES.
@property (nonatomic) BOOL wind_shouldAutoPlay;

/// The view tag that the player display in scrollView.
@property (nonatomic) NSInteger wind_containerViewTag;

/// The video contrainerView in normal model.
@property (nonatomic, strong) UIView *wind_containerView;

/// The video contrainerView type.
@property (nonatomic, assign) WindPlayerContainerType wind_containerType;

/// Filter the cell that should be played when the scroll is stopped (to play when the scroll is stopped).
- (void)wind_filterShouldPlayCellWhileScrolled:(void (^ __nullable)(NSIndexPath *indexPath))handler;

/// Filter the cell that should be played while scrolling (you can use this to filter the highlighted cell).
- (void)wind_filterShouldPlayCellWhileScrolling:(void (^ __nullable)(NSIndexPath *indexPath))handler;

@end

@interface UIScrollView (WindPlayerDeprecated)

/// The block invoked When the player did stop scroll.
@property (nonatomic, copy, nullable) void(^wind_scrollViewDidStopScrollCallback)(NSIndexPath *indexPath) __attribute__((deprecated("use `WindPlayerController.wind_scrollViewDidEndScrollingCallback` instead.")));

/// The block invoked When the player should play.
@property (nonatomic, copy, nullable) void(^wind_shouldPlayIndexPathCallback)(NSIndexPath *indexPath) __attribute__((deprecated("use `WindPlayerController.wind_playerShouldPlayInScrollView` instead.")));


/// Scroll to indexPath position  `WindPlayerScrollViewScrollPositionTop` with animations.
- (void)wind_scrollToRowAtIndexPath:(NSIndexPath *)indexPath
                completionHandler:(void (^ __nullable)(void))completionHandler __attribute__((deprecated("use `wind_scrollToRowAtIndexPath:atScrollPosition:animated:completionHandler:` instead.")));

/// Scroll to indexPath position  `WindPlayerScrollViewScrollPositionTop` with animations.
- (void)wind_scrollToRowAtIndexPath:(NSIndexPath *)indexPath
                         animated:(BOOL)animated
                completionHandler:(void (^ __nullable)(void))completionHandler __attribute__((deprecated("use `wind_scrollToRowAtIndexPath:atScrollPosition:animated:completionHandler:` instead.")));

/// Scroll to indexPath position  `WindPlayerScrollViewScrollPositionTop` with animations.
- (void)wind_scrollToRowAtIndexPath:(NSIndexPath *)indexPath
              animateWithDuration:(NSTimeInterval)duration
                completionHandler:(void (^ __nullable)(void))completionHandler __attribute__((deprecated("use `wind_scrollToRowAtIndexPath:atScrollPosition:animateDuration:completionHandler:` instead.")));

@end

NS_ASSUME_NONNULL_END
