#include "controller.h"
using namespace std;
#include <iostream>

Controller::Controller(){
}

void Controller::run(){ 
	// Variable to activate ALU & writeReg
	compute = false;
	fetch();
	decode();
	execute();
	retire();
	// Increment instruction pointer
	IP++;
}

void Controller::fetch(){ 
	// Read the current IP address and store in opCode
	opCode = theMemory.read(IP);
}

void Controller::decode(){
	switch (opCode)
	{ 
		case 2046: case 2047: case 2048: case 2049: // opCodes add,sub,mul,div
			// Read both operands from register and memory
			operand1 = Registers.readReg(regTracker);
			operand2 = theMemory.read(theMemory.read(IP + 2));
			// Increment IP by 2
			IP+=2;
			// Prepare to use the ALU 
			compute = true;
			break;

		case 2096: // Use IO to print the designated register to the screen
			theIO.write(Registers.readReg(theMemory.read(IP + 1)));
			IP++;
			break;

		case 2057: // Move to memory
			theMemory.write(theMemory.read(IP + 1), theMemory.read(IP + 2));
			// Increment IP by 2
			IP +=2;
			break;

		case 2058: // Move to register
			Registers.writeReg(theMemory.read(IP + 1), theMemory.read(theMemory.read(IP + 2)));
			// Increment IP by 2
			IP +=2;
			break;

		case 9999: // Halt 
			cout << "Halting...\n" << endl; 
			exit(0);
			break;

		default:
			break;
	}
}

void Controller::execute(){ 
	if (compute){
		// Compute the addition and store in result variable
		result = theALU.process(opCode, operand1, operand2);
	}
}

void Controller::retire() {
	if (compute){
		// Write the result to register
		Registers.writeReg(regTracker,result);
	}
}
