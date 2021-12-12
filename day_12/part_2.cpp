#include <vector>
#include <map>
#include <set>

#include "read_input.cpp"

void explore(const std::string& cave, std::map<std::string, std::set<std::string>>& links, std::set<std::string>& visited, int& valid, bool twice) {
	bool twice_init = twice;
	for (std::string c : links[cave]) {
		twice = twice_init;
		if (std::islower(c[0])) {
			if (visited.find(c) != visited.end()) {
				if (twice || c == "start") {
					continue;
				}
				twice = true;
			}
			if (c == "end") {
				valid ++;
				continue;
			}
			visited.insert(c);
		}
		explore(c, links, visited, valid, twice);

		if (std::islower(c[0]) && (twice_init || !twice)) {
			visited.erase(c);
		}
	}
}

int part_2(const std::string& filename) {
	std::map<std::string, std::set<std::string>> links;
	read_input(filename, links);
	
	int valid = 0;
	std::set<std::string> visited = {"start"};
	explore("start", links, visited, valid, false);

	return valid;
}