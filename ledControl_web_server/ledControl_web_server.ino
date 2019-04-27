#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#include "Communication.h"
#include "LEDControl.h"

#define LISTENINGPORT 8001
#define PIN 5
#define NUM_LEDS 400

const char *ssid = "Telia-72FF90";
const char *password = "E24366EA91";
char controlString[115]; // controlstring picks up the string that is sent from the app

bool isLit = false;

//move constructor for WiFi server
WiFiServer server(LISTENINGPORT);
//declaration of global variables
WiFiClient LEDclient;
Adafruit_NeoPixel LEDstrip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800); // initializes the LED-trip

bool ledIsOn(LEDControl &ledControl);
void applySettings(LEDControl &ledControl, Adafruit_NeoPixel &LEDstrip);

void setup()
{
  //PINOUT conf
  pinMode(LED_BUILTIN, OUTPUT);

  //serial communication
  Serial.begin(9600);
  Serial.println();
  
  //initialize LED strip
  LEDstrip.begin();
  LEDstrip.show();

  WiFi.begin(ssid, password);

  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) // WAITING FOR CONNECTION, FAST BLINKING
  {
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print(".");
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
  //update server status
  LEDclient = server.available();

  if (LEDclient)
  {
    if (LEDclient.connected()) //logging connected
    {
      Serial.println("LEDclient Connected");
    }
    while (LEDclient.connected())
    {
      int i = 0;                        // I IS USED TO ITERATE THROUGH THE STRING OF DATA SENT FROM THE APP, IT IS RESET HERE
      while (LEDclient.available() > 0) // EVER ASCII CHARACTER SENT FROM THE APP IS ADDED TO AVAILABLE.
      {
        c = LEDclient.read();
        controlString[i] = c;
        i++;
      }

      LEDControl ledControl(controlString);
      //Serial.println(controlString);
      //Serial.println(ledControl.getRed();
      if (ledIsOn(ledControl)) // YOU CAN REMOVE THESE IF & ELSE STATMENTS IF YOU WANT. THEY ARE FOR TEST PURPOSES ONLY
      {
          digitalWrite(LED_BUILTIN, isLit);
          isLit = true;
          applySettings(ledControl, LEDstrip);
      }
      else
      {
        digitalWrite(LED_BUILTIN, isLit);
        isLit = false;
      }
    }
    Serial.println("LEDclient Disconnecting");
    LEDclient.stop();
  }
  else //not connected
  {
    // toggle light
    digitalWrite(LED_BUILTIN, isLit);
    isLit = !isLit;
    delay(1000);
  }
}

bool ledIsOn(LEDControl &ledControl)
{
  if((ledControl.getRed() != 0 && ledControl.getGreen() != 0 && ledControl.getBlue() != 0) || ledControl.getBrightness() != 0)
  {
    return true;
  }
  return false;
}

//set pixels on the LEDStrip
void applySettings(LEDControl &ledControl, Adafruit_NeoPixel &LEDstrip)
{
  int brightness = ledControl.getBrightness();
  int red = ledControl.getRed();
  int green = ledControl.getGreen();
  int blue = ledControl.getBlue();
  //Serial.println(red);
  //Serial.println(blue);
  //Serial.println(green);

  for (int j = 0; j < NUM_LEDS; j++) // ITERATES THROUGH EVERY LED
  {
    LEDstrip.setPixelColor(j,
                           getValueSetByBrightness(red, brightness),
                           getValueSetByBrightness(green, brightness),
                           getValueSetByBrightness(blue, brightness)); // SETS EVERY LED TO CORRECT COLOR
  }

  LEDstrip.show(); // SHOWS ALL THE LED THAT YOU'VE SET
}
