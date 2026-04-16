//
//  JTSplashView.h
//  JTAdSDK
//
//  Created by Frank on 2025/6/25.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol JTSplashViewDelegate <NSObject>

- (void)splashViewDidClickContent;

- (void)splashViewDidClickSkip;

- (void)splashViewDidTimeCountDown;

@end

@class JTAdGroupModel,JTAdResponseModel;

/// 聚推开屏广告容器视图
@interface JTSplashView : UIView

@property (nonatomic, weak) id<JTSplashViewDelegate> delegate;

- (instancetype)initWithExpSize:(CGSize)expSize
                     bottomView:(UIView *)bottomView
                         adData:(JTAdResponseModel *)respModel
                     groupModel:(JTAdGroupModel *)groupModel
                         adInfo:(JTAdInfoModel *)adInfoModel;

- (void)stopVideoPlayer;

- (void)handleFCAction;

@end

NS_ASSUME_NONNULL_END
