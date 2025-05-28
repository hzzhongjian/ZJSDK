//
//  WanjaDevice.h
//  WanjaAD
//
//  Created by zwf on 2020/12/8.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WanjaDevice : NSObject

/**
 状态栏高度
  */
+ (CGFloat)wanja_statusBarHeight;

+ (CGFloat)wanja_safeHeight;

/**
 导航栏高度
  */
+ (CGFloat)wanja_navigationBarHeight;


/**
 导航栏加状态栏高度
  */
+ (CGFloat)wanja_topHeight;


/**
 X底部高度
  */
+ (CGFloat)wanja_bottomOffset;

/**
 底部高度+tabbar高度
 */
+ (CGFloat)wanja_tabbarHeight;

+ (BOOL)wanja_isPhoneX;

@end

NS_ASSUME_NONNULL_END
