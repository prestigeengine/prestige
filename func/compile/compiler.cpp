#include "compiler.hpp"
#include <iostream>
#include <vector>
#include <string>
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

std::string readLines(std::vector<std::string> lines) {
    std::string output = "";
    // for line in lines
    for (std::string line : lines) {
        // sep = line.split(' ')
        std::vector<std::string> sep = split(line, ' ');

        if (line.rfind("log", 0) == 0) { //Print()
            output += "console.log(" + line.substr(4) + ");\n";
        } 
        
        else if (line.rfind("//", 0) == 0) { //Comment out
            output += "//" + line.substr(2) + "\n";
        } 
        
        else if (line.rfind("--", 0) == 0) { // Comment out
            output += "//" + line.substr(2) + "\n";
        }

        else if (line.rfind("var", 0) == 0) { // VarDeclar!!

            // var name "hello"
            output += "var " + sep[1] + " = " + line.substr(4 + sep[1].size() + 1) + ";\n";
        } 
        
        else if (line.rfind("const", 0) == 0) { // Constants Declaration
            output += "const " + sep[1] + " = " + line.substr(6 + sep[1].size() + 1) + ";\n";
        }
        
        else if (line.rfind("end", 0) == 0) { //
            output += "};\n";
        }

        else if (line.rfind("if", 0) == 0) { // If Statement
            output += "if (" + line.substr(3) + ") {\n";
        }

        else if (line.rfind("else", 0) == 0) { // Else Statement
            output += "else {\n";
        }

        else if (line.rfind("while", 0) == 0) { // While Statement
            output += "while (" + line.substr(6) + ") {\n";
        }

        else if (line.rfind("for", 0) == 0) { // For Statement
            output += "for (" + line.substr(4) + ") {\n";
        }

        else if (line.rfind("return", 0) == 0) { // Return Statement
            output += "return " + line.substr(7) + ";\n";
        }
        //deez
    }
    return output;
}