#include "intsort.h"

#define N 32
static uint8_t i;

void intsort( const uint8_t input, uint8_t* output )
{
    #pragma HLS INTERFACE mode=s_axilite port=intsort
    #pragma HLS INTERFACE mode=s_axilite port=input
    #pragma HLS INTERFACE mode=s_axilite port=output

    static uint8_t array[N];

    while(input == '?'){ // the '?' defines a special character which is used to reset the array
        for(int k = 0; k < N; k++){
            array[k] = 0;
        }
    }
    if (input != 13) { // Recieve numbers until receiving Enter = 13 in Ascii. Insert element directly into existing sorted array.
        int j = N-1;
        while(array[j] == 0 && j >= 0){ // finding the last element in the array, 0 is not an element since 0 in ascii = 48
            j--;
        }
        while (j >= 0 && array[j] > input) { // insertionsort algorithm
            array[j+1] = array[j];
            j = j - 1;
        }
        array[j+1] = input;
        *output = '!'; // send useless ouput, since an output is required for it to work
    }else {
        int j = 0;
        while( j < N && array[j] == 0){ // finding the first element that needs to be printed
            j++;
        }
        if (j == N){
            *output = '#';
        }else{
            *output = array[j];
            array[j] = 0;
        } 
    }
}