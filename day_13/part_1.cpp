#include "read_input.cpp"
#include "functions.cpp"

int part_1(const std::string& filename) {
	std::set<std::pair<int, int>> dots;
	std::vector<std::pair<char, int>> folds;
	read_input(filename, dots, folds);

	return do_fold(dots, folds.begin()->first, folds.begin()->second).size();
}