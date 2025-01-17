#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,0);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

LCD_16X2_DISPLAY lcd;

int main()
{
        lcd.cls();
        lcd.puts("TASK-104");
        wait_us(200000);
        while (true)
    {
        
    
        
        wait_us(WAIT_TIME_MS * 10000);
        
        lcd.cls();
        lcd.puts("Red");
        red = 1;
        wait_us(10000000);

        amber = 1;
        lcd.cls();
        lcd.puts("Red and Amber");
        wait_us(2000000);

        red = 0;
        amber = 0;

        green = 1;
        lcd.cls();
        lcd.puts("Green");    
        wait_us(10000000);

        green = 0;
        amber = 1;
        wait_us(2000000);
        amber = 0;
    }
}
