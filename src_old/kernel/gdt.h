//
// Created by nadav on 12/06/2021.
//

#ifndef LEARNC___GDT_H
#define LEARNC___GDT_H
typedef struct {
    int base;
    int limit;
    int type;
} GDT_ENTRY;

void encode_base_entries(void);
#endif //LEARNC___GDT_H
