#pragma once
#include <fstream>
#include <sstream>
#include "settings.h"

void read_csv_to_2d_array_drug(std::string file_path, long double data[NUM_UNIQUE_CLONES][NUM_DRUGS]) {
    std::ifstream file(file_path);

    std::string line;
    int row = 0;
    while (getline(file, line) && row < NUM_UNIQUE_CLONES) {
        std::stringstream ss(line);
        std::string cell;
        int col = 0;
        while (getline(ss, cell, ',') && col < NUM_DRUGS) {
            data[row][col++] = std::stod(cell);
        }
        ++row;
    }
}

void write_2d_array_to_csv_clonefreq(std::string file_path, int generation, const long double data[][NUM_UNIQUE_CLONES]) {
    std::ofstream file(file_path);
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }

    for (int row=0; row<generation; row++) {
        for (int col=0; col<NUM_UNIQUE_CLONES; col++){
            if(col == NUM_UNIQUE_CLONES-1){
                file << std::setprecision(17) << data[row][col] << '\n';
                break;
            }
            file << data[row][col] <<',';
        }
    }
}

void write_array_to_csv(std::string file_path, int generation, const long double data[]) {
    std::ofstream file(file_path);
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }

    for (int row = 0; row < generation; row++) {
        file << std::setprecision(17) << data[row] << "\n";
    }
}