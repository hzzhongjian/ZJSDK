//
//  UIView+SMSAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import <WindFoundation/SMSUtilities.h>
#import <WindFoundation/SMSConstraintMaker.h>
#import <WindFoundation/SMSViewAttribute.h>

/**
 *	Provides constraint maker block
 *  and convience methods for creating SMSViewAttribute which are view + NSLayoutAttribute pairs
 */
@interface SMS_VIEW (SMSAdditions)

/**
 *	following properties return a new SMSViewAttribute with current view and appropriate NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_left;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_top;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_right;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_bottom;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_leading;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_trailing;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_width;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_height;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_centerX;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_centerY;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_baseline;
@property (nonatomic, strong, readonly) SMSViewAttribute *(^sms_attribute)(NSLayoutAttribute attr);

@property (nonatomic, strong, readonly) SMSViewAttribute *sms_firstBaseline;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_lastBaseline;

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) SMSViewAttribute *sms_leftMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_rightMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_topMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_bottomMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_leadingMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_trailingMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_centerXWithinMargins;
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_centerYWithinMargins;

@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuide NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideLeading NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideTrailing NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideLeft NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideRight NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideTop NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideBottom NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideWidth NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideHeight NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideCenterX NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *sms_safeAreaLayoutGuideCenterY NS_AVAILABLE_IOS(11.0);

#endif

/**
 *	a key to associate with this view
 */
@property (nonatomic, strong) id sms_key;

/**
 *	Finds the closest common superview between this view and another view
 *
 *	@param	view	other view
 *
 *	@return	returns nil if common superview could not be found
 */
- (instancetype)sms_closestCommonSuperview:(SMS_VIEW *)view;

/**
 *  Creates a SMSConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created SMSConstraints
 */
- (NSArray *)sms_makeConstraints:(void(NS_NOESCAPE ^)(SMSConstraintMaker *make))block;

/**
 *  Creates a SMSConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated SMSConstraints
 */
- (NSArray *)sms_updateConstraints:(void(NS_NOESCAPE ^)(SMSConstraintMaker *make))block;

/**
 *  Creates a SMSConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated SMSConstraints
 */
- (NSArray *)sms_remakeConstraints:(void(NS_NOESCAPE ^)(SMSConstraintMaker *make))block;

@end
