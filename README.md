# CSE321_Project2_aryanshs_main

-------------------
## About
-------------------
- Project Description: Explore design and implementation in a bare metal system with a combination lock/security
system
- Contribitor List: Aryansh Sharma


--------------------
## Features
--------------------
Explore design and implementation in a bare metal system with a combination lock/security
system. The LCD will lock/unlock based on if you enter the right code/password

--------------------
## Required Materials
--------------------
- LCD (1602 or 1802)
- Nucleo
- Keypad
- Solderless Breadboard
- Jumper wires
- LEDs
- Resistors

--------------------
## Resources and References
--------------------
- https://www.st.com/resource/en/reference_manual/dm00310109-stm32l4-series-advanced-armbased-32bit-mcus-stmicroelectronics.pdf

--------------------
## Getting Started
--------------------
- Assemble and connect the hardware pieces
- Clone the project using `git clone {url}`
- Navigate to the cloned repoository
- Plug in the microcontroller and run the code in CSE321_project2_aryanshs_main.cpp

--------------------
## CSE321_project2_aryanshs_main.cpp:
--------------------
The implementation and the code is in the above mentioned file

----------
- **Things Declared**
----------
  - Imports:
    - 'mbed.h'
    - 'PinNames.h'
    - cstdint
    - cstdio
    - stdio.h
    - string.h
    - "lcd_1602.h"
    
  - Variables:
    - int increment
    - char code
    - char RightCode
    - int32_t output_zero
    - int32_t output_one
    - int32_t outputPB4_ones
    - int32_t outputPB4_zeroes
    - int32_t outputPB3_ones 
    - int32_t outputPB3_zeroes
    - int32_t input_pin
    - bool locked
    - lcd (inherited from CSE321_LCD)
    
  - Functions:
    - KeyHandler8
    - KeyHandler9
    - KeyHandler10
    - KeyHandler11
    - newHandler
    - check
    - lightlcd

----------
- **API and Built In Elements Used**
----------
  - ISR
  - InterruptIn
  - LCD API
  - Bounce
----------
- **Custom Functions**
----------
  - KeyHandler8
    - An ISR function for first column that checks which row the current is flowing from
    - Inputs: None
    - Gloal variables used: increment, newHandler()
  - KeyHandler9
    - An ISR function for second column that checks which row the current is flowing from
    - Inputs: None
    - Gloal variables used: increment, newHandler()
  - KeyHandler10
    - An ISR function for third column that checks which row the current is flowing from
    - Inputs: None
    - Gloal variables used: increment, newHandler()
  - KeyHandler11
    - An ISR function for fourth column that checks which row the current is flowing from
    - Inputs: None
    - Gloal variables used: increment, newHandler()
  - newHandler
    - Function that handles the configuration of toggling led on and off at the press of a button on the keypad
    - Inputs: None
    - Global variables used: None
  - check
    - Function that checks if the code entered is right or wrong
    - Inputs: int inc
    - Global variables used: increment, lightlcd()
  - lightlcd
    - Function that handles what to display on the LCD
    - Inputs: bool lock
    - Global variables used: bool locked, lcd (class inherited from CSE321_LCD)

