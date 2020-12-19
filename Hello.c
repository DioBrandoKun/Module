#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Robert W. Oliver II");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");
static char*whom ="world";
module_param(whom, charp,0644);
MODULE_PARM_DESC(whom,"Recipient of the hello message");
static int howmany =1;
module_param(howmany,int,0644);
MODULE_PARM_DESC(howmany,"Number of greetings");
static int __init lkm_example_init(void) {
 int i;
 for(i=0;i<howmany;i++)
 pr_alert("Hi you Nikita!");
 return 0;
}
static void __exit lkm_example_exit(void) {
 pr_alert("Oh, i am sorry!");
}
module_init(lkm_example_init);
module_exit(lkm_example_exit);
