#include <msp430.h>
#include "msp430g2553.h"

#define BUTTON BIT3
#define LED1 BIT0
#define LED2 BIT6

unsigned int state = 0;

void main(void){
    WDTCTL = WDTPW | WDTHOLD;                   //stop watchdog timer
    P1DIR  = 0x00;                              //port 1 all inputs
    P1DIR |= (BIT0 | BIT6);                     //set P1.0 and P1.6 as outputs (LED1, LED2)
    P1REN |= BUTTON;                            //activate resister on P1.3
    P1OUT |= BUTTON;                            //make it pull up because SW2 is active low

    P1IE  |= BUTTON;                            //enable interrupt on selected pin
    P1IES |= BUTTON;                            //interrupt edge select, hi to lo
    __enable_interrupt();                       //enable interrupts in general
     state = 0;

    for(;;){
      if(state == 1){
            P1OUT &= ~LED2;                     //turn LED2 off
            P1OUT ^= LED1;                      //toggle LED1
            __delay_cycles(500000);             //delay 200,000 micro seconds
        }

         if(state == 2){                   //else (SW2 is low)
           P1OUT &= ~LED1;                      //turn LED1 off
           P1OUT ^= LED2;                       //toggle LED2
           __delay_cycles(250000);              //delay 200,000 micro seconds
        }

          if(state == 3){
            P1OUT &= ~LED1;                     //turn LED1 off
            P1OUT &= ~LED2;                     //turn LED2 off
            __delay_cycles(250000);             //delay 200,000 micro seconds
            P1OUT ^= LED1;                      //toggle LED1
            P1OUT ^= LED2;                      //toggle LED2
            __delay_cycles(250000);             //delay 200,000 micro seconds
        }

          if(state == 4){
            P1OUT |= LED1;                      //turn LED1 on
            P1OUT &= ~LED2;                     //turn LED2 off
            __delay_cycles(250000);             //delay 200,000 micro seconds
            P1OUT ^= LED1;                      //toggle LED1
            P1OUT ^= LED2;                      //toggle LED2
            __delay_cycles(250000);             //delay 200,000 micro seconds
        }
      // end of for infinite loop
        }
}//end of main


#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void){

    state++;
    __delay_cycles(20000);  //allow some delay for switch debounce
    if(state > 4){
        state = 1;
    }

    P1IFG &= ~BUTTON;
    __delay_cycles(20000);  //allow some delay for switch debounce
}


//end port 1 interrupt


