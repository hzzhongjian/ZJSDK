//
//  ZJ_CJBaseAd.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 * 广告素材信息对象。
 * 负责承载单条广告返回的素材标识与素材地址，
 * 仅当全局配置 canGetMaterialInfo（m_ext.c_g_m_i=1）开启时由各广告对象的 getMaterialInfo 返回。
 */
@interface ZJ_CJMaterialInfo : NSObject

/// 素材ID，服务端未下发时为空字符串
@property (nonatomic, copy, nullable) NSString *materialID;

/// 视频素材地址，非视频广告时为 nil
@property (nonatomic, copy, nullable) NSString *videoUrl;

/// 图片素材地址集合，无图片素材时为空数组
@property (nonatomic, copy, nullable) NSArray<NSString *> *imgUrls;

/// 落地页地址，同 getLandpageUrl 取值来源，未下发时为 nil
@property (nonatomic, copy, nullable) NSString *landUrl;

@end

@interface ZJ_CJBaseAd : NSObject

/// 广告的拓展信息
@property (nonatomic, strong, readonly)NSMutableDictionary *extInfo;

- (BOOL)isReady;

/// 获取广告请求的 sdkToken，供聚合层发起广告请求
- (NSString *)getLoadAdToken;

/// 根据 respToken 解析广告响应并走 SDK 内部加载流程
- (void)loadAdWithToken:(NSString *)respToken;

@end

NS_ASSUME_NONNULL_END
