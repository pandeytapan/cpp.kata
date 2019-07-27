#include <iostream>
#include <iostream>
#include <climits>

int main (int argc, char * argv[])
{
    auto x = INT_MAX ;
    auto y = INT_MAX ;
    auto z = unsigned long(x) + y;

    std::cout << std::boolalpha << std::is_same<decltype(x),int>::value << std::endl;
    std::cout << std::boolalpha << std::is_same<decltype(y),int>::value << std::endl;
    std::cout << std::boolalpha << std::is_same<decltype(z),unsigned long>::value << std::endl;

    return EXIT_SUCCESS;
}