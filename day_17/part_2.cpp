#include <cmath>

#include "read_input.cpp"

int part_2(const std::string& filename) {
	int min_x, max_x, min_y, max_y;
	read_input(filename, min_x, max_x, min_y, max_y);

	int n = 0;
	for (int init_vel_x = 0; init_vel_x <= max_x; init_vel_x++) {
		for (int init_vel_y = min_y; init_vel_y <= -min_y; init_vel_y++) {
			int pos_x = 0, pos_y = 0, vel_x = init_vel_x, vel_y = init_vel_y;
			while (pos_x <= max_x && pos_y >= min_y) {
				pos_x += vel_x;
				pos_y += vel_y;

				if (min_x <= pos_x && pos_x <= max_x && min_y <= pos_y && pos_y <= max_y) {
					n ++;
					break;
				}

				if (vel_x > 0) { vel_x -= 1; }
				vel_y -= 1;
			}
		}
	}
	return n;
}