//
//  ZJ_CJSplashAdSlot.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/11/27.
//

#import <ZJ_CJAdSDK/ZJ_CJSlot.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJSplashAdSlot : ZJ_CJSlot

/// ------------------------------------模版配置------------------------------------
/// 模版背景颜色， 默认白色
@property (nonatomic, strong) UIColor *bacColor;

/// 跳过按钮字体，默认systemFont:14
@property (nonatomic, strong) UIFont *skipBtnTextFont;

/// 跳过按钮背景颜色， 默认浅灰
@property (nonatomic, strong) UIColor *skipBtnBacColor;

/// 跳过按钮字体颜色， 默认白色
@property (nonatomic, strong) UIColor *skipBtnTextColor;

/// click按钮字体，默认systemFont:20
@property (nonatomic, strong) UIFont *clickBtnTextFont;

/// click按钮背景颜色， 默认浅灰
@property (nonatomic, strong) UIColor *clickBtnBacColor;

/// click按钮字体颜色， 默认白色
@property (nonatomic, strong) UIColor *clickBtnTextColor;

@end

NS_ASSUME_NONNULL_END
