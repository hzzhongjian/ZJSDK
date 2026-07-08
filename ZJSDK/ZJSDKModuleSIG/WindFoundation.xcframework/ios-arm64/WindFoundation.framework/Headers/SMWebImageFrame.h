//
//  SMWebImageFrame.h
//  Window
//
//  Created by happyelements on 2018/7/26.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface SMWebImageFrame : NSObject

/**
 The image of current frame. You should not set an animated image.
 */
@property (nonatomic, strong, readonly, nonnull) UIImage *image;
/**
 The duration of current frame to be displayed. The number is seconds but not milliseconds. You should not set this to zero.
 */
@property (nonatomic, readonly, assign) NSTimeInterval duration;

/**
 Create a frame instance with specify image and duration
 
 @param image current frame's image
 @param duration current frame's duration
 @return frame instance
 */
+ (instancetype _Nonnull)frameWithImage:(UIImage * _Nonnull)image duration:(NSTimeInterval)duration;

@end
