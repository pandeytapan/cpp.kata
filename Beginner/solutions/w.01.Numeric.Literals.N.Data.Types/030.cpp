#include <iostream>

int main (int argc, char * argv[])
{
    auto three_billion = 3'000'000'000;
    std::cout << "Three billion: " << three_billion << std::endl;
    std::cout << sizeof (3'000'000'000) << std::endl;

    return EXIT_SUCCESS;
}