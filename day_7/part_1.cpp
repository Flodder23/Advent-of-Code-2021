#include "read_input.cpp"

#include <vector>
#include <algorithm>

int part_1(const std::string& filename) {
	std::vector<int> crabs;
	read_input(filename, crabs);
	std::sort(crabs.begin(), crabs.end());

	int cost = 0;
	for (int i = 0; i < crabs.size(); i++) {
		cost += crabs[i];
	}
	
	int min_cost = cost;
	for (int i = 1; i < crabs.size(); i++) {
		cost += (2*i - crabs.size()) * (crabs[i] - crabs[i-1]);
		if (cost < min_cost) {
			min_cost = cost;
		}
	}

	return min_cost;
}