//
//  SMWebImageCoderHelper.h
//  Window
//
//  Created by happyelements on 2018/7/26.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/SMWebImageFrame.h>

@interface SMWebImageCoderHelper : NSObject

/**
 Return an animated image with frames array.
 For UIKit, this will apply the patch and then create animated UIImage. The patch is because that `+[UIImage animatedImageWithImages:duration:]` just use the average of duration for each image. So it will not work if different frame has different duration. Therefore we repeat the specify frame for specify times to let it work.
 For AppKit, NSImage does not support animates other than GIF. This will try to encode the frames to GIF format and then create an animated NSImage for rendering. Attention the animated image may loss some detail if the input frames contain full alpha channel because GIF only supports 1 bit alpha channel. (For 1 pixel, either transparent or not)
 
 @param frames The frames array. If no frames or frames is empty, return nil
 @return A animated image for rendering on UIImageView(UIKit) or NSImageView(AppKit)
 */
+ (UIImage * _Nullable)animatedImageWithFrames:(NSArray<SMWebImageFrame *> * _Nullable)frames;

/**
 Return frames array from an animated image.
 For UIKit, this will unapply the patch for the description above and then create frames array. This will also work for normal animated UIImage.
 For AppKit, NSImage does not support animates other than GIF. This will try to decode the GIF imageRep and then create frames array.
 
 @param animatedImage A animated image. If it's not animated, return nil
 @return The frames array
 */
+ (NSArray<SMWebImageFrame *> * _Nullable)framesFromAnimatedImage:(UIImage * _Nullable)animatedImage;

@end
