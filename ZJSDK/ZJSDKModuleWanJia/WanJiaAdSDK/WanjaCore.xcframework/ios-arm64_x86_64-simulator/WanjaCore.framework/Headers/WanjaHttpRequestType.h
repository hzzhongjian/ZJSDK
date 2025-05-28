//
//  WanjaHTTPRequestType.h
//  Pods
//
//  Created by guantou on 2019/12/9.
//

#ifndef WanjaHTTPRequestType_h
#define WanjaHTTPRequestType_h

NS_ASSUME_NONNULL_BEGIN

/* 定义请求类型的枚举 */
typedef NS_ENUM(NSUInteger, WanjaHttpRequestType) {
    /* get请求 */
    WanjaHttpRequestTypeGet                = 0,
    /* post请求 */
    WanjaHttpRequestTypePost,
    /* put请求 */
    WanjaHttpRequestTypePut,
    /* delete请求 */
    WanjaHttpRequestTypeDelete,
    /* 上传图片 */
    WanjaHttpRequestTypeUploadImage,
    /* 上传视频 */
    WanjaHttpRequestTypeUploadVideo,
    /* 上传文件 */
    WanjaHttpRequestTypeUploadFile,
    /* 下载图片 */
    WanjaHttpRequestTypeDownLoadFile
};

typedef NS_ENUM(NSUInteger, WanjaHttpRequestContentType) {
    /** 心跳*/
    WanjaHttpRequestContentTypeHearbeat    = 0,
    /** 广告*/
    WanjaHttpRequestContentTypeAdvertising    ,
    /** 日志*/
    WanjaHttpRequestContentTypeLog
};

typedef NSURLSessionTask WanjaURLSessionDataTask;

/* 定义请求成功的 block */
typedef void( ^ WanjaResponseSuccess)(WanjaURLSessionDataTask *dataTask, id response);
/* 定义请求失败的 block */
typedef void( ^ WanjaResponseFail)(WanjaURLSessionDataTask *dataTask, NSError *error);
/* 只返回结果请求成功的 block */
typedef void( ^ WanjaResponseSuccessWithModel)(id response);
/* 只返回结果请求失败的 block */
typedef void( ^ WanjaResponseFailWithError)(NSError *error);
/* 定义上传进度 block */
typedef void( ^ WanjaUploadProgress)(int64_t bytesProgress, int64_t totalBytesProgress);
/* 定义下载进度 block */
typedef void( ^ WanjaDownloadProgress)(int64_t bytesProgress, int64_t totalBytesProgress);

NS_ASSUME_NONNULL_END

#endif /* WanjaHTTPRequestType_h */
