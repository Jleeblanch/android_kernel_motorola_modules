/* Copyright (c) 2018, Motorola Mobility LLC. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef MODD_MUC_PROTOCOL_H
#define MODD_MUC_PROTOCOL_H

struct mmi_uart_hdr_t {
	uint16_t  magic;  /* 0xA1A1 */
	uint16_t  cmd;
	uint16_t  payload_length;
	uint8_t   payload[];
} __packed;
/*  Followed by CRC16 (Poly8005) */

#define MSG_MAGIC 0xA1A1
#define MSG_META_DATA_SIZE (sizeof(struct mmi_uart_hdr_t) + sizeof(uint16_t))

#define MSG_ACK_MASK     0x8000
#define MSG_NACK_MASK	 0x4000

/* Msg ID's */
#define UART_SLEEP_REQ        0x0001
#define UART_SLEEP_ACK        (UART_SLEEP_REQ|MSG_ACK_MASK)
#define UART_SLEEP_NACK       (UART_SLEEP_REQ|MSG_NACK_MASK)
#define PACKETBUS_PROT_MSG    0x0002
#define POWER_STATUS          0x0003
#define POWER_CONTROL         0x0004
#define BOOT_MODE             0x0007
/* Test commands */
/*#define DISABLE_RESET         0x000A
#define ENABLE_RESET          0x000B
#define GPIO_REQUEST          0x000C*/

enum { NORMAL = 0, BP_TOOLS, FACTORY, QCOM, };
struct boot_mode_t {
    uint8_t boot_mode;
    uint8_t ap_guid[16];        // ro.mot.build.guid
    uint8_t ap_fw_ver_str[256]; // ro.build.fingerprint
};

enum { VBUS_IN = 0, VBUS_IN_SPLIT, VBUS_OUT, DC_IN };
struct power_control_t {
    uint8_t   flow;
    uint32_t  voltage_uv;
    int32_t   current_ua;
};

struct power_status_t {
	bool	      reverse_boost; /* PMI855 Output Enabled? */
	bool          dc_in; /* DC IN Enabled */
	bool          charging; /* Battery Charging? */
	bool          charger; /* MOD USBC Attached? */
	int16_t       battery_temp; /* Degrees Celsius */
	uint16_t      battery_capacity; /* % */
	uint16_t      battery_max_capacity; /* uAhr */
	uint32_t      battery_voltage; /* uV */
	int32_t       battery_current; /* uA */
	uint32_t      battery_max_voltage; /* uV */
	uint32_t      mod_output_voltage; /* uV */
	uint32_t      mod_input_voltage; /* uV */
	uint32_t      mod_output_current; /* uA */
	uint32_t      mod_input_current; /* uA */
};

/*struct gpio_request_t {
	uint8_t msm_gpio_num;
	bool    on;
};*/

#endif /* MODD_MUC_PROTOCOL_H */