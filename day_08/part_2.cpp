#include <vector>
#include <string>
#include <map>

#include "read_input.cpp"


int part_2(const std::string& filename) {
	std::vector<std::vector<std::string>> examples, outputs;
	read_input(filename, examples, outputs);
	// length	| 2 | 3 | 4 |    5    |    6    | 7 |
	// numbers	| 1 | 7 | 4 | 2, 3, 5 | 0, 6, 9 | 8 |
	//
	//  00           88
	// 1  2         6  8
	//  33           77
	// 4  5         4  9
	//  66           77

	const std::vector<char> letters = {'a', 'b', 'c', 'd', 'e' ,'f', 'g'};
	std::vector<char> pos_char(7);
	std::map<char, int> char_amount;
	std::string four, out;
	int sum = 0;
	for (int i = 0; i < examples.size(); i++) {
		const std::vector<std::string>& example = examples[i];
		const std::vector<std::string>& output = outputs[i];

		for (const char& c : letters) {
			char_amount[c] = 0;
		}
		for (const std::string& ex : example) {
			if (ex.size() == 4) {
				four = ex;
			}
			for (const char& c : ex) {
				char_amount[c] ++;
			}
		}
		for (const char& c : letters) {
			switch (char_amount[c]) {
				case 4:
					pos_char[4] = c;
					break;
				case 6:
					pos_char[1] = c;
					break;
				case 7:
					if (four.find(c) == std::string::npos) {
						pos_char[6] = c;
					} else{
						pos_char[3] = c;
					}
					break;
				case 8:
					if (four.find(c) == std::string::npos) {
						pos_char[0] = c;
					} else {
						pos_char[2] = c;
					}
					break;
				case 9:
					pos_char[5] = c;
					break;
			}
		}
		out = "";
		for (const std::string& o : output) {
			switch (o.size()) {
				case 2:
					out += "1";
					break;
				case 3:
					out += "7";
					break;
				case 4:
					out += "4";
					break;
				case 5:
					if (o.find(pos_char[2]) == std::string::npos) {
						out += "5";
					} else if (o.find(pos_char[5]) == std::string::npos) {
						out += "2";
					} else {
						out += "3";
					}
					break;
				case 6:
					if (o.find(pos_char[2]) == std::string::npos) {
						out += "6";
					} else if (o.find(pos_char[4]) == std::string::npos) {
						out += "9";
					} else {
						out += "0";
					}
					break;
				case 7:
					out += "8";
					break;
			}
		}
		sum += std::stoi(out);
	}
	return sum;
}