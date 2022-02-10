#include <iostream>
#include <fstream>
#include <string>

struct employee{
    int num;
    std::string name;
    double hours;
};

int main() {
    std::string file;
    std::cout << "Enter binary file name:\n";
    std::getline(std::cin, file);

    int am;
    std::cout << "Enter number of lines:\n";
    std::cin >> am;
    return 0;
}
