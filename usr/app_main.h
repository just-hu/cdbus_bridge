/*
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2017, DUKELEC, Inc.
 * All rights reserved.
 *
 * Author: Duke Fong <duke@dukelec.com>
 */

#ifndef __APP_MAIN_H__
#define __APP_MAIN_H__

#include "common.h"
#include "cdnet.h"

typedef enum {
    LED_POWERON = 0,
    LED_WARN,
    LED_ERROR
} led_state_t;

typedef enum {
    APP_PASS_THRU = 0,
    APP_RAW
} app_mode_t;

typedef enum {
    INTF_RS485 = 0,
    INTF_USB,
    INTF_TTL,
    INTF_RS232
} intf_idx_t;

typedef struct {
    uint16_t    magic_code; // 0xcdcd
    bool        stay_in_bl; // stay in bootloader

    app_mode_t  mode;
    intf_idx_t  intf_idx;

    uint8_t     rs485_mac;
    uint8_t     rs485_net;
    uint32_t    rs485_baudrate_low;
    uint32_t    rs485_baudrate_high;

    uint32_t    ttl_baudrate;
    uint32_t    rs232_baudrate;

    // raw
    bool        rpt_en;
    bool        rpt_multi_net;
    uint8_t     rpt_mac;
    uint8_t     rpt_addr[2];
    uint16_t    rpt_src_port;
    uint16_t    rpt_dst_port;

} app_conf_t;


#define FLASH_PORT          10 // save to flash
#define RAW_SER_PORT        20
#define RAW_CONF_PORT       21

extern app_conf_t app_conf;
extern cdnet_intf_t n_intf;

#endif