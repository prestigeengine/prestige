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
            output += "}\n";
        }

        else if (line.rfind("if", 0) == 0) { // If Statement
            output += "if (" + line.substr(3) + ") {\n";
        }

        else if (line.rfind("else", 0) == 0) { // Else Statement
            output += "else {\n";
        }

        else if (line.rfind("else if", 0) == 0) { // else if statement
            output += "else if (" + line.substr(8) + ") {\n";
        }

        // def <name> [params]
        else if (line.rfind("def", 0) == 0) { // define function
            output += "function " + sep[1] + "(" + line.substr(4 + sep[1].size()) + ") {\n"
        }

        // call <name> [params]
        else if (line.rfind("call", 0) == 0) { // call function
            output += sep[1] + "(" + line.substr(5 + sep[1].size()) + ")"
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

        else if (line.rfind("swt", 0) == 0) { // switch Statement
            output += "switch(" + line.substr(4) + ") {\n";
        }

        else if (line.rfind("case", 0) == 0) { // switch Case
            output += "case " + line.substr(5) + ":\n";
        }

        else if (line.rfind("break", 0) == 0) { // break
            output += "break;\n";
        }

        else if (line.rfind("type", 0) == 0) { // typeof
            output += "typeof " + line.substr(5) + "\n";
        }

        else if (line.rfind("Str(", 0) == 0) { // switch Statement
            output += "String(" + line.substr(5) + ")\n";
        }

        else if (line.rfind("Int(", 0) == 0) { // switch Statement
            output += "Number(" + line.substr(5) + ")\n";
        }
        //deez
    }
    return output;
}