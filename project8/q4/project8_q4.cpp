#include <iostream>
#include <time.h>
#include <algorithm>



// given variables
int s[7];

// storage variables
int rng, index, arrVal, sorted;



void genRNG()
{
    rng = rand()%100;
}

void printUnsorted()
{
    std::cout << "Unsorted: ";
}

void printSorted()
{
    std::cout << "Sorted:   ";
}

void printVal()
{
    std::cout << arrVal;
}

void printComma()
{
    std::cout << ", ";
}

void printLine()
{
    std::cout << std::endl;
}

void sortArr()
{
    std::sort(s, s+7);
}

int main()
{
    // init
    srand(time(0));

    _asm
    {
        // init
        LEA     EBX, s
        MOV     EAX, [EBX]
        MOV     index, 0
        MOV     sorted, 0

    generate_array_loop:
        // check sentinel value
        CMP     index, 7
        JGE     end_gen_loop

        // fill the array with random numbers
        CALL    genRNG
        MOV     EAX, rng
        MOV     [EBX], EAX

        // prepare for next iteration
        INC     index
        ADD     EBX, 4
        JMP     generate_array_loop

    end_gen_loop:
        // prepare for next loop
        MOV     index, 0
        LEA     EBX, s
        CALL    printUnsorted



    display_loop:
        // check sentinel value
        CMP     index, 7
        JGE     end_display_loop

        // print the contents of the array
        MOV     ECX, [EBX]
        MOV     arrVal, ECX
        CALL    printVal
        CMP     index, 6
        JGE     end_display_loop
        CALL    printComma

        // prepare for next iteration
        INC     index
        ADD     EBX, 4
        JMP     display_loop



    end_display_loop:
        CMP     sorted, 0
        JE      sort
        JMP     end

    sort:
        // sort the array and display it again
        CALL    sortArr
        CALL    printLine
        CALL    printSorted
        MOV     sorted, 1
        MOV     index, 0
        LEA     EBX, s
        JMP     display_loop



    end:
    }

    std::cout << '\n';
    std::cout << std::endl;
    system("pause");
    return 0;
}