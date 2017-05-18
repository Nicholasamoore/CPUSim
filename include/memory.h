#ifndef HEADER_MEMORY
#define HEADER_MEMORY

// Maximum size of memory array
const int MAXMEM = 500;
// Maximum size of register array
const int MAXREG = 16;

class Memory {
    public:
        Memory();   // constructor
        // operate on the data array
        void write(int addr, int item);
        int read(int addr);
        // operate on the register array
        void writeReg(int addr, int item);
        int readReg(int addr);
    private:
        int data[MAXMEM];
        int Register[MAXREG];
};
#endif
