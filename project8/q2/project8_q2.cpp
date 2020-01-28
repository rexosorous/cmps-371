#include <iostream>



// given variables
int a[4][4] = { 10, 20, 30, 40,
                20, 10, 40, 30,
                 5, 15, 20, 25,
                30, 25, 20, 15};

// output variables
int grandTotal, XLTotal, greenTotal;

// storage variables
int index;



int main()
{
    _asm
    {
        // init
        LEA     EBX, a
        MOV     EAX, [EBX]
        MOV     index, 0
        MOV     grandTotal, 0
        MOV     XLTotal, 0
        MOV     greenTotal, 0

    grand_total_loop:
        // check sentinel value
        CMP     index, 16
        JGE     end_gt_loop

        // keep running grand total
        MOV     ECX, grandTotal
        ADD     ECX, [EBX]
        MOV     grandTotal, ECX

        // prepare for next iteration
        INC     index
        ADD     EBX, 4
        JMP     grand_total_loop



    end_gt_loop:
        // prepare for next loop
        LEA     EBX, a
        ADD     EBX, 16
        MOV     index, 0

    green_total_loop:
        // check sentinel value
        CMP     index, 4
        JGE     end_green_loop

        // keep running total of all green shirts
        MOV     ECX, greenTotal
        ADD     ECX, [EBX]
        MOV     greenTotal, ECX

        // prepare for next iteration
        INC     index
        ADD     EBX, 4
        JMP     green_total_loop



    end_green_loop:
        // prepare for next loop
        LEA     EBX, a
        ADD     EBX, 12
        MOV     index, 0

    xl_total_loop:
        // check sentinel value
        CMP     index, 4
        JGE     end_xl_loop

        // keep running total of all XL shirts
        MOV     ECX, XLTotal
        ADD     ECX, [EBX]
        MOV     XLTotal, ECX

        // prepare for next iteration
        INC     index
        ADD     EBX, 16
        JMP     xl_total_loop

    end_xl_loop:
    }

    std::cout << '\n';
    std::cout << "Total Number of ALL shirts   : " << grandTotal << std::endl;
    std::cout << "Total Number of XL shirts    : " << XLTotal << std::endl;
    std::cout << "Total Number of Green Shirts : " << greenTotal << std::endl;
    std::cout << std::endl;
    system("pause");
    return 0;
}