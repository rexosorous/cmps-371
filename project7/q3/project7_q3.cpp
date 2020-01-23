#include <iostream>
#include <string>
#include <time.h>


// input variables
char floorNum;

// output variables
std::string floorList;

// storage variables
short binaryVal, index, randCount;


void genRandom()
{
	floorNum = rand()%15 + 2;
}

void printZero()
{
	std::cout << 0;
}

void printOne()
{
	std::cout << 1;
}

void appendFloor()
{
	floorList += std::to_string(binaryVal) + ' ';
}


int main()
{
	// init
	srand(time(0));
	std::cout << "AX=";

	_asm
	{
		// init
		MOV 	index, 16
		MOV 	randCount, 10
	
		// generate random floor numbers
	randomize:
		CMP 	randCount, 0
		JE 		mainloop

		CALL 	genRandom
		MOV 	CX, 1
		MOV 	CL, floorNum
		SHL 	CX, CL
		OR 		BX, CX
		DEC 	randCount
		JMP 	randomize


	mainloop:
		// check sentinel value
		CMP 	index, 0
		JLE 	endloop

		// extract left most bit
		MOV 	CX, 0x8000
		AND 	CX, BX
		SHR 	CX, 15

		// print the left most bit
		CMP 	CX, 0
		JE 		zero 
		CALL 	printOne
		// keep track of all the floors the stop at
		MOV 	AX, index
		MOV 	binaryVal, AX
		CALL 	appendFloor
		JMP 	continueloop

	zero:
		CALL 	printZero

	continueloop:
		DEC 	index
		SHL 	BX, 1
		JMP 	mainloop

	endloop:
	}

	// output results
	std::cout << std::endl;
	std::cout << "Elevator will stop at the following floors: " << floorList << std::endl;

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
AX=1111101010100000
Elevator will stop at the following floors: 16 15 14 13 12 10 8 6
*/