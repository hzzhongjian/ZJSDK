//
//  SMSConstraint.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import <WindFoundation/SMSUtilities.h>

/**
 *	Enables Constraints to be created with chainable syntax
 *  Constraint can represent single NSLayoutConstraint (SMSViewConstraint) 
 *  or a group of NSLayoutConstraints (SMSComposisteConstraint)
 */
@interface SMSConstraint : NSObject

// Chaining Support

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects SMSConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (SMSConstraint * (^)(SMSEdgeInsets insets))insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects SMSConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (SMSConstraint * (^)(CGFloat inset))inset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects SMSConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (SMSConstraint * (^)(CGSize offset))sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects SMSConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (SMSConstraint * (^)(CGPoint offset))centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
- (SMSConstraint * (^)(CGFloat offset))offset;

/**
 *  Modifies the NSLayoutConstraint constant based on a value type
 */
- (SMSConstraint * (^)(NSValue *value))valueOffset;

/**
 *	Sets the NSLayoutConstraint multiplier property
 */
- (SMSConstraint * (^)(CGFloat multiplier))multipliedBy;

/**
 *	Sets the NSLayoutConstraint multiplier to 1.0/dividedBy
 */
- (SMSConstraint * (^)(CGFloat divider))dividedBy;

/**
 *	Sets the NSLayoutConstraint priority to a float or SMSLayoutPriority
 */
- (SMSConstraint * (^)(SMSLayoutPriority priority))priority;

/**
 *	Sets the NSLayoutConstraint priority to SMSLayoutPriorityLow
 */
- (SMSConstraint * (^)(void))priorityLow;

/**
 *	Sets the NSLayoutConstraint priority to SMSLayoutPriorityMedium
 */
- (SMSConstraint * (^)(void))priorityMedium;

/**
 *	Sets the NSLayoutConstraint priority to SMSLayoutPriorityHigh
 */
- (SMSConstraint * (^)(void))priorityHigh;

/**
 *	Sets the constraint relation to NSLayoutRelationEqual
 *  returns a block which accepts one of the following:
 *    SMSViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (SMSConstraint * (^)(id attr))equalTo;

/**
 *	Sets the constraint relation to NSLayoutRelationGreaterThanOrEqual
 *  returns a block which accepts one of the following:
 *    SMSViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (SMSConstraint * (^)(id attr))greaterThanOrEqualTo;

/**
 *	Sets the constraint relation to NSLayoutRelationLessThanOrEqual
 *  returns a block which accepts one of the following:
 *    SMSViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (SMSConstraint * (^)(id attr))lessThanOrEqualTo;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
- (SMSConstraint *)with;

/**
 *	Optional semantic property which has no effect but improves the readability of constraint
 */
- (SMSConstraint *)and;

/**
 *	Creates a new SMSCompositeConstraint with the called attribute and reciever
 */
- (SMSConstraint *)left;
- (SMSConstraint *)top;
- (SMSConstraint *)right;
- (SMSConstraint *)bottom;
- (SMSConstraint *)leading;
- (SMSConstraint *)trailing;
- (SMSConstraint *)width;
- (SMSConstraint *)height;
- (SMSConstraint *)centerX;
- (SMSConstraint *)centerY;
- (SMSConstraint *)baseline;

- (SMSConstraint *)firstBaseline;
- (SMSConstraint *)lastBaseline;

#if TARGET_OS_IPHONE || TARGET_OS_TV

- (SMSConstraint *)leftMargin;
- (SMSConstraint *)rightMargin;
- (SMSConstraint *)topMargin;
- (SMSConstraint *)bottomMargin;
- (SMSConstraint *)leadingMargin;
- (SMSConstraint *)trailingMargin;
- (SMSConstraint *)centerXWithinMargins;
- (SMSConstraint *)centerYWithinMargins;

#endif


/**
 *	Sets the constraint debug name
 */
- (SMSConstraint * (^)(id key))key;

// NSLayoutConstraint constant Setters
// for use outside of sms_updateConstraints/sms_makeConstraints blocks

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects SMSConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInsets:(SMSEdgeInsets)insets;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects SMSConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeTop, NSLayoutAttributeLeft, NSLayoutAttributeBottom, NSLayoutAttributeRight
 */
- (void)setInset:(CGFloat)inset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects SMSConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeWidth, NSLayoutAttributeHeight
 */
- (void)setSizeOffset:(CGSize)sizeOffset;

/**
 *	Modifies the NSLayoutConstraint constant,
 *  only affects SMSConstraints in which the first item's NSLayoutAttribute is one of the following
 *  NSLayoutAttributeCenterX, NSLayoutAttributeCenterY
 */
- (void)setCenterOffset:(CGPoint)centerOffset;

/**
 *	Modifies the NSLayoutConstraint constant
 */
- (void)setOffset:(CGFloat)offset;


// NSLayoutConstraint Installation support

#if TARGET_OS_MAC && !(TARGET_OS_IPHONE || TARGET_OS_TV)
/**
 *  Whether or not to go through the animator proxy when modifying the constraint
 */
@property (nonatomic, copy, readonly) SMSConstraint *animator;
#endif

/**
 *  Activates an NSLayoutConstraint if it's supported by an OS. 
 *  Invokes install otherwise.
 */
- (void)activate;

/**
 *  Deactivates previously installed/activated NSLayoutConstraint.
 */
- (void)deactivate;

/**
 *	Creates a NSLayoutConstraint and adds it to the appropriate view.
 */
- (void)install;

/**
 *	Removes previously installed NSLayoutConstraint
 */
- (void)uninstall;

@end


/**
 *  Convenience auto-boxing macros for SMSConstraint methods.
 *
 *  Defining SMS_SHORTHAND_GLOBALS will turn on auto-boxing for default syntax.
 *  A potential drawback of this is that the unprefixed macros will appear in global scope.
 */
#define sms_equalTo(...)                 equalTo(SMSBoxValue((__VA_ARGS__)))
#define sms_greaterThanOrEqualTo(...)    greaterThanOrEqualTo(SMSBoxValue((__VA_ARGS__)))
#define sms_lessThanOrEqualTo(...)       lessThanOrEqualTo(SMSBoxValue((__VA_ARGS__)))

#define sms_offset(...)                  valueOffset(SMSBoxValue((__VA_ARGS__)))


#ifdef SMS_SHORTHAND_GLOBALS

#define equalTo(...)                     sms_equalTo(__VA_ARGS__)
#define greaterThanOrEqualTo(...)        sms_greaterThanOrEqualTo(__VA_ARGS__)
#define lessThanOrEqualTo(...)           sms_lessThanOrEqualTo(__VA_ARGS__)

#define offset(...)                      sms_offset(__VA_ARGS__)

#endif


@interface SMSConstraint (AutoboxingSupport)

/**
 *  Aliases to corresponding relation methods (for shorthand macros)
 *  Also needed to aid autocompletion
 */
- (SMSConstraint * (^)(id attr))sms_equalTo;
- (SMSConstraint * (^)(id attr))sms_greaterThanOrEqualTo;
- (SMSConstraint * (^)(id attr))sms_lessThanOrEqualTo;

/**
 *  A dummy method to aid autocompletion
 */
- (SMSConstraint * (^)(id offset))sms_offset;

@end
