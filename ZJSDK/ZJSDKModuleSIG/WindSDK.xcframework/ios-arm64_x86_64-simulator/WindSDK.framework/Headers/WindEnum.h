//
//  WindEnum.h
//  WindSDK
//
//  Created by Codi on 2021/10/29.
//

typedef enum : uint32_t {
    SMNativeAdTypeVideo = 1,
    SMNativeAdTypeSingleImage = 2,
} SMNativeAdType;

typedef enum : NSUInteger {
    SigmobAdSlotTypeNone = 0,
    SigmobAdSlotTypeRewardVideo=1,
    SigmobAdSlotTypeSplash=2,
    SigmobAdSlotTypeVideo=4,
    SigmobAdSlotTypeNative=5,
    SigmobAdSlotTypeNewInterstitial=6,
} SigmobAdSlotType;

typedef NS_ENUM(NSUInteger, SMPlayMode) {
    SMPlayModeFromCache = 0,
    SMPlayModeFromNet = 1,
    SMPlayModeFromOnlyNet = 2,
};


typedef NS_ENUM(NSUInteger, SMRewardTemplateType) {
    SMRewardTemplateTypeStars = 1,
    SMRewardTemplateTypeDesc = 2
};

typedef NS_ENUM(NSUInteger, SMSplashTemplateType) {
    SMSplashTemplateTypeA = 1,
    SMSplashTemplateTypeB = 2,
    SMSplashTemplateTypeC = 4,//logo+ad+按钮
    SMSplashTemplateTypeD = 5,//摇一摇模版
};

typedef NS_ENUM(NSUInteger, SMCompanionAnimateType) {
    SMCompanionAnimateTypeSpring = 1,
    SMCompanionAnimateTypeMove = 2,
    SMCompanionAnimateTypeNone = 3,
};

typedef enum : NSUInteger {
    SigmobCreativeTypeVideoTar = 1,//由video+.tgz
    SigmobCreativeTypeImage = 3,//单张图片广告，一般由单张image_src构成
    SigmobCreativeTypeVideoHtmlSnippet = 4,//video+html_snippet组成
    SigmobCreativeTypeVideoFPSHTML = 6,//video定帧+htmlsrc
    SigmobCreativeTypeVideoOnlineURL = 7,//video+html_url
    SigmobCreativeTypeSplashVideo = 8,//开屏视频
    SigmobCreativeTypeMraid = 9, //mraid
    SigmobCreativeTypeMraid2 = 10,//mraid2
    SigmobCreativeType16 = 16, //mraid2
} SigmobCreativeType;

typedef enum : NSUInteger {
    SigmobTemplateId6001=6001,
    SigmobTemplateId6002=6002,
} SigmobTemplateId;

typedef enum : NSUInteger {
    SigmobImageTypeUnknow=0,
    SigmobImageTypeJPEG,
    SigmobImageTypePNG,
    SigmobImageTypeGIF,
} SigmobImageType;

typedef enum : NSUInteger {
    SigmobSplashOperationTypeSkip=0,
    SigmobSplashOperationTypeClick,
    SigmobSplashOperationTypeTimeout,
    SigmobSplashOperationTypeClose,
} SigmobSplashOperationType;

typedef enum : NSUInteger {
    SigmobInteractionTypeHttp = 1,
    SigmobInteractionTypeItunes = 2,
    SigmobInteractionTypeWXProgram = 7,
} SigmobInteractionType;


typedef enum : NSUInteger {
    SigmobMaterialMetaClickTypeButton=1,
    SigmobMaterialMetaClickTypeFullScreen=2,
} SigmobMaterialMetaClickType;

typedef enum : NSUInteger {
    WindAdLoadStatusNone = 0,
    WindAdLoadStatusLoading,
    WindAdLoadStatusFinished,
    WindAdLoadStatusError,
    WindAdLoadStatusPlaying,
    
} WindAdLoadStatus;

typedef enum : NSUInteger {
    WindAdReadyStatusNotReady = 0,
    WindAdReadyStatusReady,
} WindAdReadyStatus;


/** 按钮位置，左上：1，左下：2，右上：3，右下：4， */
typedef enum : NSUInteger {
    SigmobPositionLeftAndTop = 1,
    SigmobPositionLeftAndBottom = 2,
    SigmobPositionRightAndTop = 3,
    SigmobPositionRightAndBottom = 4,
} SigmobPosition;

typedef enum : NSUInteger {
    SigmobStoreControlNotificationStoreKitTypeDidReady,
    SigmobStoreControlNotificationStoreKitTypeDidFailToLoad,
    SigmobStoreControlNotificationStoreKitTypeDidPresent,
    SigmobStoreControlNotificationStoreKitTypeDidFinish,

    SigmobStoreControlNotificationSKOverlayTypeDidFailToLoad,
    SigmobStoreControlNotificationSKOverlayTypeDidFinishPresentation,
    SigmobStoreControlNotificationSKOverlayTypeDidFinishDismissal,
} SigmobStoreControlNotificationType;

typedef enum : NSUInteger {
    SigmobWebViewLoading,
    SigmobWebViewFinished,
    SigmobWebViewError,
} SigmobWebViewLoadStatus;


typedef enum : NSUInteger {
    WindSplashModeAuto = 1,
    WindSplashModeManual = 2,
} WindSplashMode;


typedef enum : NSUInteger {
    SigmobClickTypeEndcard,
    SigmobClickTypeCompanion,
    SigmobClickTypeVideo,
    SigmobClickTypeNativeAd,
    SigmobClickTypeOther,
} SigmobClickType;

typedef enum : NSUInteger {
    SMTemplateTypeUrl = 1,
    SMTemplateTypeHtml = 2,
    SMTemplateTypeTar = 3,
} SMTemplateType;

/**
* 竞价失败原因
  */
typedef NS_ENUM(NSInteger, WindAdBiddingLossReason) {
    WindAdBiddingLossReasonLowPrice          = 2,        // 竞争力不足，如Sigmob不是本次竞价的最高出价方，可上报此竞败原因
    WindAdBiddingLossReasonLoadTimeout       = 2000,        // 返回超时，如Sigmob在本次竞价中未返回广告，可上报此竞败原因
    WindAdBiddingLossReasonOther             = 2001     // 其他
};


typedef enum : NSUInteger {
    SigmobSensitivitySmaller = 1,
    SigmobSensitivityMiddle = 2,
    SigmobSensitivityLarger = 3,
    
} SigmobSensitivityType;
