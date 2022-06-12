#ifndef _MATRIXGRAPH_H_
#define _MATRIXGRAPH_H_
#include "Graph.h"
#include <vector>
using std::vector;
using std::pair;
class MatrixGraph: public Graph {
	vector<vector<int>> mat;
	int vert_cnt; // number of vertexes in the graph
	int edg_cnt; // number of edges in the graph
public:
	MatrixGraph(int vc);
	// bi_dir means does the graph connect both ways
	bool connect(int v, int u, int w = 1, bool bi_dir = false);
	bool disconnect(int v, int u, bool bi_dir = false);

	// bfs
	// dfs
	

	vector<int> bfs(int s);
	vector<int> dfs(int s);
	vector<int> prims(int s);
	vector<int> dijkstra(int s);
	vector<int> kruskal();

	vector<Edge> neighbor(int v);
};

#endif
