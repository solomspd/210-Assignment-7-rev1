#pragma once

#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
#include <iomanip>

#include "dis_set.h"

class graph
{
private:
	struct edge {
		int vertex_1;
		int vertex_2;
		int weight;

		bool operator < (const edge& rhs) const
		{
			return weight > rhs.weight;
		}

		bool operator == (const edge& rhs) const
		{
			if ((vertex_1 == rhs.vertex_1 && vertex_2 == rhs.vertex_2) || (vertex_2 == rhs.vertex_1 && vertex_1 == rhs.vertex_2)) {
				return true;
			}
			return false;
		}

		friend std::ostream& operator << (std::ostream& os, const edge& rhs)
		{
			os << char (rhs.vertex_1 + int('A')) << "	" << char(rhs.vertex_2 + int('A')) << "	" << rhs.weight << std::endl;
			return os;
		}
	};
	int vert_num, edges, order, size;
	int * seen;
	std::vector<edge> edge_list;
	int ** adjacent;
	edge * mst;

	dis_set span_set;

	void visit(int);

public:
	graph(int size_in = 25);
	void insert(int, int, int weight = 1);
	void insert_edge(int, int, int weight = 1);
	void insert_relation(int, int, int weight= 1);
	void print_adj();
	void dfs();
	void minimum_span();
	int get_size();
	int non_0_edge();
	void print_edges();
	~graph();
};

