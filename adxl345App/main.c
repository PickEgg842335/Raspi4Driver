#include <stdio.h>
#include "./interface/include/adxl485api.h"

int main(void)
{
    sfinitaladxl485();

    while(1)
    {
        printf("ID = %x\n", sfubGetadxl485DeviceId());
        printf("DataX = %d\n",sfuwGetadxl485DataX());
        printf("DataY = %d\n",sfuwGetadxl485DataY());
        printf("DataZ = %d\n",sfuwGetadxl485DataZ());
        sleep(1);
    }
    return 0;
}