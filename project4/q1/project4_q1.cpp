#include <iostream>
#include <string>

// input variables
short age;
char gender;
std::string name;

// output variables
short price;

// constant variables
const short M_CHILD = 50;
const short M_TEEN = 70;
const short M_ADULT = 100;
const short F_CHILD = 40;
const short F_TEEN = 80;
const short F_ADULT = 120;



void getName()
{
	std::cout << "Please enter your name: ";
	std::cin >> name;
}

void getInfo()
{
	std::cout << name << ", enter your age and gender (m/f): ";
	std::cin >> age >> gender;
}

void printPrice()
{
	std::cout << "	" << name << ", your membership is $" << price << "\n\n";
}


int main()
{
	std::cout << "------------ La Verne Private Club ------------\n";
	std::cout << "Male\n";
	std::cout << "	Children (age<13)..............$50\n";
	std::cout << "	Teenagers (13<=age<=19)........$70\n";
	std::cout << "	Adults (age>19)................$100\n";
	std::cout << "Female\n";
	std::cout << "	Children (age<13)..............$40\n";
	std::cout << "	Teenagers (13<=age<=19)........$80\n";
	std::cout << "	Adults (age>19)................$120\n\n";

	_asm
	{
		// get user input
		CALL 	getName
		CALL 	getInfo

		// determine price
		CMP 	gender, 'f'
		JE 		female
		CMP 	gender, 'F'
		JE 		female
		CMP 	gender, 'm'
		JE 		male
		CMP 	gender, 'M'
		JE 		male

		// determine age
	female:
		CMP 	age, 13
		JL 		femaleChild
		CMP 	age, 19
		JLE 	femaleTeen
		JMP 	femaleAdult

	male:
		CMP 	age, 13
		JL 		maleChild
		CMP 	age, 19
		JLE 	maleTeen
		JMP 	maleAdult

		// determine price
	femaleChild:
		MOV 	AX, F_CHILD
		MOV 	price, AX
		JMP 	end

	femaleTeen:
		MOV 	AX, F_TEEN
		MOV 	price, AX
		JMP 	end

	femaleAdult:
		MOV 	AX, F_ADULT
		MOV 	price, AX
		JMP 	end

	maleChild:
		MOV 	AX, M_CHILD
		MOV 	price, AX
		JMP 	end

	maleTeen:
		MOV 	AX, M_TEEN
		MOV 	price, AX
		JMP 	end

	maleAdult:
		MOV 	AX, M_ADULT
		MOV 	price, AX
		JMP 	end

	end:
		CALL 	printPrice
	}

	// end
	std::cout << '\n';
	system("pause");
	return 0;
}


/* ---------- OUTPUT -----------
------------ La Verne Private Club ------------
Male
        Children (age<13)..............$50
        Teenagers (13<=age<=19)........$70
        Adults (age>19)................$100
Female
        Children (age<13)..............$40
        Teenagers (13<=age<=19)........$80
        Adults (age>19)................$120

Please enter your name: Mary
Mary, enter your age and gender (m/f): 17 f
        Mary, your membership is $80



------------ La Verne Private Club ------------
Male
        Children (age<13)..............$50
        Teenagers (13<=age<=19)........$70
        Adults (age>19)................$100
Female
        Children (age<13)..............$40
        Teenagers (13<=age<=19)........$80
        Adults (age>19)................$120

Please enter your name: Tom
Tom, enter your age and gender (m/f): 7 M
        Tom, your membership is $50



------------ La Verne Private Club ------------
Male
        Children (age<13)..............$50
        Teenagers (13<=age<=19)........$70
        Adults (age>19)................$100
Female
        Children (age<13)..............$40
        Teenagers (13<=age<=19)........$80
        Adults (age>19)................$120

Please enter your name: Bill
Bill, enter your age and gender (m/f): 15 m
        Bill, your membership is $70



------------ La Verne Private Club ------------
Male
        Children (age<13)..............$50
        Teenagers (13<=age<=19)........$70
        Adults (age>19)................$100
Female
        Children (age<13)..............$40
        Teenagers (13<=age<=19)........$80
        Adults (age>19)................$120

Please enter your name: Bob
Bob, enter your age and gender (m/f): 27 M
        Bob, your membership is $100
*/