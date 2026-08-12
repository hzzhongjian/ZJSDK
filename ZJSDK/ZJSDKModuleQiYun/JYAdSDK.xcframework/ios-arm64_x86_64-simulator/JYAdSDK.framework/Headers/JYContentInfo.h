//
//  JYContentInfo.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/6/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, JYContentType) {
    JYContentTypeUnknown,         //未知，正常不会出现
    JYContentTypeNormal,          //普通信息流
    JYContentTypeAd,              //SDK内部广告
};

@interface JYContentInfo : NSObject
//内容标识
@property (nonatomic, copy, readonly) NSString *contentId;
//内容类型
@property (nonatomic, readonly) JYContentType contentType;
//视频时长. 毫秒
@property (nonatomic, readonly) NSTimeInterval videoDuration;
@end

NS_ASSUME_NONNULL_END
