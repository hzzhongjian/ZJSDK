//
//  KSAdViewActionConfiguration.h
//  KSUNativeAd
//
//  Created by 杜祥军 on 2024/8/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KSAdViewActionConfiguration : NSObject
/// control whether the view needs to add click event. Default is YES.
@property (nonatomic, assign) BOOL isClickable;
/// control whether the view needs to add slide event. Default is YES.
@property (nonatomic, assign) BOOL isSlidable;

- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
