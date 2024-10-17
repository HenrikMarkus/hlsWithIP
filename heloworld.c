#include "platform.h"
#include "xintsort.h"
#include "xil_printf.h"
#include "xparameters.h"

typedef struct {
    uint8_t val_reg[10];
} ArrayWrapper;

int main()
{
    print("\n\rINTSORT Filter\n\r>");

    XIntsort intsort =
    {
        // XPAR_XINTSORT_0_BASEADDR might need to be changed. 
        // The parameter can be found in xparameters.h
        // For our board (Zynq 7000) the value should be 0x40000000
        .Control_BaseAddress = XPAR_XINTSORT_0_BASEADDR, 
        .IsReady = 0
    };

    init_platform();

    XIntsort_Config* const config = XIntsort_LookupConfig(XPAR_XSLCR_0_DEVICE_ID);
    const int ret = XIntsort_CfgInitialize( &intsort, config);
    Xil_AssertNonvoid( ret == XST_SUCCESS );

    XIntsort_DisableAutoRestart(&intsort);
    
    uint8_t i = 0;
    ArrayWrapper myWrapper = { {0} };
    ArrayWrapper mySortedWrapper = { {0} };
    while(1){
        while (1) {
            myWrapper.val_reg[i] = inbyte();
            if(myWrapper.val_reg[i] == 13){
                break;
            };
            i++;
        }
        if(XIntsort_IsIdle(&intsort))
        {
            XIntsort_Set_input_r(&intsort, myWrapper);
            XIntsort_Start(&intsort);

            while(!XIntsort_IsDone(&intsort));
            
            mySortedWrapper = XIntsort_Get_output_r(&intsort);
            //print("\n\rOutputValue:\n\r>");
            //print(val);
        }
        i = 0;
        print("\n\rOutByteValues:\n\r>");
        while (mySortedWrapper.val_reg[i] != 13) {
            outbyte(mySortedWrapper.val_reg[i]);
            i++;
        }
        print("\n");
    }

    cleanup_platform();
    return 0;
}