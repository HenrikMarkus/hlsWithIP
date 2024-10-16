
#ifndef INTSORT_H
#define INTSORT_H

#include <stdint.h>
typedef struct {
    uint8_t val_reg[10];
} ArrayWrapper;

ArrayWrapper intsort(ArrayWrapper input);

#endif
