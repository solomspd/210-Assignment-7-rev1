#pragma once

#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

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
			return weight < rhs.weight;
		}

		friend std::ostream& operator << (std::ostream& os, const edge& rhs)
		{
			os << rhs.vertex_1 << "	" << rhs.vertex_2 << "	" << rhs.weight << std::endl;
			return os;
		}
	};
	int vert_num, edges, order, size;
	int * seen;
	std::vector<edge> edge_list;
	std::vector<std::vector<int>> adjacent;
	edge * mst;

	dis_set span_set;

	void visit(int);

public:
	graph();
	void insert(int, int, int weight = 1);
	void insert_edge(int, int, int weight = 1);
	void insert_relation(int, int);
	void dfs();
	void minimum_span();
	~graph();
};

