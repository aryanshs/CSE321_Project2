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
#include "mbed.h";
#include <cstdint>

/*Global Variables Section :
*/
int val = 0;
//setting/declaring the interrupts:
InterruptIn Key8(PC_8, PullDown); 
InterruptIn Key9(PC_9, PullDown);
InterruptIn Key10(PC_10, PullDown);
InterruptIn Key11(PC_11, PullDown);

//Declaring variables for ports and pins
int32_t output_zero = 0xAA0000;
int32_t output_one = 0x550000;
int32_t input_pin = 0xFF0000;



//Declare ISR:
void KeyHandler(void);


//Main Function Section:
int main(){
    //user Port B for output ->rows
    //use Port C for input ->columns
    RCC->AHB2ENR |= 0x6;

    //4 outs and 4 ins pins
    // pin 16-23, (8-11)
    GPIOC->MODER &=~input_pin; //set the input bits 00
    GPIOB->MODER &=~output_zero; //set the output bit 0
    GPIOB->MODER |= output_one; // set the output bits 0101
    
    //calling keyhandler during internupt
    Key8.rise(&KeyHandler);
    Key9.rise(&KeyHandler);
    Key10.rise(&KeyHandler);
    Key11.rise(&KeyHandler);

    //enabling interrupt
    Key8.enable_irq();
    Key9.enable_irq();
    Key10.enable_irq();
    Key11.enable_irq();

    //Turning the output on
    GPIOB->ODR |= 0xF00;

    
    
    while (1){
        printf("%d", val);
    }

     
    return 0;
}

//User-defined functions Section:

void KeyHandler(void){
    
    wait_us(5000);
    GPIOB->ODR |= 0x100;
    if ((GPIOC->IDR&0x100)==0x100){
        
        //printf("row 1 column 1");
        //printf("A");
        val = -1;
    }
    else if ((GPIOC->IDR&0x200)==0x200){
        //printf("row 1 column 2");
        //printf("3");
        val = 3;
    }
    else if ((GPIOC->IDR&0x400)==0x400){
        //printf("row 1 column 2");
        //printf("3");
        val = 2;
    }
    else if ((GPIOC->IDR&0x800)==0x800){
        //printf("row 1 column 2");
        //printf("3");
        val = 1;
    }
    else {
        val =0;
    }

    //row 2
    // GPIOB->ODR |= 0x200;
    // if ((GPIOC->IDR&0x100)==0x100){
        
    //     //printf("row 1 column 1");
    //     //printf("A");
    //     val = -2;
    // }
    // else if ((GPIOC->IDR&0x200)==0x200){
    //     //printf("row 1 column 2");
    //     //printf("3");
    //     val = 6;
    // }
    // else if ((GPIOC->IDR&0x400)==0x400){
    //     //printf("row 1 column 2");
    //     //printf("3");
    //     val = 5;
    // }
    // else if ((GPIOC->IDR&0x800)==0x800){
    //     //printf("row 1 column 2");
    //     //printf("3");
    //     val = 4;
    // }
        
    
}