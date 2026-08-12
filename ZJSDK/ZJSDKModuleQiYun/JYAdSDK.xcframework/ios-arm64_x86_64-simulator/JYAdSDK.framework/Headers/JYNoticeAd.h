//
//  JYNoticeAd.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/5/18.
//

#import <Foundation/Foundation.h>
#import <JYAdSDK/JYAdSDKConfig.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class JYNoticeAd;
@protocol JYNoticeAdDelegate <NSObject>

- (void)jy_noticeAdDidLoad:(JYNoticeAd *)noticeAd;
- (void)jy_noticeAdDidFailToLoad:(JYNoticeAd *)noticeAd error:(NSError *)error;
- (void)jy_noticeAdDidExpose:(JYNoticeAd *)noticeAd;
- (void)jy_noticeAdDidClick:(JYNoticeAd *)noticeAd;
- (void)jy_noticeAdDidClose:(JYNoticeAd *)noticeAd;
@end

@interface JYNoticeAd : NSObject
@property (nonatomic, weak, nullable) id<JYNoticeAdDelegate> delegate;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;
-(instancetype) initWithSlotId:(NSString *) slotId;
- (void)loadAd;
- (void)showAdInWindow:(UIWindow *)window;
- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
@end

NS_ASSUME_NONNULL_END
