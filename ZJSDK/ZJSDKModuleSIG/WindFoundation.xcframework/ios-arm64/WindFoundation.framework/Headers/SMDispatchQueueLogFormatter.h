// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2016, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

#import <Foundation/Foundation.h>
#import <libkern/OSAtomic.h>


#import <WindFoundation/SMLog.h>

/**
 *  Log formatter mode
 */
typedef NS_ENUM(NSUInteger, SMDispatchQueueLogFormatterMode){
    /**
     *  This is the default option, means the formatter can be reused between multiple loggers and therefore is thread-safe.
     *  There is, of course, a performance cost for the thread-safety
     */
    SMDispatchQueueLogFormatterModeShareble = 0,
    /**
     *  If the formatter will only be used by a single logger, then the thread-safety can be removed
     *  @note: there is an assert checking if the formatter is added to multiple loggers and the mode is non-shareble
     */
    SMDispatchQueueLogFormatterModeNonShareble,
};


@interface SMDispatchQueueLogFormatter : NSObject <SMLogFormatter>

/**
 * Standard init method.
 * Configure using properties as desired.
 **/
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 *  Initializer with ability to set the queue mode
 *
 *  @param mode choose between SMDispatchQueueLogFormatterModeShareble and SMDispatchQueueLogFormatterModeNonShareble, depending if the formatter is shared between several loggers or not
 */
- (instancetype)initWithMode:(SMDispatchQueueLogFormatterMode)mode;

/**
 * The minQueueLength restricts the minimum size of the [detail box].
 * If the minQueueLength is set to 0, there is no restriction.
 *
 * For example, say a dispatch_queue has a label of "diskIO":
 *
 * If the minQueueLength is 0: [diskIO]
 * If the minQueueLength is 4: [diskIO]
 * If the minQueueLength is 5: [diskIO]
 * If the minQueueLength is 6: [diskIO]
 * If the minQueueLength is 7: [diskIO ]
 * If the minQueueLength is 8: [diskIO  ]
 *
 * The default minQueueLength is 0 (no minimum, so [detail box] won't be padded).
 *
 * If you want every [detail box] to have the exact same width,
 * set both minQueueLength and maxQueueLength to the same value.
 **/
@property (assign, atomic) NSUInteger minQueueLength;

/**
 * The maxQueueLength restricts the number of characters that will be inside the [detail box].
 * If the maxQueueLength is 0, there is no restriction.
 *
 * For example, say a dispatch_queue has a label of "diskIO":
 *
 * If the maxQueueLength is 0: [diskIO]
 * If the maxQueueLength is 4: [disk]
 * If the maxQueueLength is 5: [diskI]
 * If the maxQueueLength is 6: [diskIO]
 * If the maxQueueLength is 7: [diskIO]
 * If the maxQueueLength is 8: [diskIO]
 *
 * The default maxQueueLength is 0 (no maximum, so [detail box] won't be truncated).
 *
 * If you want every [detail box] to have the exact same width,
 * set both minQueueLength and maxQueueLength to the same value.
 **/
@property (assign, atomic) NSUInteger maxQueueLength;

/**
 * Sometimes queue labels have long names like "com.apple.main-queue",
 * but you'd prefer something shorter like simply "main".
 *
 * This method allows you to set such preferred replacements.
 * The above example is set by default.
 *
 * To remove/undo a previous replacement, invoke this method with nil for the 'shortLabel' parameter.
 **/
- (NSString *)replacementStringForQueueLabel:(NSString *)longLabel;

/**
 *  See the `replacementStringForQueueLabel:` description
 */
- (void)setReplacementString:(NSString *)shortLabel forQueueLabel:(NSString *)longLabel;

@end

/**
 *  Category on `SMDispatchQueueLogFormatter` to make method declarations easier to extend/modify
 **/
@interface SMDispatchQueueLogFormatter (OverridableMethods)

/**
 *  Date formatter default configuration
 */
- (void)configureDateFormatter:(NSDateFormatter *)dateFormatter;

/**
 *  Formatter method to transfrom from date to string
 */
- (NSString *)stringFromDate:(NSDate *)date;

/**
 *  Method to compute the queue thread label
 */
- (NSString *)queueThreadLabelForLogMessage:(SMLogMessage *)logMessage;

/**
 *  The actual method that formats a message (transforms a `SMLogMessage` model into a printable string)
 */
- (NSString *)formatLogMessage:(SMLogMessage *)logMessage;

@end
