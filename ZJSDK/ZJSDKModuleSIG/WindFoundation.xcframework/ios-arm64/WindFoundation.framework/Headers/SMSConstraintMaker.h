//
//  SMSConstraintMaker.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import <WindFoundation/SMSConstraint.h>
#import <WindFoundation/SMSUtilities.h>

typedef NS_OPTIONS(NSInteger, SMSAttribute) {
    SMSAttributeLeft = 1 << NSLayoutAttributeLeft,
    SMSAttributeRight = 1 << NSLayoutAttributeRight,
    SMSAttributeTop = 1 << NSLayoutAttributeTop,
    SMSAttributeBottom = 1 << NSLayoutAttributeBottom,
    SMSAttributeLeading = 1 << NSLayoutAttributeLeading,
    SMSAttributeTrailing = 1 << NSLayoutAttributeTrailing,
    SMSAttributeWidth = 1 << NSLayoutAttributeWidth,
    SMSAttributeHeight = 1 << NSLayoutAttributeHeight,
    SMSAttributeCenterX = 1 << NSLayoutAttributeCenterX,
    SMSAttributeCenterY = 1 << NSLayoutAttributeCenterY,
    SMSAttributeBaseline = 1 << NSLayoutAttributeBaseline,

    SMSAttributeFirstBaseline = 1 << NSLayoutAttributeFirstBaseline,
    SMSAttributeLastBaseline = 1 << NSLayoutAttributeLastBaseline,
    
#if TARGET_OS_IPHONE || TARGET_OS_TV
    
    SMSAttributeLeftMargin = 1 << NSLayoutAttributeLeftMargin,
    SMSAttributeRightMargin = 1 << NSLayoutAttributeRightMargin,
    SMSAttributeTopMargin = 1 << NSLayoutAttributeTopMargin,
    SMSAttributeBottomMargin = 1 << NSLayoutAttributeBottomMargin,
    SMSAttributeLeadingMargin = 1 << NSLayoutAttributeLeadingMargin,
    SMSAttributeTrailingMargin = 1 << NSLayoutAttributeTrailingMargin,
    SMSAttributeCenterXWithinMargins = 1 << NSLayoutAttributeCenterXWithinMargins,
    SMSAttributeCenterYWithinMargins = 1 << NSLayoutAttributeCenterYWithinMargins,

#endif
    
};

/**
 *  Provides factory methods for creating SMSConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface SMSConstraintMaker : NSObject

/**
 *	The following properties return a new SMSViewConstraint
 *  with the first item set to the makers associated view and the appropriate SMSViewAttribute
 */
@property (nonatomic, strong, readonly) SMSConstraint *left;
@property (nonatomic, strong, readonly) SMSConstraint *top;
@property (nonatomic, strong, readonly) SMSConstraint *right;
@property (nonatomic, strong, readonly) SMSConstraint *bottom;
@property (nonatomic, strong, readonly) SMSConstraint *leading;
@property (nonatomic, strong, readonly) SMSConstraint *trailing;
@property (nonatomic, strong, readonly) SMSConstraint *width;
@property (nonatomic, strong, readonly) SMSConstraint *height;
@property (nonatomic, strong, readonly) SMSConstraint *centerX;
@property (nonatomic, strong, readonly) SMSConstraint *centerY;
@property (nonatomic, strong, readonly) SMSConstraint *baseline;

@property (nonatomic, strong, readonly) SMSConstraint *firstBaseline;
@property (nonatomic, strong, readonly) SMSConstraint *lastBaseline;

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) SMSConstraint *leftMargin;
@property (nonatomic, strong, readonly) SMSConstraint *rightMargin;
@property (nonatomic, strong, readonly) SMSConstraint *topMargin;
@property (nonatomic, strong, readonly) SMSConstraint *bottomMargin;
@property (nonatomic, strong, readonly) SMSConstraint *leadingMargin;
@property (nonatomic, strong, readonly) SMSConstraint *trailingMargin;
@property (nonatomic, strong, readonly) SMSConstraint *centerXWithinMargins;
@property (nonatomic, strong, readonly) SMSConstraint *centerYWithinMargins;

#endif

/**
 *  Returns a block which creates a new SMSCompositeConstraint with the first item set
 *  to the makers associated view and children corresponding to the set bits in the
 *  SMSAttribute parameter. Combine multiple attributes via binary-or.
 */
@property (nonatomic, strong, readonly) SMSConstraint *(^attributes)(SMSAttribute attrs);

/**
 *	Creates a SMSCompositeConstraint with type SMSCompositeConstraintTypeEdges
 *  which generates the appropriate SMSViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) SMSConstraint *edges;

/**
 *	Creates a SMSCompositeConstraint with type SMSCompositeConstraintTypeSize
 *  which generates the appropriate SMSViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) SMSConstraint *size;

/**
 *	Creates a SMSCompositeConstraint with type SMSCompositeConstraintTypeCenter
 *  which generates the appropriate SMSViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) SMSConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *  Whether or not to remove existing constraints prior to installing
 */
@property (nonatomic, assign) BOOL removeExisting;

/**
 *	initialises the maker with a default view
 *
 *	@param	view	any SMSConstraint are created with this view as the first item
 *
 *	@return	a new SMSConstraintMaker
 */
- (id)initWithView:(SMS_VIEW *)view;

/**
 *	Calls install method on any SMSConstraints which have been created by this maker
 *
 *	@return	an array of all the installed SMSConstraints
 */
- (NSArray *)install;

- (SMSConstraint * (^)(dispatch_block_t))group;

@end
