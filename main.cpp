#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "func/test/test.h"

int main() {
    //test_calc(1, 2);
    std::string input; 
    std::string currentLine;
    std::cout << "enter filename: ";
    std::getline(std::cin, input);


    //list of lines
    std::vector<std::string> lines;

    // read file
    std::ifstream file(input);
    
    while (std::getline (file, currentLine)) {
        lines.push_back(currentLine);
    };

    file.close();

    // write to file
    std::ofstream writeFile("output.js");


    return 0;
}