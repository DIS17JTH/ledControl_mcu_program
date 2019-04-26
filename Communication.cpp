#include "Communication.h"

int stringToInteger(char c1, char c2, char c3)
{
    int i1 = integerLUT(c1);
    int i2 = integerLUT(c2);
    int i3 = integerLUT(c3);

    return i1 * 100 + i2 * 10 + i3;
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
