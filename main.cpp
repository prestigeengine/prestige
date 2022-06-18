#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "func/test/test.hpp"
#include "func/compile/compiler.hpp"
#include "func/manifest/manifest.hpp"

int main() {
    //test_calc(1, 2);
    std::string code; 
    std::string manifest;
    std::string currentLine;
    std::cout << "enter code filename: ";
    std::getline(std::cin, code);

    std::cout << "enter manifest filename: ";
    std::getline(std::cin, manifest);

    //list of lines
    std::vector<std::string> lines;
    std::vector<std::string> manifestLines;

    // read file
    std::ifstream file(code);
    std::ifstream manifestfile(manifest);
    
    while (std::getline (file, currentLine)) {
        lines.push_back(currentLine);
    };

    while (std::getline (manifestfile, currentLine)) {
        manifestLines.push_back(currentLine);
    }; 

   file.close();
   manifestfile.close();

    // write html with manifest
    std::ofstream htmlFile("output.html");
    std::string htmlLines = manifestGet(manifestLines);
    htmlFile << htmlLines; 
    htmlFile.close();

    // write to file
    std::ofstream writeFile("output.js");
    std::string lineTest = readLinesJS(lines);
    writeFile << lineTest;
    writeFile.close();

    return 0;
}