//
//  WanjaCompatibilityMacros.h
//  WanjaCoreSDK
//
//  Created by guantou on 2023/10/10.
//

#ifndef WanjaCompatibilityMacros_h
#define WanjaCompatibilityMacros_h

#ifdef API_UNAVAILABLE
#define Wanja_API_UNAVAILABLE(x) API_UNAVAILABLE(x)
#else
#define Wanja_API_UNAVAILABLE(x)
#endif // API_UNAVAILABLE

#if __has_warning("-Wunguarded-availability-new")
#define Wanja_CAN_USE_AT_AVAILABLE 1
#else
#define Wanja_CAN_USE_AT_AVAILABLE 0
#endif

#endif /* WanjaCompatibilityMacros_h */
