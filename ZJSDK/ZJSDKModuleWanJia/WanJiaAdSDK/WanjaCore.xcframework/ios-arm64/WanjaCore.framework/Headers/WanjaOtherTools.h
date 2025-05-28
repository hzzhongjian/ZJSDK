//
//  WanjaOtherTools.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  其他工具
 */
@interface WanjaOtherTools : NSObject

/**
 判断字符串是否为空
 @param string 需要判断的字符串
 @return 空返回Yes or 不为空返回NO
 */
+ (BOOL)isEmptyString:(NSString *)string;

/**
 判断data是否为空
 @param data 需要判断的data
 @return 空返回Yes or 不为空返回NO
 */
+ (BOOL)isEmptyData:(NSData *)data;

/**
 获取文字Size
 @param string 文字内容
 @param font 文字字号
 @return 文字Size
 */
+ (CGSize)returnSizeWithString:(NSString *)string Font:(CGFloat)font;

/**
 判断是否为AppStore链接
 @param URL 输入链接
 @return 是否可以跳转
 */
+ (BOOL)isOpenAppStore:(NSURL *)URL;

/**
 获取文件路径

 @param docmentName 文件名称
 @param type 文件类型
 @return 文件路径
 */
+ (NSString *)getDocmentPath:(NSString *)docmentName ofType:(NSString *)type;

/**
 随机UUID
 */
+ (NSString *)randomUUID;

+ (UIImage *)wanja_launchImage;

@end

NS_ASSUME_NONNULL_END
