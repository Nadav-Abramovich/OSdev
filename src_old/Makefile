CC:=i686-elf-gcc
CFLAGS:=-c -Wall
LD:=i686-elf-ld
LDFLAGS:=-T linker.ld -o kernel.bin
ASM:=nasm
ASMFLAGS:=-f elf

all: kernel.o boot.o
	$(LD) $(LDFLAGS) kernel.o boot.o screen.o  gdt.o gdt_asm.o

kernel.o: screen.o gdt.o
	$(CC) $(CFLAGS) kernel/kernel.c

boot.o: kernel.o
	$(ASM) $(ASMFLAGS) -o boot.o boot/boot.asm

screen.o:
	$(CC) $(CFLAGS) kernel/screen.c

gdt_asm.o:
	$(ASM) $(ASMFLAGS) -o gdt_asm.o kernel/gdt.asm

gdt.o: gdt_asm.o
	$(CC) $(CFLAGS) kernel/gdt.c

clean:
	$(shell rm -rf *.o kernel.bin)
