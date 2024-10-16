#include "intsort.h"
#include <stdio.h>

#define N 3


static uint8_t i = 0;

ArrayWrapper sorting(ArrayWrapper input){
    i = 0;
    //uint8_t* index;
    //index = input;
    /*printf("First Value %u \n", input.val_reg[0]);
    printf("Second Value %u \n", input.val_reg[1]);
    printf("Third Value %u \n", input.val_reg[2]);
    printf("Fourth Value %u \n", input.val_reg[3]);
    printf("Last Value %u \n", input.val_reg[4]);*/
    input.val_reg[0] = '7';
    while (input.val_reg[i] != '\n') {  // 13 is the ASCII value for '0D'
        printf("Fourth iced value %u \n", input.val_reg[i]);
        /*char key = *(index+i);
        int j = i - 1;

        while (j >= 0 && *(index+j) > key) {
            *(index + j + 1) = *(index+j);
            j = j - 1;
        }
        *(index + j + 1) = key;*/
        i++;
    }
    return input;
}

//Modified example by Prof. Young-kyu Choi
ArrayWrapper intsort(ArrayWrapper input)
{
#pragma HLS INTERFACE mode=s_axilite port=intsort
#pragma HLS INTERFACE mode=s_axilite port=input
//#pragma HLS INTERFACE mode=s_axilite port=output
    ArrayWrapper output;
    output = sorting(input);

	//Divide by three
	//*output = value_reg[1];

    return output;
}
