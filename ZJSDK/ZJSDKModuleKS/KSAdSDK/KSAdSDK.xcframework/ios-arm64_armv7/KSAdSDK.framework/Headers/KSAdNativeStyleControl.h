//
//  KSAdNativeStyleControl.h
//  KSUNetworking
//
//  Created by 崔婉莹 on 2022/10/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KSAdNativeStyleControl : NSObject

///自渲染广告是否允许摇一摇
@property (nonatomic, assign) BOOL enableShake;
///自渲染广告是否允许扭一扭
@property (nonatomic, assign) BOOL enableRotate;

@end

NS_ASSUME_NONNULL_END
