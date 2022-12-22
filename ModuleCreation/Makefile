obj-m += processDetails.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	rmmod processDetails.ko
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean