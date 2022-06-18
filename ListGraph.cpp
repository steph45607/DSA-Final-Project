#ifndef _LISTGRAPH_
#define _LISTGRAPH_
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#include "Graph.cpp"
// using std::vector;
// using std::pair;
// using std::cout;
// using std::endl;
// using std::priority_queue;
// using std::greater;
using namespace std;

class ListGraph : public Graph{
	private:
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
		vert_cnt(vc), edg_cnt(0), adj(vc, vector<pair<int, int> >(vc)){}
		// bi_dir means does the graph connect both ways
		bool connect(int v, int u, int w, bool bi_dir = false){
			adj.at(v).at(u).first = u;
			adj.at(v).at(u).second = w;
			if(bi_dir){
				adj.at(u).at(v).first = v;
				adj.at(u).at(v).second = w;
			}
			return true;
		}
		bool disconnect(int v, int u, bool bi_dir) {
			adj.at(v).at(u).second = 0;
			if (bi_dir) adj.at(u).at(v).second = 0;
			return true;
		}

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
		}
		
		vector<int> dijkstra(int s){
			vector<int> prev(vert_cnt, -1);
			vector<int> dist(vert_cnt, INT_MAX);
			priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
			dist[s] = 0;
			Edge edge1 = { -1, s, 0 };
			pq.push(edge1);
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
							Edge edge2 = { e.from, e.to, dist[e.to] };
							pq.push(edge2);
						}
					}
				}
			}
			return prev;
		}
};

#endif