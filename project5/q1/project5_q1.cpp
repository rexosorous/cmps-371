#include <iostream>
#include <string>

// input variables
std::string name;
char gender, cont;
short age;

// output variables
std::string title;
short price;

// constant variables
const short ADULT_M = 150;
const short ADULT_F = 100;
const short TEEN_M = 170;
const short TEEN_F = 300;


void getName()
{
	std::cout << "Enter your name and gender: ";
	std::cin >> name >> gender;
}

void getAge()
{
	std::cout << title << " " << name << ", how old are you? ";
	std::cin >> age;
}

void printPrice()
{
	std::cout << "	" << title << " " << name << " your membership is $" << price << "\n\n";
}

void getContinue()
{
	std::cout << "CONTINUE(y/n)? ";
	std::cin >> cont;
}

void setMaleTitle()
{
	title = "Mr.";
}

void setFemaleTitle()
{
	title = "Ms.";
}



int main()
{
	_asm
	{
		// main loop
	mainloop:
		// get user name and age
		CALL 	getName

		// differentiate between male and female
		CMP 	gender, 'm'
		JE 		male
		cmp 	gender, 'f'
		JE 		female

		// get male age and determine price
	male:
		CALL 	setMaleTitle
		CALL 	getAge
		CMP 	age, 18
		JGE 	maleAdult
		JMP 	maleTeen

	maleAdult:
		MOV 	BX, ADULT_M
		MOV 	price, BX
		JMP 	contloop

	maleTeen:
		MOV 	BX, TEEN_M
		MOV 	price, BX
		JMP 	contloop


		// get female age and determine price
	female:
		CALL 	setFemaleTitle
		CALL 	getAge
		CMP 	age, 18
		JGE 	femaleAdult
		JMP 	femaleTeen

	femaleAdult:
		MOV 	BX, ADULT_F
		MOV 	price, BX
		JMP 	contloop

	femaleTeen:
		MOV 	BX, TEEN_F
		MOV 	price, BX
		JMP 	contloop


		// determine if user wants to continue
	contloop:
		CALL 	printPrice
		CALL 	getContinue
		CMP 	cont, 'y'
		JE 		mainloop
	}

	// output results
	std::cout << '\n';



	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
Enter your name and gender: John m
Mr. John, how old are you? 27
        Mr. John your membership is $150

CONTINUE(y/n)? y
Enter your name and gender: Mary f
Ms. Mary, how old are you? 15
        Ms. Mary your membership is $300

CONTINUE(y/n)? n
*/