//
//  WindmillAnimationTool.h
//  BUDemo
//
//  Created by wangyanlin on 2020/6/18.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void (^BUDAnimationCompletion)(void);

@interface WindmillAnimationTool : NSObject

+ (instancetype)sharedInstance;
- (void)transitionFromView:(UIView *)fromView toView:(UIView *)toView splashCompletion:(BUDAnimationCompletion)splashCompletion;
@end
