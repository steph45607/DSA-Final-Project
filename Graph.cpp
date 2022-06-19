#ifndef _GRAPH_
#define _GRAPH_
#include <iostream>
#include <vector>
using namespace std;


//store info about origin node and end node with the cost connecting them
struct Edge {
	int from;
	int to;
	int weight;

	// friend std::ostream& operator<<(std::ostream& os, const Edge& nw){
	// 	os << "Edge(from=" << nw.from << ", to=" << nw.to  << ", weight=" << nw.weight << ")";
	// 	return os;
	// };
	friend bool operator<(const Edge& a, const Edge& b){
		return a.weight < b.weight;
	};
	friend bool operator>(const Edge& a, const Edge& b){
		return a.weight > b.weight;
	};
	friend bool operator==(const Edge& a, const Edge& b){
		return a.weight > b.weight;
	};
};

//class for creating a weighted graph from nodes
class Graph {
public:
	virtual bool connect(int from, int to, int weight, bool bi_dir = false) = 0;
	virtual bool disconnect(int from, int to, bool bi_dir = false) = 0;
};

class DisjointSet {
private:
	vector<int> parent;
	vector<int> rank;
public:
	DisjointSet(int n) : parent(n), rank(n, 0) {
		for (int i = 0; i < n; i++) parent[i] = i;
	};
	int find(int x) {
		if (parent[x] == x) return x;
		return find(parent[x]);
	};
	void join(int x, int y){
		parent[find(x)] = find(y);
	};
};

#endif