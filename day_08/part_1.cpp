#include "read_input.cpp"

int part_1(const std::string& filename) {
	std::vector<std::vector<std::string>> examples, outputs;
	read_input(filename, examples, outputs);

	int count = 0;
	for (std::vector<std::string> out : outputs) {
		for (std::string in : out) {
			if (in.size() == 2 || in.size() == 4 || in.size() == 3 || in.size() == 7) {
				count ++;
			}
		}
	}

	return count;
}