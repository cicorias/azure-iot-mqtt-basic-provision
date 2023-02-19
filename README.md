# azure-iot-mqtt-basic-provision
simple azure IoT DPS provision validation example


## Initial Run

### Repair vcpkg clone
The clone of vcpkg is not full depth and the azure-c-sdk requires it to be set to a specific tag/has.

```
cd /usr/local/vcpkg
git fetch --unshallow
```

### Set vcpkg to tag

```bash
#see the azure c sdk for this setting.
cd /usr/local/vcpkg
git checkout tags/2022.10.19

```


### Set .vscode/setting.json
CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=/usr/local/vcpkg/scripts/buildsystems/vcpkg.cmake"

```json
{
    "cmake.buildDirectory": "${workspaceFolder}/build",
    "cmake.configureArgs": [
        "-DCMAKE_TOOLCHAIN_FILE=/usr/local/vcpkg/scripts/buildsystems/vcpkg.cmake"
    ],
    "files.associations": {
        "iot_sample_common.h": "c"
    }
}
```


### Install some vcpkg

>NOTE: this takes time for the pull and build
```
cd /usr/local/vcpkg
vcpkg install openssl
vcpkg install paho-mqtt
```

```cmake
# this is heuristically generated, and may not be correct
find_package(eclipse-paho-mqtt-c CONFIG REQUIRED)
    target_link_libraries(main PRIVATE eclipse-paho-mqtt-c::paho-mqtt3a-static eclipse-paho-mqtt-c::paho-mqtt3c-static eclipse-paho-mqtt-c::paho-mqtt3as-static eclipse-paho-mqtt-c::paho-mqtt3cs-static)
```



## Consuming the Azure C SDK

See [Azure SDK for C: consume with cmake](https://github.com/Azure/azure-sdk-for-c#consume-sdk-for-c-as-dependency-with-cmake)


```bash
mkdir certs
cd certs
cp /workspaces/azure-iot-mqtt-basic-provision/build/_deps/azuresdkforc-src/sdk/samples/iot/x509_config.cfg .
openssl ecparam -out device_ec_key.pem -name prime256v1 -genkey
openssl req -new -days 30 -nodes -x509 -key device_ec_key.pem -out device_ec_cert.pem -extensions client_auth -config x509_config.cfg -subj "/CN=paho-sample-device1"
openssl x509 -noout -text -in device_ec_cert.pem

rm -f device_cert_store.pem
cat device_ec_cert.pem device_ec_key.pem > device_cert_store.pem

openssl x509 -noout -fingerprint -in device_ec_cert.pem | sed 's/://g'| sed 's/\(SHA1 Fingerprint=\)//g' | tee fingerprint.txt

export AZ_IOT_DEVICE_X509_CERT_PEM_FILE_PATH=$(pwd)/device_cert_store.pem

```

