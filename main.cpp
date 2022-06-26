#include <string>
#include <functional>
#include <iostream>
#include <fstream>
#include <vector>
#include "test/test.hpp"
#include "compile/compiler.hpp"
#include "manifest/manifest.hpp"
#include "cat/cat.hpp"

int main(int argc, char** argv) {
    std::string code; 
    std::string manifest;

    if (argc >= 2) {
        //std::cout << "triggered";
        code = argv[1];
    };

    if (argc >= 3) {
        manifest = argv[2]; 
    }



    //test_calc(1, 2);
    
    std::string currentLine;
    
    //std::cout << argc << '\n'; 
    //std::cout << code << '\n' << manifest << '\n';

    if (argc < 2) {
        std::cout << "enter code filename: ";
        std::getline(std::cin, code);
    }

    if (argc < 3) {
        std::cout << "enter manifest filename: ";
        std::getline(std::cin, manifest);
    }


    //list of lines
    std::vector<std::string> lines;
    std::vector<std::string> manifestLines;

    // read file
    std::ifstream file(code);
    std::ifstream manifestfile(manifest);
    
    // while (std::getline (file, currentLine)) {
    //     lines.push_back(currentLine);
    // };

    while (!file.eof()) // Copy over all of the file to the lines vector
    {
        std::getline(file, currentLine);
        lines.push_back(currentLine);
        currentLine.clear();
    };
    
    // i don't know why i made this a lambda, but i don't feel like putting this thing somewhere else
    /*
    std::function looks like a mess, however type inference (auto) doesn't let me capture the function itself
    and i can't have a variable with void type...
    */ 
    std::function<void(std::vector<std::string>&)> read = [&] (std::vector<std::string>& lines) 
    {
        for (size_t index = 0; index < lines.size(); index++) // no for auto loop, because we need to know where we are in the vector
        {
            if (lines[index].find("import", 0) != std::string::npos) // if we've found the 'import' keyword... (if not, string.find() returns npos)
            {
                // remove spaces because there's gonna be someone who's gonna put two spaces instead of one and break everything
                std::string line_no_space = lines[index];
                for (size_t stri = 0; stri < line_no_space.size(); stri++)
                    if (line_no_space[stri] == ' ')
                        line_no_space.erase(line_no_space.cbegin() + stri);
                
                lines.erase(lines.cbegin() + index); // Erase the current line, which has the import keyword

                // Open imported file!
                // I can't use readIncl, because it pushes to the back of the vector, which is not what we want
                std::ifstream imported_file(line_no_space.substr(6));
                if (!imported_file)
                {
                    throw std::runtime_error("Unable to read imported file! Top level file: " + code + " - Imported file: " + line_no_space.substr(6) + " at line " + std::to_string(index));
                }
                size_t index_updated = index; // Without updating the index, vector.insert() would insert all of the lines in backwards order
                while (!imported_file.eof())
                {
                    std::getline(imported_file, currentLine);
                    lines.insert(lines.cbegin() + (index_updated++), currentLine);
                    currentLine.clear();
                }
                imported_file.close();
                read(lines); // Reread every line again, now that they've updated
            }
        }
    };

    read(lines); // :3

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
    
    std::cout << "compilation complete";
    return 0;
}