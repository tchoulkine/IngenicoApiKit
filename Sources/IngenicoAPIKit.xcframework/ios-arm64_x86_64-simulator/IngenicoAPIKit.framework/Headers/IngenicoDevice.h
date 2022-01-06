//
//  NSObject+IngenicoDevice.h
//  IngenicoAPIKit
//
//  Created by Richard Urunuela on 20/01/2020.
//  Copyright © 2020 integration. All rights reserved.
//


#import <Foundation/Foundation.h>

#ifndef IngenicoDevice_h
#define IngenicoDevice_h

@protocol GapiPclServiceClientDelegate<NSObject>
- (void)pclConnected;
- (void)pclDisconnected;
- (void)pclLog:(NSString*) message;
@end

@interface IngenicoDevice:NSObject
    @property (copy, nonatomic)  NSString* ipAddress;
    @property (copy, nonatomic) NSString* macAddress;
    @property  (copy, nonatomic) NSString* name;
    @property (nonatomic)Boolean isBluetooth;
    @property (nonatomic,weak) id delegate;
@end

@interface  GapiPclServiceClient:NSObject
typedef enum _CommunicationState
{
    SERVICE_STOPPED,
    SERVICE_STARTED,
    SERVICE_CONNECTED,
    SERVICE_FAILED_NO_CNX,
    SERVICE_FAILED_INTERNAL
} CommunicationState;


@property (nonatomic, weak) id<GapiPclServiceClientDelegate> delegate;
+(instancetype)sharedInstance;

-(CommunicationState)getPclServiceState;
-(NSArray<IngenicoDevice *> *)getAvailableTerminals;
-(CommunicationState) connect:(IngenicoDevice*) device;
-(void)disconnect;

@end




#endif /* IngenicoDevice_h */
