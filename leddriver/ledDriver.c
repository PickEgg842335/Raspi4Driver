#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/gpio.h> 
#include <linux/interrupt.h>

#include "./include/gpiopin.h"

//LED is connected to this GPIO
#define PIN Rpi4_GPIO17
#define DEVICE_MAJOR 233
#define DEVICE_NAME "led"

static int led_open(struct inode *inode, struct file *file)
{
    printk("open in kernel\n");
    return 0;
}


static int led_release(struct inode *inode, struct file *file)
{
    printk("humidity release\n");
    return 0;
}


static ssize_t led_read(struct file *file, char* buffer, size_t size, loff_t *off)
{
    return 0;
}


static ssize_t led_write(struct file *file, const char* buffer, size_t size, loff_t *off)
{
    return -1;
}


static struct file_operations strled_dev_fops={
    .owner = THIS_MODULE,
    .open = led_open,
    .read = led_read,
    .write = led_write,
    .release = led_release,
};
static struct class *led_class;
static struct device *led_device;


static int __init ledDevice_init(void)
{
    /*
     * Register device
    */
    int ret;

    ret = register_chrdev(DEVICE_MAJOR, DEVICE_NAME, &strled_dev_fops);
    if (ret < 0) {
        printk(KERN_INFO "%s: registering device %s with major %d failed with %d\n",
            __func__, DEVICE_NAME, DEVICE_MAJOR, DEVICE_MAJOR );
        return(ret);
    }
    printk("LED driver register success!\n");

    led_class = class_create(DEVICE_NAME);
    if (IS_ERR(led_class))
    {
        printk(KERN_WARNING "Can't make node %d\n", DEVICE_MAJOR);
        unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
        return PTR_ERR(led_class);
    }

    led_device = device_create(led_class, NULL, MKDEV(DEVICE_MAJOR, 0), NULL, DEVICE_NAME);
    if (IS_ERR(led_device))
    {
        printk(KERN_WARNING "Can't make node %d\n", DEVICE_MAJOR);
        unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
        class_destroy(led_class);
        return PTR_ERR(led_class);
    }

    printk("LED driver make node success!\n");

    // Reserve gpios
    if( gpio_request( PIN, DEVICE_NAME ) < 0 )	// request pin 2
    {
        printk( KERN_INFO "%s: %s unable to get TRIG gpio\n", DEVICE_NAME, __func__ );
        unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
        device_del(led_device);
        class_destroy(led_class);
        ret = -EBUSY;
        return(ret);
    }

    // Set gpios directions
    if( gpio_direction_output( PIN, 1) < 0 )	// Set pin 2 as output with default value 0
    {
        printk( KERN_INFO "%s: %s unable to set TRIG gpio as output\n", DEVICE_NAME, __func__ );
        unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
        device_del(led_device);
        class_destroy(led_class);
        ret = -EBUSY;
        return(ret);
    }

    return 0;
}


static void __exit ledDevice_exit(void)
{
    gpio_direction_input(PIN);
    gpio_free(PIN);
    unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
    device_del(led_device);
    class_destroy(led_class);
}

module_init(ledDevice_init);
module_exit(ledDevice_exit);
MODULE_LICENSE("GPL");