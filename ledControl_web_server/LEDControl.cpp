#include "LEDControl.h"

LEDControl::LEDControl()
{
    brightness = 0;
    red = 0;
    green = 0;
    blue = 0;
    strobe = 0;
    sWaveform = 0;
    sHeight = 0;
    sFreq = 0;
    sAmpl = 0;
    sOffset = 0;
    audioSync = 0;
    ledControl = 0;
    LEDs = 0;
}

LEDControl::LEDControl(std::string controlString)
{
    //needs to change -> not nice with hardcoded values
    brightness = stringToInteger(controlString[1],
                                 controlString[2],
                                 controlString[3]);
    red = stringToInteger(controlString[5],
                          controlString[6],
                          controlString[7]); // EACH COLOR PICKS OUT THEIR VAlUES FROM THE CONTROLSTRING
    green = stringToInteger(controlString[9],
                            controlString[10],
                            controlString[11]);
    blue = stringToInteger(controlString[13],
                           controlString[14],
                           controlString[15]);
    strobe = stringToInteger(controlString[offsetStrobe + 1]);
    sWaveform = stringToInteger(controlString[offsetSW + 1]);
    sHeight = stringToInteger(controlString[offsetSH + 1],
                              controlString[offsetSH + 2],
                              controlString[offsetSH + 3]);
    sFreq = stringToInteger(controlString[offsetSF + 1],
                            controlString[offsetSF + 2],
                            controlString[offsetSF + 3]);
    sAmpl = stringToInteger(controlString[offsetSA + 1],
                            controlString[offsetSA + 2],
                            controlString[offsetSA + 3]);
    sOffset = stringToInteger(controlString[offsetAudioSync + 1],
                              controlString[offsetAudioSync + 2],
                              controlString[offsetAudioSync + 3]);
    audioSync = stringToInteger(controlString[offsetLEDControl + 1]);
    ledControl = stringToInteger(controlString[offsetLEDControl + 1]);
    LEDs = stringToInteger(controlString[offsetLEDs + 1],
                           controlString[offsetLEDs + 2],
                           controlString[offsetLEDs + 3],
                           controlString[offsetLEDs + 4],
                           controlString[offsetLEDs + 5],
                           controlString[offsetLEDs + 6],
                           controlString[offsetLEDs + 7],
                           controlString[offsetLEDs + 8],
                           controlString[offsetLEDs + 9],
                           controlString[offsetLEDs + 10]);
}

int LEDControl::getBrightness()
{
    return brightness;
}
int LEDControl::getRed()
{
    return red;
}
int LEDControl::getGreen()
{
    return green;
}
int LEDControl::getBlue()
{
    return blue;
}
