//
//  UIImageView+SMWebCache.h
//  WindSDK
//
//  Created by happyelements on 2018/11/29.
//  Copyright © 2018 Codi. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^SMExternalCompletionBlock)(UIImage *_Nullable, NSError *_Nullable);

@interface UIImageView (SMWebCache)

/**
 * Set the imageView `image` with an `url`.
 *
 * The download is asynchronous and cached.
 *
 * @param url The url for the image.
 */
- (void)sm_setImageWithURL:(nullable NSURL *)url;

/**
 * Set the imageView `image` with an `url` and a placeholder.
 *
 * The download is asynchronous and cached.
 *
 * @param url         The url for the image.
 * @param placeholder The image to be set initially, until the image request finishes.
 * @see sd_setImageWithURL:placeholderImage:options:
 */
- (void)sm_setImageWithURL:(nullable NSURL *)url
          placeholderImage:(nullable UIImage *)placeholder;


- (void)sm_setImageWithURL:(nullable NSURL *)url
                 completed:(nullable SMExternalCompletionBlock)completedBlock;


- (void)sm_setImageWithURL:(nullable NSURL *)url
          placeholderImage:(nullable UIImage *)placeholder
                 completed:(nullable SMExternalCompletionBlock)completedBlock;



@end


