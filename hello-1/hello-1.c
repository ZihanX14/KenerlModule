/*
* hello-1.c - Hello World
*/
#include <linux/module.h> //needed by all modules
#include <linux/printk.h> //pr_info()

int init_module(void)
{
    pr_info("Hello World 1.\n");

    /* non 0 return = init_module failed = module cannot be loaded*/
    return 0;
}

void cleanup_module(void)
{
    pr_info("Bye World 1.\n");
}

MODULE_LICENSE("GPL")

