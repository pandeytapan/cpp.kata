#include <iostream>

int main (int argc, char * argv[])
{
    auto price = 2.55;
    auto dollars = price + 0.5;

    std::cout << sizeof(price) << std::endl;
    std::cout << sizeof(dollars) << std::endl;

    return EXIT_SUCCESS;
}