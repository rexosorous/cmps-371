#include <iostream>

// constant variables
const short SANDWICH = 4, DRINK = 2, CHIP = 1;

// input variables
short sandwiches, drinks, chips;

// output variables
short total;


int main()
{
	// user input values
	std::cout << "How many sandwiches? ";
	std::cin >> sandwiches;
	std::cout << "How many drinks? ";
	std::cin >> drinks;
	std::cout << "How many chips? ";
	std::cin >> chips;

	_asm
	{
		// calculate sandwich price
		MOV 	AX, SANDWICH // AX = 4
		IMUL	sandwiches	 // DX:AX = 4 * sandwiches
		MOV		BX, AX		 // BX = 4 * sandwiches

		// calculate drink price
		MOV 	AX, DRINK 	 // AX = 2
		IMUL 	drinks 		 // AX = 2 * drinks
		MOV 	CX, AX 		 // CX = 2 * drinks

		// calculate chip price
		MOV 	AX, CHIP 	 // AX = 1
		IMUl 	chips 		 // AX = 1 * chips

		// calculate total price
		ADD		AX, CX		 // AX = (1 * chips) + (2 * drinks)
		ADD		AX, BX		 // AX = (1 * chips) + (2 * drinks) + (4 * sandwiches)
		MOV 	total, AX
	}

	// output results
	std::cout << '\n';
	std::cout << "Your total bill is " << total << '\n';

	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
How many sandwiches? 3
How many drinks? 2
How many chips? 4

Your total bill is 20
Press any key to continue . . .
*/