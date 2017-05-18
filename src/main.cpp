#include "cpu.h"
#include <iostream>

int main() {
	// Create the CPU object
	CPU theCPU;
	// Load memory and registers
	theCPU.loadMemory();
	theCPU.loadRegister();

	theCPU.run(11);
	// theCPU.dumpMemory();
}
