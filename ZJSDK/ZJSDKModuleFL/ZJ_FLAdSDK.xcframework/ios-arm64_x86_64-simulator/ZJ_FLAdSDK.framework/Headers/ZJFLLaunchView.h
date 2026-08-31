//
//  ZJFLLaunchView.h
//  ZJ_FLAdSDK
//
//  Created by lurich on 2021/10/12.
//

#import <UIKit/UIKit.h>

@class ZJFLFeedAdData;

NS_ASSUME_NONNULL_BEGIN

typedef void(^ShowBlock)(void);

@interface ZJFLLaunchView : UIView

@property (nonatomic) CGRect tipFrame;
@property (nonatomic) CGRect skipFrame;
@property (nonatomic) CGRect volumeFrame;
@property (nonatomic, assign) BOOL frameSet;

@property (nonatomic) CGRect adFrame;
@property (nonatomic, strong) ZJFLFeedAdData *model;
@property (nonatomic, assign) NSInteger scale_type;
/// 底图背景
@property (nonatomic, strong) UIImageView *backImgView;
/// 图片
@property (nonatomic, strong) UIImageView *bigImgView;
/// 预制背景图片
@property (nonatomic, strong) UIImage *backgroundImage;

- (void)restrictedClickAreaWithFrame:(CGRect)frame;
- (void)restrictedClickCircleAreaWithCenter:(CGRect)frame;

@property (nonatomic, copy) ShowBlock block;

- (void)addTipLabel:(NSString *)tipStr WithView:(UIView *)bottomView restrictedClick:(BOOL)isRes;

@end

NS_ASSUME_NONNULL_END
