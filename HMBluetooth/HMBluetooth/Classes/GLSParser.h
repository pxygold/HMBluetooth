//
//  GLSManager.h
//  Pods
//
//  Created by 何霞雨 on 16/8/11.
//
//

#import <Foundation/Foundation.h>

#import "GlucoseRecord.h"
#import "GLSParserPrt.h"

/** Glucose service UUID */
const static NSString* GLS_SERVICE_UUID = @"00001808-0000-1000-8000-00805f9b34fb";
/** Glucose Measurement characteristic UUID */
const static NSString* GM_CHARACTERISTIC = @"00002A18-0000-1000-8000-00805f9b34fb";
/** Glucose Measurement Context characteristic UUID */
const static NSString* GM_CONTEXT_CHARACTERISTIC = @"00002A34-0000-1000-8000-00805f9b34fb";
/** Glucose Feature characteristic UUID */
const static NSString* GF_CHARACTERISTIC = @"00002A51-0000-1000-8000-00805f9b34fb";
/** Record Access Control Point characteristic UUID */
const static NSString* RACP_CHARACTERISTIC = @"00002A52-0000-1000-8000-00805f9b34fb";

@class HMBluetooth;
@class CBCharacteristic;

@interface GLSParser : NSObject

@property (nonatomic,weak)id <GLSParserPrt> delegate;

#pragma mark - GLS Value

-(void)parseGLSValueWithCharacteristic:(CBCharacteristic *)characteristic;//解析

-(void)parseGLSValue:(NSData*)data withCharacteristic:(NSString *)characteristicUUID;//解析返回值
-(void)parseGLSOpValue:(NSData*)data withCharacteristic:(NSString *)characteristicUUID;//解析操作后的返回值

-(NSArray<GlucoseRecord *>*) getRecords;//获取所有记录
#pragma mark - record
-(void)refreshRecords;

-(void)getAllRecords;
-(void)getFirstRecord;
-(void)getLastRecord;

-(void)deleteAllRecords;
-(void)clear;
-(void)abort;

@end