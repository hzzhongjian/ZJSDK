//
//  ZJFLMediaInfo.h
//  ZJ_FLAdSDK
//
//  Created by YJoo on 2026/04/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJFLMediaInfo : NSObject

/// 广告标题
@property (nonatomic, copy) NSString *title;

/// 广告描述
@property (nonatomic, copy) NSString *desc;

/// 素材URL（多个用逗号分隔；无值时为 @""）
@property (nonatomic, copy) NSString *material_urls;

/// 素材ID
@property (nonatomic, copy) NSString *material_id;

/// 落地页地址
@property (nonatomic, copy) NSString *landing_page;

/// 唤醒地址
@property (nonatomic, copy) NSString *deeplink_url;

/// 下载地址
@property (nonatomic, copy) NSString *download_url;

+ (instancetype)mediaInfoWithAdObject:(nullable id)adObject;

@end

NS_ASSUME_NONNULL_END

