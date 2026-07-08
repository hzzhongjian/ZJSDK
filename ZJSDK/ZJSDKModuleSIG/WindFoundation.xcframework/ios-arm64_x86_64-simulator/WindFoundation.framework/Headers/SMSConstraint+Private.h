//
//  SMSConstraint+Private.h
//  Masonry
//
//  Created by Nick Tymchenko on 29/04/14.
//  Copyright (c) 2014 cloudling. All rights reserved.
//

#import <WindFoundation/SMSConstraint.h>

@protocol SMSConstraintDelegate;


@interface SMSConstraint ()

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *	Usually SMSConstraintMaker but could be a parent SMSConstraint
 */
@property (nonatomic, weak) id<SMSConstraintDelegate> delegate;

/**
 *  Based on a provided value type, is equal to calling:
 *  NSNumber - setOffset:
 *  NSValue with CGPoint - setPointOffset:
 *  NSValue with CGSize - setSizeOffset:
 *  NSValue with SMSEdgeInsets - setInsets:
 */
- (void)setLayoutConstantWithValue:(NSValue *)value;

@end


@interface SMSConstraint (Abstract)

/**
 *	Sets the constraint relation to given NSLayoutRelation
 *  returns a block which accepts one of the following:
 *    SMSViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (SMSConstraint * (^)(id, NSLayoutRelation))equalToWithRelation;

/**
 *	Override to set a custom chaining behaviour
 */
- (SMSConstraint *)addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end


@protocol SMSConstraintDelegate <NSObject>

/**
 *	Notifies the delegate when the constraint needs to be replaced with another constraint. For example
 *  A SMSViewConstraint may turn into a SMSCompositeConstraint when an array is passed to one of the equality blocks
 */
- (void)constraint:(SMSConstraint *)constraint shouldBeReplacedWithConstraint:(SMSConstraint *)replacementConstraint;

- (SMSConstraint *)constraint:(SMSConstraint *)constraint addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end
