#include    <linux/i2c.h>
#include    <linux/i2c-dev.h>
#include    <sys/ioctl.h>
#include    <stdbool.h>
#include    <stdio.h>
#include    <fcntl.h>
#include    <string.h>
#include    <unistd.h>
#include    <malloc.h>

#define  LED_BLUE       0
#define  LED_GREEN      1
#define  LED_YELLOW     2
#define  LED_RED        3

extern void sfinitaladxl485(void);
extern unsigned char sfubGetadxl485DeviceId(void);
unsigned int sfuwGetadxl485DataX(void);
unsigned int sfuwGetadxl485DataY(void);
unsigned int sfuwGetadxl485DataZ(void);