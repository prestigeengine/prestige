#include "cat.hpp"
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