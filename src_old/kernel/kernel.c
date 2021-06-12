#include "screen.h"
#include "gdt.h"

int kmain(void *mbd,unsigned int magic){
    encode_base_entries();
	screen_clear();
	if (magic!=0x2BADB002){
		screen_print("Invalid multiboot header.");
		return -1;
	}
	screen_print("Hello World!");
	return 0;
}

