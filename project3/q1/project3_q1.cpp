#include <iostream>

// input variables
short a, b, c, d, e, f;

// output variables
short x, y;


int main()
{
	// get user input
	std::cout << "This program solves the system\n" <<
				"	aX + bY = c\n"<<
				" 	dX + eY = f\n";
	std::cout << "Enter the values of a, b, and c: ";
	std::cin >> a >> b >> c;
	std::cout << "Enter the values of d, e, and f: ";
	std::cin >> d >> e >> f;

	_asm
	{
		// calculate X

		// BX = b*d
		MOV 	AX, b
		MOV 	DX, d
		IMUL 	DX
		MOV 	BX, AX

		// DX:AX = a*e
		MOV 	AX, a
		MOV 	DX, e
		IMUL 	DX

		// BX = a*e - b*d
		SUB 	AX, BX
		MOV 	BX, AX



		// CX = b*f
		MOV 	AX, b
		MOV 	DX, f
		IMUL 	DX
		MOV 	CX, AX

		// DX:AX = c*e
		MOV 	AX, c
		MOV 	DX, e
		IMUL 	DX

		// CX = c*e - b*f
		SUB 	AX, CX

		// x = (c*e - b*f) / (a*e - b*d)
		IDIV 	BX
		MOV 	x, AX




		// calculate Y

		// BX = b*d
		MOV 	AX, b
		MOV 	BX, d
		IMUL 	BX
		MOV 	BX, AX

		// DX:AX = a*e
		MOV 	AX, a
		MOV 	CX, e
		IMUL 	CX

		// BX = a*e - b*d
		SUB 	AX, BX
		MOV 	BX, AX



		// CX = c*d
		MOV 	AX, c
		MOV 	DX, d
		IMUL 	DX
		MOV 	CX, AX

		// DX:AX = a*f
		MOV 	AX, a
		MOV 	DX, f
		IMUL 	DX

		// CX = a*f - c*d
		SUB 	AX, CX

		// x = (c*e - b*f) / (a*e - b*d)
		IDIV 	BX
		MOV 	y, AX
	}

	// output results
	std::cout << '\n';
	std::cout << "	X = " << x << '\n';
	std::cout << "	Y = " << y << '\n';

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
This program solves the system
        aX + bY = c
        dX + eY = f
Enter the values of a, b, and c: 3 1 1
Enter the values of d, e, and f: 1 -2 5

        X = 1
        Y = -2
*/