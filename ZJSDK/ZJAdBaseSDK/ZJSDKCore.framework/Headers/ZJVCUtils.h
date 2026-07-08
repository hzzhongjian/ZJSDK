//
//  ZJVCUtils.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/11/3.
//

#import <ZJSDKCore/ZJSDKCore.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJVCUtils : ZJNativeInterstitialAdVC

// 获取最外层显示的视图控制器
+ (UIViewController *)topmostViewController;

@end

NS_ASSUME_NONNULL_END
