#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "output_files.h"

OutputFiles::OutputFiles(std::vector<std::string> base_data) {
    base_data_template = base_data
}

std::vector<std::string> OutputFiles::FindAjustedValues(const std::string file_name) {
    std::vector<std::string> temperatures(0);
    std::ifstream temperature_file;
    std::string file_line;

    temperature_file.open("input/Temps/" + file_name + ".csv");
    if(temperature_file.is_open()) {
        for(int x = 0; x < 9; x++) {
            getline(temperature_file, file_line);
        }
        while(temperature_file.good())) {
            for(int x = 0; x < 4; x++) {
               getline(temperature_file, file_line, ','); 
            }
            temperatures.push_back(file_line);
        }
        temperature_file.close();
    }
    else{
        std::cout << "missing temperature file" << std::endl;
    }
    return temperatures;
}

void OutputFiles::Adjust(const std::string file_name) {
    std::ofstream Output("output/"+file_name+".txt");
    for(int x = 0; x < base_data_template.size(); x++) {
        Output << base_data_template[x] << FindAjustedValues(file_name)[x] << std::endl;
    }
}

