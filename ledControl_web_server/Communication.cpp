#include "Communication.h"

inline int getValueSetByBrightness(int value, int brightness)
{
    return (brightness * value) / 255;
}

int stringToInteger(char c1)
{
    return integerLUT(c1);
}
int stringToInteger(char c1, char c2, char c3)
{
    int i1 = integerLUT(c1);
    int i2 = integerLUT(c2);
    int i3 = integerLUT(c3);

    return i1 * 100 + i2 * 10 + i3;
}

int stringToInteger(char c1, char c2, char c3, char c4, char c5, char c6, char c7, char c8, char c9, char c10)
{
    int i1 = integerLUT(c1);
    int i2 = integerLUT(c2);
    int i3 = integerLUT(c3);
    int i4 = integerLUT(c4);
    int i5 = integerLUT(c5);
    int i6 = integerLUT(c6);
    int i7 = integerLUT(c7);
    int i8 = integerLUT(c8);
    int i9 = integerLUT(c9);
    int i10 = integerLUT(c10);

    return i2 * 1000000000 + i2 * 100000000 + i3 * 10000000 + i4 * 1000000 + i5 * 100000 + i6 * 10000 + i7 * 1000 + i8 * 100 + i9 * 10 + i10;
}

int integerLUT(char c)
{
    switch (c)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    }
    return 0;
}
