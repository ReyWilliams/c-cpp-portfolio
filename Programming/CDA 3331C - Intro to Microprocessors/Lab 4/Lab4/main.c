#include <msp430g2553.h>
#include <stdbool.h>

#define READROT BIT0
#define LR      BIT1
#define FS      BIT2
#define BUTTON1 BIT3
#define BUTTON2 BIT4
#define BUTTON3 BIT5
#define CUSTOM  BIT7
#define PIN1    BIT0
#define PIN2    BIT1


int pattern3 = 0;
int SW = 0;

void main(void){
WDTCTL = WDTPW + WDTHOLD;   //Stop watchdog timer

P1OUT  = 0x00;               //make sure all default outputs are zero
P2OUT  = 0x00;               //make sure all default outputs are zero

P1DIR  = 0xFF;                   //make all port 1 pins outputs by default
P2DIR  = 0x00;                   //make all port 2 pins inputs by default



//Evaluate highs (logic 0) then do else

for(;;){ //infinite loop
    /*
    int custPAT = 0;
    int CUST = P2IN & CUSTOM;
    bool isCUST = (CUST != CUSTOM);

    if(isCUST){
        int pin1 = P2IN & PIN1;
        int pin2 = P2IN & PIN2;
        bool isPIN1 = (pin1 != PIN1);
        bool isPIN2 = (pin2 != PIN2);

        if(isPIN1 && isPIN2){
            custPAT = 0b01010101;
            //custPAT = ((custPAT << 1) | (custPAT >> 7));

        }
        if(!isPIN1 && isPIN2){
            custPAT = 0b10010010;
            //custPAT = ((custPAT << 1) | (custPAT >> 7));
        }

        custPAT = ((custPAT << 1) | (custPAT >> 7));
        custPAT &= 0xFF;
        P1OUT = custPAT;
        __delay_cycles(120000);    //delay to actually show bits



    }else{
    */
    int READ = P2IN & READROT;  //mask READ value to only be read from the READ/ROTATE SWITCH(BIT0/2.0)
    bool isREAD = (READ != READROT);    //creates boolean to evaluate READ mask as input switches are active low

    if(isREAD){ //if switch evaluates to READ mode....

        pattern3 = P2IN & (BUTTON1 | BUTTON2 | BUTTON3); //create a pattern made from the mask of P2IN and
                                                         //the three buttons that make the pattern(BUTTON1,2,3)
        P1OUT = pattern3;                               //output the pattern to the P1 output by outputting it.


    }else{  //if switch evaluates to ROTATE mode....

        int LEFT = P2IN & LR;           //mask LEFT value to only be read from the LEFT/RIGHT SWITCH(BIT1/2.1)
        bool isLEFT = (LEFT != LR);     //creates boolean to evaluate LEFT mask as input switches are active low

        if(isLEFT){
            pattern3 = ((pattern3 << 1) | (pattern3 >> 7)); //rotate left
        }else{
            pattern3 = ((pattern3 >> 1) | (pattern3 << 7)); //rotate right
        }

        pattern3 &= 0xFF;           //mask the excessive bits
        P1OUT = pattern3;           //output the pattern to the P1 output by outputting it.

        int FAST = P2IN & FS;           //mask FAST value to only be read from the FAST/SLOW SWITCH(BIT2/2.2)
        bool isFAST = (FAST != FS);     //creates boolean to evaluate FAST mask as input switches are active low

        if(isFAST){
            __delay_cycles(120000);    //delay to actually show bits
        }else{
            __delay_cycles(300000);    //delay to actually show bits
        }

        }
    }
}

