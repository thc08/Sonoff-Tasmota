/*
  Final POW Elite Slim overrides.

  Tasmota's preconfigured ESP32 feature profile is included from
  tasmota_globals.h AFTER my_user_config.h. The ordinary user_config_override.h
  is therefore too early to remove every default driver. This file is included
  immediately after tasmota_configurations.h to make the POW profile final.
*/

#ifdef OTTELLO_POW_SLIM

// Required POW Elite profile.
#define USE_TINYC
#define USE_TINYC_IDE
#define USE_UFILESYS
#define USE_ENERGY_SENSOR
#define USE_CSE7766
#define USE_DISPLAY
#define USE_DISPLAY_TM1621_SONOFF

// Keep BearSSL/TLS for firmware OTA; no outbound HTTPS client or MQTT TLS.
#define USE_TLS
#undef USE_WEBCLIENT_HTTPS
#undef USE_MQTT_TLS
#undef USE_MQTT_TLS_ECDSA
#undef USE_SENDMAIL
#undef USE_ESP32MAIL
#undef USE_TELEGRAM

// TinyC replaces the classic Tasmota scripting/automation stack.
#undef USE_SCRIPT
#undef USE_RULES
#undef SUPPORT_MQTT_EVENT
#undef USE_BERRY
#undef USE_AUTOCONF
#undef USE_EXTENSION_MANAGER
#undef USE_UNISHOX_COMPRESSION

// No Bluetooth, Zigbee, Matter, Ethernet, or unrelated discovery protocols.
#undef USE_BLE_ESP32
#undef USE_MI_ESP32
#undef USE_MIBLE
#undef USE_HM10
#undef USE_ZIGBEE
#undef USE_MATTER_DEVICE
#undef USE_MATTER_C
#undef USE_MATTER_C_PLUGIN_ONLY
#undef USE_ETHERNET
#undef USE_WT32_ETH01
#undef USE_DISCOVERY
#undef USE_TASMOTA_DISCOVERY
#undef USE_HOME_ASSISTANT
#undef USE_DOMOTICZ
#undef USE_KNX
#undef USE_KNX_WEB_MENU
#undef USE_EMULATION_HUE
#undef USE_EMULATION_WEMO

// LittleFS is used for the TinyC IDE. TinyC's native SPI API needs the
// framework SPI class, but no external SPI peripheral drivers or SD card are used.
#undef USE_I2C
#define USE_SPI
#undef USE_SDCARD
#undef USE_SD_MMC
#undef USE_MIBLE
#undef USE_SONOFF_SPM

// No timers, sunrise, rules, counter, dimmer, or unrelated device protocols.
#undef USE_TIMERS
#undef USE_TIMERS_WEB
#undef USE_SUNRISE
#undef USE_COUNTER
#undef USE_AC_ZERO_CROSS_DIMMER
#undef USE_DEEPSLEEP
#undef USE_IMPROV
#undef USE_SERIAL_BRIDGE
#undef ROTARY_V1
#undef USE_SONOFF_RF
#undef USE_RF_FLASH
#undef USE_SONOFF_SC
#undef USE_TUYA_MCU
#undef USE_TUYA_TIME
#undef USE_ARMTRONIX_DIMMERS
#undef USE_PS_16_DZ
#undef USE_SONOFF_IFAN
#undef USE_BUZZER
#undef USE_ARILUX_RF
#undef USE_SHUTTER
#undef USE_EXS_DIMMER
#undef USE_DEVICE_GROUPS
#undef USE_DEVICE_GROUPS_SEND
#undef USE_PWM_DIMMER
#undef USE_PWM_DIMMER_REMOTE
#undef USE_SONOFF_D1
#undef USE_SHELLY_DIMMER
#undef SHELLY_CMDS
#undef SHELLY_FW_UPGRADE

// No general light/IR/sensor drivers; this POW profile has no I2C peripherals.
// TM1621 is GPIO-driven and CSE7766 is UART-driven. Keep unrelated sensor
// drivers out even though the generic ESP32 configuration enables them.
#undef USE_I2C
#undef USE_SPI
#undef USE_SHT
#undef USE_HTU
#undef USE_BMP
#undef USE_BME68X
#undef USE_BH1750
#undef USE_VEML6070
#undef USE_ADS1115
#undef USE_INA219
#undef USE_SHT3X
#undef USE_MGS
#undef USE_SCD30
#undef USE_SEN5X
#undef USE_SGP30
#undef USE_SGP40
#undef USE_LM75AD
#undef USE_CCS811
#undef USE_HIH6
#undef USE_DHT12
#undef USE_DS1624
#undef USE_WEMOS_MOTOR_V1

// Retain only the CSE7766 energy monitor; exclude every other energy backend.
#undef USE_ENERGY_DUMMY
#undef USE_HLW8012
#undef USE_BL09XX
#undef USE_BL0942
#undef USE_CSE7761
#undef USE_PZEM004T
#undef USE_PZEM_AC
#undef USE_PZEM_DC
#undef USE_MCP39F501
#undef USE_ADE7880
#undef USE_ADE7953
#undef USE_SDM72
#undef USE_SDM120
#undef USE_SDM230
#undef USE_SDM630
#undef USE_DDS2382
#undef USE_DDSU666
#undef USE_SOLAX_X1
#undef USE_LE01MR
#undef USE_TELEINFO
#undef USE_IEM3000
#undef USE_BL6523
#undef USE_MODBUS_ENERGY

//
#undef USE_LIGHT
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
#undef USE_WS2812
#undef USE_DHT
#undef USE_IR_REMOTE
#undef USE_IR_SEND_NEC
#undef USE_IR_SEND_RC5
#undef USE_IR_SEND_RC6
#undef USE_IR_RECEIVE
#undef USE_IR_REMOTE_FULL
#undef USE_DHT12
#undef USE_MAX31855
#undef USE_MAX31865

// No SPI expansion or LoRaWAN bridge is fitted.
#undef USE_MCP23XXX_DRV
#undef USE_SPI_LORA
#undef USE_LORA_SX126X
#undef USE_LORA_SX127X
#undef USE_LORAWAN_BRIDGE

// Keep only the CSE7766 energy monitor.
#undef USE_SML_M
#undef USE_SML
#undef USE_SML_SCRIPT_CMD
#undef USE_ENERGY_DUMMY
#undef USE_HLW8012
#undef USE_BL09XX
#undef USE_BL0942
#undef USE_CSE7761
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

// Only the Sonoff TM1621 driver is needed by this device.
#undef USE_DISPLAY_MODES1TO5
#undef USE_DISPLAY_LCD
#undef USE_DISPLAY_MATRIX
#undef USE_DISPLAY_SEVENSEG
#undef USE_DISPLAY_TM1637
#undef USE_DISPLAY_MAX7219
#undef USE_DISPLAY_MAX7219_MATRIX
#undef USE_DISPLAY_TM1640
#undef USE_DISPLAY_SH1106
#undef USE_DISPLAY_TM1650
#undef USE_UNIVERSAL_DISPLAY
#undef USE_UNIVERSAL_TOUCH
#undef USE_WEBSERVER_SSL
#undef USE_GPIO_VIEWER
#undef USE_ESP32_SENSORS
#undef USE_ADC
#undef USE_NETWORK_LIGHT_SCHEMES

// Fail the build if the final ESP32 configuration re-enables excluded modules.
#if !defined(USE_TINYC) || !defined(USE_TINYC_IDE) || !defined(USE_UFILESYS) || !defined(USE_ENERGY_SENSOR) || !defined(USE_CSE7766) || !defined(USE_DISPLAY_TM1621_SONOFF) || !defined(USE_SPI)
  #error "POW Slim: required TinyC, filesystem, CSE7766 or TM1621 feature is missing"
#endif
#if defined(USE_BERRY) || defined(USE_AUTOCONF) || defined(USE_EXTENSION_MANAGER) || defined(USE_SCRIPT) || defined(USE_RULES) || defined(USE_WEBCLIENT_HTTPS)
  #error "POW Slim: excluded scripting, extension or outbound HTTPS subsystem is still enabled"
#endif
#if defined(USE_BMP) || defined(USE_BME68X) || defined(USE_SHT) || defined(USE_HTU) || defined(USE_BH1750) || defined(USE_VEML6070) || defined(USE_ADS1115) || defined(USE_INA219) || defined(USE_SHT3X) || defined(USE_MGS) || defined(USE_SCD30) || defined(USE_SEN5X) || defined(USE_SGP30) || defined(USE_SGP40) || defined(USE_LM75AD) || defined(USE_CCS811) || defined(USE_HIH6) || defined(USE_DHT12) || defined(USE_DS1624) || defined(USE_WEMOS_MOTOR_V1)
  #error "POW Slim: an unrelated I2C/sensor driver is still enabled"
#endif
#if defined(USE_PZEM004T) || defined(USE_PZEM_AC) || defined(USE_PZEM_DC) || defined(USE_MCP39F501) || defined(USE_ADE7880) || defined(USE_ADE7953) || defined(USE_SDM72) || defined(USE_SDM120) || defined(USE_SDM230) || defined(USE_SDM630) || defined(USE_DDS2382) || defined(USE_DDSU666) || defined(USE_SOLAX_X1) || defined(USE_LE01MR) || defined(USE_TELEINFO) || defined(USE_IEM3000) || defined(USE_BL6523) || defined(USE_MODBUS_ENERGY) || defined(USE_ENERGY_DUMMY)
  #error "POW Slim: an unused energy-meter driver is still enabled"
#endif
#if defined(USE_AC_ZERO_CROSS_DIMMER) || defined(USE_COUNTER) || defined(USE_KNX) || defined(USE_KNX_WEB_MENU) || defined(USE_TUYA_MCU) || defined(USE_TUYA_TIME) || defined(USE_SHUTTER) || defined(USE_IR_REMOTE) || defined(USE_DHT) || defined(USE_DHT12) || defined(USE_MAX31855) || defined(USE_MAX31865) || defined(USE_SERIAL_BRIDGE) || defined(USE_DEEPSLEEP) || defined(USE_IMPROV) || defined(USE_SDCARD) || defined(USE_SD_MMC) || defined(USE_SONOFF_SPM) || defined(USE_SPI_LORA) || defined(USE_LORA_SX126X) || defined(USE_LORA_SX127X) || defined(USE_LORAWAN_BRIDGE) || defined(USE_TUYAMCUBR) || defined(USE_SONOFF_RF) || defined(USE_RF_FLASH) || defined(USE_SONOFF_SC) || defined(USE_ARMTRONIX_DIMMERS) || defined(USE_PS_16_DZ) || defined(USE_SONOFF_IFAN) || defined(USE_BUZZER) || defined(USE_ARILUX_RF) || defined(USE_EXS_DIMMER) || defined(USE_DEVICE_GROUPS) || defined(USE_PWM_DIMMER) || defined(USE_SONOFF_D1) || defined(USE_SHELLY_DIMMER) || defined(USE_LIGHT) || defined(USE_WS2812) || defined(USE_HLW8012) || defined(USE_BL09XX) || defined(USE_CSE7761) || defined(USE_UNISHOX_COMPRESSION) || defined(USE_SENDMAIL) || defined(USE_TELEGRAM)
  #error "POW Slim: an unrelated Tasmota driver is still enabled"
#endif

#endif  // OTTELLO_POW_SLIM
