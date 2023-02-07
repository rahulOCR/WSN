#include <ESP8266WiFi.h>
#include <Arduino.h>

#ifndef PAYLOAD_MAX_SIZE
#define PAYLOAD_MAX_SIZE 128
#endif

class wsn
{

    private:
   
    
    char* _ssid = "SSID";
    char* _password = "PASS";
    char* _host = "192.168.0.23";
    uint16_t _port = 8090;


    public:
    WiFiClient client;
     // Constructor
     wsn(char*, char*, char*, uint16_t);
     ~wsn();
    
    /*
    return 1 if successfully connected to server else 0
    */
    int connect();
    
    /*
    return 1 if connected to server else 0
    */

    int ServerConnected();
    
    /*
    return 1 if connected to AP else 0
    */
    int isconnected();

    /*
    return size of buffer comming from server
    */
    char read();
    
    int available();
    /*
    return 1 if successfully send buffer to server else 0
    */
    int send(char*);
    
    void begin();
    
    IPAddress whoami();

};
