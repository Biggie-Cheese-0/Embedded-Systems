#include "mbed.h"

// main() runs in its own thread in the OS
int main()
{
    DigitalOut red(PC_2);
    DigitalOut yellow(PC_3);
    DigitalOut green(PC_6);
    int x = 0;
    while (true) {
        red = 1;
        yellow = 0;
        green = 0;
        wait_us(500);
        yellow = 1;
        wait_us(500);
        green = 1;
        wait_us(500);
        red = 0;
        yellow = 0;
        green= 0;
        wait_us(500);
        red = 1;
        yellow = 1;
        green = 1;
        
        wait_us(200);
        red = 0;
        yellow = 0;
        green = 0;

       
        red = 1;
        wait_us(250);
        yellow = 1;
        wait_us(250);
        red = 0;
        green = 1;
        wait_us(250);
        yellow = 0;
        red = 1;
        wait_us(250);
        green=0;
            

    

    }
}

