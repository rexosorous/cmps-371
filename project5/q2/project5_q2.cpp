#include <iostream>

// input variables
char c;

// output variables
int a_count, b_count, c_count;


void read()
{
	std::cin.get(c);
}

int main()
{
	// user input values
	std::cout << "Enter 10 grades(A,B,C,D): ";

	_asm
	{
		// init
		MOV 	a_count, 0
		MOV 	b_count, 0
		MOV 	c_count, 0

		// while loop
	whileloop:
		CALL 	read 		// read the next char in input

		// check sentinel value
		CMP 	c, '\n'
		JE 		endloop

		// increment A's, B's, C's, and D's. NON-CASE-SENSITIVE
		CMP 	c, 'a'
		JE 		addA
		CMP 	c, 'A'
		JE 		addA

		CMP 	c, 'b'
		JE 		addB
		CMP 	c, 'B'
		JE 		addB

		CMP 	c, 'c'
		JE 		addC
		CMP 	c, 'C'
		JE 		addC

		JMP 	whileloop

	// increment counters
	addA:
		INC 	a_count
		JMP 	whileloop
	addB:
		INC 	b_count
		JMP 	whileloop
	addC:
		INC 	c_count
		JMP 	whileloop

	endloop:
	}

	// output results
	std::cout << '\n';
	std::cout << "No. of \"As\" scores=" << a_count << '\n';
	std::cout << "No. of \"Bs\" scores=" << b_count << '\n';
	std::cout << "No. of \"Cs\" scores=" << c_count << '\n';

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter 10 grades(A,B,C,D): AbbBcCaA

No. of "As" scores=3
No. of "Bs" scores=3
No. of "Cs" scores=2
*/