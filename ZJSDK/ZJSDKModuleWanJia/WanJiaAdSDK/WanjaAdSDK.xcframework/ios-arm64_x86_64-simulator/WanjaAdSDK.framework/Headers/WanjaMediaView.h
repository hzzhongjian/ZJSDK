//
//  WanjaMediaView.h
//  WanjaAdSDK
//
//  Created by hongji cai on 2024/4/13.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    WanjaVedioShowModelResize,
    WanjaVedioShowModelResizeAspect,
    WanjaVedioShowModelResizeFill,
} WanjaVedioShowModel;

@class WanjaSpaceInfoModel;

@interface WanjaMediaView : UIView
//视频的显示模式，默认WanjaVedioShowModelResizeAspect
@property (nonatomic, assign) WanjaVedioShowModel showModel;
//声音控制视图, 外部可以改变frame。 width / height = 1 / 1
@property (nonatomic, strong, readonly) UIView *voiceControlView;
/**控制视频的音量控制按钮是否展示（默认显示）*/
@property (nonatomic, assign) BOOL isHiddenVoiceButton;

- (instancetype)initWithFrame:(CGRect)frame spaceInfo:(WanjaSpaceInfoModel*)spaceInfo;
@end

NS_ASSUME_NONNULL_END
