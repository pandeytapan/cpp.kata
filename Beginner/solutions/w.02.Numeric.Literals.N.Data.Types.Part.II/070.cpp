#include <iostream>

int main (int argc, char * argv[])
{
    auto price = 2.95f;
    int dollars = price;
    int cents = (price - dollars) * 100 + 0.5f;

    std::cout << "Price: "<< price << std::endl;
    std::cout << "Dollars: "<< dollars << std::endl;
    std::cout << "Cents: "<< cents << std::endl;

    return EXIT_SUCCESS;
}