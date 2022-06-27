#include <iostream>
#include <inttypes.h>
#include "include/blah.h"

int main (int argc, char * argv[])
{
    int one_billion = 1'000'000'000;
    int64_t three_billion = 3'000'000'000;
 
    std::cout << sizeof(one_billion) << std::endl;
    std::cout << sizeof(three_billion) << std::endl;
    std::cout << sizeof(1'000'000'000) << std::endl;
    std::cout << sizeof(3'000'000'000) << std::endl;

    Blah().boo();
    return EXIT_SUCCESS;
}