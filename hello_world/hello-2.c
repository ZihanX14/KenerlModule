/*
 * hello-2.c - Illustrating the __init, __initdata and __exit macros
 */

#include <linux/module.h> //needed by all modules
#include <linux/printk.h> //pr_info() or include <linux/kernel.h>
#include <linux/init.h> //defines macros __init and __exit

static int hello3_data __initdata = 2;

static int __init hello2_init(void) //init_module is no longer supported
{
    pr_info("Hello World %d.\n", hello3_data);

    /* non 0 return = init_module failed = module cannot be loaded*/
    return 0;
}

static void __exit hello2_exit(void)
{
    pr_info("Bye World 3.\n");
}

module_init(hello2_init)
module_exit(hello2_exit)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zihan Xu");
MODULE_DESCRIPTION("Hello World Loadable Kernel Module(LKM)");


