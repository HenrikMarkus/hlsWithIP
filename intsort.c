#include "intsort.h"
#include <stdio.h>

#define N 3


static uint8_t i = 0;

ArrayWrapper sorting(ArrayWrapper input){
    i = 0;
    while (input.val_reg[i] != 13) {  // 13 is the ASCII value for '0D'
        char key = input.val_reg[i];
        int j = i - 1;

        while (j >= 0 && input.val_reg[j] > key) {
            input.val_reg[j+1] = input.val_reg[j];
            j = j - 1;
        }
        input.val_reg[j+1] = key;
        i++;
    }
    return input;
}

//Modified example by Prof. Young-kyu Choi
ArrayWrapper intsort(ArrayWrapper input)
{
#pragma HLS INTERFACE mode=s_axilite port=intsort
#pragma HLS INTERFACE mode=s_axilite port=input

    ArrayWrapper output;
    output = sorting(input);

    return output;
}
