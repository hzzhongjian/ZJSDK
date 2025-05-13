//
//  QMNativeAdShakeView.h
//  QMAdSDK
//
//  Created by Donnie on 2024/12/23.
//

#import <UIKit/UIKit.h>

#import <QMAdSDK/QMNativeAd.h>

NS_ASSUME_NONNULL_BEGIN

/// 初始化摇一摇组件，组件高度需要大于80pt。
/// 摇一摇文案内容为：摇动手机 了解更多 如果组件宽度不够，则会自动将宽度适配文字长度。
@interface QMNativeAdShakeView : UIView

@property (nonatomic, strong) QMNativeAd *nativeAd;

/// 开启摇动检测
- (void)startShake;

/// 停止摇动检测
- (void)stopShake;

@end

NS_ASSUME_NONNULL_END
