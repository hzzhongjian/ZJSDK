//
//  NVHTarFile.h
//  Pods
//
//  Created by Niels van Hoorn on 26/03/14.
//
//

#import <Foundation/Foundation.h>
#import <WindFoundation/SigNVHFile.h>

@interface SigNVHTarFile : SigNVHFile

- (BOOL)createFilesAndDirectoriesAtPath:(NSString *)destinationPath error:(NSError **)error;
- (void)createFilesAndDirectoriesAtPath:(NSString *)destinationPath completion:(void(^)(NSError*))completion;

- (BOOL)packFilesAndDirectoriesAtPath:(NSString *)sourcePath error:(NSError **)error;
- (void)packFilesAndDirectoriesAtPath:(NSString *)sourcePath completion:(void (^)(NSError *))completion;

@end
