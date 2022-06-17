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

// Matrix part
class MatrixGraph{
	vector< vector<int> > mat;
	int vert_cnt; // number of vertexes in the graph
	int edg_cnt; // number of edges in the graph
public:
	MatrixGraph(int vc):
	vert_cnt(vc),
	edg_cnt(0),
	mat(vc, vector<int>(vc)) { }
	// bi_dir means does the graph connect both ways
	bool connect(int v, int u, int w, bool bi_dir) {
	mat.at(v).at(u) = w;
	if (bi_dir) mat.at(u).at(v) = w;
	return true;
}
	bool disconnect(int v, int u, bool bi_dir) {
	mat.at(v).at(u) = 0;
	if (bi_dir) mat.at(u).at(v) = 0;
	return true;
}

int getWeight(int from, int to){
		return mat.at(from).at(to);
	}


vector<Edge> neighbor(int v) {
	vector<Edge> res;
	for (int i = 0; i < vert_cnt; i++) {
		if (mat.at(v).at(i) > 0) {
			Edge a = {v, i, mat.at(v).at(i)};
			res.push_back(a);
		}
	}
	return res;
}


vector<int> dijkstra(int s) {
	vector<int> prev(vert_cnt, -1);
	vector<int> dist(vert_cnt, INT_MAX);
	priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
	dist[s] = 0;
	Edge ed = {-1, s, 0};
	pq.push(ed);
	Edge current;
	while (!pq.empty()) {
		current = pq.top();
		pq.pop();
		if (dist[current.to] == current.weight) {
			vector<Edge> edges = neighbor(current.to);
			for (Edge& e : edges) {
				if (dist[e.to] > dist[e.from] + e.weight) {
					dist[e.to] = dist[e.from] + e.weight;
					prev[e.to] = e.from;
					Edge toPush = {e.from, e.to, dist[e.to]};
					pq.push(toPush);
				}
			}
		}
	}
	return prev;
}

};

class ListGraph{
	
	vector<vector< pair<int, int> > > adj;
	// The vector is going to like this:
	// each pair is going to be (u, w)
	// 0 [(1, 2), (2, 3)]
	// 1 [(0, 2), ]
	// 2 []
	// 3 []
	int vert_cnt; // number of vertexes in the graph[
	int edg_cnt; // number of edges in the graph

public:
	ListGraph(int vc):
	vert_cnt(vc),
	edg_cnt(0),
	adj(vc, vector<pair<int, int> >(vc)){}
	// bi_dir means does the graph connect both ways
	bool connect(int v, int u, int w, bool bi_dir = false){
		adj.at(v).at(u).first = u;
		adj.at(v).at(u).second = w;
		if(bi_dir){
			adj.at(u).at(v).first = v;
			adj.at(u).at(v).second = w;
		}
		return true;
	};

	int getWeight(int from, int to){
		return adj.at(from).at(to).second;
	}

	vector<Edge> neighbor(int v){
		vector<Edge> res;
		for (int i = 0; i < vert_cnt; i++) {
			if (adj.at(v).at(i).second > 0) {
				Edge a = {v, i, adj.at(v).at(i).second};
				res.push_back(a);
			}
		}
		return res;
	};

	vector<int> dijkstra(int s){
		vector<int> prev(vert_cnt, -1);
		vector<int> dist(vert_cnt, INT_MAX);
		priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
		dist[s] = 0;
		Edge ed1 = { -1, s, 0 };
		pq.push(ed1);
		Edge current;
		while (!pq.empty()) {
			current = pq.top();
			pq.pop();
			if (dist[current.to] == current.weight) {
				vector<Edge> edges = neighbor(current.to);
				for (Edge& e : edges) {
					if (dist[e.to] > dist[e.from] + e.weight) {
						dist[e.to] = dist[e.from] + e.weight;
						prev[e.to] = e.from;
						Edge ed2 = { e.from, e.to, dist[e.to] };
						pq.push(ed2);
					}
				}
			}
		}
		return prev;
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