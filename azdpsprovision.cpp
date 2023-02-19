#include <iostream>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <MQTTClient.h>

#include <azure/az_core.h>
#include <azure/az_iot.h>

#include "aziothelper.h"

// Functions
static void create_and_configure_mqtt_client(void);
static void connect_mqtt_client_to_provisioning_service(void);
static void subscribe_mqtt_client_to_provisioning_service_topics(void);
static void register_device_with_provisioning_service(void);
static void receive_device_registration_status_message(void);
static void disconnect_mqtt_client_from_provisioning_service(void);


int main(int, char**) {
    std::cout << "Hello, world!\n";

    create_and_configure_mqtt_client();
    IOT_SAMPLE_LOG_SUCCESS("Client created and configured.");

    connect_mqtt_client_to_provisioning_service();
    IOT_SAMPLE_LOG_SUCCESS("Client connected to provisioning service.");

    subscribe_mqtt_client_to_provisioning_service_topics();
    IOT_SAMPLE_LOG_SUCCESS("Client subscribed to provisioning service topics.");

    register_device_with_provisioning_service();
    IOT_SAMPLE_LOG_SUCCESS("Client registering with provisioning service.");

    receive_device_registration_status_message();
    IOT_SAMPLE_LOG_SUCCESS("Client received registration status message.");

    disconnect_mqtt_client_from_provisioning_service();
    IOT_SAMPLE_LOG_SUCCESS("Client disconnected from provisioning service.");

    return 0;
}


static void create_and_configure_mqtt_client(void)
{
  int rc;
}

static void connect_mqtt_client_to_provisioning_service(void) {
    int rc;
}

static void subscribe_mqtt_client_to_provisioning_service_topics(void){
    int rc;
}

static void register_device_with_provisioning_service(void) {
    int rc;
}

static void receive_device_registration_status_message(void){
    int rc;
}

static void disconnect_mqtt_client_from_provisioning_service(void){
    int rc;
}
