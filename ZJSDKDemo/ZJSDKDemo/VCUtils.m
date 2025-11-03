//
//  VCUtils.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2025/11/3.
//  Copyright © 2025 zj. All rights reserved.
//

#import "VCUtils.h"

@implementation VCUtils

+ (UIWindow *)keyWindow {
    if (@available(iOS 13.0, *)) {
        UIWindow *topWindow = nil;
        CGFloat topWindowLevel = CGFLOAT_MIN;

        for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {
            // 只处理 UIWindowScene 类型的 scene
            if (![scene isKindOfClass:[UIWindowScene class]]) {
                continue;
            }

            UIWindowScene *windowScene = (UIWindowScene *)scene;
            if (windowScene.activationState != UISceneActivationStateForegroundActive) {
                continue;
            }

            for (UIWindow *window in windowScene.windows) {
                if (!window.isHidden && window.windowLevel > topWindowLevel) {
                    topWindowLevel = window.windowLevel;
                    topWindow = window;
                }
            }
        }

        // 如果没找到，回退到 keyWindow（某些情况下可能仍有）
        if (!topWindow) {
            for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {
                if ([scene isKindOfClass:[UIWindowScene class]]) {
                    UIWindowScene *windowScene = (UIWindowScene *)scene;
                    for (UIWindow *window in windowScene.windows) {
                        if (window.isKeyWindow && !window.isHidden) {
                            return window;
                        }
                    }
                }
            }
        }

        return topWindow;
    } else {
        // iOS 12 及以下
        return [UIApplication sharedApplication].keyWindow;
    }
}

+ (UIViewController *)topmostViewController {
    UIViewController *rootVC = [[self class] keyWindow].rootViewController;
    return [self topmostViewControllerFrom:rootVC];
}

+ (UIViewController *)topmostViewControllerFrom:(UIViewController *)vc {
    if ([vc isKindOfClass:[UINavigationController class]]) {
        UINavigationController *nav = (UINavigationController *)vc;
        return [self topmostViewControllerFrom:nav.visibleViewController];
    } else if ([vc isKindOfClass:[UITabBarController class]]) {
        UITabBarController *tab = (UITabBarController *)vc;
        return [self topmostViewControllerFrom:tab.selectedViewController];
    } else if (vc.presentedViewController) {
        UIViewController *presented = vc.presentedViewController;
        // 检查是否正在 dismiss，避免返回已消失的 VC
        if (presented.isBeingDismissed) {
            return vc;
        }
        return [self topmostViewControllerFrom:presented];
    } else {
        return vc;
    }
}

@end
