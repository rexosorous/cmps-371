#include <iostream>

// input variables
int num;

// storage variables
int sum;

void printSum()
{
	std::cout << "	Total of digits is " << sum << '\n';
}

void printNotDivisible()
{
	std::cout << "	" << num << " is not divisible by 3\n";
}

void printDivisible()
{
	std::cout << "	" << num << " is divisible by 3\n";
}

int main()
{
	std::cout << "Enter a number: ";
	std::cin >> num;

	_asm
	{
		// EBX = first digit
		MOV 	EAX, num
		CDQ
		MOV 	ECX, 100
		IDIV 	ECX
		MOV 	EBX, EAX

		// EAX = second digit, EDX = third digit
		MOV 	EAX, EDX
		CDQ
		MOV 	ECX, 10
		IDIV 	ECX

		// EAX = sum of all digits
		ADD 	EAX, EDX
		ADD 	EAX, EBX

		// print sum
		MOV 	sum, EAX
		CALL 	printSum

		// determine divisibility
		CDQ
		MOV 	ECX, 3
		IDIV 	ECX
		CMP 	EDX, 0
		JE 		isdiv
		JMP 	notdiv

	isdiv:
		CALL 	printDivisible
		JMP 	end

	notdiv:
		CALL 	printNotDivisible
		JMP 	end

	end:
	}

	// end
	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter a number: 125
        Total of digits is 8
        125 is not divisible by 3


Enter a number: 225
        Total of digits is 9
        225 is divisible by 3
*/