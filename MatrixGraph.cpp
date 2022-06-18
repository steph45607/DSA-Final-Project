#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <climits>
#include <queue> // for queue and priority queue
#include <vector>
#include "Graph.cpp"

// using std::cout;
// using std::endl;
// using std::priority_queue;
// using std::greater;
// using std::vector;
using namespace std;

// Matrix part
class MatrixGraph : public Graph{
	private:
		vector< vector<int> > mat;
		int vert_cnt; // number of vertexes in the graph
		int edg_cnt; // number of edges in the graph
	public:
		MatrixGraph(int vc):
		vert_cnt(vc), edg_cnt(0), mat(vc, vector<int>(vc)) { }
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

#endif