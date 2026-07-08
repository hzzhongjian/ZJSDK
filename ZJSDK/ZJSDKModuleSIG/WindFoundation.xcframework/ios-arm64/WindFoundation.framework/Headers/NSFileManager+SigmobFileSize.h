//
//  NSFileManager+SigmobFileSize.h
//  Pods
//
//  Created by Niels van Hoorn on 03/07/15.
//
//

#import <Foundation/Foundation.h>

@interface NSFileManager (SigmobFileSize)

- (unsigned long long)sig_fileSizeOfItemAtPath:(NSString *)path;

@end
