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
The implementation and the code is thie above mentioned file

----------
- **Things Declared**
----------
  - Imports:
    'mbed.h'
    'PinNames.h'
    <cstdint>
    <cstdio>
    <stdio.h>
    <string.h>
    "lcd_1602.h"
    
  - Variables:
   int increment
   char code
   char RightCode
   int32_t output_zero
   int32_t output_one
   
    
  - Functions:
    

----------
- **API and Built In Elements Used**
----------
  - ISR
  - InterruptIn
----------
- **Custom Functions**
----------


