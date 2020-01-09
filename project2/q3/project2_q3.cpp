#include <iostream>

// input variables
short num;

// output variables
short sum;


int main()
{
	// user input values
	std::cout << "Enter a three digit integer number: ";
	std::cin >> num;

	_asm
	{
		// calculate hundreds place
		MOV		AX, num 	// AX = num
		CWD					// AX:DX = num
		MOV 	BX, 100		// BX = 100
		IDIV 	BX 			// AX = num / 100 , DX = num % 100
		MOV		BX, AX		// BX = num / 100 <first digit>

		// calculate tens place
		MOV 	AX, DX		// AX = num % 100
		MOV		DX, 0	    // reset DX to 0
		CWD					// AX:DX = num % 100
		MOV		CX, 10		// CX = 10
		IDIV	CX			// AX = (num % 100) / 10 <second digit> , DX = (num % 100) % 10 <third digit>

		// calculate sum
		ADD		AX, DX      // AX = second digit + third digit
		ADD		AX, BX		// AX = first digit + second digit + third digit
		MOV 	sum, AX
	}

	// output results
	std::cout << '\n';
	std::cout << "Sum of digits in  " << num << " is " << sum << '\n';

	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter a three digit integer number: 362

Sum of digits in  362 is 11
Press any key to continue . . .
*/