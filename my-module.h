#ifndef MY_MODULE_H
#define MY_MODULE_H

#include <linux/printk.h>
#include <linux/kernel.h>

#define my_module_info(fmt, ...) \
	pr_info("[my_module]: "fmt, ##__VA_ARGS__)

#define my_module_err(fmt, ...) \
	pr_err("[my_module]: "fmt, ##__VA_ARGS__)

#define my_module_debug(fmt, ...) \
	pr_debug("[my_module]: "fmt, ##__VA_ARGS__)

int do_disk_operation(int major, int minor);

#endif /* MY_MODULE_H */
