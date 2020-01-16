#include <iostream>

// input variables
int count, sandwichSize;
char drinktype;

// output variables
int bill;

// constant variables
const int SODA_PRICE = 2;
const int WATER_PRICE = 1;
const int BEER_RPICE = 3;
const int SANDIWCH_6 = 2;
const int SANDWICH_10 = 3;
const int SANDWICH_12 = 5;



void get_drink_count()
{
	std::cout << "How many drinks? ";
	std::cin >> count;
}

void get_drink_drinktype()
{
	std::cout << "	What kind of drink (S=Soda, W=Water, B=Beer)? ";
	std::cin >> drinktype;
}

void get_sandwich_count()
{
	std::cout << "How many sandwiches? ";
	std::cin >> count;
}

void get_sandwich_size()
{
	std::cout << "	What size of sandwich (6/10/12 inches)? ";
	std::cin >> sandwichSize;
}


int main()
{
	_asm
	{
		// --------- DRINKS ------- //

		// get user input for drinks
		CALL 	get_drink_count
		CALL 	get_drink_drinktype

		// determine drink drinktype
		CMP 	drinktype, 'S'
		JE 		soda
		CMP 	drinktype, 'W'
		JE 		water
		CMP 	drinktype, 'B'
		JE 		beer
		MOV 	EBX, 0
		JMP 	sandwiches

		// EAX = drink price
	soda:
		MOV		EAX, SODA_PRICE
		JMP 	drinkprice

	water:
		MOV 	EAX, WATER_PRICE
		JMP 	drinkprice

	beer:
		MOV 	EAX, BEER_RPICE
		JMP 	drinkprice

		// EBX = total drink price
	drinkprice:
		MOV 	EBX, count
		IMUL 	EBX
		MOV 	EBX, EAX



		// -------- SANDWICHES ---------- //

		// get user input for sandwiches
	sandwiches:
		CALL 	get_sandwich_count
		CALL 	get_sandwich_size

		// determine sandwich size
		CMP 	sandwichSize, 6
		JE 		six
		CMP 	sandwichSize, 10
		JE 		ten
		CMP 	sandwichSize, 12
		JE 		twelve
		MOV 	EAX, 0
		JMP 	totalbill

		// EAX = sandwich price
	six:
		MOV 	EAX, SANDIWCH_6
		JMP 	sandwichprice

	ten:
		MOV 	EAX, SANDWICH_10
		JMP 	sandwichprice

	twelve:
		MOV 	EAX, SANDWICH_12
		JMP 	sandwichprice

		// EDX:EAX = total sandwich price
	sandwichprice:
		MOV 	EDX, count
		IMUL 	EDX



		// -------- TOTAL BILL ----- //

		// EAX = total bill
	totalbill:
		ADD 	EAX, EBX
		MOV 	bill, EAX
	}

	// output results
	std::cout << '\n';
	std::cout << "Your total bill = $" << bill << '\n';

	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
How many drinks? 2
        What kind of drink (S=Soda, W=Water, B=Beer)? S
How many sandwiches? 3
        What size of sandwich (6/10/12 inches)? 6

Your total bill = $10



How many drinks? 2
        What kind of drink (S=Soda, W=Water, B=Beer)? b
How many sandwiches? 2
        What size of sandwich (6/10/12 inches)? 12

Your total bill = $10
*/