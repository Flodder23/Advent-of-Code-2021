#include <vector>

#include "read_input.cpp"
#include "functions.cpp"

void lift_digits(const std::vector<int>& message, std::vector<int>& bin_num, int& pos, int len) {
	for (int i = 0; i < len; i++) {
		bin_num.push_back(message[pos]);
		pos ++;
	}
}

std::vector<int> parse_package(const std::vector<int>& message, int& pos) {
	int start_pos = pos;
	int version = 4*message[pos] + 2*message[pos+1] + message[pos+2];
	pos += 3;
	int type = 4*message[pos] + 2*message[pos+1] + message[pos+2];
	pos += 3;
	
	std::vector<int> num;
	if (type == 4) {
		while (message[pos] != 0) {
			pos ++;
			lift_digits(message, num, pos, 4);
		}
		pos ++;
		lift_digits(message, num, pos, 4);
	} else {
		std::vector<std::vector<int>> nums;
		if (message[pos] == 0) {
			pos ++;
			std::vector<int> pack_len_bin;
			lift_digits(message, pack_len_bin, pos, 15);
			int end_pos = pos + bin_to_dec(pack_len_bin);
			while (pos < end_pos) {
				nums.push_back(parse_package(message, pos));
			}
		} else {
			pos ++;
			std::vector<int> num_subs_bin;
			lift_digits(message, num_subs_bin, pos, 11);
			int num_subs = bin_to_dec(num_subs_bin);
			for (int i = 0; i < num_subs; i++) {
				nums.push_back(parse_package(message, pos));
			}
		}
		switch (type) {
			case 0:
				for (const std::vector<int>& n : nums) {
					num = add_bin_num(num, n);
				}
				break;
			case 1:
				num = {1};
				for (const std::vector<int>& n : nums) {
					num = prod_bin_num(n, num);
				}
				break;
			case 2:
				for (std::vector<int>& n : nums) {
					if (num.size() == 0) {
						num = n;
					} else {
						num = min_bin_num(n, num);
					}
				}
				break;
			case 3:
				for (std::vector<int>& n : nums) {
					num = max_bin_num(n, num);
				}
				break;
			case 5:
				num = greater_bin_num(nums[0], nums[1]);
				break;
			case 6:
				num = lesser_bin_num(nums[0], nums[1]);
				break;
			case 7:
				num = equal_bin_num(nums[0], nums[1]);
				break;
			default:
				std::cout << "uh oh";
		}
	}
	return num;
}

bigboi part_2(const std::string& filename) {
	std::vector<int> message;
	read_input(filename, message);

	int pos = 0;
	return bin_to_dec(parse_package(message, pos));
}