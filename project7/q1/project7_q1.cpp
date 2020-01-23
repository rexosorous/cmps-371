#include <iostream>

// input variables
char next;

// output variables
char fixed;


void read()
{
	std::cin.get(next);
}

void print()
{
	std::cout << fixed;
}


int main()
{
	// user input values
	std::cout << "Enter a sentence: ";

	_asm
	{
		// upper: 65-90
		// lower: 97-122
		// diff : 32

	mainloop:
		// init
		CALL 	read
		MOV 	AH, next

		// check sentinel value
		CMP 	next, '\n'
		JE 		endloop

		// check for upper case
		CMP 	next, 'A'
		JL 		printnormal
		CMP 	next, 'Z'
		JL 		printlower

		// check for lower case
		CMP 	next, 'a'
		JL 		printnormal
		CMP 	next, 'z'
		JL 		printupper
		JMP 	printnormal

		// prints chars as is to handle spaces and other special chars
	printnormal:
		MOV 	fixed, AH
		JMP 	continueloop

		// converts from upper to lower case
	printlower:
		ADD 	AH, 32
		MOV 	fixed, AH
		JMP 	continueloop

		// converts from lower to upper case
	printupper:
		SUB 	AH, 32
		MOV 	fixed, AH
		JMP 	continueloop

	continueloop:
		CALL 	print
		JMP 	mainloop

	endloop:
	}

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter a sentence: Today Is Tue
tODAY iS tUE
*/