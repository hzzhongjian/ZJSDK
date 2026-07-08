//
//  SMWebImageManager.h
//  WindSDK
//
//  Created by happyelements on 2018/7/30.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/**
 下载图片的回调

 @param image 暂时未空，通过url获取（[[SMWebImageManager sharedManager] getImageWithKey_URL:url];）
 @param data 暂时未空，通过url获取（[[SMWebImageManager sharedManager] getImageDataWithKey_URL:url];）
 @param error 下载出错信息
 */
typedef void(^SMInternalCompletionBlock)(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error);

@interface SMWebImageManager : NSObject

+ (nonnull instancetype)sharedManager;

/**
 获取图片缓存的路径
 
 @return 路径
 */
- (NSString *_Nonnull)img_namespace;

- (void)loadImageWithURL:(NSURL *_Nullable)URL completed:(SMInternalCompletionBlock _Nullable )completedBlock;
- (BOOL)diskImageExistsForURL:(NSURL *_Nullable)url;
- (NSData *_Nullable)getImageDataWithKey_URL:(NSURL *_Nullable)url;
- (UIImage *_Nullable)getImageWithKey_URL:(NSURL *_Nullable)url;


/**
 获取图片的本地路径

 @param url 图片的URL
 @return图片的本地路径
 */
- (NSString *_Nullable)diskImagePathWithUrl:(NSURL *_Nullable)url;


/**
 清除开屏的所有图片缓存
 */
- (void)clearAllCache;


@end
