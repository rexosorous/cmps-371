#include <iostream>

// input variables
char c;

// output variables
int y_count, n_count;


void read()
{
	std::cin.get(c);
}

void printYes()
{
	std::cout << "	YES VOTES=" << y_count << " = ";
}

void printNo()
{
	std::cout << "	NO  VOTES=" << n_count << " = ";
}

void printAsterisk()
{
	std::cout << "* ";
}

void printNewLine()
{
	std::cout << '\n';
}

int main()
{
	// user input values
	std::cout << "Enter a group of votes:\n";

	_asm
	{
		// init
		MOV 	y_count, 0
		MOV 	n_count, 0

	// while loop
	whileloop:
		CALL 	read 		// read the next char in input

		// check sentinel value
		CMP 	c, '\n'
		JE 		endwhileloop

		// count yes votes
		CMP 	c, 'y'
		JE 		addY
		CMP 	c, 'Y'
		JE 		addY

		// count no votes
		CMP 	c, 'n'
		JE 		addN
		CMP 	c, 'N'
		JE 		addN

		JMP 	whileloop

	// increment counters
	addY:
		INC 	y_count
		JMP 	whileloop
	addN:
		INC 	n_count
		JMP 	whileloop

	endwhileloop:

		// output
		CALL 	printYes
	
	yesloop:
		CMP 	y_count, 0
		JE 		endyesloop
		CALL 	printAsterisk
		DEC 	y_count
		JMP 	yesloop

	endyesloop:
		CALL 	printNewLine
		CALL 	printNo

	noloop:
		CMP 	n_count, 0
		JE 		endnoloop
		CALL 	printAsterisk
		DEC 	n_count
		JMP 	noloop

	endnoloop:
	}

	// output results
	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter a group of votes:
yNNNYnyynN
        YES VOTES=4 = * * * *
        NO  VOTES=6 = * * * * * *
*/