//
//  WindAdImageData.h
//  WindSDK
//
//  Created by duyuwei on 2026/1/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WindAdImageData : NSObject

// image address URL
@property (nonatomic, copy, nullable) NSString *imageURL;

// image width
@property (nonatomic, assign) float width;

// image height
@property (nonatomic, assign) float height;

@end

NS_ASSUME_NONNULL_END
