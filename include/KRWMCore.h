//
//  KRWMCore.h
//  KRoadWaterMeter
//
//  Created by 远征 马 on 2017/5/5.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "KRWMBlock.h"
#import "KRWMDefine.h"


/**
 @class KRWMCore
 @discussion 蓝牙通讯核心文件
 */
@interface KRWMCore : NSObject
@property (nonatomic, strong, readonly) CBPeripheral  *peripheral;
@property (nonatomic, assign, readonly) KRSyncType syncType;
@property (nonatomic, assign, readonly, getter=isSynchronizing) BOOL synchronizing;
@property (nonatomic, assign)  KRManagerState managerState;



+ (instancetype)sharedCore;


/*!
 @discussion  扫描蓝牙外设，如果uuidString存在则返回指定uuidString的外设，不存在则扫描所有符合条件的外设

 @param uuidString 蓝牙uuid字符串
 @param handler 扫描结果回调block
 */
- (void)scanForPeripherals:(NSString *)uuidString retHandler:(KRWMPeriphralsHandler)handler;


/*!
 @discussion 停止扫描外设
 */
- (void)stopScan;

/**
 @discussion 判断当前<i>peripheral</i>是否已经连接

 @return YES/NO
 */
- (BOOL)isConnected;

/*!
 @discussion 连接<i>peripheral</i>
 
 @param peripheral 蓝牙外设对象
 @return YES/NO,如果<i>peripheral</i>存在，返回YES，否则返回NO
 */
- (BOOL)connectPeripheral:(CBPeripheral*)peripheral;


- (void)disconnect;

/*!
 @discussion 断开<i>peripheral</i>连接

 @param peripheral 蓝牙外设
 @return YES/NO,如果<i>peripheral</i>存在，返回YES，否则返回NO
 */
- (BOOL)disconnectPeripheral:(CBPeripheral*)peripheral;


#pragma mark - 蓝牙通讯


/**
 @discussion 清楚设备项目信息
 
 @param dataCallback 响应结果回调
 @param retHandler 同步结果回调
 */
- (void)krClearNumOfDevice:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;

/**
 @discussion 下发项目编号，操作员用

 @param deviceId 设备id
 @param productId 产品id
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krAssignNumForDevice:(NSNumber*)deviceId productId:(NSNumber*)productId dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 分配费率参数

 @param data 费率参数信息 
 @see KRRateObject
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krAssginRateForDevice:(NSData*)data dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;



/**
 @discussion 结束消费指令
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)KrEndConsumptionOfDevice:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 获取设备状态

 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krGetStateOfDevice:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 采集消费数据

 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krGetConsumptionDetails:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;


/**
 @discussion 获取记录存储结果

 @param data 记录查询相关数据
 @see KRStoreResultObject
 @param dataCallback 响应数据回调
 @param retHandler 同步结果回调
 */
- (void)krGetStoredResults:(NSData*)data dataCallback:(KRWMDataHandler)dataCallback result:(KRWMResultHandler)retHandler;
@end
