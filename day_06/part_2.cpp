#include <vector>

#include "read_input.cpp"

typedef unsigned long long int fishcount;

fishcount part_2(const std::string& filename) {

	std::vector<int> fish;
	read_input(filename, fish);

	int cycle_length = 7;
	int init_delay = 2;

	std::vector<fishcount> countdown(cycle_length + init_delay, 0);
	for (int i = 0; i < fish.size(); i++) {
		countdown[fish[i]] ++;
	}

	for (int i = 0; i < 256; i++) {
		fishcount reproduced = countdown[0];
		for (int j = 1; j < countdown.size(); j++) {
			countdown[j-1] = countdown[j];
		}
		countdown[cycle_length + init_delay - 1] = reproduced;
		countdown[cycle_length - 1] += reproduced;
	}

	fishcount tot_fish = 0;
	for (int i = 0; i < countdown.size(); i++) {
		tot_fish += countdown[i];
	}

	return tot_fish;
}