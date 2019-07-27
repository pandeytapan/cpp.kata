#include <iostream>

int main (int argc, char * argv[])
{
    std::cout << unsigned(3 * 1'000 * 1'000 *1'000) << std::endl;
    std::cout << std::fixed<< 3.0 * 1'000 * 1'000 *1'000 << std::endl;

    return EXIT_SUCCESS;
}