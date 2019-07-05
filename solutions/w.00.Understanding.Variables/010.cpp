#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

int main (int argc, char *argv[])
{
    // // Displaying age of  person
    // std::cout << "Age of a person: " << 78 << std::endl;
    // std::cout << "Age of person: " << std::dec << 78 << std::endl;
    // printf("Age of person: %u\n", 78);
    // fprintf(stdout, "Age of person: %u\n", 78);

    // Value of absolute zero in celcius
    // std::cout << "Value of absolute zero: " << -273.15F << std::endl;
    // std::cout << "Value of absolute zero: " << std::setprecision(7) << -273.15F << std::endl;
    // std::cout << "Value of absolute zero: " << std::fixed << -273.15F << '\n'
    //           << "Value of absolute zero: " << std::scientific << -273.15F << '\n'
    //           << "Value of absolute zero: " << std::hexfloat << -273.15F << '\n'
    //           << "Value of absolute zero: " << std::defaultfloat << -273.15F << '\n';

    // printf("Value of absolute zero: %f\n", -273.15F);
    // printf("Value of absolute zero: %e\n", -273.15F);
    // printf("Value of absolute zero: %g\n", -273.15F);
    // printf("Value of absolute zero: %4.2\n", -273.15F);

    // Value of PI

    // std::cout << 22/7 << std::endl;
    // std::cout << 22.0/7.0 << std::endl;
    // std::cout << 22./7 << std::endl;
    // std::cout << 22/7. << std::endl;
    // std::cout << 22.0F/7.0 << std::endl;

    // std::cout << std::fixed << 22./7 << std::endl;
    // std::cout << std::scientific << 22/7. << std::endl;
    // std::cout << std::defaultfloat << 22.0F/7.0 << std::endl;
    // std::cout << std::hexfloat << 3.14 << std::endl;

    // printf("%f\n", 22 / 7);
    // printf("%f\n", 22. / 7);
    // printf("%.6f\n", 22. / 7);
    // std::cout << M_PI;

    // printing the bit wise value
    // std::cout << 0b0000'0000'0000'1000 << std::endl;
    // std::cout << 8 << std::endl;
    // std::cout << 010 << std::endl;
    // std::cout << 0x8 << std::endl;

    // Integer 57005 in hexadecimal
    // std::cout << std::hex << 57005 << std::endl;
    // printf("%x\n", 57005);
    // printf("%#x\n", 57005);
    // std::cout << std::showbase << std::hex << 57005 << std::endl;

    // 1.8233323443434
    std::cout << 1.8233323443434 << std::endl;
    std::cout << std::fixed << 1.8233323443434 << std::endl;
    std::cout << std::hexfloat << 1.8233323443434 << std::endl;
    std::cout << std::scientific << 1.8233323443434 << std::endl;
    std::cout << std::defaultfloat << 1.8233323443434 << std::endl;
    std::cout << std::defaultfloat << 1.8233323443434 << std::endl;
    std::cout << std::setprecision(13) << 1.8233323443434 << std::endl;

    printf("%f\n", 1.8233323443434F);
    printf("%.13lf\n", 1.8233323443434);

    // name of capital city of India
    std::cout << "New Delhi" << std::endl;
    printf("New Delhi\n");
    printf("%s", "New Delhi");
    std::cout.write("New Delhi\n");

    // First alphabet of english
    // First alphabet of hindi language

    return EXIT_SUCCESS;
}