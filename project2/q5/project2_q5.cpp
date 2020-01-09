#include <iostream>

// input variables
int a, b, c, d, h;

// output variables
int area, perimeter;


int main()
{
	// user input values
	std::cout << "Enter the values of a, b, c, d, and h: ";
	std::cin >> a >> b >> c >> d >> h;

	_asm
	{
		// calculate perimeter
		MOV 	EAX, a 	 // EAX = a
		ADD		EAX, b	 // EAX = a + b
		ADD 	EAX, c   // EAX = a + b + c
		ADD 	EAX, d	 // EAX = a + b + c + d
		MOV     perimeter, EAX

		// calculate area
		// calculate a + d
		MOV 	EAX, a 	 // EAX = a
		ADD		EAX, d	 // EAX = a + d
		//calculate (a + d) * h
		IMUL	h		 // EDX:EAX = (a + d) * h
		//calculate (a + d ) * h / 2
		MOV 	EBX, 2	 // EBX = 2
		IDIV	EBX		 // EAX = (a + d) * h / 2 , EDX = (a + d) * h % 2
		MOV 	area, EAX
	}

	// output results
	std::cout << '\n';
	std::cout << "Area = " << area << '\n';
	std::cout << "Perimeter = " << perimeter << '\n';

	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter the values of a, b, c, d, and h: 7 5 6 10 4

Area = 34
Perimeter = 28
Press any key to continue . . .
*/