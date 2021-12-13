#include "read_input.cpp"
#include "functions.cpp"

void part_2(const std::string& filename) {
	std::set<std::pair<int, int>> dots;
	std::vector<std::pair<char, int>> folds;
	read_input(filename, dots, folds);

	for (const std::pair<char, int>& fold : folds) {
		dots = do_fold(dots, fold.first, fold.second);
	}

	int max_x = 0, max_y = 0;
	for (const std::pair<int, int>& dot : dots) {
		if (dot.first > max_x) {
			max_x = dot.first;
		}
		if (dot.second > max_y) {
			max_y = dot.second;
		}
	}
	for (int i = 0; i <= max_y; i++) {
		std::cout << "\n";
		for (int j = 0; j <= max_x; j++) {
			if (dots.find({j, i}) == dots.end()) {
				std::cout << " ";
			} else {
				std::cout << "█";
			}
		}
	}
}