#include <iostream>
#include <string>



// output variables
short onCount;
std::string offList;

// storage variables
short binaryVal, index;


void printZero()
{
	std::cout << 0;
}

void printOne()
{
	std::cout << 1;
}

void appendOff()
{
	offList += std::to_string(binaryVal) + ' ';
}


int main()
{
	std::cout << "AX=";
	_asm
	{
		// init
		MOV 	index, 16
		MOV 	onCount, 0
		MOV 	BX, 0x6A2F

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
		INC 	onCount 	// keep track of how many sprinklers are on
		JMP 	continueloop

	zero:
		CALL 	printZero
		// keep track of all the spinklers that are off
		MOV 	AX, index
		MOV 	binaryVal, AX
		CALL 	appendOff

	continueloop:
		DEC 	index
		SHL 	BX, 1
		JMP 	mainloop

	endloop:
	}

	// output results
	std::cout << std::endl;
	std::cout << onCount << " sprinklers are ON" << std::endl;
	std::cout << "Defective sprinklers are: " << offList << std::endl;

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
AX=0110101000101111
9 sprinklers are ON
Defective sprinklers are: 16 13 11 9 8 7 5
*/