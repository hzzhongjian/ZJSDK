//
//  ZJ_CJ_NativeAdSlot.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/10.
//

#import <ZJ_CJAdSDK/ZJ_CJAdSDK.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJ_NativeAdSlot : ZJ_CJ_Slot

/// 任务完成之后，是否需要后端检查验证任务有效性，默认NO
@property (nonatomic, assign) CGSize adSize;
/// 渲染类型，默认是模板渲染
@property (nonatomic, assign) ZJ_CJ_AdRenderType renderType;

/// 单次请求的广告数量，目前只支持一次请求1个
@property (nonatomic, assign) NSUInteger adCount;

/// ------------------------------------模版配置------------------------------------
/// 模版背景颜色， 默认白色
@property (nonatomic, strong) UIColor *bacColor;

/// max宽度，最大 & 默认屏幕宽度
@property (nonatomic, assign) CGFloat maxWidth;

/// title 字体，默认systemFont:16
@property (nonatomic, strong) UIFont *titleFont;

/// title 字体，默认#262626
@property (nonatomic, strong) UIColor *titleTxtColor;

/// 描述字体，默认systemFont:10
@property (nonatomic, strong) UIFont *desFont;

/// 描述字体，默认#262626
@property (nonatomic, strong) UIColor *desTxtColor;

/// 查看按钮字体，默认systemFont:14
@property (nonatomic, strong) UIFont *linkBtnFont;

/// 查看按钮背景颜色， 默认蓝色
@property (nonatomic, strong) UIColor *linkBtnBacColor;

/// 查看按钮字体颜色， 默认白色
@property (nonatomic, strong) UIColor *linkBtnTxtColor;

@end

NS_ASSUME_NONNULL_END
