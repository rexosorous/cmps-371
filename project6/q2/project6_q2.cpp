#include <iostream>
#include <bitset>


// input variables
short numCount, num;

// storage variables
short index;



void getNum()
{
	std::cout << "	Enter an integer number: ";
	std::cin >> num;
}

void printEven()
{
	std::cout << "		" << num << " is EVEN" << std::endl;
}

void printOdd()
{
	std::cout << "		" << num << " is ODD" << std::endl;
}


int main()
{
	// get user input
	std::cout << "How many numbers would you like to try: ";
	std::cin >> numCount;

	_asm
	{
		// init
		MOV 	index, 0

	mainloop:
		// check for sentinel value
		MOV 	AX, numCount
		CMP 	index, AX
		JGE 	endloop

		// get user input
		CALL 	getNum
		MOV 	AX, num

		// extract right most bit
		MOV 	BX, 0x0001
		AND 	AX, BX

		// determine if even or odd
		CMP 	AX, 1
		JE 		odd
		CALL 	printEven
		JMP 	continueloop

	odd:
		CALL 	printOdd

	continueloop:
		INC 	index
		JMP 	mainloop

	endloop:
	}

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
How many numbers would you like to try: 4
        Enter an integer number: 124
                124 is EVEN
        Enter an integer number: 37
                37 is ODD
        Enter an integer number: 3456
                3456 is EVEN
        Enter an integer number: 555
                555 is ODD
*/