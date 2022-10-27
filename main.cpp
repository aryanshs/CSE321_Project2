/*  Author1: Aryansh Sharma (aryanshs@buffalo.edu)
    Author2: I worked alone
    Title: Project 2
    Date:    Fall 2022
    Course:  Computer Science 321

    Description: Project 2, Explore design and implementation in a bare metal system with a combination lock/security system

    Overview: This is a template for projects in the course Embedded Systems

    Inputs : Keypad
    Outputs : LCD, LED

    References:
*/

//Includes Section/Imports:
#include "PinNamesTypes.h"
#include "mbed.h"
#include <cstdint>
#include <stdio.h>
#include <string.h>

/*Global Variables Section :
*/
int increment = 0; //increment to check the length of code
char code[5] ="";
char RightCode[5] = "A321";
//setting/declaring the interrupts:
InterruptIn Key8(PC_8, PullDown); 
InterruptIn Key9(PC_9, PullDown);
InterruptIn Key10(PC_10, PullDown);
InterruptIn Key11(PC_11, PullDown);

// InterruptIn Key8(PB_8, PullDown); 
// InterruptIn Key9(PB_9, PullDown);
// InterruptIn Key10(PB_10, PullDown);
// InterruptIn Key11(PB_11, PullDown);

//Declaring variables for ports and pins
//int32_t output_zero = 0xAA0000;
int32_t output_zero = 0x2A0000; //PB 8,9,10 output keypad
int32_t output_one = 0x150000; // PB 8,9,10 output keypad

//PB4 output keypad
int32_t outputPB4_ones = 0x100;
int32_t outputPB4_zeroes = 0x200;

//PB3 output LED
int32_t outputPB3_ones = 0x40;
int32_t outputPB3_zeroes = 0x80;

int32_t input_pin = 0xFF0000; //PC 8,9,10,11 input keypad



//Declare ISR:
void KeyHandler8(void);
void KeyHandler9(void);
void KeyHandler10(void);
void KeyHandler11(void);

//led
void newHandler(void);

//checking code
void check(int inc);

int retval(int val);

//Main Function Section:
int main(){
    //user Port B for output ->rows
    //use Port C for input ->columns
    RCC->AHB2ENR |= 0x6;

    //4 outs and 4 ins pins
    // pin 16-23, (8-11)
    //PC 8,9,10,11
    GPIOC->MODER &=~input_pin; //set the input bits 00

    //PB4 output
    GPIOB->MODER |= outputPB4_ones; //bit 8 to 1 
    GPIOB->MODER &= ~outputPB4_zeroes;

    //PB 8,9,10
    GPIOB->MODER &=~output_zero; //set the output bit 0
    GPIOB->MODER |= output_one; // set the output bits 0101

    //PB 3 output led
    GPIOB->MODER |= outputPB3_ones;
    GPIOB->MODER &= ~outputPB3_zeroes;

    //PB 5 passcode led
    GPIOB->MODER |= 0x400;
    GPIOB->MODER &= ~(0x800);

    //calling keyhandler during internupt
    Key8.rise(&KeyHandler8);
    Key9.rise(&KeyHandler9);
    Key10.rise(&KeyHandler10);
    Key11.rise(&KeyHandler11);

    //enabling interrupt
    Key8.enable_irq();
    Key9.enable_irq();
    Key10.enable_irq();
    Key11.enable_irq();

    //Turning the output on
    //GPIOB->ODR |= 0xF00;

    
    
    while (1){
        //row1
        GPIOB->ODR |= 0x100;
        wait_us(300);
        
        GPIOB->ODR &= ~(0x100);
        //wait_us(200);

        

        //row2
        GPIOB->ODR |= 0x200;
        wait_us(300);
        GPIOB->ODR &= ~(0x200);
        //wait_us(200);

        //row 3
        GPIOB->ODR |= 0x400;
        wait_us(300);
        GPIOB->ODR &= ~(0x400);
        //wait_us(200);

        //row 4
        GPIOB->ODR |= 0x10;
        wait_us(300);
        GPIOB->ODR &= ~(0x10);
        //wait_us(200);

        //printf("%s", code);

        //checking the right code
        //check(increment);
    }

     
    return 0;
}

//User-defined functions Section:

//takes care of the first column
void KeyHandler8(void){
    
    wait_us(300000);
    if ((GPIOB->ODR&0X100)==0X100){
        strncat(code, "1", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X200)==0X200){
        strncat(code, "4", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X400)==0X400){
        strncat(code, "7", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X10)==0X10){
        strncat(code, "*", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    
}

//takes care of the second column
void KeyHandler9(void){
        
    wait_us(300000);
    if ((GPIOB->ODR&0X100)==0X100){
        strncat(code, "2", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X200)==0X200){
        strncat(code, "5", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X400)==0X400){
        strncat(code, "8", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X10)==0X10){
        strncat(code, "0", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
}

//takes care of the third column
void KeyHandler10(void){
    
    wait_us(300000);
    if ((GPIOB->ODR&0X100)==0X100){
        strncat(code, "3", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X200)==0X200){
        strncat(code, "6", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X400)==0X400){
        strncat(code, "9", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X10)==0X10){
        strncat(code, "#", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }

}

//takes care of the fourth column
void KeyHandler11(void){

    wait_us(300000);
    if ((GPIOB->ODR&0X100)==0X100){
        strncat(code, "A", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X200)==0X200){
        strncat(code, "B", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X400)==0X400){
        strncat(code, "C", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }
    else if ((GPIOB->ODR&0X10)==0X10){
        strncat(code, "D", 1);
        increment = increment +1;
        newHandler();
        check(increment);
    }


}

//toggle led on and off
void newHandler(void){
    GPIOB->ODR |= 0x8;
    wait_us(50000);
    GPIOB->ODR &= ~(0x8);
}
void check(int inc){
    
    bool right = true;

    if (inc ==4){
        
        for (int i = 0; i<inc; i++){
            
            if (code[i] != RightCode[i]){
                right = false;
            }
        }

        if (right == true){
            GPIOB->ODR |= 0x20;
        }
        else{
            printf("Wrong Code");
        }
        
    }
    //printf("%d", inc);
  
    // printf(val);
}
