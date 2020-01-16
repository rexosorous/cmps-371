#include <iostream>
#include <time.h>

// input variables
int answer;
char cont;

// storage variables
int a, b;

// output variables
int correct_count, wrong_count;


void rng()
{
	a = rand() % 100;
	b = rand() % 100;
}

void problem()
{
	std::cout << a << " + " << b << " = ? ";
	std::cin >> answer;
}

void printCorrect()
{
	std::cout << "	CORRECT\n";
}

void printWrong()
{
	std::cout << "	WRONG\n";
}

void getCont()
{
	std::cout << "CONTINUE(y/n)? ";
	std::cin >> cont;
}


int main()
{
	srand(time(0));

	_asm
	{
	mainloop:
		CALL 	rng
		CALL 	problem

		// calculate correct answer
		MOV 	EAX, a
		MOV 	EBX, b
		ADD 	EAX, EBX

		// compare to user's answer
		MOV 	EBX, answer
		CMP 	EAX, EBX
		JE 		correct
		CALL 	printWrong
		INC 	wrong_count
		JMP 	askCont

	correct:
		CALL 	printCorrect
		INC 	correct_count
		JMP 	askCont

	askCont:
		CALL 	getCont
		CMP 	cont, 'y'
		JE 		mainloop
	}

	// output
	std::cout << '\n';

	std::cout << "Number of CORRECT answers = " << correct_count << '\n';
	std::cout << "Number of WRONG answers   = " << wrong_count << '\n';

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
31 + 84 = ? 10
        WRONG
CONTINUE(y/n)? y
70 + 54 = ? 20
        WRONG
CONTINUE(y/n)? y
12 + 73 = ? 85
        CORRECT
CONTINUE(y/n)? n

Number of CORRECT answers = 1
Number of WRONG answers   = 2
*/