#!/bin/bash

module_name="test-module.ko"


sudo rmmod ${module_name}

sudo insmod ${module_name}

#if want to show module param
#sudo insmod ${module_name} mod_param=1

#remove module from system
sudo rmmod ${module_name}

#show log
dmesg | grep my_module
