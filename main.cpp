#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "func/test/test.hpp"
#include "func/compile/compiler.hpp"

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

    
    //std::cout << lineTest;

    // write to file
    std::ofstream writeFile("output.js");
    std::string lineTest = readLines(lines);
    writeFile << lineTest;
    writeFile.close();

    return 0;
}