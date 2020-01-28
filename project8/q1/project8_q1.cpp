#include <iostream>



// given variables
int a[7] = {33, 66, 11, 17, 20, 25, 10};

// output variables
int total, max, min;

// storage variables
int index;



int main()
{
    _asm
    {
        // init
        LEA     EBX, a
        MOV     EAX, [EBX]
        MOV     total, EAX
        MOV     max, EAX
        MOV     min, EAX
        ADD     EBX, 4
        MOV     index, 1

    mainloop:
        // check sentinel value
        CMP     index, 7
        JGE     endloop

        MOV     EAX, [EBX]

        // keep track of total
        MOV     ECX, total
        ADD     ECX, EAX
        MOV     total, ECX

        // keep track of max
        CMP     EAX, max
        JG      updatemax

        // keep track of min
        CMP     EAX, min
        JL      updatemin

        JMP     continueloop

    updatemax:
        MOV     max, EAX
        JMP     continueloop

    updatemin:
        MOV     min, EAX
        JMP     continueloop

    continueloop:
        INC     index
        ADD     EBX, 4
        JMP     mainloop

    endloop:
    }

    std::cout << '\n';
    std::cout << "Total  : " << total << std::endl;
    std::cout << "Maximum: " << max << std::endl;
    std::cout << "Minimum: " << min << std::endl;
    std::cout << std::endl;
    system("pause");
    return 0;
}