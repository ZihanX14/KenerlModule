/*
 * hello-3.c - Demonstrates command line argument passing to a module
 */
#include <linux/init.h> //defines macros __init and __exit
#include <linux/kernel.h> //for ARRAY_SIZE()
#include <linux/module.h> //needed by all modules
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/stat.h>


static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myintarray[2] = {420, 420};
static int arr_argc = 0;

/* module_param(foo, int, 0000)
 * The first param is the parameter's name
 * The second param is its data type.
 * The final argument is the permissions bits,
 * for exposing parameteres in sysfs (if non-zero) at a later stage.
 */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "A integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

/* module_param_array(name, type, num, perm);
 * The first param is the parameter's (in this case the array's) name
 * The second param is the data type of the elements of the array
 * The third argument is a pointer to the variable that will store the number of elements of the array initialized by the user at module loading time
 * The fourth argument is the permission bits
 */

 module_param_array(myintarray, int, &arr_argc, 0000);
 MODULE_PARM_DESC(myintarray, "An array of integers");

static int __init hello3_init(void) //init_module is no longer supported
{
    int i;
    pr_info("Hello World 3.\n============\n");
    pr_info("myshort is a short integer: %hd\n", myshort);
    pr_info("myint is an integer: %d\n", myint);
    pr_info("mylong is a long integer: %ld\n", mylong);
    pr_info("mystring is a string: %s\n", mystring);

    for (i=0; i < ARRAY_SIZE(myintarray); i++) {
        pr_info("myintarray[%d] = %d\n", i, myintarray[i]);
    }

    pr_info("got %d arguments for myintarray.\n", arr_argc);

    /* non 0 return = init_module failed = module cannot be loaded*/
    return 0;
}

static void __exit hello3_exit(void)
{
    pr_info("Bye World 3.\n");
}

module_init(hello3_init)
module_exit(hello3_exit)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zihan Xu");
MODULE_DESCRIPTION("Hello World Loadable Kernel Module(LKM)");


