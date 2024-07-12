#include <stdio.h>
#include <fcntl.h>

#define  LED_BLUE       0
#define  LED_GREEN      1
#define  LED_YELLOW     2
#define  LED_RED        3

extern int  sfSetLedOutput(int wLedColor,char bValue);