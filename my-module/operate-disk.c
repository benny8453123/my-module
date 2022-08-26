#include <linux/blkdev.h>
#include "my-module.h"

int do_disk_operation(int major, int minor)
{
	struct block_device *bdev;
	//struct gendisk *gendisk;
	//struct device *dev;

	bdev = blkdev_get_by_dev(MKDEV(major, minor), FMODE_READ | FMODE_WRITE, NULL);
	if (IS_ERR(bdev)) {
		my_module_err("Get blk dev failed !\n");
		return -1;
	} else {
		my_module_info("Get blk dev succeed !\n");

		/* Print struct device */
		my_module_info("struct device:\n");
		if (bdev->bd_device.init_name)
			my_module_info("init_name: %s\n", bdev->bd_device.init_name);
		else
			my_module_info("init_name is null\n");

		/* Print struct gendisk */
		if (bdev->bd_disk) {
			my_module_info("struct gendisk:\n");
			my_module_info("disk_name: %s\n", bdev->bd_disk->disk_name);
		}
	}

	return 0;
}
