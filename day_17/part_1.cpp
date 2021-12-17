#include "read_input.cpp"

int part_1(const std::string& filename) {
	int min_x, max_x, min_y, max_y;
	read_input(filename, min_x, max_x, min_y, max_y);
	
/*	some maths and some assumptions make this simple (though
	the problem doesn't actually state all the assumptions
	made, the example and my input suggest they are ok to make)
*/	
	return (-min_y)*(-1 - min_y)/2;
}