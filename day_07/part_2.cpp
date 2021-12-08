#include <vector>
#include <algorithm>
#include <cmath>

#include "read_input.cpp"

int part_2(const std::string& filename) {
	std::vector<int> crabs;
	read_input(filename, crabs);

	int cost = 0;
	for (int i = 0; i < crabs.size(); i++) {
		cost += (crabs[i] * (crabs[i]+1)) / 2;
	}
	
	int min_cost = cost;
	for (int i = 1; i < crabs.size(); i++) {
		cost = 0;
		for (int j = 0; j < crabs.size(); j++) {
			int n = std::abs(crabs[j] - i);
			cost += n*(n+1) / 2;
		}
		if (cost < min_cost) {
			min_cost = cost;
		}
	}

	return min_cost;
}