#include <iostream>
#include <string>
#include <vector>
#include "InputFiles.h"
#include "OutputFiles.h"

int main() {
    InputFiles Temperatures;
    std::vector<std::string> TemperatureFiles = Temperatures.findFileNames("input/Temps");
    InputFiles Original;
    std::vector<std::string> OriginalFile = Original.findFileNames("input");

    OutputFiles TemperatureChanges;
    for(int x = 0; x < (Temperatures.findFileNames("input/Temps")).size(); x++) {
        std::cout << TemperatureFiles[x] << std::endl;
    }
    
    for(int x = 0; x < (Temperatures.findFileNames("input/Temps")).size(); x++) {
        TemperatureChanges.Adjust(TemperatureFiles[x], OriginalFile[0]);
    }
    
    return 0;
}