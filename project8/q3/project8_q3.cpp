#include <iostream>



// given variables
int a[3][3][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

// output variables
int grandTotal, medTotal, ssTotal, blueTotal;

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
        MOV     medTotal, 0
        MOV     ssTotal, 0
        MOV     blueTotal, 0

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
        ADD     EBX, 4
        MOV     index, 0

    med_total_loop:
        // check sentinel value
        CMP     index, 6
        JGE     end_med_loop

        // keep running total of all green shirts
        MOV     ECX, medTotal
        ADD     ECX, [EBX]
        MOV     medTotal, ECX

        // prepare for next iteration
        INC     index
        ADD     EBX, 12
        JMP     med_total_loop



    end_med_loop:
        // prepare for next loop
        LEA     EBX, a
        MOV     index, 0

    ss_total_loop:
        // check sentinel value
        CMP     index, 9
        JGE     end_ss_loop

        // keep running total of all XL shirts
        MOV     ECX, ssTotal
        ADD     ECX, [EBX]
        MOV     ssTotal, ECX

        // prepare for next iteration
        INC     index
        ADD     EBX, 4
        JMP     ss_total_loop



    end_ss_loop:
        // prepare for next loop
        LEA     EBX, a
        ADD     EBX, 12
        MOV     index, 0

    blue_total_loop:
        // check sentinel value
        CMP     index, 6
        JGE     end_blue_loop

        // make sure to "skip" values to only count blue shirts
        CMP     index, 3
        JE      fix_blue_index

    blue_continue:
        // keep running total of all green shirts
        MOV     ECX, blueTotal
        ADD     ECX, [EBX]
        MOV     blueTotal, ECX

        // prepare for next iteration
        INC     index
        ADD     EBX, 4
        JMP     blue_total_loop

    fix_blue_index:
        ADD     EBX, 24
        JMP     blue_continue

    end_blue_loop:
    }

    std::cout << '\n';
    std::cout << "Total Number of ALL shirts          : " << grandTotal << std::endl;
    std::cout << "Total Number of Medium shirts       : " << medTotal << std::endl;
    std::cout << "Total Number of Short Sleeve Shirts : " << ssTotal << std::endl;
    std::cout << "Total Number of Blue Shirts         : " << blueTotal << std::endl;
    std::cout << std::endl;
    system("pause");
    return 0;
}