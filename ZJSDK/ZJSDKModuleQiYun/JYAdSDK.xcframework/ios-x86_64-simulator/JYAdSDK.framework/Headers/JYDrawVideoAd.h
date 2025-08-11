//
//  JYDrawVideoAd.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/6/16.
//

#import <Foundation/Foundation.h>
#import "JYDrawVideoAdRelatedView.h"
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYDrawVideoAd;
@protocol JYDrawVideoAdDelegate <NSObject>

- (void)jy_drawVideoAdDidLoad:(NSArray<JYDrawVideoAdRelatedView *> * _Nullable)drawVideoAdRelatedViews error:(NSError * _Nullable) error;

@end

@interface JYDrawVideoAd : NSObject <JYAdProtocol>

@property (nonatomic, weak, nullable) id<JYDrawVideoAdDelegate> delegate;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType __attribute__(( deprecated ( "使用JYDrawVideoAdRelatedView中unionType代替" )));
@property (nonatomic, assign) BOOL videoMuted;

- (instancetype) initWithSlotId:(NSString *)slotId adSize:(CGSize)adSize;
- (void)loadAdWithCount:(NSInteger)count;

- (NSInteger)eCPM __attribute__(( deprecated ( "使用JYDrawVideoAdRelatedView中-eCPM代替" )));
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo __attribute__(( deprecated ( "使用JYDrawVideoAdRelatedView中-sendWinNotificationWithInfo:代替" )));
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo __attribute__(( deprecated ( "使用JYDrawVideoAdRelatedView中-sendLossNotificationWithInfo:代替" )));

@end

NS_ASSUME_NONNULL_END
