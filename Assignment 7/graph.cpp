#include "graph.h"

graph::graph(int size_in) : size(size_in)
{
	adjacent = new int*[size];
	for (int i = 0; i < size; i++) {
		adjacent[i] = new int[size];
	}
	vert_num = 0;
	edges = 0;
}

void graph::insert(int vertex_1_in, int vertex_2_in, int weight_in) {
	insert_edge(vertex_1_in, vertex_2_in, weight_in);
	insert_relation(vertex_1_in, vertex_2_in, weight_in);
}

void graph::insert_edge(int vertex_1_in, int vertex_2_in, int weight_in) {
	if (weight_in > 0) {
		edge new_edge;
		new_edge.vertex_1 = vertex_1_in;
		new_edge.vertex_2 = vertex_2_in;
		new_edge.weight = weight_in;
		//std::cout << new_edge;
		edge_list.push_back(new_edge);
	}
}

void graph::insert_relation(int vertex_main_in, int vertex_append_in ,int weight_in) {
	adjacent[vertex_main_in][vertex_append_in] = weight_in;
}

void graph::print_adj() {
	for (int i = 0; i < size; i++) {
		std::cout << char(i + int('A'));
		for (int j = 0; j < size; j++) {
			std::cout << std::setw(5) << adjacent[i][j];
		}
		std::cout << std::endl;
	}
}

int graph::get_size() {
	return size;
}

int graph::non_0_edge() {
	return edge_list.size();
}

void graph::print_edges() {
	for (int i = 0; i < edge_list.size(); i++) {
		std::cout << edge_list[i];
	}
}

void graph::minimum_span() {
	std::priority_queue<edge> que;
	for (int i = 0; i < size; i++) {
		if (edge_list[i].weight > 0) {
			que.push(edge_list[i]);
		}
	}
	edges = size - 1;
	mst = new edge[edges];
	for (int i = 0; i < edges && !que.empty(); i) {
		edge temp = que.top();
		que.pop();
		int x = span_set.find(temp.vertex_1), y = span_set.find(temp.vertex_2);
		if (x != y) {
			i++;
			mst[i] = temp;
			std::cout << temp;
			span_set.set_union(x, y);
		}
	}
}

void graph::visit(int in) {
	seen[in] = ++order;
	std::cout << char(in + int('A')) << std::endl;
	for (int i = 0; i < size; i++) {
		if (adjacent[in][i] > 0 && seen[in] == -1) {
			visit(i);
		}
	}
}

void graph::dfs() {
	order = 0;
	seen = new int[edge_list.size()];
	for (int i = 0; i < size; i++) {
		seen[i] = -1;
	}
	for (int i = 0; i < size; i++) {
		if (seen[i] == -1) {
			visit(i);
		}
	}
}

graph::~graph()
{
}
