#include <string.h>
#include <stdint.h>
#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
    std::string sz_name;
    int16_t n16_first = 0;
    int16_t n16_second = 0;
    int16_t n16_sum = 0;

    cout << "Please enter your name: ";
    getline(std::cin, sz_name);

    cout << "Hello " << sz_name << "!" << std::endl; 
    
    cout << "Please enter two integers, one at a time:" << std::endl;
    cin >> n16_first >> n16_second;

   

    cout << "What is the sum of " << n16_first << " and " << n16_second << "? ";
    cin >> n16_sum;

    if (n16_sum == n16_first + n16_second)
            cout << "Congrats! " << sz_name << " you got it correct";
    else    
            cout << "Oops, looks like you need to ge back to school " << sz_name;

    return EXIT_SUCCESS;
}
