#include "intsort.h"
#include <stdio.h>

#define N 10
static uint8_t i;
//Modified example by Prof. Young-kyu Choi
void intsort( const uint8_t input, uint8_t* output )
{
#pragma HLS INTERFACE mode=s_axilite port=intsort
#pragma HLS INTERFACE mode=s_axilite port=input
#pragma HLS INTERFACE mode=s_axilite port=output

    static uint8_t array[N];
    while(input == '?'){
        for(int k = 0; k < N; k++){
            array[k] = 0;
        }
    }
    if (input != 13) {
        int j = 9;
        while(array[j] == 0 && j >= 0){
            j--;
        }  // 13 is the ASCII value for '0D'
        while (j >= 0 && array[j] > input) {
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = input;
        *output = '!';
    }else {
        int j = 0;
        while( j < 10 && array[j] == 0){
            j++;
        }
        if (j == 10){
            *output = '#';
        }else{
            *output = array[j];
            array[j] = 0;
        } 
    }
}