/*
  Variant-specific configuration overrides.
  This file is included by my_user_config.h when USE_CONFIG_OVERRIDE is set.
  All customizations are guarded so the standard Tasmota environments remain unchanged.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

#ifdef OTTELLO_POW_SLIM

// TinyC VM, browser IDE and LittleFS-backed files/charts/backups.
#define USE_TINYC
#define USE_TINYC_IDE
#define USE_UFILESYS

// Sonoff POW Elite 316D/320D: both use CSE7766; display is GPIO-driven TM1621.
#ifndef USE_ENERGY_SENSOR
  #define USE_ENERGY_SENSOR
#endif
#ifndef USE_CSE7766
  #define USE_CSE7766
#endif
#define USE_DISPLAY
#define USE_DISPLAY_TM1621_SONOFF

// Remove unused energy-meter drivers. Keep CSE7766.
#undef USE_SML_M
#undef USE_SML_SCRIPT_CMD
#undef USE_ENERGY_DUMMY
#undef USE_BL0942
#undef USE_PZEM004T
#undef USE_PZEM_AC
#undef USE_PZEM_DC
#undef USE_MCP39F501
#undef USE_ADE7880
#undef USE_ADE7953
#undef USE_SDM120
#undef USE_SDM630
#undef USE_DDS2382
#undef USE_DDSU666
#undef USE_SOLAX_X1
#undef USE_LE01MR
#undef USE_TELEINFO

// Remove large optional subsystems not used by this device.
#undef USE_BLE_ESP32
#undef USE_MI_ESP32
#undef USE_ZIGBEE
#undef USE_MATTER_DEVICE
#undef USE_MATTER_C_PLUGIN_ONLY
#undef USE_BERRY
#undef USE_AUTOCONF
#undef USE_EXTENSION_MANAGER
// Disable Tasmota's outbound HTTPS webclient, but keep BearSSL itself for
// TinyC raw TLS syscalls (tlsConnect/tlsWrite/tlsRead and certificate helpers).
#undef USE_WEBCLIENT_HTTPS
#define USE_TLS
#undef USE_SCRIPT
#undef USE_RULES

// No Tasmota I2C/SPI peripherals are connected; TM1621 uses GPIO lines.
#undef USE_I2C
#undef USE_SPI

// Remove unused automation, discovery and protocol integrations.
#undef USE_TIMERS
#undef USE_TIMERS_WEB
#undef USE_SUNRISE
#undef USE_DOMOTICZ
#undef USE_HOME_ASSISTANT
#undef USE_TASMOTA_DISCOVERY
#undef USE_DISCOVERY
#undef USE_KNX
#undef USE_EMULATION_HUE
#undef USE_EMULATION_WEMO
#undef USE_WEBSERVER_SSL

#endif  // OTTELLO_POW_SLIM


// -----------------------------------------------------------------------------
// Full Otello TinyC profile without Smart-Meter/SML support.
// This intentionally does NOT inherit the aggressively reduced POW Slim profile.
// -----------------------------------------------------------------------------
#ifdef OTTELLO_TC_NOSML

// Keep the original Otello ESP32 feature profile; remove only SML-specific code.
#undef USE_DOMOTICZ
#undef USE_EMULATION_HUE
#undef USE_EMULATION_WEMO
#undef USE_SONOFF_RF
#undef USE_SONOFF_SC
#undef USE_TUYA_MCU
#undef USE_ARMTRONIX_DIMMERS
#undef USE_PS_16_DZ
#undef USE_SONOFF_IFAN
#undef USE_BUZZER
#undef USE_ARILUX_RF
#undef USE_SHUTTER
#undef USE_EXS_DIMMER
#undef USE_DEVICE_GROUPS
#undef USE_PWM_DIMMER
#undef USE_SONOFF_D1
#undef USE_SHELLY_DIMMER
#undef SHELLY_CMDS
#undef SHELLY_FW_UPGRADE
#undef USE_LIGHT
#undef USE_WS2812
#undef USE_MY92X1
#undef USE_SM16716
#undef USE_SM2135
#undef USE_SM2335
#undef USE_BP1658CJ
#undef USE_BP5758D
#undef USE_SONOFF_L1
#undef USE_ELECTRIQ_MOODL
#undef USE_LIGHT_PALETTE
#undef USE_LIGHT_VIRTUAL_CT
#undef USE_DGR_LIGHT_SEQUENCE
#undef USE_SERIAL_BRIDGE
#undef USE_ENERGY_DUMMY
#undef USE_PZEM004T
#undef USE_PZEM_AC
#undef USE_PZEM_DC
#undef USE_MCP39F501
#undef USE_IR_REMOTE
#undef GV_USE_ESPINFO
#undef USE_GPIO_VIEWER
#undef USE_NETWORK_LIGHT_SCHEMES
#undef USE_BERRY
#undef USE_AUTOCONF
#undef USE_CSE7761

// SML and its TinyC command hooks are the only Otello features deliberately omitted.
#undef USE_SML_M
#undef USE_SML_SCRIPT_CMD
#undef USE_SML_CRC
#undef USE_SML_AUTHKEY

// Full Otello ESP32 baseline (not the POW Slim exclusions).
#define USE_BMP
#define DS18X20_MAX_SENSORS 10
#define SET_ESP32_STACK_SIZE (12 * 1024)
#define USE_PING
#define USE_UFILESYS
#undef UFSYS_SIZE
#define UFSYS_SIZE 16384

#define USE_HOME_ASSISTANT
#define USE_WEBCLIENT_HTTPS
#define USE_TLS
#define USE_ESP32_SW_SERIAL
#define USE_MQTT_TLS
#define USE_INFLUXDB

// Original Otello TC-specific configuration.
#define USE_MATTER_C
#define USE_MATTER_C_PLUGIN_ONLY
#define USE_DISCOVERY
#define WEBSERVER_ADVERTISE
#define USE_BINPLUGINS
#define USE_TINYC_REPO_IDE
#undef USE_RULES
#define USE_TINYC
#define USE_TINYC_IDE
#define TINYC_DEFAULT_REPO "https://raw.githubusercontent.com/ottelo9/tasmota-sml-script/main/tinyc/bytecode"
#define TINYC_DEFAULT_IDE_URL "https://raw.githubusercontent.com/ottelo9/tasmota-sml-script/main/tinyc/tinyc_ide.html.gz"
#define TINYC_REPO_LIST \
  "TinyC Examples (gemu2015)|https://raw.githubusercontent.com/gemu2015/Sonoff-Tasmota/universal/tasmota/tinyc"

#endif  // OTTELLO_TC_NOSML

#endif  // _USER_CONFIG_OVERRIDE_H_
