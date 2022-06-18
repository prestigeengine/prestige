#include "manifest.hpp"
#include "func/cat/cat.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string manifestGet(std::vector<std::string> lines) {
    std::string output = "<script>\n";

    for (std::string line : lines) {
        std::vector<std::string> sep = split(line, ' ');

        // IMG: <name> <url>
        if (line.rfind("IMG: ", 0) == 0) {
            output += "let " + sep[1] + " = " + "new Image();\n";
            output += sep[1] + ".src = " + sep[2] + ";\n";
        }
    }

    output += "</script>";

    return output;
}