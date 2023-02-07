#include <wsn.h>

char* ssid = "your ssid";
char* pass = "your pass";
char* host = "192.168.0.23";
uint16_t port = 8080;
char pac[12];

wsn mynetwork(ssid, pass, host, port);

void setup()
{
  int s = 0;
    Serial.begin(115200);
    mynetwork.begin();
    while(! mynetwork.isconnected())
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    if(mynetwork.connect())
    {
        Serial.println("Connected to server!!");
    }

   
}


void loop()
{

   mynetwork.send("Hello from esp");
   recieve();
   timeout();

}

void recieve()
{

     // Reading upcomming packets
    int i = 0;
    while (mynetwork.available()) 
    {
        char ch =mynetwork.read();
        pac[i] = ch;
        i += 1;
    }
    Serial.println(pac);

}

void timeout()
{
  unsigned long timeout = millis();
  while (mynetwork.client.available() == 0) 
  {
    if (millis() - timeout > 5000) 
    {
      Serial.println(">>> Client Timeout !");
      mynetwork.client.stop();
      delay(60000);
      return;
    }
  }
}
