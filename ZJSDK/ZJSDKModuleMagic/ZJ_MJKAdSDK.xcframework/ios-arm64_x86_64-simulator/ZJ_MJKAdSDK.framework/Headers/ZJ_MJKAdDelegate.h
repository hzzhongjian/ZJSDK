//
//  ZJ_MJKAdDelegate.h
//  Pods
//
//  Created by Harry Jiang on 2025/10/10.
//

#ifndef ZJ_MJKAdDelegate_h
#define ZJ_MJKAdDelegate_h
#import <ZJ_MJKAdSDK/ZJ_MJKAdError.h>

@protocol ZJ_MJKAdLoadDelegate <NSObject>
@optional
//广告缓存加载，可设置1-4条，如果设置数和缓存总数之和超过4，那么新缓存的数量为4减去已缓存的数量
-(void)onMgcAdCacheLoaded:(NSInteger)succCount;
-(void)onMgcAdCacheError:(ZJ_MJKAdError *)err;
@end

@protocol ZJ_MJKAdInitDelegate <NSObject>
@optional
-(void)onZJ_MJKAdInitSuccess;
-(void)onZJ_MJKAdInitError:(NSString *)msg;
@end

#endif /* ZJ_MJKAdDelegate_h */
