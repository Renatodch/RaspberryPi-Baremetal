#
TARGET=kernel8.img
PATH=C:/Users/Renato/Desktop/rpi_bm/

CROSS=./aarch64_elf/bin/aarch64-none-elf-
CC=$(CROSS)gcc
CFLAGS = -Wall -O2 -mstrict-align -fno-tree-loop-vectorize -fno-tree-slp-vectorize
#CFLAGS=-Wall -O2 -ffreestanding -fno-stack-protector -nostartfiles

LDFLAGS = -nostdlib -nodefaultlibs -nostartfiles -ffreestanding -fno-asynchronous-unwind-tables -fomit-frame-pointer -specs=nosys.specs
LIBFLAGS = -lm -lc -lgcc
LINKERFLAGS=-Wl,-gc-sections -Wl,--build-id=none -Wl,-Bdynamic
START_O = ./sys/start.o
# -nostdlib -nostdinc

INCS=$(PATH)inc
LINKER=$(PATH)sys/linker.ld
START_S=$(PATH)sys/start.S

CFLAGS += $(INCS:%=-I%)
#CFLAGS +=-I$(INCS)
 

SRCS=$(wildcard $(PATH)/src/*.c)
OBJS=$(SRCS:.c=.o)

all: $(TARGET)

kernel8.elf: $(SRCS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LINKERFLAGS) -Wl,-T,$(LINKER) -Wl,-Map=linker.map $(START_S) $(SRCS) -o $@ $(LIBFLAGS)  

$(TARGET): kernel8.elf
	$(CROSS)objcopy -O binary $< $@

clean:
	rm kernel8.img linker.map kernel8.elf $(START_O) $(OBJS)
	
	
