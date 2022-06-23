#include <iostream>
#include <vector>


#ifndef COMPILER_H 
#define COMPILER_H

std::string readLinesJS(std::vector<std::string> lines);
void throwError (std::string line, std::string err);

#endif 