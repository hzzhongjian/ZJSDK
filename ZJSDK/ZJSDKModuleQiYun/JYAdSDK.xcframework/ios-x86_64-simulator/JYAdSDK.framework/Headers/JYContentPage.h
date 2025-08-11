//
//  JYContentPage.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/6/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JYContentInfo.h"
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYContentPage;

@protocol JYContentPageDelegate <NSObject>
@optional
- (void)jy_contentPageDidLoad:(JYContentPage *)entryElement;
- (void)jy_contentPageDidFailToLoad:(JYContentPage *)entryElement error:(NSError *)error;
@end

@protocol JYContentPageContentDelegate <NSObject>
@optional
- (void)jy_contentPageContentDidFullDisplay:(JYContentPage *)entryElement contentInfo:(JYContentInfo *) contentInfo;
- (void)jy_contentPageContentDidEndDisplay:(JYContentPage *)entryElement contentInfo:(JYContentInfo *) contentInfo;
- (void)jy_contentPageContentDidPause:(JYContentPage *)entryElement contentInfo:(JYContentInfo *) contentInfo;
- (void)jy_contentPageContentDidResume:(JYContentPage *)entryElement contentInfo:(JYContentInfo *) contentInfo;
@end

@protocol JYContentPageVideoDelegate <NSObject>
@optional
- (void)jy_contentPageVideoDidStartPlay:(JYContentPage *)entryElement contentInfo:(JYContentInfo *) contentInfo;
- (void)jy_contentPageVideoDidPause:(JYContentPage *)entryElement contentInfo:(JYContentInfo *) contentInfo;
- (void)jy_contentPageVideoDidResume:(JYContentPage *)entryElement contentInfo:(JYContentInfo *) contentInfo;
- (void)jy_contentPageVideoDidEndPlay:(JYContentPage *)entryElement contentInfo:(JYContentInfo *) contentInfo;
- (void)jy_contentPageVideoDidFailToPlay:(JYContentPage *)entryElement contentInfo:(JYContentInfo *) contentInfo error:(NSError *)error;
@end

@interface JYContentPage : NSObject
@property (nonatomic, weak, nullable) id<JYContentPageDelegate> delegate;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;
@property (nonatomic, weak, nullable) id<JYContentPageContentDelegate> contentDelegate;
@property (nonatomic, weak, nullable) id<JYContentPageVideoDelegate> videoDelegate;
@property (nonatomic, strong, nullable) UIViewController * viewController;
- (instancetype)initWithSlotId:(NSString *) slotId;
- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
@end

NS_ASSUME_NONNULL_END
