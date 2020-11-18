#include "mbed.h"
#include "../lib/uopmsb/uop_msb_2_0_0.h"
#include "PushSwitch.hpp"
using namespace uop_msb_200;

void task1();
void task2();

DigitalOut yellow_led(TRAF_YEL1_PIN);  
Thread t1, t2;

int main() {
    t1.start(task1);
    t2.start(task2);
    //t1.set_priority(osPriorityRealtime);  //Try this
    while(true) { 
        yellow_led = !yellow_led;
        ThisThread::sleep_for(500ms);
    }
}

// Version 1 - Partially uses a spinning technique
void task1() {
    DigitalOut red_led(TRAF_RED1_PIN);  
    DigitalIn sw1(BTN1_PIN);
    red_led = sw1;
    
    while(true) {
        while (sw1 == 0) {};            //BLOCKS via SPINNING
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state
        while (sw1 == 1) {};            //BLOCKS via SPINNING
        red_led = !red_led;             
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state
    }    
}

// Version 2 - uses a much more power-friendly ISR driven method
void task2() {
    DigitalOut green_led(TRAF_GRN1_PIN);
    PushSwitch button2(BTN2_PIN);
    green_led = button2;    //Blocks until there is a change

    while(true) {
        button2.waitForPress();         //Blocks in the WAITING state 
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state
        button2.waitForRelease();       //Blocks in the WAITING state
        green_led = !green_led;         
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state
    }    
}
