//
//  UIView+SMSShorthandAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import <WindFoundation/View+SMSAdditions.h>

#ifdef SMS_SHORTHAND

/**
 *	Shorthand view additions without the 'sms_' prefixes,
 *  only enabled if SMS_SHORTHAND is defined
 */
@interface SMS_VIEW (SMSShorthandAdditions)

@property (nonatomic, strong, readonly) SMSViewAttribute *left;
@property (nonatomic, strong, readonly) SMSViewAttribute *top;
@property (nonatomic, strong, readonly) SMSViewAttribute *right;
@property (nonatomic, strong, readonly) SMSViewAttribute *bottom;
@property (nonatomic, strong, readonly) SMSViewAttribute *leading;
@property (nonatomic, strong, readonly) SMSViewAttribute *trailing;
@property (nonatomic, strong, readonly) SMSViewAttribute *width;
@property (nonatomic, strong, readonly) SMSViewAttribute *height;
@property (nonatomic, strong, readonly) SMSViewAttribute *centerX;
@property (nonatomic, strong, readonly) SMSViewAttribute *centerY;
@property (nonatomic, strong, readonly) SMSViewAttribute *baseline;
@property (nonatomic, strong, readonly) SMSViewAttribute *(^attribute)(NSLayoutAttribute attr);

@property (nonatomic, strong, readonly) SMSViewAttribute *firstBaseline;
@property (nonatomic, strong, readonly) SMSViewAttribute *lastBaseline;

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) SMSViewAttribute *leftMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *rightMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *topMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *bottomMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *leadingMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *trailingMargin;
@property (nonatomic, strong, readonly) SMSViewAttribute *centerXWithinMargins;
@property (nonatomic, strong, readonly) SMSViewAttribute *centerYWithinMargins;

#endif

#if TARGET_OS_IPHONE || TARGET_OS_TV

@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideLeading NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideTrailing NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideLeft NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideRight NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideTop NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideBottom NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideWidth NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideHeight NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideCenterX NS_AVAILABLE_IOS(11.0);
@property (nonatomic, strong, readonly) SMSViewAttribute *safeAreaLayoutGuideCenterY NS_AVAILABLE_IOS(11.0);

#endif

- (NSArray *)makeConstraints:(void(^)(SMSConstraintMaker *make))block;
- (NSArray *)updateConstraints:(void(^)(SMSConstraintMaker *make))block;
- (NSArray *)remakeConstraints:(void(^)(SMSConstraintMaker *make))block;

@end

#define SMS_ATTR_FORWARD(attr)  \
- (SMSViewAttribute *)attr {    \
    return [self sms_##attr];   \
}

#define SMS_ATTR_FORWARD_AVAILABLE(attr, available)  \
- (SMSViewAttribute *)attr available {    \
    return [self sms_##attr];   \
}

@implementation SMS_VIEW (SMSShorthandAdditions)

SMS_ATTR_FORWARD(top);
SMS_ATTR_FORWARD(left);
SMS_ATTR_FORWARD(bottom);
SMS_ATTR_FORWARD(right);
SMS_ATTR_FORWARD(leading);
SMS_ATTR_FORWARD(trailing);
SMS_ATTR_FORWARD(width);
SMS_ATTR_FORWARD(height);
SMS_ATTR_FORWARD(centerX);
SMS_ATTR_FORWARD(centerY);
SMS_ATTR_FORWARD(baseline);

SMS_ATTR_FORWARD(firstBaseline);
SMS_ATTR_FORWARD(lastBaseline);

#if TARGET_OS_IPHONE || TARGET_OS_TV

SMS_ATTR_FORWARD(leftMargin);
SMS_ATTR_FORWARD(rightMargin);
SMS_ATTR_FORWARD(topMargin);
SMS_ATTR_FORWARD(bottomMargin);
SMS_ATTR_FORWARD(leadingMargin);
SMS_ATTR_FORWARD(trailingMargin);
SMS_ATTR_FORWARD(centerXWithinMargins);
SMS_ATTR_FORWARD(centerYWithinMargins);

SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideLeading, NS_AVAILABLE_IOS(11.0));
SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideTrailing, NS_AVAILABLE_IOS(11.0));
SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideLeft, NS_AVAILABLE_IOS(11.0));
SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideRight, NS_AVAILABLE_IOS(11.0));
SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideTop, NS_AVAILABLE_IOS(11.0));
SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideBottom, NS_AVAILABLE_IOS(11.0));
SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideWidth, NS_AVAILABLE_IOS(11.0));
SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideHeight, NS_AVAILABLE_IOS(11.0));
SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideCenterX, NS_AVAILABLE_IOS(11.0));
SMS_ATTR_FORWARD_AVAILABLE(safeAreaLayoutGuideCenterY, NS_AVAILABLE_IOS(11.0));

#endif

- (SMSViewAttribute *(^)(NSLayoutAttribute))attribute {
    return [self sms_attribute];
}

- (NSArray *)makeConstraints:(void(NS_NOESCAPE ^)(SMSConstraintMaker *))block {
    return [self sms_makeConstraints:block];
}

- (NSArray *)updateConstraints:(void(NS_NOESCAPE ^)(SMSConstraintMaker *))block {
    return [self sms_updateConstraints:block];
}

- (NSArray *)remakeConstraints:(void(NS_NOESCAPE ^)(SMSConstraintMaker *))block {
    return [self sms_remakeConstraints:block];
}

@end

#endif
