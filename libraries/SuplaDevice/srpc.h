/*
 ============================================================================
 Name        : srpc.h [SUPLA REMOTE PROCEDURE CALL]
 Author      : Przemyslaw Zygmunt p.zygmunt@acsoftware.pl [AC SOFTWARE]
 Version     : 1.3
 Copyright   : 2015-2016 GPLv2
 ============================================================================
 */

#ifndef supladex_H_
#define supladex_H_

#include <stdio.h>
#include <stddef.h>
#include "proto.h"
#include "eh.h"

#ifdef ESP8266
  #include <os_type.h>
  #define SRPC_ICACHE_FLASH ICACHE_FLASH_ATTR
#else 
  #define SRPC_ICACHE_FLASH 
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef _supla_int_t (*_func_srpc_DataRW)(void *buf, _supla_int_t count, void *user_params);
typedef void (*_func_srpc_event_OnRemoteCallReceived)(void *_srpc, unsigned _supla_int_t rr_id, unsigned _supla_int_t call_type, void *user_params, unsigned char proto_version);
typedef void (*_func_srpc_event_BeforeCall)(void *_srpc, unsigned _supla_int_t call_type, void *user_params);
typedef void (*_func_srpc_event_OnVersionError)(void *_srpc, unsigned char remote_version, void *user_params);

typedef struct {

	_func_srpc_DataRW data_read;
	_func_srpc_DataRW data_write;
	_func_srpc_event_OnRemoteCallReceived on_remote_call_received;
	_func_srpc_event_OnVersionError on_version_error;
	_func_srpc_event_BeforeCall before_async_call;
	TEventHandler *eh;

	void *user_params;

}TsrpcParams;

union TsrpcDataPacketData {

	TDCS_SuplaPingServer *dcs_ping;
	TSDC_SuplaPingServerResult *sdc_ping_result;
	TSDC_SuplaGetVersionResult *sdc_getversion_result;
	TSDC_SuplaVersionError *sdc_version_error;
	TDCS_SuplaSetActivityTimeout *dcs_set_activity_timeout;
	TSDC_SuplaSetActivityTimeoutResult *sdc_set_activity_timeout_result;
	TDS_SuplaRegisterDevice *ds_register_device;
	TDS_SuplaRegisterDevice_B *ds_register_device_b;
	TSD_SuplaRegisterDeviceResult *sd_register_device_result;
	TCS_SuplaRegisterClient *cs_register_client;
	TSC_SuplaRegisterClientResult *sc_register_client_result;
	TDS_SuplaDeviceChannelValue *ds_device_channel_value;
	TSC_SuplaLocation *sc_location;
	TSC_SuplaLocationPack *sc_location_pack;
	TSC_SuplaChannel *sc_channel;
	TSC_SuplaChannelPack *sc_channel_pack;
	TSC_SuplaChannelValue *sc_channel_value;
	TSC_SuplaEvent *sc_event;
	TSD_SuplaChannelNewValue *sd_channel_new_value;
	TDS_SuplaChannelNewValueResult *ds_channel_new_value_result;
	TCS_SuplaChannelNewValue *cs_channel_new_value;
	TCS_SuplaChannelNewValue_B *cs_channel_new_value_b;

};

typedef struct {

  unsigned _supla_int_t call_type;
  unsigned _supla_int_t rr_id;

  union TsrpcDataPacketData data;

}TsrpcReceivedData;

void SRPC_ICACHE_FLASH srpc_params_init(TsrpcParams *params);

void* SRPC_ICACHE_FLASH srpc_init(TsrpcParams *params);
void SRPC_ICACHE_FLASH srpc_free(void *_srpc);

char SRPC_ICACHE_FLASH srpc_iterate(void *_srpc);

char SRPC_ICACHE_FLASH srpc_getdata(void *_srpc, TsrpcReceivedData *rd, unsigned _supla_int_t rr_id);
void SRPC_ICACHE_FLASH srpc_rd_free(TsrpcReceivedData *rd);

unsigned char SRPC_ICACHE_FLASH srpc_get_proto_version(void *_srpc);
void SRPC_ICACHE_FLASH srpc_set_proto_version(void *_srpc, unsigned char version);

// device/client <-> server
_supla_int_t SRPC_ICACHE_FLASH srpc_dcs_async_getversion(void *_srpc);
_supla_int_t SRPC_ICACHE_FLASH srpc_sdc_async_getversion_result(void *_srpc, char *SoftVer);
_supla_int_t SRPC_ICACHE_FLASH srpc_sdc_async_versionerror(void *_srpc, unsigned char remote_version);
_supla_int_t SRPC_ICACHE_FLASH srpc_dcs_async_ping_server(void *_srpc);
_supla_int_t SRPC_ICACHE_FLASH srpc_sdc_async_ping_server_result(void *_srpc);
_supla_int_t SRPC_ICACHE_FLASH srpc_dcs_async_set_activity_timeout(void *_srpc, TDCS_SuplaSetActivityTimeout *dcs_set_activity_timeout);
_supla_int_t SRPC_ICACHE_FLASH srpc_dcs_async_set_activity_timeout_result(void *_srpc, TSDC_SuplaSetActivityTimeoutResult *sdc_set_activity_timeout_result);

// device <-> server
_supla_int_t SRPC_ICACHE_FLASH srpc_ds_async_registerdevice(void *_srpc, TDS_SuplaRegisterDevice *registerdevice);
_supla_int_t SRPC_ICACHE_FLASH srpc_ds_async_registerdevice_b(void *_srpc, TDS_SuplaRegisterDevice_B *registerdevice); // ver. >= 2
_supla_int_t SRPC_ICACHE_FLASH srpc_sd_async_registerdevice_result(void *_srpc, TSD_SuplaRegisterDeviceResult *registerdevice_result);
_supla_int_t SRPC_ICACHE_FLASH srpc_ds_async_channel_value_changed(void *_srpc, unsigned char channel_number, char *value);
_supla_int_t SRPC_ICACHE_FLASH srpc_sd_async_set_channel_value(void *_srpc, TSD_SuplaChannelNewValue *value);
_supla_int_t SRPC_ICACHE_FLASH srpc_ds_async_set_channel_result(void *_srpc, unsigned char ChannelNumber, _supla_int_t SenderID, char Success);

// client <-> server
_supla_int_t SRPC_ICACHE_FLASH srpc_cs_async_registerclient(void *_srpc, TCS_SuplaRegisterClient *registerclient);
_supla_int_t SRPC_ICACHE_FLASH srpc_sc_async_registerclient_result(void *_srpc, TSC_SuplaRegisterClientResult *registerclient_result);
_supla_int_t SRPC_ICACHE_FLASH srpc_sc_async_location_update(void *_srpc, TSC_SuplaLocation *location);
_supla_int_t SRPC_ICACHE_FLASH srpc_sc_async_locationpack_update(void *_srpc, TSC_SuplaLocationPack *location_pack);
_supla_int_t SRPC_ICACHE_FLASH srpc_sc_async_channel_update(void *_srpc, TSC_SuplaChannel *channel);
_supla_int_t SRPC_ICACHE_FLASH srpc_sc_async_channelpack_update(void *_srpc, TSC_SuplaChannelPack *channel_pack);
_supla_int_t SRPC_ICACHE_FLASH srpc_sc_async_channel_value_update(void *_srpc, TSC_SuplaChannelValue *channel_item_value);
_supla_int_t SRPC_ICACHE_FLASH srpc_cs_async_get_next(void *_srpc);
_supla_int_t SRPC_ICACHE_FLASH srpc_sc_async_event(void *_srpc, TSC_SuplaEvent *event);
_supla_int_t SRPC_ICACHE_FLASH srpc_cs_async_set_channel_value(void *_srpc, TCS_SuplaChannelNewValue *value);
_supla_int_t SRPC_ICACHE_FLASH srpc_cs_async_set_channel_value_b(void *_srpc, TCS_SuplaChannelNewValue_B *value);

#ifdef __cplusplus
}
#endif

#endif /* supladex_H_ */
