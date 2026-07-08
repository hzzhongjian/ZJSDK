//
//  SMSLayoutConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 3/08/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import <WindFoundation/SMSUtilities.h>

/**
 *	When you are debugging or printing the constraints attached to a view this subclass
 *  makes it easier to identify which constraints have been created via Masonry
 */
@interface SMSLayoutConstraint : NSLayoutConstraint

/**
 *	a key to associate with this constraint
 */
@property (nonatomic, strong) id sms_key;

@end
