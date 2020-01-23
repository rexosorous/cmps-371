#include <iostream>


//output variables
short ramSize, floppyCount, printerCount;

// storage variables
short index, mem;



void printZero()
{
	std::cout << 0;
}

void printOne()
{
	std::cout << 1;
}

void printLine()
{
	std::cout << std::endl;
}

void printRam()
{
	std::cout << "The size of RAM is " << ramSize << "K" << std::endl;
}

void printFloppy()
{
	std::cout << "The number of floppy drives are " << floppyCount << std::endl;
}

void printPrinters()
{
	std::cout << "The number of installed printers are " << printerCount << std::endl;
}

void printGameYes()
{
	std::cout << "Game adapter is installed" << std::endl;
}

void printGameNo()
{
	std::cout << "Game adapter is not installed" << std::endl;
}


int main()
{
	std::cout << "This is the content of AX at base 2: ";

	_asm
	{
		// PRINT AX IN BASE 2

		// init
		MOV 	BX, 0xFB86
		MOV 	index, 15

	mainloop:
		// check for sentinel value
		CMP 	index, 0
		JL  	endloop

		// extract left most bit
		MOV 	CX, 0x8000
		AND 	CX, BX
		SHR 	CX, 15

		// print bits
		CMP 	CX, 0
		JE 		zero
		CALL 	printOne
		JMP 	continueloop

	zero:
		CALL 	printZero

	continueloop:
		SHL 	BX, 1
		DEC 	index
		JMP 	mainloop

	endloop:
		CALL 	printLine
		MOV 	BX, 0xFB86

		// determine ram size
		MOV 	CX, 0000000000001100b
		AND 	CX, BX
		SHR 	CX, 2
		CMP 	CX, 0
		JE 		ram16
		CMP 	CX, 1
		JE 		ram32
		CMP 	CX, 2
		JE 		ram64
		MOV 	ramSize, 128
		JMP 	continuelogic

	ram16:
		MOV 	ramSize, 16
		JMP 	continuelogic

	ram32:
		MOV 	ramSize, 32
		JMP 	continuelogic

	ram64:
		MOV 	ramSize, 64

	continuelogic:
		CALL 	printRam

		// determine floppy drive count
		MOV 	CX, 0000000111000000b
		AND 	CX, BX
		SHR 	CX, 6
		ADD 	CX, 1
		MOV 	floppyCount, CX
		CALL 	printFloppy

		// determine printer count
		MOV 	CX, 1110000000000000b
		AND 	CX, BX
		SHR 	CX, 13
		MOV 	printerCount, CX
		CALL 	printPrinters

		// determine game adapter
		MOV 	CX, 0001000000000000b
		AND 	CX, BX
		SHR 	CX, 12
		CMP 	CX, 0
		JE 		installed
		CALL 	printGameYes
		JMP 	end

	installed:
		CALL 	printGameNo

	end:
	}

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
This is the content of AX at base 2: 1111101110000110
The size of RAM is 32K
The number of floppy drives are 7
The number of installed printers are 7
Game adapter is installed
*/