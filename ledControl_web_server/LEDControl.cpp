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
    _LEDControl = 0;
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
    _LEDControl = stringToInteger(controlString[offsetLEDControl + 1]);
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

//SETTERS
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
void LEDControl::setStrobe(int strobe)
{
    _strobe = strobe;
}
void LEDControl::setSWaveform(int sWaveform)
{
    _sWaveform = sWaveform;
}
void LEDControl::setSHeight(int sHeight)
{
    _sHeight = sHeight;
}
void LEDControl::setSFreq(int sFreq)
{
    _sFreq = sFreq;
}
void LEDControl::setSAmpl(int sAmpl)
{
    _sAmpl = sAmpl;
}
void LEDControl::setSOffset(int sOffset)
{
    _sOffset = sOffset;
}
void LEDControl::setAudioSync(int audioSync)
{
    _audioSync = audioSync;
}
void LEDControl::setLEDControl(int LEDControl)
{
    _LEDControl = LEDControl;
}
void LEDControl::setLEDs(int LEDs)
{
    _LEDs = LEDs;
}
//GETTERS
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
int LEDControl::getSWaveform()
{
    return _sWaveform;
}
int LEDControl::getSHeight()
{
    return _sHeight;
}
int LEDControl::getSFreq()
{
    return _sFreq;
}
int LEDControl::getSAmpl()
{
    return _sAmpl;
}
int LEDControl::getSOffset()
{
    return _sOffset;
}
int LEDControl::getAudioSync()
{
    return _audioSync;
}
int LEDControl::getLEDControl()
{
    return _LEDControl;
}
/*bool LEDControl::*getLEDarr()
{
    return NULL;
}*/

LEDControl::~LEDControl()
{
}
