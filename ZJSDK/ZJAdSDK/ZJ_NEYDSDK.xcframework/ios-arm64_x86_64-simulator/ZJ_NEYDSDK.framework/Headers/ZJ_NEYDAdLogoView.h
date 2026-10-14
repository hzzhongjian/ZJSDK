//
//  ZJ_NEYDAdLogoView.h
//  ZJ_NEYDSDK-2.0.0
//  广告角标标识，可复用于开屏、原生、原生视频、激励视频。
//  两种形态由编译宏 ZJ_NEYD_ADLOGO_STYLE_CAPSULE 切换（白标脚本 --logo-style 注入）：
//    - 默认(single)：单个 UIImageView，图片(zj_neyd_ad_logo)已含图标+文字，透明无底色。
//    - capsule：图标 + "广告" UILabel，黑色 30% 半透明圆角胶囊。
//  Created by Zj_neyd. Copyright © Zj_neyd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_NEYDAdLogoView : UIView

/// 角标建议尺寸（按角标图片自适应）。初始化后 bounds 已按该尺寸设置，调用方只需设置 origin。
- (CGSize)sizeThatFits:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
