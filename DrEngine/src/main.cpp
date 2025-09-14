#include <iostream>
#include <string>

int main(int, char**) {
    std::cout << "Hello, from DrEngine!\n";

    std::string userInput;
    std::cout << "Input here: ";
    std::cin >> userInput;

    std::cout << "You entered: " << userInput << "\n";

    return 0;
}