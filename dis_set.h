#pragma once

class dis_set
{
private:
	int null;
	int * set;
	int rep;
public:
	dis_set( int size = 100, int null_in = -1);
	void insert(int);
	void set_union(int, int);
	int find(int);
	~dis_set();
};

