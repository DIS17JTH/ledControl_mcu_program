#ifndef LEDControl_h
#define LEDControl_h

#include <string>
#include "Communication.h"

class LEDControl
{
public:
  LEDControl();
  LEDControl(std::string controlString);
  int getBrightness();
  int getRed();
  int getGreen();
  int getBlue();

private:
  int brightness;
  int red;
  int green;
  int blue;
  int strobe;
  int sWaveform;
  int sHeight;
  int sFreq;
  int sAmpl;
  int sOffset;
  int audioSync;
  int ledControl;
  int LEDs;
  const int offsetStrobe = 16;
  const int offsetSW = 18;
  const int offsetSH = 22;
  const int offsetSF = 26;
  const int offsetSA = 30;
  const int offsetSO = 34;
  const int offsetAudioSync = 36;
  const int offsetLEDControl = 38;
  const int offsetLEDs = 40;
};

#endif
