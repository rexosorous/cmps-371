#include <iostream>
#include <iomanip>



// input variables
float a, b, c, h, len, wid, radius, height;

// storage variables
float f2 = 2, pi = 3.14;

// output variables
float triangleArea, trianglePerim, rectangleArea, rectanglePerim, cylinderArea, cylinderVol;




int main()
{
    // get user input
    std::cout << "Enter the values of a, b, c, and h for the triangle: ";
    std::cin >> a >> b >> c >> h;
    std::cout << "Enter the length and the width of the rectangle:     ";
    std::cin >> len >> wid;
    std::cout << "Enter the radius and the height of the cylinder:     ";
    std::cin >> radius >> height;

    _asm
    {
        // calculate triangle area
        // (c*h)/2 --> ch*2/
        FLD     c
        FLD     h
        FMUL        // c*h
        FLD     f2
        FDIV        // (c*h)/2
        FSTP    triangleArea

        // calculate triangle perimeter
        // a+b+c --> ab+c+
        FLD     a
        FLD     b
        FADD        // a+b
        FLD     c
        FADD        // a+b+c
        FSTP    trianglePerim



        // calculate rectangle area
        // len * wid --> len wid *
        FLD     len
        FLD     wid
        FMUL        // len * wid
        FSTP    rectangleArea

        // calculate rectangle perimeter
        // (2 * len) + (2 * wid) --> 2 len * 2 wid * +
        FLD     f2
        FLD     len
        FMUL        // 2 * len
        FLD     f2
        FLD     wid
        FMUL        // 2 * wid
        FADD        // (2 * len) + (2 * wid)
        FSTP    rectanglePerim



        // calculate cylinder surface area
        // (2*pi*radius^2) + (2*pi*radius*height) --> 2pi*radius*radius*2pi*radius*height*+
        FLD     f2
        FLD     pi 
        FMUL        // 2 * pi
        FLD     radius
        FMUL        // 2 * pi * radius
        FLD     radius
        FMUL        // 2 * pi * radius^2
        FLD     f2
        FLD     pi 
        FMUL        // 2 * pi
        FLD     radius
        FMUL        // 2 * pi * radius
        FLD     height
        FMUL        // 2 * pi * radius * height
        FADD        // (2 * pi * radius^2) + (2 * pi * radius * height)
        FSTP    cylinderArea

        // calculate cylinder volume
        // pi*radius^2*height --> pi radius * radius * height *
        FLD     pi
        FLD     radius
        FMUL        // pi * radius
        FLD     radius
        FMUL        // pi * radius^2
        FLD     height
        FMUL        // pi * radius^2 * height
        FSTP    cylinderVol
    }

    std::cout << std::endl;
    std::cout << std::fixed << std::showpoint << std::setprecision(2);

    std::cout << "Triangle" << std::endl;
    std::cout << "  Area................" << triangleArea << std::endl;
    std::cout << "  Perimeter..........." << trianglePerim << std::endl;
    std::cout << "Rectangle" << std::endl;
    std::cout << "  Area................" << rectangleArea << std::endl;
    std::cout << "  Perimter............" << rectanglePerim << std::endl;
    std::cout << "Cylinder" << std::endl;
    std::cout << "  Surface Area........" << cylinderArea << std::endl;
    std::cout << "  Volum..............." << cylinderVol << std::endl;

    std::cout << std::endl;
    system("pause");
    return 0;
}