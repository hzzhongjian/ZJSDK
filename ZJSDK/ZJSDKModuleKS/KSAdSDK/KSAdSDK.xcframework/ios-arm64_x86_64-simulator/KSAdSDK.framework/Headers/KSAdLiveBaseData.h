//
//  KSAdLiveBaseData.h
//  KSUModel
//
//  Created by 崔婉莹 on 2024/4/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KSAdLiveBaseData : NSObject
/// 广告主名称
@property (nonatomic, copy) NSString *userName;
/// 广告主头像
@property (nonatomic, copy) NSString *portraitUrl;
/// 在线观看人数
@property (nonatomic, assign) long liveDisplayWatchingCount;

@end

NS_ASSUME_NONNULL_END
