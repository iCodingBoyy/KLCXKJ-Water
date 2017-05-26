//
//  KRWMObject.h
//  KRoadWaterMeter
//
//  Created by 远征 马 on 2017/5/5.
//  Copyright © 2017年 马远征. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KRWMDefine.h"
#import <CoreBluetooth/CoreBluetooth.h>

@interface CBPeripheral (advertisementData)
@property (nonatomic,strong)  NSDictionary *advertisementData;
- (NSString*)macAddress;
- (BOOL)isConnectEnable;
- (BOOL)isEqualToPeripheral:(id)object;
@end



/**
 @class KRRateObject
 @discussion 费率对象，用于下发费率到设备
 */
@interface KRRateObject : NSObject

/**
 @discussion 时间序号 2016年11月7日12时12分12秒 格式为161107121212 如果不赋值，Getter方法可以自动生成
 @property timeId
 */
@property (nonatomic,strong)  NSString *timeId;

/**
 @discussion 项目编号
 @property productId
 */
@property (nonatomic,strong)  NSNumber *productId;

/**
 @discussion 账号
 @property accountId
 */
@property (nonatomic,strong)  NSNumber *accountId;

/**
 @discussion 账户类别(1：管理员2：普通用户)
 @property accountType
 */
@property (nonatomic,strong)  NSNumber *accountType;

/**
 @discussion 个人帐号使用次数
 @property useCount
 */
@property (nonatomic,strong)  NSNumber *useCount;

/**
 @discussion 预扣金额 单位 厘（1000厘=1元）
 @property ykMoney
 */
@property (nonatomic,strong)  NSNumber *ykMoney;

/**
 @discussion 1 标准水表 2 阶梯收费
 @property paraTypeId
 */
@property (nonatomic,strong)  NSNumber *paraTypeId;

/**
 @discussion 费率（500厘=0.5元）
 @property rate1
 */
@property (nonatomic,strong)  NSNumber *rate1;

/**
 @discussion 费率（500厘=0.5元）
 @property rate1
 */
@property (nonatomic,strong)  NSNumber *rate2;

/**
 @discussion 费率（500厘=0.5元）
 @property rate1
 */
@property (nonatomic,strong)  NSNumber *rate3;

/**
 @discussion 保底消费时间（分钟）
 @property minTime
 */
@property (nonatomic,strong)  NSNumber *minTime;

/**
 @discussion 保底消费金额（元）
 @property minMoney
 */
@property (nonatomic,strong)  NSNumber *minMoney;

/**
 @discussion 1字节计费方式 00 计时 17计量  16进制0x00,0x11
 @property chargeMethod
 */
@property (nonatomic,strong)  NSNumber *chargeMethod;

/**
 @discussion 计费单位 大于0的脉冲数（计量） 6*N秒为单位（计时）
 @property minChargeUnit
 */
@property (nonatomic,strong)  NSNumber *minChargeUnit;

/**
 @discussion 自动断开时间（秒）没信号最大断开时间，以6秒为一个单位
 @property autoDisConTime
 */
@property (nonatomic,strong)  NSNumber *autoDisConTime;

/**
 经过编码的二进制数据。可直接用于蓝牙通讯
 
 @return 按协议编码的二进制数据
 */
- (NSData*)writeData;
@end


#pragma mark - KRStateObject

/**
 @class KRStateObject
 @discussion 设备状态信息
 */
@interface KRStateObject : NSObject

/**
 @discussion 项目编号
 @property productId
 */
@property (nonatomic,strong)  NSNumber *productId;

/**
 @discussion 设备ID
 @property deviceId
 */
@property (nonatomic,strong)  NSNumber *deviceId;

/**
 @discussion 帐号(1)
 @property accountId
 */
@property (nonatomic,strong)  NSNumber *accountId;

/**
 @discussion 设备物理地址
 @property macAddress
 */
@property (nonatomic,strong)  NSString *macAddress;

/**
 @discussion 00表示空闲 01表示有订单在进行 02表示刷卡消费 03表示消费完成数据没采集
 @property onCharge
 */
@property (nonatomic,strong)  NSNumber *onCharge;

/**
 @discussion 设备故障信息
 @property status
 */
@property (nonatomic,strong)  NSNumber *status;
@end




#pragma mark - KRConsumptionDetailsObject

/**
 @class KRConsumptionDetailsObject
 @discussion 消费详情数据，
 */
@interface KRConsumptionDetailsObject : NSObject

/**
 @discussion 时间序号
 @property timeId
 */
@property (nonatomic,strong)  NSString *timeId;

/**
 @discussion 姓名编号
 @property productId
 */
@property (nonatomic,strong)  NSNumber *productId;

/**
 @discussion 设备id
 @property deviceId
 */
@property (nonatomic,strong)  NSNumber *deviceId;

/**
 @discussion 账号id
 @property accountId
 */
@property (nonatomic,strong)  NSNumber *accountId;

/**
 @discussion 账户类别 1：管理员 2：普通用户
 @property accountType
 */
@property (nonatomic,strong)  NSNumber *accountType;

/**
 @discussion 账号使用次数
 @property useCount
 */
@property (nonatomic,strong)  NSNumber *useCount;

/**
 @discussion 预扣金额 5000厘
 @property ykMoney
 */
@property (nonatomic,strong)  NSNumber *ykMoney;

/**
 @discussion 消费金额
 @property consumeMone
 */
@property (nonatomic,strong)  NSNumber *consumeMone;

/**
 @discussion 费率
 @property rate
 */
@property (nonatomic,strong)  NSNumber *rate;

/**
 @discussion Mac物理地址
 @property macAddress
 */
@property (nonatomic,strong)  NSString *macAddress;

/**
 清除消费账单命令，查询消费账单之后发送清除命令成功后水表进入空闲状态
 
 @return 清除消费命令数据
 */
- (NSData*)writeData;
@end
