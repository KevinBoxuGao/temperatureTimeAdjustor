#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include "InputFiles.h"
namespace fs = boost::filesystem;

std::vector<std::string> InputFiles::findFileNames(const std::string path) {
    std::vector<std::string> names(0);
    for(auto & file: fs::directory_iterator(path)) {
        names.push_back(fs::basename(file));
    }
    return names;
}