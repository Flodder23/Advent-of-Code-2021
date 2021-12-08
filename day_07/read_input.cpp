#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>

void split_string(const std::string& str, const char& delim, std::vector<std::string>& vec) {
	std::size_t curt = 0, next = 0;
	while (true) {
		next = str.find_first_of(delim, curt);
		if (next == std::string::npos) {
			vec.push_back(str.substr(curt));
			return;
		}
		if (next != curt) {
			vec.push_back(str.substr(curt, next-curt));
		}
		if (next == str.size()-1) { return; }
		curt = next+1;
	}
}

void str_vec_to_int_vec(const std::vector<std::string>& str_vec, std::vector<int>& int_vec) {
	for (int i = 0; i < str_vec.size(); i++) {
		int_vec.push_back(std::stoi(str_vec[i]));
	}
}

void read_input(const std::string& filename, std::vector<int>& crabs) {
	std::ifstream input(filename);
	std::string in;
	std::getline(input, in);
	std::vector<std::string> crabs_str;
	split_string(in, ',', crabs_str);
	str_vec_to_int_vec(crabs_str, crabs);
}

#endif