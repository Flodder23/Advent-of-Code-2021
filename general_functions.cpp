#ifndef GENERAL_FUNCTIONS_CPP
#define GENERAL_FUNCTIONS_CPP

#include <string>
#include <vector>
#include <cmath>

typedef unsigned long long bigboi;

void split_string(const std::string& str, const char& delim, std::vector<std::string>& vec_str) {
	std::size_t curt = 0, next = 0;
	while (true) {
		next = str.find_first_of(delim, curt);
		if (next == std::string::npos) {
			vec_str.push_back(str.substr(curt));
			return;
		}
		if (next != curt) {
			vec_str.push_back(str.substr(curt, next-curt));
		}
		if (next == str.size()-1) { return; }
		curt = next+1;
	}
}

void str_to_vec_char(const std::string& str, std::vector<char>& vec_char) {
	for (char c : str) {
		vec_char.push_back(c);
	}
}

void vec_char_to_vec_int(const std::vector<char>& vec_char, std::vector<int>& vec_int) {
	for (char c : vec_char) {
		vec_int.push_back(std::atoi(&c));
	}
}

void vec_str_to_vec_int(const std::vector<std::string>& vec_str, std::vector<int>& vec_int) {
	for (std::string str : vec_str) {
		vec_int.push_back(std::stoi(str));
	}
}

bigboi bin_to_dec(const std::vector<int>& num) {
	bigboi result = 0;
	for (int i = 0; i < num.size(); i++) {
//		std::cout << num[i];
		if (num[num.size() - i - 1] == 1) {
			result += std::pow(2, i);
		}
	}
//	std::cout << "\n";
	return result;
}

#endif