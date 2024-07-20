#include    <stdio.h>
#include    <stdbool.h>
#include    <unistd.h>
#include    "./interface/include/wbs2812bapi.h"

int main(void)
{
    unsigned char ubRBBData[2][3] = {{255, 0, 0} , {0, 255, 0}};
    unsigned char flag[2] = {false, false};
    unsigned char index[2] = {1, 2};
    int i;

    while(1)
    {
        sfOpenWbs2812bLedEnable(true);
        sfSetWbs2812bQty(6);
        sfSetWbs2812bRGBData(1,ubRBBData[0]);
        sfSetWbs2812bRGBData(2,ubRBBData[1]);
        sfSetWbs2812bStartDisplay();
        usleep(10000);
        for(i = 0; i < 2; i++)
        {
            if(flag[i] == false)
            {
                ubRBBData[i][index[i]]++;
                if(ubRBBData[i][index[i]] == 255)
                {
                    flag[i] = true;
                    if(index[i] == 0)
                    {
                        index[i] = 2;
                    }
                    else
                    {
                        index[i]--;
                    }
                }
            }
            else
            {
                ubRBBData[i][index[i]]--;
                if(ubRBBData[i][index[i]] == 0)
                {
                    flag[i] = false;
                    index[i] = (index[i] + 2) % 3;
                }
            }
        }
        sfOpenWbs2812bLedEnable(false);
    }
    return 0;
}