//
//  ZJNativeSplashModel.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/10/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJPaddingModel : NSObject

// 左
@property (nonatomic, assign) CGFloat left;

// 上
@property (nonatomic, assign) CGFloat top;

// 右
@property (nonatomic, assign) CGFloat right;

// 下
@property (nonatomic, assign) CGFloat bottom;

+ (ZJPaddingModel *)parseModel:(NSArray *)params;

@end

// 关闭按钮
@interface ZJCloseButtonModel : NSObject

// 是否可见（0->是|1->否）
@property (nonatomic, assign) NSInteger visible;

// 背景色
@property (nonatomic, copy) NSString *background;

// 前景色（图标、文字颜色）
@property (nonatomic, copy) NSString *foreground;

// 内边距（左上右下）
@property (nonatomic, strong) ZJPaddingModel *padding;

// 外边距
@property (nonatomic, assign) CGFloat margin;

+ (ZJCloseButtonModel *)parseModel:(NSDictionary *)params;

@end

// 来源信息
@interface ZJSourceInfoModel : NSObject

// 样式（0->图文| 1->纯图| 2->纯文字| 3->隐藏）
@property (nonatomic, assign) NSInteger style;

// 背景色
@property (nonatomic, copy) NSString *background;

// 前景色（文字颜色、图标明亮/暗黑模式）
@property (nonatomic, copy) NSString *foreground;

// 预设的图片宽高比
@property (nonatomic, assign) CGFloat ratio;

+ (ZJSourceInfoModel *)parseModel:(NSDictionary *)params;

@end

// 内容区域
@interface ZJContentAreaModel : NSObject

// 样式（0->半屏|1->全屏）
@property (nonatomic, assign) NSInteger style;

// 缩放模式（0->双边缩放| 1->单边缩放）
@property (nonatomic, assign) NSInteger scale_type;

// 内容的宽高比（部分样式需要使用）
@property (nonatomic, assign) CGFloat ratio;

// 模板样式（可多选）
@property (nonatomic, strong) NSArray *template_style;

+ (ZJContentAreaModel *)parseModel:(NSDictionary *)parmas;

@end

// 布局样式
@interface ZJLayoutModel : NSObject

// 关闭按钮
@property (nonatomic, strong) ZJCloseButtonModel *close_btn;

// 来源信息
@property (nonatomic, strong) ZJSourceInfoModel *source_info;

// 内容区域
@property (nonatomic, strong) ZJContentAreaModel *content;

+ (ZJLayoutModel *)parseModel:(NSDictionary *)params;

@end

// 功能开关
@interface ZJFeatureModel : NSObject

// 挽留页（激励未完成时跳过的挽留弹窗）
@property (nonatomic, assign) NSInteger retention_card;

// 结束页（激励跳过后的一个静态页面）
@property (nonatomic, assign) NSInteger end_card;

// 一键关闭（默认关闭，达成奖励条件后点击关闭按钮时直接关闭广告，无论当前处于什么状态）
@property (nonatomic, assign) NSInteger one_click_close;

// 点击后关闭（默认关闭。达成奖励条件后触发广告点击后直接关闭广告）
@property (nonatomic, assign) NSInteger click_to_close;

+ (ZJFeatureModel *)parseModel:(NSDictionary *)params;

@end


// 策略配置
@interface ZJPolicyModel : NSObject


// 跳过按钮的出现时长，默认观看5S后可以跳过
@property (nonatomic, assign) NSInteger skip_after_seconds;

// 获得奖励的时长，默认25S
@property (nonatomic, assign) NSInteger reward_after_seconds;

// 交互类型（0->纯点击|1->摇一摇| 2->晃一晃）
@property (nonatomic, assign) NSInteger interaction_type;

// 摇一摇的三抽加速度阈值
@property (nonatomic, assign) NSInteger acceleration;

// 晃一晃的三抽角度阈值
@property (nonatomic, assign) NSInteger rotation_angle;

+ (ZJPolicyModel *)parseModel:(NSDictionary *)params;

@end


@interface ZJNativeSplashModel : NSObject

// 布局样式
@property (nonatomic, strong) ZJLayoutModel *layout;

// 功能开关
@property (nonatomic, strong) ZJFeatureModel *feature;

// 策略配置
@property (nonatomic, strong) ZJPolicyModel *policy;

+ (ZJNativeSplashModel *)parseModel:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
