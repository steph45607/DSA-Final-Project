// #ifndef _LISTGRAPH_CPP_
// #define _LISTGRAPH_CPP_
#include "ListGraph.h"
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

// #include "Graph.h"
using std::vector;
using std::pair;
using std::cout;
using std::endl;
using std::queue;
using std::priority_queue;
using std::greater;

ListGraph::ListGraph(int vc):
	vert_cnt(vc),
	edg_cnt(0),
	adj(vc, vector<pair<int, int>>(vc)) {}

// bi_dir means does the graph connect both ways
bool ListGraph::connect(int v, int u, int w, bool bi_dir){
	adj.at(v).at(u).first = u;
	adj.at(v).at(u).second = w;
	if(bi_dir){
		adj.at(u).at(v).first = v;
		adj.at(u).at(v).second = w;
	}
	return true;

};
	// bool disconnect(int v, int u, bool bi_dir = false){
	// 	adj.at(v).at(u).first = u;
	// 	adj.at(v).at(u).second = 0;
	// 	if(bi_dir){
	// 		adj.at(u).at(v).first = v;
	// 		adj.at(u).at(v).second = 0;
	// 	}
	// 	return true;
	// };

	vector<Edge> ListGraph::neighbor(int v){
		vector<Edge> res;
		for (int i = 0; i < vert_cnt; i++) {
			if (adj.at(v).at(i).second > 0) {
				Edge a = {v, i, adj.at(v).at(i).second};
				res.push_back(a);
			}
		}
		return res;
	};

	vector<int> ListGraph::dijkstra(int s){
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
	};


// #endif