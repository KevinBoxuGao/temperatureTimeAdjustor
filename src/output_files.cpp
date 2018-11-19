#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "output_files.h"

OutputFiles::OutputFiles(std::vector<std::string> base_data) {
    base_data_template = base_data;
}

void OutputFiles::Adjust(const std::string file_name) {
    std::ofstream output("output/"+file_name+".txt");
    
    std::ifstream temperature_file;
    std::string file_line;
    temperature_file.open("input/TemperatureChanges/" + file_name + ".csv");
    if(temperature_file.is_open()) {
        for(int i = 0; i < 9; i++) {
            getline(temperature_file, file_line);
        }
        for(unsigned int x = 0; x < base_data_template.size(); x++) {
            std::string substr;
            getline(temperature_file, file_line);
            std::istringstream iss(file_line);
            for(int x = 0; x < 4; x++) {
               getline(iss, substr, ','); 
            }
            output << base_data_template[x] << substr << std::endl;
        }
    }
    else{
        std::cout << "missing temperature file" << std::endl;
    }
}

