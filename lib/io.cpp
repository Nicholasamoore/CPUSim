#include "io.h"
#include "controller.h"
#include <iostream>
using namespace std;

IO::IO() {
}

void IO::write(int data) {
	// Print the result on the screen
	cout << "the result is: " << data << endl;
}
