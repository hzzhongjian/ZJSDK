//
//  ZJ_CJNativeExpressView.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/10.
//
//  信息流模板广告 View：支持原生 templateType(1-6) 与 H5 dynamic_adm 动态模板。
//

#import <UIKit/UIKit.h>
#import <ZJ_CJAdSDK/ZJ_CJNativeAdData.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJNativeExpressView : UIView

/// 根据广告数据源创建广告View
- (instancetype)initWithAdData:(ZJ_CJNativeAdData *)adData;

/**
 * 释放广告
 */
- (void)destory;

@end

NS_ASSUME_NONNULL_END
