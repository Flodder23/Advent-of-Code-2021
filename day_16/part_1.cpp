#include "read_input.cpp"

void get_sum_versions(const std::vector<int>& message, int& pos, int& sum) {
	// get sum of versions of packets in packet starting at given position
	int start_pos = pos;
	int version = 4*message[pos] + 2*message[pos+1] + message[pos+2];
	pos += 3;
	int type = 4*message[pos] + 2*message[pos+1] + message[pos+2];
	pos += 3;
	
	sum += version;
	if (type == 4) {
		while (message[pos] != 0) {
			pos += 5;
		}
		pos += 5;
	} else {
		if (message[pos] == 0) {
			pos ++;
			int end_pos = pos + 15;
			for (int i = 0; i < 15; i++) {
				end_pos += message[pos] * std::pow(2, 14-i);
				pos ++;
			}
			while (pos < end_pos) {
				get_sum_versions(message, pos, sum);
			}
		} else {
			pos ++;
			int num_subs = 0;
			for (int i = 0; i < 11; i++) {
				num_subs += message[pos] * std::pow(2, 10-i);
				pos ++;
			}
			for (int i = 0; i < num_subs; i++) {
				get_sum_versions(message, pos, sum);
			}
		}
	}
}

int part_1(const std::string& filename) {
	std::vector<int> message;
	read_input(filename, message);

	int pos = 0,  sum = 0;
	while (pos < message.size() - 4) {
		get_sum_versions(message, pos, sum);
	}

	return sum;
}