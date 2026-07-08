//
//  ZJNativeButton.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/10/29.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJNativeButton : UIButton

// 外边距
@property (nonatomic, assign) UIEdgeInsets margin;

// 内边距
@property (nonatomic, assign) UIEdgeInsets padding;

// 显示文字的标题
@property (nonatomic, copy) NSString *title;

// 字体大小
@property (nonatomic, assign) CGFloat fontSize;

// 背景色
@property (nonatomic, copy) NSString *backgroundViewColor;

// 文字颜色
@property (nonatomic, copy) NSString *textColor;


- (void)buildView;

@property (nonatomic, copy) void(^skipButtonDidClick)(void);

@end

NS_ASSUME_NONNULL_END
