#include "platform.h"
#include "xintsort.h"
#include "xil_printf.h"
#include "xparameters.h"

int main()
{
    print("\n\r Enter your unsorted numbers. Confirm starting the sorting with Enter. Maximum length 32.\n\r");

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
    
    int userInput = 1;

    if(XIntsort_IsIdle(&intsort)){
        XIntsort_Set_input_r(&intsort, '?'); // Reset the array to 0 by sending '?'.
        XIntsort_Start(&intsort);
    }

    while(1){
        const char c = inbyte();
        if(c == '\r'){
            userInput = 0;
        }
        if(userInput == 1){ // case for sending values to be sorted
            if(XIntsort_IsIdle(&intsort)){
                XIntsort_Set_input_r(&intsort, c);
                XIntsort_Start(&intsort);
            }
        }else{ // receiving and printing sorted array
            while(1){
                if(XIntsort_IsIdle(&intsort)){
                    XIntsort_Set_input_r(&intsort, '\r');
                    XIntsort_Start(&intsort);
                    while(!XIntsort_IsDone(&intsort));
                    const uint8_t outputvalue = XIntsort_Get_output_r(&intsort);
                    if(outputvalue == '#'){
                        userInput = 1;
                        break;
                    }
                    outbyte(outputvalue);
                }
            }
        }
    }
    cleanup_platform();
    return 0;
}
