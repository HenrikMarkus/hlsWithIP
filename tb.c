#include "intsort.h"
#include <stdio.h>

static uint8_t value_reg[]= {'3','6','1','8','\n'};

int main()
{
    ArrayWrapper myWrapper = { {0} };
    myWrapper.val_reg[0] = '3';
    myWrapper.val_reg[1] = '6';
    myWrapper.val_reg[2] = '1';
    myWrapper.val_reg[3] = '8';
    myWrapper.val_reg[4] = '\n';
    //uint8_t in = myWrapper;
    //printf("Array first address %u \n", &value_reg[0]);
    //printf("Array first element %u \n", value_reg[0]);
	uint8_t out;
    printf("First Value %u \n", myWrapper.val_reg[0]);
    printf("Last Value %u \n", myWrapper.val_reg[4]);
	printf("\n Output: ");
    myWrapper = intsort(myWrapper);
    printf("First Value %u \n", myWrapper.val_reg[0]);
    //printf("%c \n Starting with real values: \n", (char)out);
    uint8_t i = 0;
    
    /*while (*(in+i) != '\n') {
        printf("%04x ",*(in+i));
        i++;
    }*/
	printf("\n");
	return 0;
}
