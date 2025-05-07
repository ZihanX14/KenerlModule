#obj-m += hello-1.o #not hello-1.c file
#obj-m += hello-2.o
obj-m += hello-3.o

PWD := $(CURDIR)

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean