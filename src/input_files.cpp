#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "input_files.h"
namespace fs = boost::filesystem;

std::vector<std::string> InputFiles::FindFileNames(const std::string path) {
    std::vector<std::string> names(0);
    for(auto & file: fs::directory_iterator(path)) {
        names.push_back(fs::basename(file));
    }
    return names;
}

std::vector<std::string> InputFiles::FindUnchangingData(const std::string file_name) {
    std::ifstream input_file;
    std::string file_line;

    std::vector<std::string> unchanging_data(0);
    
    input_file.open("input/" + file_name + ".txt");
    if(input_file.is_open()) {
        while(getline(input_file, file_line)) { 
            unchanging_data.push_back(file_line.substr(0,16));
        }
        input_file.close();
    }
    else{
        std::cout << "missing inputfile" << std::endl;
    }
    return unchanging_data;
}