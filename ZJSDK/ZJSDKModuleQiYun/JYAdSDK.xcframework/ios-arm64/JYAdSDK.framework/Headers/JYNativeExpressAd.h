//
//  JYNativeExpressAd.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/5/14.
//

#import <Foundation/Foundation.h>
#import "JYNativeExpressAdRelatedView.h"
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYNativeExpressAd;
@protocol JYNativeExpressAdDelegate <NSObject>

- (void)jy_nativeExpressAdDidLoad:(NSArray<JYNativeExpressAdRelatedView *> * _Nullable)nativeExpressAdRelatedViews error:(NSError * _Nullable)error;
@end


@interface JYNativeExpressAd : NSObject <JYAdProtocol>
@property (nonatomic, weak, nullable) id<JYNativeExpressAdDelegate> delegate;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType  __attribute__(( deprecated ( "使用JYNativeExpressAdRelatedView中unionType代替" )));

-(instancetype) initWithSlotId:(NSString *) slotId adSize:(CGSize) adSize;
- (void)loadAdWithCount:(NSInteger) count;

- (NSInteger)eCPM __attribute__(( deprecated ( "使用JYNativeExpressAdRelatedView中-eCPM代替" )));
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo __attribute__(( deprecated ( "使用JYNativeExpressAdRelatedView中-sendWinNotificationWithInfo:代替" )));
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo __attribute__(( deprecated ( "使用JYNativeExpressAdRelatedView中-sendLossNotificationWithInfo:代替" )));
@end

NS_ASSUME_NONNULL_END
