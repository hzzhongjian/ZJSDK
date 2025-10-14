//
//  JYNativeAdDataObject.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/4/21.
//

#import <Foundation/Foundation.h>
#import "JYVideoConfig.h"
#import "JYAdViewActionConfig.h"
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, JYNativeAdCreativeType) {
    JYNativeAdCreativeTypeUnkown = 0,
    
    JYNativeAdCreativeType_ADX_NONE = (1 << 24) | 0,
    JYNativeAdCreativeType_ADX_TXT = (1 << 24) | 1,//TXT 纯文字
    JYNativeAdCreativeType_ADX_IMG = (1 << 24) | 2,//IMG 纯图片
    JYNativeAdCreativeType_ADX_HYBRID = (1 << 24) | 3,//HYBRID 图文混合
    JYNativeAdCreativeType_ADX_VIDEO = (1 << 24) | 4,//VIDEO 视频广告
    JYNativeAdCreativeType_ADX_IMGS = (1 << 24) | 5,//多图

    JYNativeAdCreativeType_GDT_isAppAd = (2 << 24) | 1,//isAppAd
    JYNativeAdCreativeType_GDT_isVideoAd = (2 << 24) | 2,//isVideoAd
    JYNativeAdCreativeType_GDT_isThreeImgsAd = (2 << 24) | 3,//isThreeImgsAd
    JYNativeAdCreativeType_GDT_isWechatCanvasAd = (2 << 24) | 4,//isWechatCanvasAd
    
    JYNativeAdCreativeType_CSJ_SmallImage = (3 << 24) | 2,
    JYNativeAdCreativeType_CSJ_LargeImage = (3 << 24) | 3,
    JYNativeAdCreativeType_CSJ_GroupImage = (3 << 24) | 4,
    JYNativeAdCreativeType_CSJ_VideoImage = (3 << 24) | 5,// video ad || rewarded video ad horizontal screen
    JYNativeAdCreativeType_CSJ_VideoPortrait = (3 << 24) | 15,// rewarded video ad vertical screen
    JYNativeAdCreativeType_CSJ_ImagePortrait = (3 << 24) | 16,
    JYNativeAdCreativeType_CSJ_SquareImage = (3 << 24) | 33,//SquareImage Currently it exists only in the oversea now. V3200 add
    JYNativeAdCreativeType_CSJ_SquareVideo = (3 << 24) | 50,//SquareVideo Currently it exists only in the oversea now. V3200 add
    JYNativeAdCreativeType_CSJ_UnionSplashVideo = (3 << 24) | 154, // Video splash, V3800 add
    JYNativeAdCreativeType_CSJ_UnionVerticalImage = (3 << 24) | 173, // vertical picture
    
    JYNativeAdCreativeType_KS_AdMaterialTypeVideo = (4 << 24) | 1,      // video
    JYNativeAdCreativeType_KS_AdMaterialTypeSingle = (4 << 24) | 2,      // single image
    JYNativeAdCreativeType_KS_AdMaterialTypeAtlas = (4 << 24) | 3,      // multiple image
    
    /// 原生自渲染-横版大图16：9
    JYNativeAdCreativeType_KLN_HorBigImage = (5 << 24) | 1001,
    /// 原生自渲染-横版视频16：9
    JYNativeAdCreativeType_KLN_HorVideo = (5 << 24) | 1002,
    
    JYNativeAdCreativeType_BD_NORMAL = (6 << 24) | 0, // 一般图文或图片广告
    JYNativeAdCreativeType_BD_VIDEO = (6 << 24) | 1, // 视频广告，需开发者增加播放器支持
    JYNativeAdCreativeType_BD_HTML = (6 << 24) | 2, // html模版广告
    JYNativeAdCreativeType_BD_GIF = (6 << 24) | 3, //GIF广告
    
    JYNativeAdCreativeType_GRO_SmallImage = (7 << 24) | 2,
    JYNativeAdCreativeType_GRO_LargeImage = (7 << 24) | 3,
    JYNativeAdCreativeType_GRO_GroupImage = (7 << 24) | 4,
    JYNativeAdCreativeType_GRO_VideoImage = (7 << 24) | 5, // video ad || rewarded video ad horizontal screen
    JYNativeAdCreativeType_GRO_VideoPortrait = (7 << 24) | 15, // rewarded video ad vertical screen
    JYNativeAdCreativeType_GRO_ImagePortrait = (7 << 24) | 16,
    JYNativeAdCreativeType_GRO_SquareImage = (7 << 24) | 33, //SquareImage Currently it exists only in the oversea now. V3200 add
    JYNativeAdCreativeType_GRO_SquareVideo = (7 << 24) | 50, //SquareVideo Currently it exists only in the oversea now. V3200 add
    JYNativeAdCreativeType_GRO_UnionSplashVideo = (7 << 24) | 154, // Video splash, V3800 add
    JYNativeAdCreativeType_GRO_LiveStream = (7 << 24) | 166, // Live Stream Ad. v5200 add
    JYNativeAdCreativeType_GRO_UnionVerticalImage = (7 << 24) | 173, // vertical picture
    JYNativeAdCreativeType_GRO_UnionAtlas = (7 << 24) | 180, // atlas
    JYNativeAdCreativeType_GRO_MediationUnknown = (7 << 24) | 1000, //聚合其他广告sdk未知
    
    JYNativeAdCreativeType_GRO_Unknown = (7 << 24) | 0,
    JYNativeAdCreativeType_GRO_LandscapeVideo = JYNativeAdCreativeType_GRO_VideoImage,
    JYNativeAdCreativeType_GRO_PortraitVideo = JYNativeAdCreativeType_GRO_VideoPortrait,
    JYNativeAdCreativeType_GRO_PortraitImage = JYNativeAdCreativeType_GRO_ImagePortrait,
    
    JYNativeAdCreativeType_SIG_VIDEO = (8 << 24) | 0,
    JYNativeAdCreativeType_SIG_IMAGE = (8 << 24) | 1,
    JYNativeAdCreativeType_SIG_UNKNOWN = (8 << 24) | 2,
};

typedef NS_ENUM(NSInteger, JYNativeAdInteractionType) {
    JYNativeAdInteractionTypeUnkown = 0,
    JYNativeAdInteractionTypeBrowser = 1,
    JYNativeAdInteractionTypeDownload = 2,
};

@class JYInnerNativeAdDataObject;

@interface JYNativeAdDataObject : NSObject <JYAdProtocol>
{
    @package
     JYInnerNativeAdDataObject * _innerNativeAdDataObject;
}

@property (nonatomic, copy, readonly) NSString *title;
@property (nonatomic, copy, readonly) NSString *desc;
@property (nonatomic, copy, readonly) NSString *imageUrl;
@property (nonatomic, readonly) NSInteger imageWidth;
@property (nonatomic, readonly) NSInteger imageHeight;
@property (nonatomic, readonly) NSInteger videoWidth;
@property (nonatomic, readonly) NSInteger videoHeight;
@property (nonatomic, copy, readonly) NSString *iconUrl;
@property (nonatomic, copy, readonly) NSArray *imageUrls;
@property (nonatomic, readonly) JYNativeAdCreativeType creativeType;
@property (nonatomic, readonly) JYNativeAdInteractionType interactionType;

@property (nonatomic, strong) JYVideoConfig *videoConfig;
@property (nonatomic, strong) JYAdViewActionConfig *actionConfig;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;

- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

/// 判断当前返回的广告素材是：图片/视频
- (BOOL)isVideoMaterial;

@end

NS_ASSUME_NONNULL_END
