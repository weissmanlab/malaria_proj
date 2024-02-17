#pragma once
#include <unordered_set>
#include <stdint.h>

class Host{
public:
	Host();
	uint8_t moi;
	uint8_t drug;
	long double fitness;

	// storing clones and clone freqs for INDIVIDUALS
	std::unordered_set<uint8_t> i_clones;
	long double i_freqs[NUM_UNIQUE_CLONES];

	void choose_clones(long double frequencies[], int total_clones, int indices_for_diceroll[]); 
	void choose_drugs(int generation, int clone_id);
	void recombine();
	void naturally_select(long double fitness_data[NUM_UNIQUE_CLONES][NUM_DRUGS]);
	void reset();
	void print_summary();
};
