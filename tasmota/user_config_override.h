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
// Keep USE_WEBCLIENT_HTTPS: TinyC's raw TLS syscalls and Tasmota's
// BearSSL declarations are compiled as part of the TinyC driver.
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

#endif  // _USER_CONFIG_OVERRIDE_H_
