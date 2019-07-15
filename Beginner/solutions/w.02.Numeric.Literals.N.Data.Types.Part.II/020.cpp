#include <iostream>

int main (int argc, char * argv[])
{
    __int8 age = 21;
    
    std::cout <<  unsigned(age) << std::endl;     
    std::cout << sizeof(age) << std::endl;

    return EXIT_SUCCESS;
}