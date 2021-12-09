#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>

#include "read_input.cpp"

typedef std::vector<std::set<sc>> vssc;

int intersect_size(const sc& s1, const sc& s2) {
	int size = 0;
	for (char c : s1) {
		if (s2.find(c)  != s2.end()) {
			size ++;
		}
	}
	return size;
}

int part_2(const std::string& filename) {
	vvsc examples, outputs;
	read_input(filename, examples, outputs);
	// length	| 2 | 3 | 4 |    5    |    6    | 7 |
	// numbers	| 1 | 7 | 4 | 2, 3, 5 | 0, 6, 9 | 8 |

	int sum = 0;
	for (int i = 0; i < examples.size(); i++) {
		vsc& example = examples[i];
		vsc& output = outputs[i];
		vsc num_chars(10); // map chars to number
		vssc len_vec_chars(8); // map length to vector of possible char sets
		
		for (sc& ex : example) {
			len_vec_chars[ex.size()].insert(ex);
		}
		num_chars[1] = *len_vec_chars[2].begin();
		num_chars[4] = *len_vec_chars[4].begin();
		num_chars[7] = *len_vec_chars[3].begin();
		num_chars[8] = *len_vec_chars[7].begin();
		for (sc chars : len_vec_chars[5]) {
			if (intersect_size(num_chars[1], chars) == 2) {
				num_chars[3] = chars;
				len_vec_chars[5].erase(chars);
				break;
			}
		}
		for (sc chars : len_vec_chars[6]) {
			if (intersect_size(num_chars[3], chars) == 5) {
				num_chars[9] = chars;
				len_vec_chars[6].erase(chars);
				break;
			}
		}
		for (sc chars : len_vec_chars[5]) {
			if (intersect_size(chars, num_chars[9]) == 5) {
				num_chars[5] = chars;
				len_vec_chars[5].erase(chars);
				break;
			}
		}
		num_chars[2] = *len_vec_chars[5].begin();
		for (sc chars : len_vec_chars[6]) {
			if (intersect_size(num_chars[5], chars) == 5) {
				num_chars[6] = chars;
				len_vec_chars[6].erase(chars);
				break;
			}
		}
		num_chars[0] = *len_vec_chars[6].begin();

		std::map<sc, std::string> chars_num;
		for (int i = 0; i <= 9; i++) {
			chars_num[num_chars[i]] = std::to_string(i);
		}
		std::string out = "";
		for (sc o : output) {
			out += chars_num[o];
		}
		sum += std::stoi(out);
	}
	return sum;
}