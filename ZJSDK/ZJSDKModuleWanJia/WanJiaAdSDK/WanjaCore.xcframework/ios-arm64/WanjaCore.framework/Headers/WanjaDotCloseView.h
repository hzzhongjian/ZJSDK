//
//  WanjaDotCloseView.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/25.
//  ***需要完善内容---按钮需要根据返回的广告内容去修改其逻辑。目前完成的是可在按钮外部自定义按钮的大小及其位置。

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 圆形点击关闭按钮，适用于激励视频等广告
*/
@protocol WanjaTimeCloseDelegate <NSObject>

@optional
/**
 圆形点击关闭按钮
 */
- (void)wanja_dotCloseButton;

@end

@interface WanjaDotCloseView : UIView

@property (nonatomic, weak) id<WanjaTimeCloseDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame;

@property (nonatomic, assign) BOOL autoClose;
@property (nonatomic, assign) int maxTime;
@property (nonatomic, assign) BOOL manualClosable;
@property (nonatomic, assign) int minTime;

//  显示关闭按钮
- (void)showDotCloseView;

//  移除关闭按钮
- (void)closeSelf;

@end

NS_ASSUME_NONNULL_END
