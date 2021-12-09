#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <set>

typedef std::set<char> sc;
typedef std::vector<sc> vsc;
typedef std::vector<vsc> vvsc;

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

void str_to_sc(const std::string& str, sc& set_char) {
	for (char c : str) {
		set_char.insert(c);
	}
}
void str_vec_to_vsc(const std::vector<std::string>& vec_str, vsc& vec_set_char) {
	for (std::string str : vec_str) {
		sc vec_char;
		str_to_sc(str, vec_char);
		vec_set_char.push_back(vec_char);
	}
}

void read_input(const std::string& filename, vvsc& examples, vvsc& outputs) {
	std::ifstream input(filename);
	std::string in;
	while (std::getline(input, in)) {
		std::vector<std::string> split, ex_str, out_str;
		split_string(in, '|', split);
		split_string(split[0], ' ', ex_str);
		split_string(split[1], ' ', out_str);
		vsc ex, out;
		str_vec_to_vsc(ex_str, ex);
		str_vec_to_vsc(out_str, out);
		examples.push_back(ex);
		outputs.push_back(out);
	}
}

#endif