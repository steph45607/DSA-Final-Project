#ifndef _GRAPH_
#define _GRAPH_
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
	int from;
	int to;
	int weight;

	friend std::ostream& operator<<(std::ostream& os, const Edge& nw){
		os << "Edge(from=" << nw.from << ", to=" << nw.to  << ", weight=" << nw.weight << ")";
		return os;
	};
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

class Graph {
public:
	virtual bool connect(int v, int u, int w, bool bi_dir = false) = 0;
	virtual bool disconnect(int v, int u, bool bi_dir = false) = 0;
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

template <class T>
void print(const vector<T>& vec, const string& pre = "", const string& suf = "\n") {
	cout << pre << "[";
	for (const T& x : vec) {
		cout << x << ", ";
	}
	cout << "]" << suf;
}
#endif