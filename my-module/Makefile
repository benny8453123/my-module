#CONFIG_MODULE_SIG=n
#obj-$(CONFIG_MY_MODULE)		+= my_module.o
#my_module-objs			:= my-module.o

obj-m				+= test-module.o
test-module-objs		:= my-module.o operate-disk.o

#CC=gcc
KVERSION = $(shell uname -r)
KERNEL_DIR := /lib/modules/$(KVERSION)/build

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
	#$(MAKE) -C $(KERNEL_DIR) M=$(shell pwd) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
	#$(MAKE) -C $(KERNEL_DIR) M=$(shell pwd) clean
