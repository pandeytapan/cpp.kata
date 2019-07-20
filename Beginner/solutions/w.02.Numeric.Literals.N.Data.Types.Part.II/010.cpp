#include <iostream>
#include <cassert>
int main (int argc, char * argv[])
{
    __int8 mystery = 1;
    mystery = 2 * (1- mystery);
    assert(mystery == 0);
    return EXIT_SUCCESS;
}