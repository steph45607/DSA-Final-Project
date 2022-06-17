#include "Graph.h"

std::ostream& operator<<(std::ostream& os, const Edge& nw) {
	os << "Edge(from=" << nw.from << ", to=" << nw.to  << ", weight=" << nw.weight << ")";
	return os;
}

bool operator<(const Edge& a, const Edge& b) {
	return a.weight < b.weight;
}
bool operator>(const Edge& a, const Edge& b) {
	return a.weight > b.weight;
}

bool operator==(const Edge& a, const Edge& b) {
	return a.weight > b.weight;
}

DisjointSet::DisjointSet(int n): parent(n), rank(n, 0) {
	for (int i = 0; i < n; i++) parent[i] = i;
} 


int DisjointSet::find(int x) {
	if (parent[x] == x) return x;
	return find(parent[x]);
}

void DisjointSet::join(int x, int y) {
	parent[find(x)] = find(y);
}