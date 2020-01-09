#include <iostream>

// input variables
int c;

// output variables
int f;


int main()
{
	// user input values
	std::cout << "Enter temperature in Celsius: ";
	std::cin >> c;

	_asm
	{
		// calculate 9c
		MOV 	EAX, c 	// EAX = c
		MOV 	EBX, 9 	// EBX = 9
		IMUL	EBX		// EDX:EAX = c * 9

		// calculate 9c/5
		MOV		EBX, 5	// EBX = 5
		IDIV	EBX		// EAX = 9c/5, EDX = 9c%5

		//calculate 9c/5 + 32
		ADD		EAX, 32	// EAX = 9c/5 + 32
		MOV 	f, EAX
	}

	// output results
	std::cout << '\n';
	std::cout << c << char(248) << "C is " << f << char(248) << "F" << '\n';

	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter temperature in Celsius: 35

35°C is 95°F
Press any key to continue . . .
*/