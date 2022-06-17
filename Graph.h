#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include <vector>

using std::vector;
struct Edge {
	int from;
	int to;
	int weight;

	friend std::ostream& operator<<(std::ostream& os, const Edge& nw);
	friend bool operator<(const Edge& a, const Edge& b);
	friend bool operator>(const Edge& a, const Edge& b);
	friend bool operator==(const Edge& a, const Edge& b);
};

class Graph {
public:
	virtual bool 
		connect(int v, int u, int w, bool bi_dir = false) = 0;
	virtual bool 
		disconnect(int v, int u, bool bi_dir = false) = 0;
};

class DisjointSet {
private:
	vector<int> parent;
	vector<int> rank;
public:
	DisjointSet(int n);
	int find(int x);
	void join(int x, int y);
};
#endif