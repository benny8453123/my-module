#include <linux/init.h>
#include <linux/module.h>
//#include <linux/kthread.h>
#include "my-module.h"

/* module param init */
int mod_param = 0;
module_param(mod_param, int, 0);
MODULE_PARM_DESC(MODULE_PARM_DESC, "If set will show \"mod_param was set\" log");

static int __init my_module_init(void)
{
	/* testing printk  */
	my_module_info("Hello, this is %s\n", __func__);

	/* test module param */
	if (mod_param) {
		my_module_info("module param was set !\n");
	}

	do_disk_operation(8, 16);
	return 0;
}

static void __exit my_module_exit(void)
{
	my_module_info("Goodbye, this is %s\n", __func__);
	return;
}

module_init(my_module_init);
module_exit(my_module_exit);
MODULE_LICENSE("GPLv2");
MODULE_AUTHOR("Ben Chang");
MODULE_DESCRIPTION("Testing Module");

