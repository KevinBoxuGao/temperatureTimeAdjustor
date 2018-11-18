#ifndef OUTPUT_FILES_H
#define OUTPUT_FILES_H
#include <string>
#include <vector>

class OutputFiles
{
    private:
        std::vector<std::string> base_data_template;
        std::vector<std::string> FindAjustedValues(const std::string);
    public:
        OutputFiles(std::vector<std::string>);
        void Adjust(const std::string);
};

#endif