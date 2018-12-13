#include "dis_set.h"


dis_set::dis_set(int size, int null_in) : null(null_in)
{
	set = new int[size];
	for (int i = 0; i < size; i++) {
		set[i] = null;
	}
	rep = -1;
}

void dis_set::insert(int in) {
	if (rep == -1) {
		in = rep;
	}
	else {
		set[in] = rep;
	}
}

int dis_set::find(int query) {
	while (set[query] == -1) {
		query = set[query];
	}
	return query;
}

void dis_set::set_union(int set_1, int set_2) {
	set[find(set_1)] = find(set_2);
}

dis_set::~dis_set()
{
	delete []set;
}
