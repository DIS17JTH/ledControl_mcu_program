#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#include "Communication.h"

const char *ssid = "Telia-72FF90";
const char *password = "E24366EA91";
char controlString[115]; // controlstring picks up the string that is sent from the app

#define LISTENINGPORT 8001
#define PIN 5
#define NUM_LEDS 300

//move constructor for WiFi server
WiFiServer server(LISTENINGPORT);
//declaration of global variables
WiFiClient LEDclient;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800); // initializes the LED-trip

void setup()
{
  strip.begin();
  strip.show();
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(ssid, password);

  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) // WAITING FOR CONNECTION, FAST BLINKING
  {
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println(".");
  }

  if (WiFi.status() == WL_CONNECTED) // CONNECTION ESSTABLISHED; BLINK ONCE
  {
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Connected");
  }

  server.begin();

  //controlString = "w000r000g000b000";
}

void loop()
{
  char c;
  int red, green, blue;

  //update server status
  LEDclient = server.available();

  //test blink
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);

  if (LEDclient)
  {
    Serial.println("LEDclient Connected");

    while (LEDclient.connected())
    {
      int i = 0;                        // I IS USED TO ITERATE THROUGH THE STRING OF DATA SENT FROM THE APP, IT IS RESET HERE
      while (LEDclient.available() > 0) // EVER ASCII CHARACTER SENT FROM THE APP IS ADDED TO AVAILABLE.
      {
        c = LEDclient.read();
        controlString[i] = c;
        i++;
      }

      red = stringToInteger(controlString[5], controlString[6], controlString[7]); // EACH COLOR PICKS OUT THEIR VAlUES FROM THE CONTROLSTRING
      green = stringToInteger(controlString[9], controlString[10], controlString[11]);
      blue = stringToInteger(controlString[13], controlString[14], controlString[15]);
      if (red == 0 && green == 0 && blue == 0) // YOU CAN REMOVE THESE IF & ELSE STATMENTS IF YOU WANT. THEY ARE FOR TEST PURPOSES ONLY
        digitalWrite(LED_BUILTIN, HIGH);
      else
        digitalWrite(LED_BUILTIN, LOW);
      for (int j = 0; j < NUM_LEDS; j++) // ITERATES THROUGH EVERY LED
      {
        strip.setPixelColor(j, red, green, blue); // SETS EVERY LED TO CORRECT COLOR
      }
      strip.show(); // SHOWS ALL THE LED THAT YOU'VE SET
    }
    Serial.println("LEDclient Disconnecting");
    LEDclient.stop();
  }
}