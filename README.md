# my-module
learning for simple kernel module

## how to test?

### 1. compile & install
- compile
`make`

- install
`sudo insmod chardev-test-module.ko`

### 2. find char device name & major number
- check char device name
```
my-chardev.c

CDEV_NAME "my_char_dev"
```

- device major number
```
ben@ben-virtual-machine:~/kernel-source/focal/drivers/misc/my-chardev$ cat /proc/devices | grep my_char_dev
235 my_char_dev
```

### 3. make node
`sudo mknod my-chardev-nod c 235 0`
```
ben@ben-virtual-machine:/dev$ sudo mknod my_chardev c 235 0
ben@ben-virtual-machine:/dev$ ll | grep my_chardev
crw-r--r--   1 root root    235,   0  九   6 18:17 my_chardev
```

:::info
mknod help
```
ben@ben-virtual-machine:/dev$ mknod --help
Usage: mknod [OPTION]... NAME TYPE [MAJOR MINOR]
...
```
:::

### 4. echo & cat with root permission
`sudo -s`
`echo "hello" > my_chardev`
`cat my_chardev`
```
root@ben-virtual-machine:/dev# echo "hello" > my_chardev
root@ben-virtual-machine:/dev# cat my_chardev
hello
```

### 5. sudo ./test
`cd test`
`make`
`sudo ./test`
```
ben@ben-virtual-machine:~/kernel-source/focal/drivers/misc/my-chardev/test$ sudo ./test 
read_buffer = 
don't need to close device
read 30 bytes
read_buffer = Hello World! This is FIFO buf
```
