//
//  UIViewController+SMSAdditions.h
//  Masonry
//
//  Created by Craig Siemens on 2015-06-23.
//
//

#import <WindFoundation/SMSUtilities.h>
#import <WindFoundation/SMSConstraintMaker.h>
#import <WindFoundation/SMSViewAttribute.h>

#ifdef SMS_VIEW_CONTROLLER

@interface SMS_VIEW_CONTROLLER (SMSAdditions)

/**
 *	following properties return a new SMSViewAttribute with appropriate UILayoutGuide and NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_topLayoutGuide NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_bottomLayoutGuide NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_topLayoutGuideTop NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_topLayoutGuideBottom NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_bottomLayoutGuideTop NS_DEPRECATED_IOS(8.0, 11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_bottomLayoutGuideBottom NS_DEPRECATED_IOS(8.0, 11.0);

@end

#endif
