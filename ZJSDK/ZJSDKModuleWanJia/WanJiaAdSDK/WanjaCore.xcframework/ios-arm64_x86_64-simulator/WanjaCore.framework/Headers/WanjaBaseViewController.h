//
//  WanjaBaseViewController.h
//  WanjaCore
//
//  Created by hongji cai on 2024/1/22.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WanjaBaseViewController : UIViewController
@property (nonatomic, assign) BOOL isStatusBarLightContent;
@property (nonatomic, assign) BOOL hideNavigationBar;
@property (nonatomic, assign) BOOL navBlackStyle;
@property (nonatomic, assign) BOOL isListenAppEnterForegroundNotify;

- (void)configUIStyle;
- (void)wanjaApplicationWillEnterForeground:(NSNotification*)notification;
@end

NS_ASSUME_NONNULL_END
