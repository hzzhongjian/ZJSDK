//
//  UIImage+SMImage.h
//  WindSDK
//
//  Created by happyelements on 2018/6/29.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (SMImage)

+ (UIImage *)sm_imageWithBase64String:(NSString *)base64;

+ (UIImage *)sm_imageWithColor:(UIColor *)color;


@end
