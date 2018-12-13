#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "dis_set.h"
#include "graph.h"

void main() {
	bool * seen;
	std::cout << "enter file name" << std::endl;
	std::string file_name;
	std::cin >> file_name;
	std::ifstream in_file(file_name.c_str());
	if (in_file.is_open()) {
		std::vector<std::string> vec_str_in;
		std::string in_temp;
		while (std::getline(in_file, in_temp)) {
			vec_str_in.push_back(in_temp);
		}
		graph vill_map;
		for (int i = 0; i < vec_str_in.size(); i++) {
			std::istringstream temp_str_stream(vec_str_in[i]);
			for (int j = 0; j < vec_str_in.size(); j++) {
				int temp;
				temp_str_stream >> temp;
				if (temp > 0) {
					vill_map.insert(i, j, temp);
				}
			}
		}

	}
	else {
		std::cout << "error: cannot open file" << std::endl;
	}
	system("pause");
}