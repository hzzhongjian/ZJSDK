//
//  JLContentInfo.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/6/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, JLContentType) {
    JLContentTypeUnknown,         //未知，正常不会出现
    JLContentTypeNormal,          //普通信息流
    JLContentTypeAd,              //SDK内部广告
};

@interface JLContentInfo : NSObject
//内容标识
@property (nonatomic, copy, readonly) NSString *contentId;
//内容类型
@property (nonatomic, readonly) JLContentType contentType;
//视频时长. 毫秒
@property (nonatomic, readonly) NSTimeInterval videoDuration;
@end

NS_ASSUME_NONNULL_END
