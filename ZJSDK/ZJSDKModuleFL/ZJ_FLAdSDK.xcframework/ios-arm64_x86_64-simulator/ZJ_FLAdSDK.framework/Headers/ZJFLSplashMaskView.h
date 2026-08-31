//
//  ZJFLSplashMaskView.h
//  ZJ_FLAdSDK
//
//  Created by Lurich on 2024/1/3.
//

#import <UIKit/UIKit.h>
#import "ZJFLLaunchView.h"
#import "ZJFLSkipAdButton.h"

NS_ASSUME_NONNULL_BEGIN


@class ZJFLSlideView;

@protocol ZJFLSplashMaskDelegate <NSObject>

@optional
- (void)slideView:(ZJFLSlideView *)slideView iphoneSlideBegan:(CGRect)frame downPoint:(CGPoint)downPoint upPoint:(CGPoint)upPoint;
- (void)iphoneMotionBegan:(CGRect)frame;

@end

@interface ZJFLSplashMaskView : UIView

@property (nonatomic, weak) ZJFLLaunchView *launchView;
@property (nonatomic, weak) ZJFLSkipAdButton *skipButton;

@property (nonatomic, weak) id<ZJFLSplashMaskDelegate> delegate;

/// 1 : 有bottomView   0 ：无bottomView
@property (nonatomic, assign) NSInteger type;

@property (nonatomic, assign) NSInteger sensitivity;
/// 0: 正常 1: 大 2: 超大
@property (nonatomic, assign) NSInteger scale_type;
/// 6: 遮罩 7: 半圆
@property (nonatomic, assign) NSInteger style_type;

- (void)addClickAreaWithView:(UIView *)bottomView restrictedClick:(BOOL)isRes;

@end

NS_ASSUME_NONNULL_END
