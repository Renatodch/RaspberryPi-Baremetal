CROSS=./aarch64_elf/bin/aarch64-none-elf-
CC=$(CROSS)gcc
CFLAGS=-Wall -O -ffreestanding

HELLO_OBJS=crt0.o hello.o

all: kernel8.img

kernel8.img: hello.elf
	$(CROSS)objcopy -O binary $< $@

hello.elf: $(HELLO_OBJS) ram.ld
	$(CROSS)ld -o $@ $(HELLO_OBJS) -Tram.ld -Map hello.map

clean:
	rm $(HELLO_OBJS) kernel8.img hello.elf hello.map
