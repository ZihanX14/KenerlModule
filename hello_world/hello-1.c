/*
 * hello-1.c - Hello World
 */

#include <linux/module.h> //needed by all modules
#include <linux/printk.h> //pr_info() or include <linux/module.h>
#include <linux/init.h> //defines macros __init and __exit

static int __init hello_init(void) //init_module is no longer supported
{
    pr_info("Hello World 1.\n");

    /* non 0 return = init_module failed = module cannot be loaded*/
    return 0;
}

static void __exit hello_exit(void)
{
    pr_info("Bye World 1.\n");
}

module_init(hello_init)
module_exit(hello_exit)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zihan Xu");
MODULE_DESCRIPTION("Hello World Loadable Kernel Module(LKM)");


