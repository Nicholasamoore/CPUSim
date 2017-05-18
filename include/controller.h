#ifndef HEADER_CONTROLLER
#define HEADER_CONTROLLER
#include "memory.h"
#include "alu.h"
#include "io.h"

class Controller {
    public:
        Controller();   // constructor
        void fetch();
        void decode();
        void execute();
        void retire();
        void run();

        // Create memory, ALU, IO, register objects
        Memory theMemory;
        ALU theALU;
        IO theIO;
        Memory Registers;

        // Register location
        const int regTracker = 8;
        
        // Track when to use the ALU and write result to memory
        bool compute = false;
    private:
    	// Keep track of instruction pointer,
		// current opcode, operands, and result
    	int IP = 0, opCode = 0, operand1 = 0, operand2 = 0, result = 0;
};
#endif
