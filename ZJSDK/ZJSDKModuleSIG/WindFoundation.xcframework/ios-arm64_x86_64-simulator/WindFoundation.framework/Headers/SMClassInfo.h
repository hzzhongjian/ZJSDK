//
//  SMClassInfo.h
//  SMCoder
//
//  Created by happyelements on 2019/5/30.
//  Copyright © 2019 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type encoding's type.
 */
typedef NS_OPTIONS(NSUInteger, SMEncodingType) {
    SMEncodingTypeMask       = 0xFF, ///< mask of type value
    SMEncodingTypeUnknown    = 0, ///< unknown
    SMEncodingTypeVoid       = 1, ///< void
    SMEncodingTypeBool       = 2, ///< bool
    SMEncodingTypeInt8       = 3, ///< char / BOOL
    SMEncodingTypeUInt8      = 4, ///< unsigned char
    SMEncodingTypeInt16      = 5, ///< short
    SMEncodingTypeUInt16     = 6, ///< unsigned short
    SMEncodingTypeInt32      = 7, ///< int
    SMEncodingTypeUInt32     = 8, ///< unsigned int
    SMEncodingTypeInt64      = 9, ///< long long
    SMEncodingTypeUInt64     = 10, ///< unsigned long long
    SMEncodingTypeFloat      = 11, ///< float
    SMEncodingTypeDouble     = 12, ///< double
    SMEncodingTypeLongDouble = 13, ///< long double
    SMEncodingTypeObject     = 14, ///< id
    SMEncodingTypeClass      = 15, ///< Class
    SMEncodingTypeSEL        = 16, ///< SEL
    SMEncodingTypeBlock      = 17, ///< block
    SMEncodingTypePointer    = 18, ///< void*
    SMEncodingTypeStruct     = 19, ///< struct
    SMEncodingTypeUnion      = 20, ///< union
    SMEncodingTypeCString    = 21, ///< char*
    SMEncodingTypeCArray     = 22, ///< char[10] (for example)
    
    SMEncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    SMEncodingTypeQualifierConst  = 1 << 8,  ///< const
    SMEncodingTypeQualifierIn     = 1 << 9,  ///< in
    SMEncodingTypeQualifierInout  = 1 << 10, ///< inout
    SMEncodingTypeQualifierOut    = 1 << 11, ///< out
    SMEncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    SMEncodingTypeQualifierByref  = 1 << 13, ///< byref
    SMEncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    SMEncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    SMEncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    SMEncodingTypePropertyCopy         = 1 << 17, ///< copy
    SMEncodingTypePropertyRetain       = 1 << 18, ///< retain
    SMEncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    SMEncodingTypePropertyWeak         = 1 << 20, ///< weak
    SMEncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    SMEncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    SMEncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};


SMEncodingType SM_EncodingGetType(const char *typeEncoding);



/**
 Instance variable information.
 */
@interface SMClassIvarInfo : NSObject
@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar opaque struct
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar's name
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar's offset
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar's type encoding
@property (nonatomic, assign, readonly) SMEncodingType type;    ///< Ivar's type

/**
 Creates and returns an ivar info object.
 
 @param ivar ivar opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithIvar:(Ivar)ivar;
@end


/**
 Method information.
 */
@interface SMClassMethodInfo : NSObject
@property (nonatomic, assign, readonly) Method method;                  ///< method opaque struct
@property (nonatomic, strong, readonly) NSString *name;                 ///< method name
@property (nonatomic, assign, readonly) SEL sel;                        ///< method's selector
@property (nonatomic, assign, readonly) IMP imp;                        ///< method's implementation
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< method's parameter and return types
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< return value's type
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< array of arguments' type

/**
 Creates and returns a method info object.
 
 @param method method opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithMethod:(Method)method;
@end


/**
 Property information.
 */
@interface SMClassPropertyInfo : NSObject
@property (nonatomic, assign, readonly) objc_property_t property; ///< property's opaque struct
@property (nonatomic, strong, readonly) NSString *name;           ///< property's name
@property (nonatomic, assign, readonly) SMEncodingType type;      ///< property's type
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< property's encoding value
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< property's ivar name
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< may be nil
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///< may nil
@property (nonatomic, assign, readonly) SEL getter;               ///< getter (nonnull)
@property (nonatomic, assign, readonly) SEL setter;               ///< setter (nonnull)

/**
 Creates and returns a property info object.
 
 @param property property opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithProperty:(objc_property_t)property;
@end


/**
 Class information for a class.
 */
@interface SMClassInfo : NSObject
@property (nonatomic, assign, readonly) Class cls; ///< class object
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< super class object
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< class's meta class object
@property (nonatomic, readonly) BOOL isMeta; ///< whether this class is meta class
@property (nonatomic, strong, readonly) NSString *name; ///< class name
@property (nullable, nonatomic, strong, readonly) SMClassInfo *superClassInfo; ///< super class's class info
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, SMClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, SMClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, SMClassPropertyInfo *> *propertyInfos; ///< properties

/**
 If the class is changed (for example: you add a method to this class with
 'class_addMethod()'), you should call this method to refresh the class info cache.
 
 After called this method, `needUpdate` will returns `YES`, and you should call
 'classInfoWithClass' or 'classInfoWithClassName' to get the updated class info.
 */
- (void)setNeedUpdate;

/**
 If this method returns `YES`, you should stop using this instance and call
 `classInfoWithClass` or `classInfoWithClassName` to get the updated class info.
 
 @return Whether this class info need update.
 */
- (BOOL)needUpdate;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param cls A class.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClass:(Class)cls;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param className A class name.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
