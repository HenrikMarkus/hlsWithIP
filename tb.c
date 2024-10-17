#include "intsort.h"
#include <stdint.h>
#include <stdio.h>

#define M 17

int main()
{
    uint8_t array[M] = {'3', '6', '1', '8', '3', '6', '1', '8', '3', '6', '5', '8', '3', '6', '1', '8', '\r'};
	printf("\n Output: ");
    uint8_t out;
    for(int i = 0; i < M; i++){
        intsort(array[i], &out);
    }
    while((char) out != '#'){
        printf("%c ", (char) out);
        intsort('\r', &out);
    }
	printf("\n");
	return 0;
}
