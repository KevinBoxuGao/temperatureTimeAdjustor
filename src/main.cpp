#include <iostream>
#include <string>
#include <vector>
#include "input_files.h"
#include "output_files.h"

int main() {
    InputFiles temperature_changes;
    std::vector<std::string> temperature_changes_files = temperature_changes.FindFileNames("input/TemperatureChanges");
    
    InputFiles original;
    std::string original_file = original.FindFileNames("input")[0];
   
    OutputFiles temperature_changes_output(original.FindUnchangingData(original_file));

    for(unsigned int x = 0; x < temperature_changes_files.size(); x++) {
        temperature_changes_output.Adjust(temperature_changes_files[x]);
    }
    
    return 0;
}