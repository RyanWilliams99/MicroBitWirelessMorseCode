# NOTE: This file is generated by yotta: changes will be overwritten!

cmake_minimum_required(VERSION 2.8.11)

include_directories("/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source")


set(YOTTA_AUTO_BLE-NRF51822_CPP_FILES
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle_advertising.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xGattClient.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xServiceDiscovery.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/custom/custom_helper.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xCharacteristicDescriptorDiscoverer.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xGattServer.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xDiscoveredCharacteristic.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle_discovery.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle_gap.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle_security.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xn.cpp"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xGap.cpp"
)
# force dependency on the config header for cpp files, which CMake otherwise wouldn't track:
set_property(SOURCE ${YOTTA_AUTO_BLE-NRF51822_CPP_FILES} PROPERTY OBJECT_DEPENDS "/home/ryan/MicroBit/microbitwirelessmorsecode/build/bbc-microbit-classic-gcc/yotta_config.h")
set(YOTTA_AUTO_BLE-NRF51822_HEADER_FILES
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xGattServer.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle_security.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xGattClient.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/common/compiler.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/projectconfig.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/common/ble_error.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/custom/custom_helper.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/common/ansi_escape.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/common/assertion.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle_advertising.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xn.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle_discovery.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/common/common.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xServiceDiscovery.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xCharacteristicDescriptorDiscoverer.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xDiscoveredCharacteristic.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/btle/btle_gap.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xGap.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/nRF5xSecurityManager.h"
    "/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/common/binary.h"
)
# force dependency on the config header for header files, which CMake otherwise wouldn't track:
set_property(SOURCE ${YOTTA_AUTO_BLE-NRF51822_HEADER_FILES} PROPERTY OBJECT_DEPENDS "/home/ryan/MicroBit/microbitwirelessmorsecode/build/bbc-microbit-classic-gcc/yotta_config.h")


add_library(ble-nrf51822
    ${YOTTA_AUTO_BLE-NRF51822_CPP_FILES}
    ${YOTTA_AUTO_BLE-NRF51822_HEADER_FILES}
)

yotta_postprocess_target(LIBRARY ble-nrf51822)



target_link_libraries(ble-nrf51822
    ble
    nrf51-sdk
)

include("/home/ryan/MicroBit/microbitwirelessmorsecode/yotta_modules/ble-nrf51822/source/supress-warnings.cmake")
