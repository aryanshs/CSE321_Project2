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


--------------------
## Getting Started
--------------------
- Clone the project using `git clone {url}`

--------------------
## cse321_project1_aryanshs_corrected_code.cpp:
--------------------
The implementation to toggle the led on and off consists in this file. The contents of the file are mentioned below:

----------
- **Things Declared**
----------
  - Imports:
    - mbed.h
    
  - Variables:
    - Thread yarn
    - DigitalOut fire
    - int OnorOff
    - int Count
    
  - Functions:
    - ThreadHandler
    - Toggler_Helper
    - Toggler
    - Main

----------
- **API and Built In Elements Used**
----------
  - Thread
  - DigitalOut
  - InterruptIn
----------
- **Custom Functions**
----------

- ThreadHandler
  - Handles the functionality of the thread in the code, and toggles the fire variable
  - Inputs: None
  - Global variables used: fire, printf, thread_sleep_for, count

- Toggler_Helper
  - Helps toggling of the led by setting OnorOff to 1
  - Inputs: None
  - Global variables used: OnorOff
  
 - Toggler
   - Handles the functionality of toggling the led on or off
   - Inputs: None
   - Global variables used: OnorOff, count
