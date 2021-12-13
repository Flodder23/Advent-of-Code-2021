#include <vector>
#include <string>
#include <map>
#include <set>

#include "read_input.cpp"

typedef std::vector<std::set<sc>> vssc;
typedef std::set<sc> ssc;

char find_pos_2(const sc& chars_1, const ssc& len_6) {
for (const sc& chars : len_6) {
		for (const char& c : chars_1) {
			if (chars.find(c) == chars.end()) {
				return c;
			}
		}
	}
	return ' ';
}

char find_pos_3(const sc& chars_4, const ssc& len_6) {
	for (const sc& chars : len_6) {
		for (const char& c : chars_4) {
			if (chars.find(c) == chars.end()) {
				return c;
			}
		}
	}
	return ' ';
}

int part_2(const std::string& filename) {
	vvsc examples, outputs;
	read_input(filename, examples, outputs);
	// length	| 2 | 3 | 4 |    5    |    6    | 7 |
	// numbers	| 1 | 7 | 4 | 2, 3, 5 | 0, 6, 9 | 8 |
	//
	//  00
	// 1  2
	//  33
	// 4  5
	//  66

	int sum = 0;
	for (int i = 0; i < examples.size(); i++) {
		vsc& example = examples[i];
		vsc& output = outputs[i];
		vssc len_to_vec_chars(8);
		
		for (sc& ex : example) {
			len_to_vec_chars[ex.size()].insert(ex);
		}
		sc chars_1 = *len_to_vec_chars[2].begin();
		sc chars_4 = *len_to_vec_chars[4].begin();
		char pos_2 = find_pos_2(chars_1, len_to_vec_chars[6]);
		char pos_5;
		for (const char& c : chars_1) {
			if (c != pos_2) {
				pos_5 = c;
			}
			chars_4.erase(c);
		}
		char pos_3 = find_pos_3(chars_4, len_to_vec_chars[6]);

		std::string out = "";
		for (const sc& o : output) {
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
					if (o.find(pos_2) == o.end()) {
						out += "5";
					} else if (o.find(pos_5) == o.end()) {
						out += "2";
					} else {
						out += "3";
					}
					break;
				case 6:
					if (o.find(pos_2) == o.end()) {
						out += "6";
					} else if (o.find(pos_3) == o.end()) {
						out += "0";
					} else {
						out += "9";
					}
					break;
				default:
					out += "8";
					break;
			}
		}
		sum += std::stoi(out);
	}
	return sum;
}