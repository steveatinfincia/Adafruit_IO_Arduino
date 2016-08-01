#ifdef ESP8266

#include "AdafruitIO_ESP8266.h"

AdafruitIO_ESP8266::AdafruitIO_ESP8266(const char *ssid, const char *pass):AdafruitIO()
{
  _ssid = ssid;
  _pass = pass;
  _client = new WiFiClientSecure;
  _mqtt = new Adafruit_MQTT_Client(_client, _host, _port);
}

AdafruitIO_ESP8266::AdafruitIO_ESP8266(const __FlashStringHelper *ssid, const __FlashStringHelper *pass):AdafruitIO()
{
  _ssid = (const char*)ssid;
  _pass = (const char*)pass;
  _client = new WiFiClientSecure;
  _mqtt = new Adafruit_MQTT_Client(_client, _host, _port);
}

void AdafruitIO_ESP8266::_connect()
{

  delay(100);
  WiFi.begin(_ssid, _pass);
  delay(100);
  _status = AIO_NET_DISCONNECTED;

}

aio_status_t AdafruitIO_ESP8266::networkStatus()
{

  switch(WiFi.status()) {
    case WL_CONNECTED:
      return AIO_NET_CONNECTED;
    case WL_CONNECT_FAILED:
      return AIO_NET_CONNECT_FAILED;
    case WL_IDLE_STATUS:
      return AIO_IDLE;
    default:
      return AIO_NET_DISCONNECTED;
  }

}

#endif // ESP8266
