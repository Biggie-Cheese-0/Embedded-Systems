#include "uop_msb.h"
using namespace uop_msb;

Buzzer buzz;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);


int main()
{
    printf("\nTASK-112\n");

    //getchar
    char c1, c2;
    printf("\n\nPress a key\n");
    c1 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c1, c1);

    printf("\n\nPress another key\n");
    c2 = getchar();
    printf("You entered character %c which has the ASCII code %d\n", c2, c2);








    //scanf
    printf("\n\nEnter an on time (ms) and press return\n");
    int delay_ms1;
    int parsed = scanf("%d", &delay_ms1);
    
    printf("You entered %d correct integer values. The value was %dms\n", parsed, delay_ms1);

    while (parsed > 0) {
        //off time
        printf("\n\nEnter an off time (ms) and press return\n");
        int delay_ms2;
        int parsed2 = scanf("%d", &delay_ms2);
        
        printf("You entered %d correct integer values. The value was %dms\n", parsed, delay_ms2);

        // Stop
        while (parsed2 > 0) {
            wait_us(delay_ms2 * 1000);
            led1 = 1;
            led2 = 1;
            led3 = 1;
            wait_us(delay_ms1 * 1000);
            led1 = 0;
            led2 = 0;
            led3 = 0;        
        } 
        while(1);
        printf("incorrect off time restart and try again");
    }
    printf("Invalid - please restart and try again\n");
    while(1);    
}