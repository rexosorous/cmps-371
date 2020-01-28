#include <iostream>
#include <iomanip>



// input variables
int customerCount, sandwichSize;
float drinkCount, sandwichCount;
char drinkType;

// storage variables
const float SODA = 2.25;
const float WATER = 1.75;
const float JUICE = 2.80;
const float SANDWICH10 = 3.45;
const float SANDWICH12 = 5.25;
int index;

// output variables
float bill;



void getOrder()
{
    std::cout << "Customer " << index << std::endl;
    std::cout << "     How many drinks? ";
    std::cin >> drinkCount;
    std::cout << "      What kind of drink (S=Soda, W=Water, J=Juice)? ";
    std::cin >> drinkType;
    std::cout << "      How many sandwiches? ";
    std::cin >> sandwichCount;
    std::cout << "      What size of sandwich (10/12 inches)? ";
    std::cin >> sandwichSize;
}

void printBill()
{
    std::cout << "            Your total bill = $" << bill << std::endl << std::endl;
}


int main()
{
    // intitial output
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "--------------- 7-11 Convenience Store ---------------" << std::endl;
    std::cout << "Drinks" << std::endl;
    std::cout << "     Soda (S)....................................$2.25" << std::endl;
    std::cout << "     Water (W)...................................$1.75" << std::endl;
    std::cout << "     Juice (J)...................................$2.80" << std::endl;
    std::cout << "Sandwiches" << std::endl;
    std::cout << "     10 inches...................................$3.45" << std::endl;
    std::cout << "     12 inches...................................$5.25" << std::endl;

    // get user input
    std::cout << std::endl;
    std::cout << "Enter the number of customers: ";
    std::cin >> customerCount;

    _asm
    {
        // init
        MOV     index, 1

    mainloop:
        // check sentinel value
        CMP     index, 2
        JG      endloop

        // get user input
        CALL    getOrder

        // calculate drink subtotal
        CMP     drinkType, 'S'
        JE      soda 
        CMP     drinkType, 'W'
        JE      water 
        CMP     drinkType, 'J'
        JE      juice 

    soda:
        FLD     SODA
        JMP     sandwich

    water:
        FLD     WATER
        JMP     sandwich

    juice:
        FLD     JUICE
        JMP     sandwich

    sandwich:
        FLD     drinkCount
        FMUL

        // calculate sandwich subtotal
        CMP     sandwichSize, 10
        JE      small
        CMP     sandwichSize, 12
        JE      large

    small:
        FLD     SANDWICH10
        JMP     grandtotal

    large:
        FLD     SANDWICH12
        JMP     grandtotal

    grandtotal:
        FLD     sandwichCount
        FMUL
        FADD
        FSTP    bill
        CALL    printBill

        // prepare for next iteration
        INC     index
        JMP     mainloop

    endloop:
    }

    std::cout << std::endl;
    system("pause");
    return 0;
} 