cmake_minimum_required(VERSION 3.20.0)
project(azdpsprovision VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(azdpsprovision azdpsprovision.cpp)


find_package(eclipse-paho-mqtt-c CONFIG REQUIRED)
target_link_libraries(azdpsprovision PRIVATE eclipse-paho-mqtt-c::paho-mqtt3a-static eclipse-paho-mqtt-c::paho-mqtt3c-static eclipse-paho-mqtt-c::paho-mqtt3as-static eclipse-paho-mqtt-c::paho-mqtt3cs-static)

find_package(OpenSSL REQUIRED)
target_link_libraries(azdpsprovision PRIVATE OpenSSL::SSL OpenSSL::Crypto)

include(FetchContent)
FetchContent_Declare(
    azurecsdk
    URL      https://github.com/Azure/azure-sdk-for-c/archive/refs/tags/1.5.0.tar.gz
    URL_HASH MD5=396ea77b3108c4a2125924f77d4d9a3e
)
FetchContent_MakeAvailable(azurecsdk)
# FetchContent_Declare(
#     azurecsdk
#     GIT_REPOSITORY https://github.com/Azure/azure-iot-sdk-c.git # 
#     GIT_TAG        
# )


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
