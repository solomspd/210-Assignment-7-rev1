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
	file_name += ".txt";
	std::ifstream in_file(file_name.c_str());
	if (in_file.is_open()) {
		std::vector<std::string> vec_str_in;
		std::string in_temp;
		while (std::getline(in_file, in_temp)) {
			vec_str_in.push_back(in_temp);
		}
		graph vill_map(vec_str_in.size());
		for (int i = 0; i < vec_str_in.size(); i++) {
			std::istringstream temp_str_stream(vec_str_in[i]);
			for (int j = 0; j < vec_str_in.size(); j++) {
				int temp;
				temp_str_stream >> temp;
				vill_map.insert(i, j, temp);
			}
		}
		std::cout << "Adjacency matrix" << std::endl << std::endl;
		for (int i = 0; i < vill_map.get_size(); i++) {
			std::cout << std::setw(5) << std::internal << char(i + char('A'));
		}
		std::cout << std::endl;
		vill_map.print_adj();
		std::cout << "number of non zero edges is " << vill_map.non_0_edge() << std::endl;
		std::cout << "number of vertecies is " << vill_map.get_size() << std::endl;
		std::cout << "these " << vill_map.get_size() << " edges are" << std::endl;
		vill_map.print_edges();
		std::cout << "DFS Graph Traversal starting from node A gives: ";
		vill_map.dfs();
		vill_map.minimum_span();
		std::cout << std::endl << std::endl << "The edges of the Minimum Spanning Tree are: " << std::endl;
		vill_map.print_edges();
	}
	else {
		std::cout << "error: cannot open file" << std::endl;
	}
	system("pause");
}