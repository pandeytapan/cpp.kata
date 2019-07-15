#include <iostream>

int main (int argc, char * argv[])
{
    auto three_billion = 3'000'000'000;

    std::cout << "Three billion: " << three_billion << std::endl;
    
    std::cout << sizeof(3'000'000'000) << std::endl;
    std::cout << sizeof(three_billion) << std::endl;
    
    std::cout << std::boolalpha << std::is_same<decltype(three_billion),unsigned long>::value;

    return EXIT_SUCCESS;
}