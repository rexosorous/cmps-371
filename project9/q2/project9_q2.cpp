#include <iostream>
#include <iomanip>



// input variables
float a, b, c;

// storage variables
float fn1 = -1, f2 = 2, f4 = 4;

// output variables
float x1, x2;




int main()
{
    // get user input
    std::cout << "To see the two real roots of aX^2 + bX + c = 0, enter the a, b, and c values: ";
    std::cin >> a >> b >> c;

    _asm
    {
        // calculate x1
        // x1 = (-b + sqrt(b^2 - 4ac))/2a --> b fn1 * b b * 4 a * c * - sqrt + 2 a * /
        FLD     b
        FLD     fn1
        FMUL        // -b
        FLD     b
        FLD     b
        FMUL        // b^2
        FLD     f4
        FLD     a
        FMUL        // 4a
        FLD     c
        FMUL        // 4ac
        FSUB        // b^2 - 4ac
        FSQRT       // sqrt(b^2 - 4ac)
        FADD        // -b + sqrt(b^2 - 4ac)
        FLD     f2
        FLD     a
        FMUL        // 2a
        FDIV        // (-b + sqrt(b^2 - 4ac))/2a
        FSTP    x1



        // calculate x2
        // x2 = (-b - sqrt(b^2 - 4ac))/2a --> b fn1 * b b * 4 a * c * - sqrt - 2 a * /
        FLD     b
        FLD     fn1
        FMUL        // -b
        FLD     b
        FLD     b
        FMUL        // b^2
        FLD     f4
        FLD     a
        FMUL        // 4a
        FLD     c
        FMUL        // 4ac
        FSUB        // b^2 - 4ac
        FSQRT       // sqrt(b^2 - 4ac)
        FSUB        // -b - sqrt(b^2 - 4ac)
        FLD     f2
        FLD     a
        FMUL        // 2a
        FDIV        // (-b + sqrt(b^2 - 4ac))/2a
        FSTP    x2
    }

    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << "  X1=" << x1;
    std::cout << "  x2=" << x2 << std::endl;

    std::cout << std::endl;
    system("pause");
    return 0;
}