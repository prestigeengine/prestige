#include "manifest.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split2(std::string str, char delimiter) {
    // Python .split() ported to C++
  std::vector<std::string> result;
  std::stringstream ss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(ss,tok,delimiter)) {
    result.push_back(tok);
  }
  
  return result;
}

std::string manifestGet(std::vector<std::string> lines) {
    std::string output = "<script>\n";

    for (std::string line : lines) {
        std::vector<std::string> sep = split2(line, ' ');

        // IMG: <name> <url>
        if (line.rfind("IMG: ", 0) == 0) {
            output += "let " + sep[1] + " = " + "new Image();\n";
            output += sep[1] + ".src = " + sep[2] + ";\n";
        }
    }

    output += "</script>";

    return output;
}