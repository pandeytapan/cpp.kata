#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main (int argc, char * argv[])
{
    const double EPSILON = 8.854 * pow(10, -12);
    
    double Q1 = 23.345;
    double Q2 = 11.186;
    double radius = 4.678;

    double Force = (Q1 * Q2) / 4 * M_PI * EPSILON * pow(radius, 2);

    std::cout << "The force on the charged particles Q1 " << Q1 << ", Q2 " << Q2 << " is " << Force << std::endl; 
    return EXIT_SUCCESS;
}