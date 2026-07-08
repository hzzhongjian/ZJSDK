//
//  SMSUtilities.h
//  Masonry
//
//  Created by Jonas Budelmann on 19/08/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import <Foundation/Foundation.h>



#if TARGET_OS_IPHONE || TARGET_OS_TV

    #import <UIKit/UIKit.h>
    #define SMS_VIEW UIView
    #define SMS_VIEW_CONTROLLER UIViewController
    #define SMSEdgeInsets UIEdgeInsets

    typedef UILayoutPriority SMSLayoutPriority;
    static const SMSLayoutPriority SMSLayoutPriorityRequired = UILayoutPriorityRequired;
    static const SMSLayoutPriority SMSLayoutPriorityDefaultHigh = UILayoutPriorityDefaultHigh;
    static const SMSLayoutPriority SMSLayoutPriorityDefaultMedium = 500;
    static const SMSLayoutPriority SMSLayoutPriorityDefaultLow = UILayoutPriorityDefaultLow;
    static const SMSLayoutPriority SMSLayoutPriorityFittingSizeLevel = UILayoutPriorityFittingSizeLevel;

#elif TARGET_OS_MAC

    #import <AppKit/AppKit.h>
    #define SMS_VIEW NSView
    #define SMSEdgeInsets NSEdgeInsets

    typedef NSLayoutPriority SMSLayoutPriority;
    static const SMSLayoutPriority SMSLayoutPriorityRequired = NSLayoutPriorityRequired;
    static const SMSLayoutPriority SMSLayoutPriorityDefaultHigh = NSLayoutPriorityDefaultHigh;
    static const SMSLayoutPriority SMSLayoutPriorityDragThatCanResizeWindow = NSLayoutPriorityDragThatCanResizeWindow;
    static const SMSLayoutPriority SMSLayoutPriorityDefaultMedium = 501;
    static const SMSLayoutPriority SMSLayoutPriorityWindowSizeStayPut = NSLayoutPriorityWindowSizeStayPut;
    static const SMSLayoutPriority SMSLayoutPriorityDragThatCannotResizeWindow = NSLayoutPriorityDragThatCannotResizeWindow;
    static const SMSLayoutPriority SMSLayoutPriorityDefaultLow = NSLayoutPriorityDefaultLow;
    static const SMSLayoutPriority SMSLayoutPriorityFittingSizeCompression = NSLayoutPriorityFittingSizeCompression;

#endif

/**
 *	Allows you to attach keys to objects matching the variable names passed.
 *
 *  view1.sms_key = @"view1", view2.sms_key = @"view2";
 *
 *  is equivalent to:
 *
 *  SMSAttachKeys(view1, view2);
 */
#define SMSAttachKeys(...)                                                        \
    {                                                                             \
        NSDictionary *keyPairs = NSDictionaryOfVariableBindings(__VA_ARGS__);     \
        for (id key in keyPairs.allKeys) {                                        \
            id obj = keyPairs[key];                                               \
            NSAssert([obj respondsToSelector:@selector(setSms_key:)],             \
                     @"Cannot attach sms_key to %@", obj);                        \
            [obj setSms_key:key];                                                 \
        }                                                                         \
    }

/**
 *  Used to create object hashes
 *  Based on http://www.mikeash.com/pyblog/friday-qa-2010-06-18-implementing-equality-and-hashing.html
 */
#define SMS_NSUINT_BIT (CHAR_BIT * sizeof(NSUInteger))
#define SMS_NSUINTROTATE(val, howmuch) ((((NSUInteger)val) << howmuch) | (((NSUInteger)val) >> (SMS_NSUINT_BIT - howmuch)))

/**
 *  Given a scalar or struct value, wraps it in NSValue
 *  Based on EXPObjectify: https://github.com/specta/expecta
 */
static inline id _SMSBoxValue(const char *type, ...) {
    va_list v;
    va_start(v, type);
    id obj = nil;
    if (strcmp(type, @encode(id)) == 0) {
        id actual = va_arg(v, id);
        obj = actual;
    } else if (strcmp(type, @encode(CGPoint)) == 0) {
        CGPoint actual = (CGPoint)va_arg(v, CGPoint);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(CGSize)) == 0) {
        CGSize actual = (CGSize)va_arg(v, CGSize);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(SMSEdgeInsets)) == 0) {
        SMSEdgeInsets actual = (SMSEdgeInsets)va_arg(v, SMSEdgeInsets);
        obj = [NSValue value:&actual withObjCType:type];
    } else if (strcmp(type, @encode(double)) == 0) {
        double actual = (double)va_arg(v, double);
        obj = [NSNumber numberWithDouble:actual];
    } else if (strcmp(type, @encode(float)) == 0) {
        float actual = (float)va_arg(v, double);
        obj = [NSNumber numberWithFloat:actual];
    } else if (strcmp(type, @encode(int)) == 0) {
        int actual = (int)va_arg(v, int);
        obj = [NSNumber numberWithInt:actual];
    } else if (strcmp(type, @encode(long)) == 0) {
        long actual = (long)va_arg(v, long);
        obj = [NSNumber numberWithLong:actual];
    } else if (strcmp(type, @encode(long long)) == 0) {
        long long actual = (long long)va_arg(v, long long);
        obj = [NSNumber numberWithLongLong:actual];
    } else if (strcmp(type, @encode(short)) == 0) {
        short actual = (short)va_arg(v, int);
        obj = [NSNumber numberWithShort:actual];
    } else if (strcmp(type, @encode(char)) == 0) {
        char actual = (char)va_arg(v, int);
        obj = [NSNumber numberWithChar:actual];
    } else if (strcmp(type, @encode(bool)) == 0) {
        bool actual = (bool)va_arg(v, int);
        obj = [NSNumber numberWithBool:actual];
    } else if (strcmp(type, @encode(unsigned char)) == 0) {
        unsigned char actual = (unsigned char)va_arg(v, unsigned int);
        obj = [NSNumber numberWithUnsignedChar:actual];
    } else if (strcmp(type, @encode(unsigned int)) == 0) {
        unsigned int actual = (unsigned int)va_arg(v, unsigned int);
        obj = [NSNumber numberWithUnsignedInt:actual];
    } else if (strcmp(type, @encode(unsigned long)) == 0) {
        unsigned long actual = (unsigned long)va_arg(v, unsigned long);
        obj = [NSNumber numberWithUnsignedLong:actual];
    } else if (strcmp(type, @encode(unsigned long long)) == 0) {
        unsigned long long actual = (unsigned long long)va_arg(v, unsigned long long);
        obj = [NSNumber numberWithUnsignedLongLong:actual];
    } else if (strcmp(type, @encode(unsigned short)) == 0) {
        unsigned short actual = (unsigned short)va_arg(v, unsigned int);
        obj = [NSNumber numberWithUnsignedShort:actual];
    }
    va_end(v);
    return obj;
}

#define SMSBoxValue(value) _SMSBoxValue(@encode(__typeof__((value))), (value))
