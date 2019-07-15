#include <iostream>

int main (int argc, char * argv[])
{
    int one_billion = 1'000'000'000;
    std::cout << "One billion: " << one_billion << std::endl;
    unsigned three_billion = 3'000'000'000;
    std::cout << "Three billion: " << three_billion << std::endl;

    std::cout << sizeof(one_billion) << std::endl;
    std::cout << sizeof(three_billion) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(unsigned) << std::endl;

    return EXIT_SUCCESS;
}