#include "LEDControl.h"

LEDControl::LEDControl()
{
    _brightness = 0;
    _red = 0;
    _green = 0;
    _blue = 0;
    _strobe = 0;
    _sWaveform = 0;
    _sHeight = 0;
    _sFreq = 0;
    _sAmpl = 0;
    _sOffset = 0;
    _audioSync = 0;
    _ledControl = 0;
    _LEDs = 0;
}

LEDControl::LEDControl(std::string controlString)
{

    //needs to change -> not nice with hardcoded values
    setBrightness(stringToInteger(controlString[1],
                                  controlString[2],
                                  controlString[3]));
    setRed(stringToInteger(controlString[5],
                           controlString[6],
                           controlString[7])); // EACH COLOR PICKS OUT THEIR VAlUES FROM THE CONTROLSTRING
    setGreen(stringToInteger(controlString[9],
                             controlString[10],
                             controlString[11]));
    setBlue(stringToInteger(controlString[13],
                            controlString[14],
                            controlString[15]));

    _strobe = stringToInteger(controlString[offsetStrobe + 1]);
    _sWaveform = stringToInteger(controlString[offsetSW + 1]);
    _sHeight = stringToInteger(controlString[offsetSH + 1],
                               controlString[offsetSH + 2],
                               controlString[offsetSH + 3]);
    _sFreq = stringToInteger(controlString[offsetSF + 1],
                             controlString[offsetSF + 2],
                             controlString[offsetSF + 3]);
    _sAmpl = stringToInteger(controlString[offsetSA + 1],
                             controlString[offsetSA + 2],
                             controlString[offsetSA + 3]);
    _sOffset = stringToInteger(controlString[offsetAudioSync + 1],
                               controlString[offsetAudioSync + 2],
                               controlString[offsetAudioSync + 3]);
    _audioSync = stringToInteger(controlString[offsetLEDControl + 1]);
    _ledControl = stringToInteger(controlString[offsetLEDControl + 1]);
    _LEDs = stringToInteger(controlString[offsetLEDs + 1],
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

void LEDControl::setBrightness(int brightness)
{
    _brightness = brightness;
}

void LEDControl::setRed(int red)
{
    _red = red;
}

void LEDControl::setGreen(int green)
{
    _green = green;
}

void LEDControl::setBlue(int blue)
{
    _blue = blue;
}

int LEDControl::getBrightness()
{
    return _brightness;
}

int LEDControl::getRed()
{
    return _red;
}

int LEDControl::getGreen()
{
    return _green;
}

int LEDControl::getBlue()
{
    return _blue;
}

LEDControl::~LEDControl()
{
}