#include "cpu.h"
#include "controller.h"
using namespace std;
#include <iostream>


CPU::CPU() {
}

void CPU::dumpMemory(){   
	// Display "memory" to the screen
	std::cout << "MEMORY\n";
   
	// Display memory
	for (int i = 0; i < 500; i++){ 
		std::cout << theController.theMemory.read(i) << " ";
	}

	// Display "register" to the screen
	std::cout << "\nREGISTER\n";

	// Display register
	for (int i = 0; i < 16; i++){ 
		std::cout << theController.Registers.readReg(i) << " ";
	}	std::cout << "\n";
}   

	
	
void CPU::loadMemory(){   
	// Set memory indexes to value 0 
	for (int i = 0; i < 500; i++){   
		theController.theMemory.write(i, 0);
	}

	// Program instructions
	int program[30] = {2057, 50, 1234, 2057, 51, 1111, 2058, 8, 50, 2046, 
	8, 51, 2057, 52, 2222, 2047, 8, 52, 2057, 53, 2, 2049, 8, 53, 2048, 
	8, 51, 2096, 8, 9999};

	// Add the instructions to sequential memory locations 0-29
	for (int i = 0; i < 30; i++){
		theController.theMemory.write(i, program[i]);
	}
}

void CPU::loadRegister(){
	// Set register indexes to value 0 
	for (int i = 0; i < 16; i++){   
		theController.Registers.writeReg(i, 0);
	}
}

void CPU::run(int steps)
{	// Run the controller x number of steps
  	for (int i = 0; i < steps; i++){
		theController.run();
  	}
}
