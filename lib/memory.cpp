#include "memory.h"

Memory::Memory() {
}

// Write the item to the specified address
void Memory::write(int addr, int item) {
	data[addr] = item;
}

// Read from specified memory address
int Memory::read(int addr){
	return data[addr];
}

// Write to specified register address
void Memory::writeReg(int addr, int item){
	Register[addr] = item;
}

// Read from specified register address
int Memory::readReg(int addr){
	return Register[addr];
}
