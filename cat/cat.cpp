#include "cat.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::string> split(std::string str, char delimiter) {
    // Python .split() ported to C++
  std::vector<std::string> result;
  std::stringstream ss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(ss,tok,delimiter)) {
    result.push_back(tok);
  }
  
  return result;
}

void readIncl(std::string fileName, std::vector<std::string> *lines) {
    std::string curLine;
    std::ifstream inclFile(fileName);
    while (std::getline(inclFile, curLine)) {
        (*lines).push_back(curLine);
    }
    inclFile.close();
}

void throwError(std::string line, std::string err) {
    std::string errorArguments = "";
    errorArguments += err+"\n\n"+line;

    std::cout << errorArguments;
    exit(1);
    return;
}
