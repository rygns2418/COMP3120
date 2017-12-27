#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init init_hello(void)
{
printk("[COMP3120_rygns2418]: Starting module in kernel ver 4.10.0-28-generic");

	return 0;
}


static void __exit exit_hello(void)
{
	printk("[COMP3120_rygns2418]: kernel module terminating");

}

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
