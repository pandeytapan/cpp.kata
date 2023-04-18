#include <string>
#include <iostream>

using namespace std;

int main()
{
    // Accepting name here
    // Memory for the name 
    string name;
    cout << "Enter your name: ";
    cin >> name;

    cout << "Hello, " << name << "!" << endl;

    // Accepting the integers and their summation here
    int first; // Memory location to store the integer value
    int second;
    int sum;

    cout << "Enter first integer:";
    cin >> first;

    cout << "You have entered first integer as " << first << endl;
    
    cout << "Enter second integer:";
    cin >> second;

    cout << "You have entered second integer as " << second << endl;
    
    cout << "Enter summation of the integers:";
    cin >> sum;

    cout << "You have entered summation equals " << sum << endl;

    // We need to compare the summation of the integers with the sum entered by the user
    
    if ( first + second == sum)
    {
        // truthy part
        cout << "Congrats! You've given correct answer";
    }
    else
    {
        // falsy part
        cout << "Oops! You need to do your Arithmetic classes again!!";
    }
    //
    //
    return EXIT_SUCCESS;
}
