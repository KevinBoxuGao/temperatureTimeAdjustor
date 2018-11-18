#ifndef OUTPUTFILES_H
#define OUTPUTFILES_H
#include <string>
#include <vector>

class OutputFiles
{
    private:
        int indexes(std::string);
        std::vector<std::string> Find_Temp(const std::string file_name);
    public:
        void Adjust(const std::string, const std::string);
};

#endif