//
//  NSArray+SMSShorthandAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import <WindFoundation/NSArray+SMSAdditions.h>

#ifdef SMS_SHORTHAND

/**
 *	Shorthand array additions without the 'sms_' prefixes,
 *  only enabled if SMS_SHORTHAND is defined
 */
@interface NSArray (SMSShorthandAdditions)

- (NSArray *)makeConstraints:(void(^)(SMSConstraintMaker *make))block;
- (NSArray *)updateConstraints:(void(^)(SMSConstraintMaker *make))block;
- (NSArray *)remakeConstraints:(void(^)(SMSConstraintMaker *make))block;

@end

@implementation NSArray (SMSShorthandAdditions)

- (NSArray *)makeConstraints:(void(^)(SMSConstraintMaker *))block {
    return [self sms_makeConstraints:block];
}

- (NSArray *)updateConstraints:(void(^)(SMSConstraintMaker *))block {
    return [self sms_updateConstraints:block];
}

- (NSArray *)remakeConstraints:(void(^)(SMSConstraintMaker *))block {
    return [self sms_remakeConstraints:block];
}

@end

#endif
