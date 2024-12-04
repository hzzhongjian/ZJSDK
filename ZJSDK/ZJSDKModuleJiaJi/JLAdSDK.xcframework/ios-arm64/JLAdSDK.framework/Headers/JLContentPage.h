//
//  JLContentPage.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/6/15.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JLContentInfo.h"
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLContentPage;

@protocol JLContentPageDelegate <NSObject>
@optional
- (void)jl_contentPageDidLoad:(JLContentPage *)entryElement;
- (void)jl_contentPageDidFailToLoad:(JLContentPage *)entryElement error:(NSError *)error;
@end

@protocol JLContentPageContentDelegate <NSObject>
@optional
- (void)jl_contentPageContentDidFullDisplay:(JLContentPage *)entryElement contentInfo:(JLContentInfo *) contentInfo;
- (void)jl_contentPageContentDidEndDisplay:(JLContentPage *)entryElement contentInfo:(JLContentInfo *) contentInfo;
- (void)jl_contentPageContentDidPause:(JLContentPage *)entryElement contentInfo:(JLContentInfo *) contentInfo;
- (void)jl_contentPageContentDidResume:(JLContentPage *)entryElement contentInfo:(JLContentInfo *) contentInfo;
@end

@protocol JLContentPageVideoDelegate <NSObject>
@optional
- (void)jl_contentPageVideoDidStartPlay:(JLContentPage *)entryElement contentInfo:(JLContentInfo *) contentInfo;
- (void)jl_contentPageVideoDidPause:(JLContentPage *)entryElement contentInfo:(JLContentInfo *) contentInfo;
- (void)jl_contentPageVideoDidResume:(JLContentPage *)entryElement contentInfo:(JLContentInfo *) contentInfo;
- (void)jl_contentPageVideoDidEndPlay:(JLContentPage *)entryElement contentInfo:(JLContentInfo *) contentInfo;
- (void)jl_contentPageVideoDidFailToPlay:(JLContentPage *)entryElement contentInfo:(JLContentInfo *) contentInfo error:(NSError *)error;
@end

@interface JLContentPage : NSObject
@property (nonatomic, weak, nullable) id<JLContentPageDelegate> delegate;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;
@property (nonatomic, weak, nullable) id<JLContentPageContentDelegate> contentDelegate;
@property (nonatomic, weak, nullable) id<JLContentPageVideoDelegate> videoDelegate;
@property (nonatomic, strong, nullable) UIViewController * viewController;
- (instancetype)initWithSlotId:(NSString *) slotId;
- (NSInteger)eCPM;
@end

NS_ASSUME_NONNULL_END
