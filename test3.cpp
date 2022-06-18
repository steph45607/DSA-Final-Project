#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
#include <string>

using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::priority_queue;
using std::greater;
using std::pair;
using std::vector;
using namespace std;

struct Edge {
	int from;
	int to;
	int weight;

	
	friend std::ostream& operator<<(std::ostream& os, const Edge& nw) {
		os << "Edge(from=" << nw.from << ", to=" << nw.to  << ", weight=" << nw.weight << ")";
		return os;
	}

	friend bool operator<(const Edge& a, const Edge& b) {
		return a.weight < b.weight;
	}

	friend bool operator>(const Edge& a, const Edge& b) {
		return a.weight > b.weight;
	}

	friend bool operator==(const Edge& a, const Edge& b) {
		return a.weight > b.weight;
	}
};

class DisjointSet {
private:
	vector<int> parent;
	vector<int> rank;
public:
	DisjointSet(int n): parent(n), rank(n, 0) {
	for (int i = 0; i < n; i++) parent[i] = i;
} 
	int find(int x) {
	if (parent[x] == x) return x;
	return find(parent[x]);
}

void join(int x, int y) {
	parent[find(x)] = find(y);
}
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