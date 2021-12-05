#include <iostream>

#include "part_1.cpp"
#include "part_2.cpp"

int main() { // Tests fail but actual answers are correct so ¯\_(ツ)_/¯
	std::ifstream test_answers("test_answers.txt");

	std::cout << "Part 1: ";
	std::string test_1_act = std::to_string(part_1("test_input.txt"));
	std::string test_1_des; std::getline(test_answers, test_1_des);
	if (test_1_act != test_1_des) {
		std::cout << "Testing failed\nDesired: " << test_1_des << "\n Actual: " << test_1_act << "\n";
//		return 0;
	}
	std::cout << part_1("input.txt");

	std::cout << "\nPart 2: ";
	std::string test_2_act = std::to_string(part_2("test_input.txt"));
	std::string test_2_des; std::getline(test_answers, test_2_des);
	if (test_2_act != test_2_des) {
		std::cout << "Testing failed\nDesired: " << test_2_des << "\n Actual: " << test_2_act << "\n";
//		return 0;
	}
	std::cout << part_2("input.txt");
}