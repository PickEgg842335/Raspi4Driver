#include <stdio.h>
#include "./interface/include/dht11Api.h"

int main(void)
{
    float fDht11Data[2];
    int wRet;
    while(1)
    {
        wRet = swfGetDht11HumidityTemparture(fDht11Data);
        if(wRet >= 0)
        {
            printf("H = %3.1f, T = %3.1f\n", fDht11Data[0], fDht11Data[1]);
        }
        sleep(2);
    }
    return 0;
}