#include "intsort.h"
#include <stdio.h>

int main()
{
    ArrayWrapper myWrapper = { {0} };
    myWrapper.val_reg[0] = '3';
    myWrapper.val_reg[1] = '6';
    myWrapper.val_reg[2] = '1';
    myWrapper.val_reg[3] = '8';
    myWrapper.val_reg[4] = '2';
    myWrapper.val_reg[5] = '9';
    myWrapper.val_reg[6] = '0';
    myWrapper.val_reg[7] = '8';    
    myWrapper.val_reg[8] = '\r';
	printf("\n Output: ");
    myWrapper = intsort(myWrapper);
    uint8_t i = 0;
    
    while (myWrapper.val_reg[i] != 13) {
        printf("%u ",myWrapper.val_reg[i]);
        i++;
    }
	printf("\n");
	return 0;
}
