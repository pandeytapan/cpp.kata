#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "What is your name? ";
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!" << std::endl;

    int first, second, answer;
    std::cout << "Please enter two integers, one at a time:" << std::endl;
    std::cin >> first >> second;

    std::cout << "What is the sum of " << first << " and " << second << "? ";
    std::cin >> answer;

    if (answer == first + second) {
        std::cout << "Congratulations, " << name << "!" << std::endl;
    } else {
        std::cout << "Oops, looks like you need to go back to school, " << name << "!" << std::endl;
    }

    return 0;
}
