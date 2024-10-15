#include "fir.h"

#define N 3

static uint8_t value_reg[]= {3,6,1,8,13};
static uint8_t i = 0;

void sorting(){
    i = 0;
    while (value_reg[i] != 13) {  // 13 is the ASCII value for '0D'
        char key = value_reg[i];
        int j = i - 1;

        while (j >= 0 && value_reg[j] > key) {
            value_reg[j + 1] = value_reg[j];
            j = j - 1;
        }
        value_reg[j + 1] = key;
        i++;
    }
}

//Modified example by Prof. Young-kyu Choi
void fir( const uint8_t input, uint8_t* output )
{
#pragma HLS INTERFACE mode=s_axilite port=fir
#pragma HLS INTERFACE mode=s_axilite port=input
#pragma HLS INTERFACE mode=s_axilite port=output

    sorting();


	//Divide by three
	*output = value_reg[1];
}
