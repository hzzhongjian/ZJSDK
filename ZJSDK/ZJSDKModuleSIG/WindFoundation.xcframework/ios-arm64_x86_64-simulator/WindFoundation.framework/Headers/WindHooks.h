//
//  WindHooks.h
//  WindHooks - A delightful, simple library for aspect oriented programming.
//
//  Copyright (c) 2014 Peter Steinberger. Licensed under the MIT license.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, WindHookOptions) {
    WindHookPositionAfter   = 0,            /// Called after the original implementation (default)
    WindHookPositionInstead = 1,            /// Will replace the original implementation.
    WindHookPositionBefore  = 2,            /// Called before the original implementation.
    
    WindHookOptionAutomaticRemoval = 1 << 3 /// Will remove the hook after the first execution.
};

/// Opaque WindHook Token that allows to deregister the hook.
@protocol WindHookToken <NSObject>

/// Deregisters an aspect.
/// @return YES if deregistration is successful, otherwise NO.
- (BOOL)remove;

@end

/// The WindHookInfo protocol is the first parameter of our block syntax.
@protocol WindHookInfo <NSObject>

/// The instance that is currently hooked.
- (id)instance;

/// The original invocation of the hooked method.
- (NSInvocation *)originalInvocation;

/// All method arguments, boxed. This is lazily evaluated.
- (NSArray *)arguments;

@end

/**
 WindHooks uses Objective-C message forwarding to hook into messages. This will create some overhead. Don't add aspects to methods that are called a lot. WindHooks is meant for view/controller code that is not called a 1000 times per second.

 Adding aspects returns an opaque token which can be used to deregister again. All calls are thread safe.
 */
@interface NSObject (WindHooks)

/// Adds a block of code before/instead/after the current `selector` for a specific class.
///
/// @param block WindHooks replicates the type signature of the method being hooked.
/// The first parameter will be `id<WindHookInfo>`, followed by all parameters of the method.
/// These parameters are optional and will be filled to match the block signature.
/// You can even use an empty block, or one that simple gets `id<WindHookInfo>`.
///
/// @note Hooking static methods is not supported.
/// @return A token which allows to later deregister the aspect.
+ (id<WindHookToken>)windhook_hookSelector:(SEL)selector
                           withOptions:(WindHookOptions)options
                            usingBlock:(id)block
                                 error:(NSError **)error;

/// Adds a block of code before/instead/after the current `selector` for a specific instance.
- (id<WindHookToken>)windhook_hookSelector:(SEL)selector
                           withOptions:(WindHookOptions)options
                            usingBlock:(id)block
                                 error:(NSError **)error;

@end


typedef NS_ENUM(NSUInteger, WindHookErrorCode) {
    WindHookErrorSelectorBlacklisted,                   /// Selectors like release, retain, autorelease are blacklisted.
    WindHookErrorDoesNotRespondToSelector,              /// Selector could not be found.
    WindHookErrorSelectorDeallocPosition,               /// When hooking dealloc, only WindHookPositionBefore is allowed.
    WindHookErrorSelectorAlreadyHookedInClassHierarchy, /// Statically hooking the same method in subclasses is not allowed.
    WindHookErrorFailedToAllocateClassPair,             /// The runtime failed creating a class pair.
    WindHookErrorMissingBlockSignature,                 /// The block misses compile time signature info and can't be called.
    WindHookErrorIncompatibleBlockSignature,            /// The block signature does not match the method or is too large.

    WindHookErrorRemoveObjectAlreadyDeallocated = 100   /// (for removing) The object hooked is already deallocated.
};

extern NSString *const WindHookErrorDomain;
