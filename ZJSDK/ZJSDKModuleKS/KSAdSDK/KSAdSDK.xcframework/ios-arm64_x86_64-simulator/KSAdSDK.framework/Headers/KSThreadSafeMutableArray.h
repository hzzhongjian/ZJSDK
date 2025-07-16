//
//  KSThreadSafeMutableArray.h
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 线程安全数组
// - 每个变更/访问接口都会经过 lock
// - 添加 nil 不崩溃
// - 常用接口越界不崩溃
//
// 不实现 NSFastEnumeration，因为 for in 无法保证线程安全
// 不提供 Enumerator 系列方法，因为外部遍历无法保证线程安全
// 全部走 enumerate 系列 block 遍历
@interface KSThreadSafeMutableArray<ObjectType> : NSObject <NSCoding>
/// 返回原始集合的不可变备份
- (NSArray<ObjectType> *)rawImmutableArray;

+ (instancetype)array;
- (instancetype)init;
- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (instancetype)initWithArray:(NSArray<ObjectType> *)array;
- (instancetype)initWithNSMutableArray:(NSMutableArray *)mutableArray;

- (void)addObject:(nullable ObjectType)anObject;
- (void)insertObject:(nullable ObjectType)anObject atIndex:(NSUInteger)index;
- (void)removeLastObject;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(ObjectType)anObject;

- (NSUInteger)count;
- (nullable id)objectAtIndex:(NSUInteger)index;
- (NSArray<ObjectType> *)arrayByAddingObject:(ObjectType)anObject;
- (NSArray<ObjectType> *)arrayByAddingObjectsFromArray:(NSArray<ObjectType> *)otherArray;
- (NSString *)componentsJoinedByString:(NSString *)separator;
- (BOOL)containsObject:(ObjectType)anObject;
- (NSUInteger)indexOfObject:(nullable ObjectType)anObject;
- (NSUInteger)indexOfObject:(nullable ObjectType)anObject inRange:(NSRange)range;
- (NSUInteger)indexOfObjectIdenticalTo:(nullable ObjectType)anObject;
- (NSUInteger)indexOfObjectIdenticalTo:(nullable ObjectType)anObject inRange:(NSRange)range;
- (BOOL)isEqualToArray:(KSThreadSafeMutableArray<ObjectType> *)otherArray;
@property (nullable, nonatomic, readonly) ObjectType firstObject;
@property (nullable, nonatomic, readonly) ObjectType lastObject;

@property (readonly, copy) NSData *sortedArrayHint;
- (NSArray<ObjectType> *)subarrayWithRange:(NSRange)range;

- (void)addObjectsFromArray:(NSArray<ObjectType> *)otherArray;
- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (void)removeAllObjects;
- (void)removeObject:(nullable ObjectType)anObject inRange:(NSRange)range;
- (void)removeObject:(nullable ObjectType)anObject;
- (void)removeObjectIdenticalTo:(nullable ObjectType)anObject inRange:(NSRange)range;
- (void)removeObjectIdenticalTo:(nullable ObjectType)anObject;
- (void)removeObjectsInArray:(NSArray<ObjectType> *)otherArray;
- (void)removeObjectsInRange:(NSRange)range;
- (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(NSArray<ObjectType> *)otherArray range:(NSRange)otherRange;
- (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(NSArray<ObjectType> *)otherArray;
- (void)setArray:(NSArray<ObjectType> *)otherArray;

- (void)sortUsingFunction:(NSInteger (*)(id, id, void *))compare context:(void *)context;
- (void)sortUsingSelector:(SEL)comparator;
- (void)insertObjects:(NSArray<ObjectType> *)objects atIndexes:(NSIndexSet *)indexes;
- (void)removeObjectsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectsAtIndexes:(NSIndexSet *)indexes withObjects:(NSArray<ObjectType> *)objects;

- (NSArray<ObjectType> *)objectsAtIndexes:(NSIndexSet *)indexes;
- (nullable ObjectType)objectAtIndexedSubscript:(NSUInteger)idx;

/// 注意整个 block 都会在锁里，不要在 block 里做耗时任务，否则可能会导致主线程拿不到锁
/// 如果要做耗时遍历，可以走 .rawImmutableArray enumerate 遍历备份集合
- (void)enumerateObjectsUsingBlock:(void (^NS_NOESCAPE)(id _Nonnull, NSUInteger, BOOL * _Nonnull))block;
/// 注意整个 block 都会在锁里，不要在 block 里做耗时任务，否则可能会导致主线程拿不到锁
/// 如果要做耗时遍历，可以走 .rawImmutableArray enumerate 遍历备份集合
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;
/// 注意整个 block 都会在锁里，不要在 block 里做耗时任务，否则可能会导致主线程拿不到锁
/// 如果要做耗时遍历，可以走 .rawImmutableArray enumerate 遍历备份集合
- (void)enumerateObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;

- (void)sortUsingComparator:(NSComparator)cmptr;
- (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
- (NSArray<ObjectType> *)sortedArrayUsingFunction:(NSInteger (NS_NOESCAPE *)(ObjectType, ObjectType, void * _Nullable))comparator context:(nullable void *)context;
- (NSArray<ObjectType> *)sortedArrayUsingFunction:(NSInteger (NS_NOESCAPE *)(ObjectType, ObjectType, void * _Nullable))comparator context:(nullable void *)context hint:(nullable NSData *)hint;
- (NSArray<ObjectType> *)sortedArrayUsingSelector:(SEL)comparator;
- (void)makeObjectsPerformSelector:(SEL)aSelector NS_SWIFT_UNAVAILABLE("Use enumerateObjectsUsingBlock: or a for loop instead");
- (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(nullable id)argument NS_SWIFT_UNAVAILABLE("Use enumerateObjectsUsingBlock: or a for loop instead");
- (NSArray<ObjectType> *)sortedArrayUsingComparator:(NSComparator NS_NOESCAPE)cmptr;
- (NSArray<ObjectType> *)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmptr;
- (NSUInteger)indexOfObject:(ObjectType)obj inSortedRange:(NSRange)r options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmp;
@end

@interface KSThreadSafeMutableArray (Copying) <NSCopying, NSMutableCopying>
/// copy 返回 KSThreadSafeMutableArray ，如需 NSArray 请使用 `rawImmutableArray`
- (KSThreadSafeMutableArray *)copy;
- (KSThreadSafeMutableArray *)mutableCopy;
@end


// example:
//
//@[@"1", @"2"];
//
// =>
//
//LA(
//   LAE(@"1")
//   LAE(@"2")
//   )
//包含条件
//LA(
//   LAE(@"1")
//   LAE(@"2")
//   if (1) LAE(@3)
//   )

#define LiteralArray(...) \
({ \
NSMutableArray *__mutableArray = [NSMutableArray array]; \
__VA_ARGS__; \
__mutableArray.copy; \
})

#define LA(...) LiteralArray(__VA_ARGS__)

static inline void KSThreadSafeCollectionSafeAddArrayObject(NSMutableArray *mutableArray, id element) {
    if (element) [mutableArray addObject:element];
}

#define LiteralArrayElement(_element) \
KSThreadSafeCollectionSafeAddArrayObject(__mutableArray, _element);

#define LAE(_element) LiteralArrayElement(_element)

NS_ASSUME_NONNULL_END
