#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#ifndef CAT_H 
#define CAT_H

std::vector<std::string> split(std::string str, char delimiter);
void readIncl(std::string fileName, std::vector<std::string> *lines);

#endif 