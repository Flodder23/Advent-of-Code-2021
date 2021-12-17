#ifndef READ_INPUT_CPP
#define READ_INPUT_CPP

#include <fstream>
#include <string>
#include <map>

#include "../general_functions.cpp"

struct pairInfo {
	std::pair<char, char> pair;
	char mapsto;
	bigboi cur_num;
	bigboi next_num;
};

void read_input(const std::string& filename, std::string& poly, std::map<std::pair<char, char>, pairInfo>& pairs) {
	std::ifstream input(filename);
	
	std::getline(input, poly);

	std::string in;
	std::getline(input, in); // skip blank line
	while (std::getline(input, in)) {
		std::vector<std::string> rule;
		split_string(in, ' ', rule);
		std::pair<char, char> r = {rule[0][0], rule[0][1]};
		pairInfo info;
		info.pair = r;
		info.mapsto = rule[2][0];
		info.cur_num = 0;
		info.next_num = 0;
		pairs[r] = info;
	}
	
	for (int i = 1; i < poly.size(); i++) {
		pairs[{poly[i-1], poly[i]}].cur_num += 1;
	}
}

#endif