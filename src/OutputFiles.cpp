#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "OutputFiles.h"

int OutputFiles::indexes(std::string line) {
    int indexes[3];
    int index;
    unsigned int x, coord_count;
    for(x = 0, coord_count = 0; x < line.length(); x++) {
        if (line[x] == ',')
        {
            coord_count++;
            indexes[coord_count] = x;
            continue;
        }
    }
    return indexes[3];
}

std::vector<std::string> OutputFiles::Find_Temp(const std::string File_name) {
    std::vector<std::string> temps(0);
    std::ifstream Temperatures;
    std::string TempLine;
    Temperatures.open("input/Temps/" + File_name + ".csv");
    if(Temperatures.is_open()) {
        for(int x = 0; x < 9; x++) {
            getline(Temperatures, TempLine);
        }
        for(int x = 0; getline(Temperatures, TempLine); x++) {
            temps.push_back(TempLine.substr(indexes(TempLine), 15));
        }
        Temperatures.close();
    }
    else{
        std::cout << "missing temperature file" << std::endl;
    }
    return temps;
}

void OutputFiles::Adjust(const std::string file_name, const std::string pair_file, std::vector<std::string> nodelines) {
    std::ofstream Output("output/"+file_name+".txt");

    
    for(int x = 0; x < nodelines.size(); x++) {
        Output << nodelines[x] + Find_Temp(file_name)[x] << std::endl;
    }
}