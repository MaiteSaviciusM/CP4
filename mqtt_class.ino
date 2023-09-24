/**
 ******************************************************************************
   @file        mqtt_class.ino
   @author      Maite Savicius Murilo Obinata
   @copyright   None
   @date        24.09.2023
   @version     1.0
   @brief       Arduino Sketch to send data to the Tago.io application throug
                MQTT protocol
 ******************************************************************************
*/
/* Private includes ----------------------------------------------------------*/
#include <ArduinoJson.h>    // Lib to format JSON Document
#include "EspMQTTClient.h"  // Lib to comunicate MQTT from ESP
#include "DHT.h";           // Lib to access the DHT sensor
/* Board Configuration--------------------------------------------------------*/
char temperatura[100];
char umidade    [100];
char luminosidade[100];
/* DHT Configuration----------------------------------------------------------*/
DHT dht (13, DHT11); // The sensor is connect under the GPIO 13
float dhtTemperature = 0;
float dhtHumidity = 0;
float dhtLuminosity = 0;
//MQTT and WiFi configuration
EspMQTTClient client
(
  "Maitê",        //nome da sua rede Wi-Fi
  "M07012005",  //senha da sua rede Wi-Fi
  "mqtt.tago.io",       //Endereço do servidor MQTT
  "Default",            //User é sempre default pois vamos usar token
  "b9ff66e3-de9b-44b8-b503-ae9a4982b945",// Código do Token
  "esp32",         //Nome do device
  1883                  //Porta de comunicação padrao
);
void setup()
{
  //dht.begin();
}
// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{}
//loop do programa
void loop()
{
  //Getting temperature and Humidity data
  getDhtData();
  StaticJsonDocument<300> TemperaturaJson;
  TemperaturaJson["variable"] = "temperatura";
  TemperaturaJson["value"] = dhtTemperature;
  StaticJsonDocument<300> UmidadeJson;
  UmidadeJson["variable"] = "umidade";
  UmidadeJson["value"] = dhtHumidity;
  StaticJsonDocument<300> LuminosidadeJson;
  luminosidadeJson["variable"] = "luminosidade";
  luminosidadeJson["value"] = dhtLuminosity;
  
  serializeJson(TemperaturaJson, temperatura);
  serializeJson(UmidadeJson, umidade);
  serializeJson(LuminosidadeJson, luminosidade)
  
  client.publish("temperatura", temperatura); 
  client.publish("umidade", umidade);
  client.publish("luminosidade", luminosidade)
  delay(5000);
  client.loop();
}
/*
   @brief Gets the Temp/Hum data
*/
void getDhtData(void) {
}