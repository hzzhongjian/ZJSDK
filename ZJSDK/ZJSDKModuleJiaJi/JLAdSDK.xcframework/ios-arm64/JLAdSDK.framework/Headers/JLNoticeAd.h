//
//  JLNoticeAd.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/5/18.
//

#import <Foundation/Foundation.h>
#import <JLAdSDK/JLAdSDKConfig.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class JLNoticeAd;
@protocol JLNoticeAdDelegate <NSObject>

- (void)jl_noticeAdDidLoad:(JLNoticeAd *)noticeAd;
- (void)jl_noticeAdDidFailToLoad:(JLNoticeAd *)noticeAd error:(NSError *)error;
- (void)jl_noticeAdDidExpose:(JLNoticeAd *)noticeAd;
- (void)jl_noticeAdDidClick:(JLNoticeAd *)noticeAd;
- (void)jl_noticeAdDidClose:(JLNoticeAd *)noticeAd;
@end

@interface JLNoticeAd : NSObject
@property (nonatomic, weak, nullable) id<JLNoticeAdDelegate> delegate;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;
-(instancetype) initWithSlotId:(NSString *) slotId;
- (void)loadAd;
- (void)showAdInWindow:(UIWindow *)window;
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
