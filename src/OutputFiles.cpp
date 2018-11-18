#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "OutputFiles.h"

int OutputFiles::indexes(std::string line) {
    int index;
    unsigned int x, coord_count;
    for(x = 0, coord_count = 0; x < line.length(); x++) {
        if (line[x] == ',' && coord_count == 3)
        {
            coord_count++;
            index = x;
            continue;
        }
        else if (line[x] == ',') {
            coord_count++;
        }
    }
    return index;
}

std::vector<std::string> OutputFiles::Find_Temp(const std::string File_name) {
    std::vector<std::string> temps(0);
    std::ifstream Temperatures;
    std::string TempLine;
    Temperatures.open("input/Temps/" + File_name + ".csv");
    if(Temperatures.is_open()) {
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

void OutputFiles::Adjust(const std::string file_name, const std::string pair_file) {
    std::ifstream NodeFile;
    std::ofstream Output("output/" + file_name + ".txt");
    std::string NodeLine;
    std::vector<std::string> base_information(0);
    
    NodeFile.open("input/" + pair_file + ".txt");
    if(NodeFile.is_open()) {
        while(getline(NodeFile, NodeLine)) {
            base_information.push_back(NodeLine.substr(0,16));
            
        }
        NodeFile.close();
    }
    else{
        std::cout << "missing pairs" << std::endl;
    }
    for(int x = 0; x < base_information.size(); x++) {
        Output << base_information[x] + Find_Temp(file_name)[x] << std::endl;
    }
}