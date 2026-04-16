//
//  ZJ_CJ_BannerSlot.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/8.
//

#import <ZJ_CJAdSDK/ZJ_CJAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJ_BannerSlot : ZJ_CJ_Slot

/// 模版背景颜色， 默认白色
@property (nonatomic, strong) UIColor *bacColor;

/// max宽度，最大 & 默认屏幕宽度
@property (nonatomic, assign) CGFloat maxWidth;

/// title 字体，默认systemFont:16
@property (nonatomic, strong) UIFont *titleFont;

/// title 字体，默认#262626
@property (nonatomic, strong) UIColor *titleTxtColor;

/// 描述字体，默认systemFont:12
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
