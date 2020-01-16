#include <iostream>

// input variables
int num;


void printOdd()
{
	std::cout << "	" << num << " is EVEN";
}

void printEven()
{
	std::cout << "	" << num << " is ODD";
}


int main()
{
	std::cout << "Enter a number: ";
	std::cin >> num;

	_asm
	{
		MOV 	EAX, num
		CDQ
		MOV 	EBX, 2
		IDIV 	EBX

		CMP 	EDX, 0
		JE 		isOdd
		JMP 	isEven

	isEven:
		CALL 	printEven
		JMP 	end

	isOdd:
		CALL 	printOdd
		JMP 	end

	end:
	}

	// end
	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter a number: 123
        123 is ODD


Enter a number: 12
        12 is EVEN


Enter a number: 335
        335 is ODD
*/