#include <iostream>
#include <bit>

#include "utils.h"

int weighted_dice_roll(const long double weights[], int num_sides) {
    if (num_sides <= 0) {
           throw std::invalid_argument("Number of sides must > 0");
    }
    // Use arc4random_uniform to generate a random numbe
    uint32_t random_number = arc4random();
    long double current_weight = 0;
    
    for (int k=0; k<num_sides; ++k) {
        current_weight += weights[k];
        if (random_number < current_weight * 4294967295) {
            return k; 
        }
    }
    // This should not happen unless there's an issue with the weights.
    std::cout << "current_weight: " << current_weight << std::endl;
    throw std::logic_error("Invalid weighted dice state.");
}

bool weighted_flip(double prob){
    uint32_t random_number = arc4random();
    if(random_number < prob * 4294967295){
        return true;
    }
    else{
        return false;
    }
}

void find_bit_combinations(std::vector<uint8_t>& arr, std::unordered_set<uint8_t>& set) {
    for (uint8_t mask = 1; mask != 0; mask <<= 1) {
        for(int i = 0; i < arr.size()-1; i++){
            if((arr[i] & mask) != (arr[i+1] & mask)){ 
                std::vector<uint8_t> rep1(arr.size());
                std::vector<uint8_t> rep2(arr.size());
                for(int j = 0; j < arr.size(); j++){
                    rep1[j] = arr[j] & ~mask;
                    rep2[j] = arr[j] | mask;
                }
                find_bit_combinations(rep1, set);
                find_bit_combinations(rep2, set);
                return;
            }
        }
    }
    set.insert(arr[0]);
}

bool are_same(long double a, long double b){
    return fabs(a - b) < 0.00000000000001;
}