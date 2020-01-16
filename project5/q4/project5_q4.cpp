#include <iostream>

// input variables
int numStudents, score;

// output variables
int avg, max, min;

// storage variables
int total;


void read()
{
	std::cin >> score;
}

int main()
{
	// user input values
	std::cout << "Please enter the number of students: ";
	std::cin >> numStudents;
	std::cout << "	Enter " << numStudents << " scores: ";

	_asm
	{
		// init
		CALL 	read
		MOV 	EDX, score
		MOV 	max, EDX
		MOV 	min, EDX
		MOV 	ECX, EDX	// total
		MOV 	total, ECX
		MOV 	EBX, 1 		// sentinel value

	// for loop
	forloop:
		// check sentinel value
		CMP 	EBX, numStudents;
		JE 		endloop

		CALL 	read 		// read the next int in input
		MOV 	EDX, score
		MOV 	ECX, total
		ADD 	ECX, EDX 	// ECX += score
		MOV 	total, ECX

		// check max
		CMP 	max, EDX
		JL 		updateMax

		// check min
		CMP 	min, EDX
		JG 		updateMin

		INC 	EBX 		// increment sentinel value
		JMP 	forloop

	// keep track of max and min
	updateMax:
		MOV 	max, EDX
		INC 	EBX 		// increment sentinel value
		JMP 	forloop

	updateMin:
		MOV 	min, EDX
		INC 	EBX 		// increment sentinel value
		JMP 	forloop

	endloop:
	// calculate average
		MOV 	EAX, ECX 	// EAX = ECX
		CDQ
		IDIV 	EBX 		// EAX = EAX/EBX , EDX = EAX%EBX
		MOV 	avg, EAX
	}

	// output results
	std::cout << '\n';
	std::cout << "	Class average:" << avg << '\n';
	std::cout << "	Maximum score:" << max << '\n';
	std::cout << " 	Minimum score:" << min << '\n';

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Please enter the number of students: 5
        Enter 5 scores: 85 75 55 95 80

        Class average:78
        Maximum score:95
        Minimum score:55
*/