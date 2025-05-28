//
//  WanjaNormalPageViewController.h
//  WanjaCoreSDK
//

//

#import <UIKit/UIKit.h>
#import "WanjaBaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaNormaPageCloseDelegate <NSObject>

@optional

- (void)wanja_NormaPageCloseButton;

@end

@interface WanjaNormalPageViewController : WanjaBaseViewController

@property (nonatomic, copy) NSString *loadURL;

@property (nonatomic, weak) id<WanjaNormaPageCloseDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
