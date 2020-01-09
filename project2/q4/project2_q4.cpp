#include <iostream>

// input variables
short fahrenheit;

// output variables
short celsius;


int main()
{
	// user input values
	std::cout << "Enter temperature in Fahrenheit: ";
	std::cin >> fahrenheit;

	_asm
	{
		// formula: C = 5(F-32)/9
		// calculate F - 32
		MOV		AX, fahrenheit 	// AX = fahrenheit
		SUB		AX, 32			// AX = fahrenheit - 32

		// calculate 5 * (F - 32)
		MOV 	BX, 5			// BX = 5
		IMUL 	BX				// DX:AX = 5 * (fahrenheit - 32)

		// calculate 5 * (F - 32) / 9
		MOV 	BX, 9			// BX = 9
		IDIV	BX				// AX = 5 * (fahrenheit - 32) / 9 , DX = 5 * (fahrenheit - 32) % 9
		MOV 	celsius, AX
	}

	// output results
	std::cout << '\n';
	std::cout << fahrenheit << char(248) << "F is " << celsius << char(248) << "C" << '\n';

	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter temperature in Fahrenheit: 95

95°F is 35°C
Press any key to continue . . .
*/