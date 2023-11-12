#ifndef ReadFile_H_
#define ReadFile_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ReadFile
{
public:
    ReadFile(std::string fileName);
    std::vector<std::string> read();

private:
    std::string fileName_;
};

#endif // ReadFile_H_
