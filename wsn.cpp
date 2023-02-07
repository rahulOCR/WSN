#include "wsn.h"

wsn::wsn(char* ssid, char* password, char* host, uint16_t port)
{
    _ssid = ssid;
    _password = password;
    _host = host;
    _port = port;
    
}

void wsn::begin()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid, _password);

}


int wsn::isconnected()
{
    return WiFi.status() == WL_CONNECTED;
}

int wsn::ServerConnected()
{
    if(! isconnected())
    return 0;

    return client.connected();
}

IPAddress wsn::whoami()
{
    return WiFi.localIP();
}

int wsn::connect()
{
    return client.connect(_host, _port);
}


char wsn::read()
{

    return static_cast<char>(client.read());

}

int wsn::send(char* pac)
{
    return client.write(pac);
}


wsn::~wsn()
{
    client.stop();
}

int wsn::available()
{
    return client.available();
}
