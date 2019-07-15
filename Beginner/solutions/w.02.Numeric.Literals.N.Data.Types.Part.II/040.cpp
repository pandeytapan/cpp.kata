#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main (int argc, char *argv[])
{
    double radius = 12.5;
    double area = M_PI * radius * radius;
    std::cout << "Area:" << area << " Radius:" << radius << std::endl;
    std::cout << sizeof(float) << std::endl << sizeof(double) << std::endl;
    return EXIT_SUCCESS;
}