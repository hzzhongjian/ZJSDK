//
//  JTMaterialMeta.h
//  JTAdSDK
//
//  Created by Frank on 2025/7/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class JTVideoPlayerView;

/// 自渲染广告的素材数据模型
@interface JTMaterialMeta : UIView

/// 素材标题
@property (nonatomic, copy) NSString *title;

/// 素材描述文案
@property (nonatomic, copy) NSString *desc;

/// 素材App名称
@property (nonatomic, copy) NSString *app_name;

/// 素材APP Logo地址url
@property (nonatomic, copy) NSString *app_logo;

/// 素材url
@property (nonatomic, copy) NSString *url;

/// 素材尺寸模型
@property (nonatomic, strong) JTAdSizeModel *sizeModel;

/// 该属性已废弃。请使用【jtLogoView】。重命名，防止误判！！！属性的性质无任何变化，只是名称变化。
//@property (nonatomic, strong) UIView *logoView;

/// 聚推联盟Logo的View
@property (nonatomic, strong) UIView *jtLogoView;
/// 聚推联盟Logo的Url
@property (nonatomic, copy) NSString *jtLogoUrl;

/// 视频素材播放器。可由此控制播放进度及监听播放事件。
@property (nonatomic, strong) JTVideoPlayerView *videoPlayerView;

/// 摇一摇的视图。只有当前自渲染支持摇一摇交互的时候，shakeView才不为空。
@property (nonatomic, strong, nullable) UIView *shakeView;

@end

NS_ASSUME_NONNULL_END
