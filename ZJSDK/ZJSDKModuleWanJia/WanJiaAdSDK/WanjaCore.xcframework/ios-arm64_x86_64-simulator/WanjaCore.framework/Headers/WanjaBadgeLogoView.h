//
//  WanjaBadgeLogoView.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaImageCatchDelegate;
/**
 角标View
*/
@interface WanjaBadgeLogoView : UIView

//该协议仅sdk内部使用
@property (nonatomic, weak) id<WanjaImageCatchDelegate> catchDelegate;

- (instancetype)initWithFrame:(CGRect)frame;

//  角标位置，0为左，1为右
@property (nonatomic, assign) NSInteger location;

//  先设置 location 后在 drawe icon
- (void)draweImageWithURL:(NSString *)imageURL andTitle:(NSString *)title;

@end

NS_ASSUME_NONNULL_END
