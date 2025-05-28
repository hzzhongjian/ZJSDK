//
//  WanjaClickWorker.h
//  WanjaCore
//
//  Created by ZY on 2020/2/24.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaWebViewPageCloseDelegate <NSObject>

@optional

- (void)wanja_webViewPageCloseButton:(NSString *)pageType;
- (void)wanja_deepLinkSuccess:(BOOL)isSuccess;
@end

@interface WanjaClickWorker : NSObject

@property (nonatomic, copy) NSString *landingPageURL;
@property (nonatomic, copy) NSString *phoneNumber;
@property (nonatomic, copy) NSString *deeplinkURL;
@property (nonatomic, copy) NSString *spaceID;

@property (nonatomic, assign) int32_t interactType;
//为NO时，跳到外部浏览器
@property (nonatomic, assign) BOOL useBuiltInBrow;
@property (nonatomic, assign) BOOL removeSecondaryConfirmation;

@property (nonatomic, weak) id<WanjaWebViewPageCloseDelegate> delegate;

- (void)presentClickWithRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
