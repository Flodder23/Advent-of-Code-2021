#include "read_input.cpp"

bigboi part_2(const std::string& filename) {
	std::string poly;
	std::map<std::pair<char, char>, pairInfo> pairs;
	read_input(filename, poly, pairs);

	for (int i = 0; i < 40; i++) {
		for (std::pair<const std::pair<char, char>, pairInfo>& pair : pairs) {
			pairInfo& p = pair.second;
			pairs[{p.pair.first, p.mapsto}].next_num += p.cur_num;
			pairs[{p.mapsto, p.pair.second}].next_num += p.cur_num;
		}

		for (std::pair<const std::pair<char, char>, pairInfo>& pair : pairs) {
			pair.second.cur_num = pair.second.next_num;
			pair.second.next_num = 0;
		}
	}

	std::map<char, bigboi> char_amount;
	for (std::pair<const std::pair<char, char>, pairInfo>& pair : pairs) {
		pairInfo& p = pair.second;
		for (char c : {p.pair.first, p.pair.second}) {
			if (char_amount.find(c) == char_amount.end()) {
				char_amount[c] = p.cur_num;
			} else {
				char_amount[c] += p.cur_num;
			}
		}
	}

	bigboi min = -1, max = 0;
	for (std::pair<const char, bigboi>& c_a: char_amount) {
		// The first and last characters are only counted once so we add one on...
		char c = c_a.first;
		bigboi a = c_a.second;
		if (c == poly[0]) {
			a ++;
		}
		if (c == poly[poly.size()-1]) {
			a ++;
		}
		// ... and then divide all of them by 2.
		a /= 2;

		if (min < 0 || a < min) {
			min = a;
		}
		if (a > max) {
			max = a;
		}
	}

	return max - min;
}