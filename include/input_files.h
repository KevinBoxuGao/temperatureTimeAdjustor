#ifndef INPUT_FILES_H
#define INPUT_FILES_H
#include <string>
#include <vector>

class InputFiles
{
    public:
        std::vector<std::string> FindFileNames(const std::string);
        std::vector<std::string> FindUnchangingData(const std::string);
};

#endif