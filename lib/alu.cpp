#include "alu.h"
#include <iostream>
using namespace std;

ALU::ALU() {
}

int ALU::process(int code, int op1, int op2){
	switch (code){ 
		case 2046: // Add
			cout << "Adding " << op1 << " and " << op2 << "..." << endl;
			cout << op1 + op2 << endl;
			return op1 + op2;
			break;

		case 2047: // Subtract
			cout << "Subtracting " << op2 << " from " << op1 << "..." << endl;
			cout << op1-op2 << endl;
			return op1-op2;
			break;

		case 2048: // Multiply
			cout << "Multiplying " << op1 << " and " << op2 << "..." << endl;
			cout << op1 * op2 << endl;
			return op1 * op2;
			break;

		case 2049: // Divide
			cout << "Dividing " << op1 << " by " << op2 << "..." << endl;
			cout << op1 / op2 << endl;
			return op1 / op2;
			break;

		default:
			break;
	}
}
