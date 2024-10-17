#include "intsort.h"
#include <stdint.h>
#include <stdio.h>

int main()
{
    uint8_t array[10] = {'3', '6', '1', '8', '\r', 0, 0, 0, 0, 0};
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
