#include <vector>
#include <map>
#include <set>

#include "read_input.cpp"

void explore(const std::string& cave, std::map<std::string, std::set<std::string>>& links, std::set<std::string>& visited, int& valid) {
	for (std::string c : links[cave]) {
		if (std::islower(c[0])) {
			if (visited.find(c) != visited.end()) {
				continue;
			}
			if (c == "end") {
				valid ++;
				continue;
			}
			visited.insert(c);
		}
		explore(c, links, visited, valid);

		if (std::islower(c[0])) {
			visited.erase(c);
		}
	}
}

int part_1(const std::string& filename) {
	std::map<std::string, std::set<std::string>> links;
	read_input(filename, links);
	
	int valid = 0;
	std::set<std::string> visited = {"start"};
	explore("start", links, visited, valid);

	return valid;
}