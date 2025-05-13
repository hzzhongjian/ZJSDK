//
//  JLNativeAdDataObject.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/4/21.
//

#import <Foundation/Foundation.h>
#import "JLVideoConfig.h"
#import "JLAdViewActionConfig.h"
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, JLNativeAdCreativeType) {
    JLNativeAdCreativeTypeUnkown = 0,
    
    JLNativeAdCreativeType_ADX_NONE = (1 << 24) | 0,
    JLNativeAdCreativeType_ADX_TXT = (1 << 24) | 1,//TXT 纯文字
    JLNativeAdCreativeType_ADX_IMG = (1 << 24) | 2,//IMG 纯图片
    JLNativeAdCreativeType_ADX_HYBRID = (1 << 24) | 3,//HYBRID 图文混合
    JLNativeAdCreativeType_ADX_VIDEO = (1 << 24) | 4,//VIDEO 视频广告
    JLNativeAdCreativeType_ADX_IMGS = (1 << 24) | 5,//多图

    JLNativeAdCreativeType_GDT_isAppAd = (2 << 24) | 1,//isAppAd
    JLNativeAdCreativeType_GDT_isVideoAd = (2 << 24) | 2,//isVideoAd
    JLNativeAdCreativeType_GDT_isThreeImgsAd = (2 << 24) | 3,//isThreeImgsAd
    JLNativeAdCreativeType_GDT_isWechatCanvasAd = (2 << 24) | 4,//isWechatCanvasAd
    
    JLNativeAdCreativeType_CSJ_SmallImage = (3 << 24) | 2,
    JLNativeAdCreativeType_CSJ_LargeImage = (3 << 24) | 3,
    JLNativeAdCreativeType_CSJ_GroupImage = (3 << 24) | 4,
    JLNativeAdCreativeType_CSJ_VideoImage = (3 << 24) | 5,// video ad || rewarded video ad horizontal screen
    JLNativeAdCreativeType_CSJ_VideoPortrait = (3 << 24) | 15,// rewarded video ad vertical screen
    JLNativeAdCreativeType_CSJ_ImagePortrait = (3 << 24) | 16,
    JLNativeAdCreativeType_CSJ_SquareImage = (3 << 24) | 33,//SquareImage Currently it exists only in the oversea now. V3200 add
    JLNativeAdCreativeType_CSJ_SquareVideo = (3 << 24) | 50,//SquareVideo Currently it exists only in the oversea now. V3200 add
    JLNativeAdCreativeType_CSJ_UnionSplashVideo = (3 << 24) | 154, // Video splash, V3800 add
    JLNativeAdCreativeType_CSJ_UnionVerticalImage = (3 << 24) | 173, // vertical picture
    
    JLNativeAdCreativeType_KS_AdMaterialTypeVideo = (4 << 24) | 1,      // video
    JLNativeAdCreativeType_KS_AdMaterialTypeSingle = (4 << 24) | 2,      // single image
    JLNativeAdCreativeType_KS_AdMaterialTypeAtlas = (4 << 24) | 3,      // multiple image
    
    /// 原生自渲染-横版大图16：9
    JLNativeAdCreativeType_KLN_HorBigImage = (5 << 24) | 1001,
    /// 原生自渲染-横版视频16：9
    JLNativeAdCreativeType_KLN_HorVideo = (5 << 24) | 1002,
    
    JLNativeAdCreativeType_BD_NORMAL = (6 << 24) | 0, // 一般图文或图片广告
    JLNativeAdCreativeType_BD_VIDEO = (6 << 24) | 1, // 视频广告，需开发者增加播放器支持
    JLNativeAdCreativeType_BD_HTML = (6 << 24) | 2, // html模版广告
    JLNativeAdCreativeType_BD_GIF = (6 << 24) | 3, //GIF广告
    
    JLNativeAdCreativeType_GRO_SmallImage = (7 << 24) | 2,
    JLNativeAdCreativeType_GRO_LargeImage = (7 << 24) | 3,
    JLNativeAdCreativeType_GRO_GroupImage = (7 << 24) | 4,
    JLNativeAdCreativeType_GRO_VideoImage = (7 << 24) | 5, // video ad || rewarded video ad horizontal screen
    JLNativeAdCreativeType_GRO_VideoPortrait = (7 << 24) | 15, // rewarded video ad vertical screen
    JLNativeAdCreativeType_GRO_ImagePortrait = (7 << 24) | 16,
    JLNativeAdCreativeType_GRO_SquareImage = (7 << 24) | 33, //SquareImage Currently it exists only in the oversea now. V3200 add
    JLNativeAdCreativeType_GRO_SquareVideo = (7 << 24) | 50, //SquareVideo Currently it exists only in the oversea now. V3200 add
    JLNativeAdCreativeType_GRO_UnionSplashVideo = (7 << 24) | 154, // Video splash, V3800 add
    JLNativeAdCreativeType_GRO_LiveStream = (7 << 24) | 166, // Live Stream Ad. v5200 add
    JLNativeAdCreativeType_GRO_UnionVerticalImage = (7 << 24) | 173, // vertical picture
    JLNativeAdCreativeType_GRO_UnionAtlas = (7 << 24) | 180, // atlas
    JLNativeAdCreativeType_GRO_MediationUnknown = (7 << 24) | 1000, //聚合其他广告sdk未知
    
    JLNativeAdCreativeType_GRO_Unknown = (7 << 24) | 0,
    JLNativeAdCreativeType_GRO_LandscapeVideo = JLNativeAdCreativeType_GRO_VideoImage,
    JLNativeAdCreativeType_GRO_PortraitVideo = JLNativeAdCreativeType_GRO_VideoPortrait,
    JLNativeAdCreativeType_GRO_PortraitImage = JLNativeAdCreativeType_GRO_ImagePortrait,
};

typedef NS_ENUM(NSInteger, JLNativeAdInteractionType) {
    JLNativeAdInteractionTypeUnkown = 0,
    JLNativeAdInteractionTypeBrowser = 1,
    JLNativeAdInteractionTypeDownload = 2,
};

@class JLInnerNativeAdDataObject;

@interface JLNativeAdDataObject : NSObject <JLAdProtocol>
{
    @package
     JLInnerNativeAdDataObject * _innerNativeAdDataObject;
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
@property (nonatomic, readonly) JLNativeAdCreativeType creativeType;
@property (nonatomic, readonly) JLNativeAdInteractionType interactionType;

@property (nonatomic, strong) JLVideoConfig *videoConfig;
@property (nonatomic, strong) JLAdViewActionConfig *actionConfig;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;

- (NSInteger)eCPM;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

/// 判断当前返回的广告素材是：图片/视频
- (BOOL)isVideoMaterial;

@end

NS_ASSUME_NONNULL_END
