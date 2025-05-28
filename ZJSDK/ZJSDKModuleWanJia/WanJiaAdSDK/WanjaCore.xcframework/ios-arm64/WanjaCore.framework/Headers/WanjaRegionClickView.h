//
//  WanjaRegionClickView.h
//  WanjaopusAdSDK
//
//  Created by zwf on 2023/5/18.
//

#import <UIKit/UIKit.h>
#import "WanjaConfigureModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaRegionClickDelegate <NSObject>

@optional

- (void)wanja_adRegionClickAction;

@end

@interface WanjaRegionClickView : UIView

@property (nonatomic, weak) id<WanjaRegionClickDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame;
- (instancetype)initWithFrame:(CGRect)frame zoomScale:(CGFloat)zoomScale;

- (void)setRegionClick:(WanjaRegionalClick *)regionClick;

@end

NS_ASSUME_NONNULL_END
