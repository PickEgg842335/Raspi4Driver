#include <stdio.h>
#include "./interface/include/adxl485api.h"

int main(void)
{
    int wDatax, wDatay ,wDataz;
    sfinitaladxl485();

    while(1)
    {
        wDatax = sfwGetadxl485DataX();
        wDatay = sfwGetadxl485DataY();
        wDataz = sfwGetadxl485DataZ();
        printf("ID = %x\n", sfubGetadxl485DeviceId());
        printf("DataX = %d\n",wDatax);
        printf("DataY = %d\n",wDatay);
        printf("DataZ = %d\n",wDataz);
        sleep(1);
    }
    return 0;
}