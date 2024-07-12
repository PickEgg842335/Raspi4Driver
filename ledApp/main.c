#include <stdio.h>
#include "./interface/include/colorledApi.h"

int main(void)
{
    while(1)
    {
        sfSetLedOutput(LED_BLUE, 1);
        sfSetLedOutput(LED_GREEN, 0);
        sfSetLedOutput(LED_YELLOW, 0);
        sfSetLedOutput(LED_RED, 0);
        sleep(1);
        sfSetLedOutput(LED_BLUE, 1);
        sfSetLedOutput(LED_GREEN, 1);
        sfSetLedOutput(LED_YELLOW, 0);
        sfSetLedOutput(LED_RED, 0);
        sleep(1);
        sfSetLedOutput(LED_BLUE, 1);
        sfSetLedOutput(LED_GREEN, 1);
        sfSetLedOutput(LED_YELLOW, 1);
        sfSetLedOutput(LED_RED, 0);
        sleep(1);
        sfSetLedOutput(LED_BLUE, 1);
        sfSetLedOutput(LED_GREEN, 1);
        sfSetLedOutput(LED_YELLOW, 1);
        sfSetLedOutput(LED_RED, 1);
        sleep(1);
        sfSetLedOutput(LED_BLUE, 0);
        sfSetLedOutput(LED_GREEN, 1);
        sfSetLedOutput(LED_YELLOW, 1);
        sfSetLedOutput(LED_RED, 1);
        sleep(1);
        sfSetLedOutput(LED_BLUE, 0);
        sfSetLedOutput(LED_GREEN, 0);
        sfSetLedOutput(LED_YELLOW, 1);
        sfSetLedOutput(LED_RED, 1);
        sleep(1);
        sfSetLedOutput(LED_BLUE, 0);
        sfSetLedOutput(LED_GREEN, 0);
        sfSetLedOutput(LED_YELLOW, 0);
        sfSetLedOutput(LED_RED, 1);
        sleep(1);
        sfSetLedOutput(LED_BLUE, 0);
        sfSetLedOutput(LED_GREEN, 0);
        sfSetLedOutput(LED_YELLOW, 0);
        sfSetLedOutput(LED_RED, 0);
        sleep(1);
    }
    return 0;
}