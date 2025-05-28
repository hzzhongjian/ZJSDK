//
//  WanjaSwipeView.h
//  WanjaopusAdSDK
//
//  Created by zwf on 2023/5/17.
//

#import <UIKit/UIKit.h>

@class WanjaSwipeViewModel;

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaSwipeViewDelegate <NSObject>

@optional

- (void)wanja_adSwipeAction;

@end

@interface WanjaSwipeView : UIImageView

@property (nonatomic, weak) id<WanjaSwipeViewDelegate> delegate;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *details;
@property (nonatomic, strong) WanjaSwipeViewModel *swipeViewModel;

- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithFrame:(CGRect)frame zoomScale:(CGFloat)zoomScale;

@end

NS_ASSUME_NONNULL_END
