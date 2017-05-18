2/12/17 Afternoon

	* 1. Began the project by cloning the repo and moving Lab 1 files over.
	* 2. ALU::Process() - Added cases for more math operations (2047, 2048, and 2049).
	* 3. Controller::Decode() - Added cases 2047, 2048, and 2049 to existing operand retrieval switch.
	* 4. Created a new array inside of the Memory class called Register.
	* 5. Updated the memory constructor to set both data and Register arrays to 0 for all indexes. Removed the loop that set that indexes to 0 in the loadProgram() function.

More additions 2/12/17 Evening:

	* 1. Memory.h class: Since I'm using the memory class to store both data[] and Register[] arrays, I needed to add a writeReg() method that writes to the register and a readReg() that reads from the register.
	* 2. Memory.cpp constructor: Added the Lab2 program instructions into the first 30 indexes of the data array.
	* 3. Memory.cpp: Implemented writeReg() and readReg().
	* 4. NOTE: The add,subtract,multiply,divide cases in Decode() don't fully work yet, as they aren't reading from the register & the array yet.
	* 5. Controller.h: Created the Register object
	* 6. Controller.cpp: Created case 2057 and case 2058
	* 7. NOTE: Still working on the Lab so it is not fully functional yet (compiles without errors. Yay!).


Even more additions 2/12/17:

	1. cpu.cpp: Modified dumpMemory() to show the data array AND the register array
	2. controller.h: Added registryTracker and memoryTracker variables to hold the values stored in the last cycle
	3. controller.h: Added a 'compute' boolean that is used to determine if an theALU.process() and a Registers.writeReg() are needed. I needed a way to only call the ALU and write to the register if a mathematical opCode has been read in the previous cycle.
	4. I used memoryTracker and regTracker to keep track of the indexes that were last accessed in cases 2057 and 2058. This helps me retrieve the correct operands.
	5. Altered retire() to write to the register array instead of data array .
	6. main.cpp: Running the CPU::run() method a total of 30 times.

I ran the CPU in increments of 3 steps at a time, executing each instruction in the table (provided for Lab2) one at a time until I reached the last instruction (30 steps). I did not allow 'Halt' to end the program because I needed to dump the memory and register arrays at the very end. It was very helpful in testing and checking to see that all of the numbers were being sent in the right places.

I think the result is correct. I had to make some minor changes to how operand #2 is retrieved in order to get the multiplication step to work properly. I removed my memoryTracker variable. It seems pointless.

2/13/17

	* 1. Fixed the MOVR method to move the correct value into the register
	* 2. Achieved the correct result (67,771)

2/13/17

	* 1. Used professor's Makefile and organized project into correct folders
	* 2. Created loadMemory and loadRegister functions
	* 3. Added comments and organized code

2/15/17

	* 1. Altered my controller so that the IP increments by two when grabbing both operands, moving to the memory, and moving to the register. IP also increments by one when writing to the IO. Now I can pass in the exact number of steps to run() inside of main.cpp. This makes the emulator more efficient.
	* 2. Final commit.


