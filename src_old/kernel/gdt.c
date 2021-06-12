//
// Created by nadav on 12/06/2021.
//

#include "gdt.h"
int GDT[10];

extern void setGdt(int*, int);

// TODO: Make this unsigned
void encodeGdtEntry(int * target, GDT_ENTRY source)
{
    // source.limit is 16 bit
    if ((source.limit > 0x10000) && ((source.limit & 0xFFF) != 0xFFF)) {
        // TODO: Kerror
        return;
    }
    if(source.limit > 0x10000) {
        source.limit >>= 12;
        // TODO: Understand this :(
        // 0b1100_0000
        target[6] = 0xC0;
    } else {
        // 0b01000000
        target[6] = 0x40;
    }

    // Encode the limit
    target[0] = source.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    target[6] |= (source.limit >> 16) & 0xF;


    // Encode the base
    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;

    // And... Type
    target[5] = source.type;
}

void encode_base_entries() {
    GDT_ENTRY t;
    t.limit = 1;
    t.base = 1;
    t.type = 1;
    encodeGdtEntry(GDT, t);
    setGdt(GDT, sizeof(GDT));
}