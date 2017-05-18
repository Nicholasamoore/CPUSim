#ifndef HEADER_CPU
#define HEADER_CPU
#include "controller.h"

class CPU {
    public:
        CPU();  // constructor
        void loadMemory();
        void loadRegister();
        void dumpMemory();
        void run(int steps);
    private:
    	// Create controller object
        Controller theController;
};
#endif
