# azure-iot-mqtt-basic-provision
simple azure IoT DPS provision validation example


```
CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=/usr/local/vcpkg/scripts/buildsystems/vcpkg.cmake"
```

```cmake
# this is heuristically generated, and may not be correct
find_package(eclipse-paho-mqtt-c CONFIG REQUIRED)
    target_link_libraries(main PRIVATE eclipse-paho-mqtt-c::paho-mqtt3a-static eclipse-paho-mqtt-c::paho-mqtt3c-static eclipse-paho-mqtt-c::paho-mqtt3as-static eclipse-paho-mqtt-c::paho-mqtt3cs-static)
```
    

## Consuming the Azure C SDK

See [Azure SDK for C: consume with cmake](https://github.com/Azure/azure-sdk-for-c#consume-sdk-for-c-as-dependency-with-cmake)