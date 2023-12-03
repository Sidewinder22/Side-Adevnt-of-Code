#ifndef ReadFile_H_
#define ReadFile_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace tools
{

class ReadFile
{
public:
    ReadFile(std::string fileName);
    std::vector<std::string> read();

private:
    std::string fileName_;
};

} // namespace tools

#endif // ReadFile_H_
