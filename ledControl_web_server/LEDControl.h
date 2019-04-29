#ifndef LEDControl_h
#define LEDControl_h

#include <string>
#include "Communication.h"

class LEDControl
{
public:
  LEDControl();
  LEDControl(std::string controlString);
  void setBrightness(int brightness);
  void setRed(int red);
  void setGreen(int green);
  void setBlue(int blue);
  int getBrightness();
  int getRed();
  int getGreen();
  int getBlue();
  ~LEDControl();

private:
  int _brightness;
  int _red;
  int _green;
  int _blue;
  int _strobe;
  int _sWaveform;
  int _sHeight;
  int _sFreq;
  int _sAmpl;
  int _sOffset;
  int _audioSync;
  int _ledControl;
  int _LEDs;
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
