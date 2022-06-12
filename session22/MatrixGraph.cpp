#include "MatrixGraph.h"
#include <iostream>
#include <climits>
#include <queue> // for queue and priority queue
#include <stack>
using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::priority_queue;
using std::greater;

MatrixGraph::MatrixGraph(int vc):
	vert_cnt(vc),
	edg_cnt(0),
	mat(vc, vector<int>(vc)) { }

bool MatrixGraph::connect(int v, int u, int w, bool bi_dir) {
	mat.at(v).at(u) = w;
	if (bi_dir) mat.at(u).at(v) = w;
	return true;
}

bool MatrixGraph::disconnect(int v, int u, bool bi_dir) {
	mat.at(v).at(u) = 0;
	if (bi_dir) mat.at(u).at(v) = 0;
	return true;
}

vector<Edge> MatrixGraph::neighbor(int v) {
	vector<Edge> res;
	for (int i = 0; i < vert_cnt; i++) {
		if (mat.at(v).at(i) > 0) {
			Edge a = {v, i, mat.at(v).at(i)};
			res.push_back(a);
		}
	}
	return res;
}

vector<int> MatrixGraph::bfs(int s) {
	vector<int> dist(vert_cnt, 0);
	vector<bool> visited(vert_cnt, false);
	queue<int> que;
	que.push(s);
	visited[s] = true;
	int current;
	while (!que.empty()) {
		current = que.front();
		que.pop();
		vector<Edge> neighbors = neighbor(current);
		for (Edge e : neighbors) {
			if (!visited[e.to]) {
				dist[e.to] = dist[e.from] + e.weight;
				que.push(e.to);
				visited[e.to] = true;
			}
		}
	}
	return dist;
}

vector<int> MatrixGraph::dfs(int s) {
	vector<int> dist(vert_cnt, 0);
	vector<bool> visited(vert_cnt, false);
	stack<int> sta;
	sta.push(s);
	visited[s] = true;
	int current;
	while (!sta.empty()) {
		current = sta.top();
		sta.pop();
		vector<Edge> neighbors = neighbor(current);
		for (Edge e : neighbors) {
			if (!visited[e.to]) {
				dist[e.to] = dist[e.from] + e.weight;
				sta.push(e.to);
				visited[e.to] = true;
			}
		}
	}
	return dist;
}

vector<int> MatrixGraph::prims(int s) {
	vector<int> prev(vert_cnt, -1);
	vector<bool> visited(vert_cnt, false);
	vector<int> dist(vert_cnt, INT_MAX);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	dist[s] = 0;
	pq.push(Edge{-1, s, 0});
	Edge current;
	while (!pq.empty()) {
		current = pq.top();
		pq.pop();
		if (dist[current.to] == current.weight) {
			visited[current.to] = true;
			vector<Edge> neighbors = neighbor(current.to);
			for (Edge& e : neighbors) {
				if (!visited[e.to] && (dist[e.to] > e.weight)) {
					dist[e.to] = e.weight;
					prev[e.to] = e.from;
					pq.push(e);
				}
			}
		}
	}
	return prev;
}

vector<int> MatrixGraph::dijkstra(int s) {
	vector<int> prev(vert_cnt, -1);
	vector<int> dist(vert_cnt, INT_MAX);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	dist[s] = 0;
	pq.push(Edge{ -1, s, 0 });
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
					pq.push(Edge{ e.from, e.to, dist[e.to] });
				}
			}
		}
	}
	return prev;
}

vector<int> MatrixGraph::kruskal() {
	vector<Edge> allEdges;
	for (int i = 0; i < vert_cnt; i++) {
		for (Edge e : neighbor(i)) {
			allEdges.push_back(e);
		}
	}
	DisjointSet s(vert_cnt);
	std::sort(allEdges.begin(), allEdges.end());
	vector<int> prev(vert_cnt, -1);
	for (Edge& e : allEdges) {
		if (s.find(e.from) != s.find(e.to)) {
			s.join(e.from, e.to);
			prev[e.to] = e.from;
		}
	};
	return prev;
}
