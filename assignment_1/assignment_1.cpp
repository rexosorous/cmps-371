#include <iostream>

// input variables
short len, wid, a, b, c, h;

// output variables
short rect_perim, rect_area, tri_perim, tri_area;


int main()
{
	// user input values
	std::cout << "enter rectangle length: ";
	std::cin >> len;
	std::cout << "enter rectangle width: ";
	std::cin >> wid;
	std::cout << "enter triangle a: ";
	std::cin >> a;
	std::cout << "enter triangle b: ";
	std::cin >> b;
	std::cout << "enter triangle c: ";
	std::cin >> c;
	std::cout << "enter triangle h: ";
	std::cin >> h;

	_asm
	{
		// calculate rectangle perimeter
		MOV		AX, len // AX = len
		ADD		AX, len // AX = len + len
		ADD		AX, wid // AX = len + len + wid
		ADD		AX, wid // AX = len + len + wid + wid
		MOV		rect_perim, AX

		// calculate rectangle area
		MOV		AX, len // AX = len
		IMUL	wid     // DX:AX = len * wid
		MOV		rect_area, AX

		// calculate triangle perimeter
		MOV		AX, a  // AX = a
		ADD		AX, b  // AX = a + b
		ADD		AX, c  // AX = a + b + c
		MOV		tri_perim, AX

		// calculate triangle area
		MOV		AX, c  // AX = c
		IMUL 	h      // DX:AX = c * h
		MOV		BX, 2  // BX = 2
		IDIV	BX     // AX = (c * h) / 2 , DX = (c * h) % 2
		MOV 	tri_area, AX
	}

	// output results
	std::cout << '\n';
	std::cout << "rectangle perimeter: " << rect_perim << '\n';
	std::cout << "rectangle area: " << rect_area << '\n';
	std::cout << "triangle perimeter: " << tri_perim << '\n';
	std::cout << "triangle area: " << tri_area << '\n';

	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
enter rectangle length: 5
enter rectangle width: 10
enter triangle a: 7
enter triangle b: 6
enter triangle c: 10
enter triangle h: 5

rectangle perimeter: 30
rectangle area: 50
triangle perimeter: 23
triangle area: 25
Press any key to continue . . .
*/