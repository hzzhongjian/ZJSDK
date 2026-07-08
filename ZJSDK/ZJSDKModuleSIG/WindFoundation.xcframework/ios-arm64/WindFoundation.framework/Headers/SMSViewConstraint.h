//
//  SMSViewConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import <WindFoundation/SMSViewAttribute.h>
#import <WindFoundation/SMSConstraint.h>
#import <WindFoundation/SMSLayoutConstraint.h>
#import <WindFoundation/SMSUtilities.h>

/**
 *  A single constraint.
 *  Contains the attributes neccessary for creating a NSLayoutConstraint and adding it to the appropriate view
 */
@interface SMSViewConstraint : SMSConstraint <NSCopying>

/**
 *	First item/view and first attribute of the NSLayoutConstraint
 */
@property (nonatomic, strong, readonly) SMSViewAttribute *firstViewAttribute;

/**
 *	Second item/view and second attribute of the NSLayoutConstraint
 */
@property (nonatomic, strong, readonly) SMSViewAttribute *secondViewAttribute;

/**
 *	initialises the SMSViewConstraint with the first part of the equation
 *
 *	@param	firstViewAttribute	view.sms_left, view.sms_width etc.
 *
 *	@return	a new view constraint
 */
- (id)initWithFirstViewAttribute:(SMSViewAttribute *)firstViewAttribute;

/**
 *  Returns all SMSViewConstraints installed with this view as a first item.
 *
 *  @param  view  A view to retrieve constraints for.
 *
 *  @return An array of SMSViewConstraints.
 */
+ (NSArray *)installedConstraintsForView:(SMS_VIEW *)view;

@end
