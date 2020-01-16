#include <iostream>

// input
short input;

// output
short digit;

// temp
short counter;


void printDigit()
{
	std::cout << digit;
}

void printSpace()
{
	std::cout << ' ';
}

int main()
{
	std::cout << "enter a number: ";
	std::cin >> input;

	_asm
	{
		//init
		MOV 	counter, 8 			// sentinel

	forloop:
		// check sentinel value
		CMP 	counter, 0
		JE 		endloop

		// add spaces
		MOV 	AX, counter
		MOV 	CX, 4
		CWD
		IDIV 	CX
		CMP 	DX, 0
		JNE 	skipspace
		CALL 	printSpace

	skipspace:
		// extract the leading digit
		MOV 	BX, 10000000b
		AND 	BX, input
		SHR 	BX, 7

		// print digit 
		MOV 	digit, BX
		CALL 	printDigit

		// prepare for next loop
		SHL 	input, 1 			// to read the next digit of input
		DEC 	counter  			// decrement sentinel
		JMP 	forloop

	endloop:
	}

	// output results
	std::cout << '\n';

	std::cout << '\n';
	system("pause");
	return 0;
}