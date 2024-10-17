#include "intsort.h"
#include <stdint.h>
#include <stdio.h>

int main()
{
    uint8_t array[10] = {0};
    array[0] = '3';
    array[1] = '6';
    array[2] = '1';
    array[3] = '8';      
    array[4] = '\r';
	printf("\n Output: ");
    uint8_t out;
    for(int i = 0; i <=4; i++){
        
        intsort(array[i], &out);
    }
    while((char) out != '#'){
        printf("%c ", (char) out);
        intsort('\r', &out);
    }
	printf("\n");
	return 0;
}
