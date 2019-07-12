#include <iostream>

int main (int argc, char * argv[])
{
    int one_billion = 1'000'000'000;
    __int64 three_billion = 3'000'000'000;
 
    std::cout << sizeof(one_billion) << std::endl;
    std::cout << sizeof(three_billion) << std::endl;
    std::cout << sizeof(1'000'000'000) << std::endl;
    std::cout << sizeof(3'000'000'000) << std::endl;

    return EXIT_SUCCESS;
}