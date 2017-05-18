*Built in a Linux virtual machine using Oracle VM VirtualBox

Basic CPU emulator
==================

The purpose of this project is to explore the steps taken inside the processor based on Von Neumann architecture. The C++ code here mimics assembly language (opCode, dest, src) for research/learning purposes. Classes are implemented for the following:

* ALU
* Controller
* CPU
* I/O
* Memory

Operations used: WRITE, MOV, MOVR, ADD, SUB, MUL, DIV, HALT

Instruction/opCode:

* WRITE (2096) - Display register to the screen
* MOV (2057) - Move a value into the memory array
* MOVR (2058) - Move a value from memory into a register
* ADD (2046) 
* SUB (2047)
* MUL (2048)
* DIV (2049)
* HALT (9999)

Testing the machine
===================

The following 11 instructions are stored in sequential memory locations:

* MOV, 50, 1234
* MOV, 51, 1111
* MOVR, 8, 50
* ADD, 8, 51
* MOV, 52, 2222
* SUB, 8, 52
* MOV, 53, 2
* DIV, 8, 53
* MUL, 8, 51
* WRITE, 8
* HALT

After these 11 steps have executed, a result of 67771 should be displayed.

Output:

    Adding 1234 and 1111...

    2345

    Subtracting 2222 from 2345...

    123

    Dividing 123 by 2...

    61

    Multiplying 61 and 1111...

    67771

    the result is: 67771

    Halting...

To run the program:

* $ ./app











