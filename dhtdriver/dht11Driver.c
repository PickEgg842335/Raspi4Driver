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
#define DEVICE_MAJOR 232
#define DEVICE_NAME "dht11"

static int dht11_open(struct inode *inode, struct file *file)
{
    printk("open in kernel\n");
    return 0;
}


static int dht11_release(struct inode *inode, struct file *file)
{
    printk("humidity release\n");
    return 0;
}


static ssize_t dht11_read(struct file *file, char* buffer, size_t size, loff_t *off)
{
    return 0;
}


static struct file_operations strdht11_dev_fops={
    .owner = THIS_MODULE,
    .open = dht11_open,
    .read = dht11_read,
    .release = dht11_release,
};
static struct class *dht_class;
static struct device *dht_device;


static int __init dht11Device_init(void)
{
    /*
     * Register device
    */
    int ret;

    ret = register_chrdev(DEVICE_MAJOR, DEVICE_NAME, &strdht11_dev_fops);
    if (ret < 0) {
        printk(KERN_INFO "%s: registering device %s with major %d failed with %d\n",
            __func__, DEVICE_NAME, DEVICE_MAJOR, DEVICE_MAJOR );
        return(ret);
    }
    printk("DHT11 driver register success!\n");

    dht_class = class_create(DEVICE_NAME);
    if (IS_ERR(dht_class))
    {
        printk(KERN_WARNING "Can't make node %d\n", DEVICE_MAJOR);
        return PTR_ERR(dht_class);
    }

    dht_device = device_create(dht_class, NULL, MKDEV(DEVICE_MAJOR, 0), NULL, DEVICE_NAME);

    printk("DHT11 driver make node success!\n");

    // Reserve gpios
    if( gpio_request( PIN, DEVICE_NAME ) < 0 )	// request pin 2
    {
        printk( KERN_INFO "%s: %s unable to get TRIG gpio\n", DEVICE_NAME, __func__ );
        unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
        device_del(dht_device);
        class_destroy(dht_class);
        ret = -EBUSY;
        return(ret);
    }

    // Set gpios directions
    if( gpio_direction_output( PIN, 1) < 0 )	// Set pin 2 as output with default value 0
    {
        printk( KERN_INFO "%s: %s unable to set TRIG gpio as output\n", DEVICE_NAME, __func__ );
        unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
        device_del(dht_device);
        class_destroy(dht_class);
        ret = -EBUSY;
        return(ret);
    }

    return 0;
}


static void __exit dht11Device_exit(void)
{
    gpio_direction_input(PIN);
    gpio_free(PIN);
    unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
    device_del(dht_device);
    class_destroy(dht_class);
}

module_init(dht11Device_init);
module_exit(dht11Device_exit);
MODULE_LICENSE("GPL");