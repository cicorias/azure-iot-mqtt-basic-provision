cmake_minimum_required(VERSION 3.20.0)
project(azdpsprovision VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(azdpsprovision azdpsprovision.cpp)

find_package(eclipse-paho-mqtt-c CONFIG REQUIRED)
target_link_libraries(azdpsprovision PRIVATE eclipse-paho-mqtt-c::paho-mqtt3a-static eclipse-paho-mqtt-c::paho-mqtt3c-static eclipse-paho-mqtt-c::paho-mqtt3as-static eclipse-paho-mqtt-c::paho-mqtt3cs-static)

find_package(OpenSSL REQUIRED)
target_link_libraries(azdpsprovision PRIVATE OpenSSL::SSL OpenSSL::Crypto)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")
include(AddAzureSDKforC)
target_link_libraries(azdpsprovision PRIVATE az_core)


# Azure IoT Samples Library
add_library (az_iot_sample_common
  ${CMAKE_CURRENT_LIST_DIR}/iot_sample_common.c
)

target_link_libraries(az_iot_sample_common
  PUBLIC
    az::iot::hub
    az::iot::provisioning
)

target_link_libraries(az_iot_sample_common
  PUBLIC
    eclipse-paho-mqtt-c::paho-mqtt3cs-static
    OpenSSL::SSL
    OpenSSL::Crypto
)

#add_library (az::iot::sample::common ALIAS az_iot_sample_common)

# Provisioning (Certificates) Sample from SDK
add_executable (paho_iot_provisioning_sample
  ${CMAKE_CURRENT_LIST_DIR}/paho_iot_provisioning_sample.c
)

target_link_libraries(paho_iot_provisioning_sample
  PRIVATE
    az_iot_sample_common
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
