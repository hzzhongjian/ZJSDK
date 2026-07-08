//
//  SMSCompositeConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 21/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import <WindFoundation/SMSConstraint.h>
#import <WindFoundation/SMSUtilities.h>

/**
 *	A group of SMSConstraint objects
 */
@interface SMSCompositeConstraint : SMSConstraint

/**
 *	Creates a composite with a predefined array of children
 *
 *	@param	children	child SMSConstraints
 *
 *	@return	a composite constraint
 */
- (id)initWithChildren:(NSArray *)children;

@end
