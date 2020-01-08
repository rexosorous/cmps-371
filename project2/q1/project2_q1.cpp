#include <iostream>

// input variables
short len, wid;

// output variables
short area, perimeter;


int main()
{
	// user input values
	std::cout << "enter length: ";
	std::cin >> len;
	std::cout << "enter width: ";
	std::cin >> wid;

	_asm
	{
		// calculate area
		MOV		AX, len 	// AX = len
		IMUL	wid 		// DX:AX = len * wid
		MOV 	area, AX

		// calculate perimeter
		MOV		AX, len 	// AX = len
		ADD 	AX, len 	// AX = len + len
		ADD 	AX, wid 	// AX = len + len + wid
		ADD 	AX, wid 	// AX = len + len + wid + wid
		MOV 	perimeter, AX
	}

	// output results
	std::cout << '\n';
	std::cout << "Area = " << area << '\n';
	std::cout << "Perimter = " << perimeter << '\n';

	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
enter length: 23
enter width: 44

Area = 1012
Perimter = 134
Press any key to continue . . .
*/