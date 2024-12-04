//
//  JLNativeExpressAd.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/5/14.
//

#import <Foundation/Foundation.h>
#import "JLNativeExpressAdRelatedView.h"
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLNativeExpressAd;
@protocol JLNativeExpressAdDelegate <NSObject>

- (void)jl_nativeExpressAdDidLoad:(NSArray<JLNativeExpressAdRelatedView *> * _Nullable)nativeExpressAdRelatedViews error:(NSError * _Nullable)error;
@end


@interface JLNativeExpressAd : NSObject <JLAdProtocol>
@property (nonatomic, weak, nullable) id<JLNativeExpressAdDelegate> delegate;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType  __attribute__(( deprecated ( "使用JLNativeExpressAdRelatedView中unionType代替" )));

-(instancetype) initWithSlotId:(NSString *) slotId adSize:(CGSize) adSize;
- (void)loadAdWithCount:(NSInteger) count;

- (NSInteger)eCPM __attribute__(( deprecated ( "使用JLNativeExpressAdRelatedView中-eCPM代替" )));
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo __attribute__(( deprecated ( "使用JLNativeExpressAdRelatedView中-sendWinNotificationWithInfo:代替" )));
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo __attribute__(( deprecated ( "使用JLNativeExpressAdRelatedView中-sendLossNotificationWithInfo:代替" )));
@end

NS_ASSUME_NONNULL_END
