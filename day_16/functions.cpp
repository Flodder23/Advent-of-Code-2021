#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP

#include <cmath>
#include <vector>

void disp_bin_num(const std::vector<int>& bin_num) {
	for (const int& i : bin_num) {
		std::cout << i;
	}
}

int get_bin_digit(const std::vector<int>& bin_num, int place) {
	if (place < bin_num.size()) {
		return bin_num[bin_num.size() - 1 - place];
	} else {
		return 0;
	}
}

void trim_bin_num(std::vector<int>& bin_num) {
	if (bin_num.size() == 0) { return; }
	if (bin_num[0] == 0) {
		std::vector<int>::iterator end = bin_num.begin();
		while (*end == 0 && end != bin_num.end()) {
			end ++;
		}
		bin_num.erase(bin_num.begin(), end);
	}
	if (bin_num.size() == 0) { bin_num = {0}; }
}

std::vector<int> add_bin_num(std::vector<int> bin_num_1, std::vector<int> bin_num_2) {
	int max_len = std::max(bin_num_1.size(), bin_num_2.size()) + 1;
	std::vector<int> bin_num(max_len);

	int carry = 0;
	int val;
	for (int i = 0; i < max_len; i++) {
		val = carry + get_bin_digit(bin_num_1, i) + get_bin_digit(bin_num_2, i);
		carry = (val > 1) ? 1 : 0;
		bin_num[max_len - 1 - i] = val%2;
	}
	trim_bin_num(bin_num);
	return bin_num;
}

std::vector<int> prod_bin_num(std::vector<int> bin_num_1, std::vector<int> bin_num_2) {
	int max_len = bin_num_1.size() + bin_num_2.size() + 1;
	std::vector<int> bin_num(max_len, 0);

	for (int i = 0; i < bin_num_2.size(); i++) {
		if (get_bin_digit(bin_num_2, i) > 0) {
			bin_num = add_bin_num(bin_num, bin_num_1);
		}
		bin_num_1.push_back(0);
	}
	trim_bin_num(bin_num);
	return bin_num;
}

std::vector<int> lesser_bin_num(std::vector<int> bin_num_1, std::vector<int> bin_num_2) {
	trim_bin_num(bin_num_1);
	trim_bin_num(bin_num_2);
	if (bin_num_1.size() < bin_num_2.size()) {
		return {1};
	} else if (bin_num_2.size() < bin_num_1.size()) {
		return {0};
	}
	// Otherwise they have same length
	for (int i = 0; i < bin_num_1.size(); i++) {
		if (bin_num_1[i] < bin_num_2[i]) {
			return {1};
		} else if (bin_num_2[i] < bin_num_1[i]) {
			return {0};
		}
	}
	return {0};
}
std::vector<int> min_bin_num(std::vector<int> bin_num_1, std::vector<int> bin_num_2) {
	if (lesser_bin_num(bin_num_1, bin_num_2)[0] == 1) {
		return bin_num_1;
	}
	return bin_num_2;
}

std::vector<int> greater_bin_num(std::vector<int> bin_num_1, std::vector<int> bin_num_2) {
	trim_bin_num(bin_num_1);
	trim_bin_num(bin_num_2);
	if (bin_num_1.size() > bin_num_2.size()) {
		return {1};
	} else if (bin_num_2.size() > bin_num_1.size()) {
		return {0};
	}
	// Otherwise they have same length
	for (int i = 0; i < bin_num_1.size(); i++) {
		if (bin_num_1[i] > bin_num_2[i]) {
			return {1};
		} else if (bin_num_2[i] > bin_num_1[i]) {
			return {0};
		}
	}
	return {0};
}
std::vector<int> max_bin_num(std::vector<int> bin_num_1, std::vector<int> bin_num_2) {
	if (greater_bin_num(bin_num_1, bin_num_2)[0] == 1) {
		return bin_num_1;
	}
	return bin_num_2;
}

std::vector<int> equal_bin_num(std::vector<int> bin_num_1, std::vector<int> bin_num_2) {
	trim_bin_num(bin_num_1);
	trim_bin_num(bin_num_2);
	if (bin_num_1.size() != bin_num_2.size()) { return {0}; }
	for (int i = 0; i < bin_num_1.size(); i++) {
		if (bin_num_1[i] != bin_num_2[i]) {
			return {0};
		}
	}
	return {1};
}

#endif