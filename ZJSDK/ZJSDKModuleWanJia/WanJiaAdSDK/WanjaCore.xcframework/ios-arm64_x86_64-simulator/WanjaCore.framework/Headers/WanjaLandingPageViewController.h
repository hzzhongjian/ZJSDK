//
//  WanjaLandingPageViewController.h
//  WanjaCoreSDK
//
//  Created by guantou on 2020/2/24.
//

#import <UIKit/UIKit.h>
#import "WanjaBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaLandingPageCloseDelegate <NSObject>

@optional

- (void)wanja_landingPageCloseButton;

@end

@interface WanjaLandingPageViewController : WanjaBaseViewController

@property (nonatomic, copy) NSString *loadURL;

@property (nonatomic, copy) NSString *nextloadURL;

@property (nonatomic, assign) int32_t interactType;
@property (nonatomic, assign) BOOL removeSecondaryConfirmation;

@property (nonatomic, assign) BOOL isAlert;

@property (nonatomic, weak) id<WanjaLandingPageCloseDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
