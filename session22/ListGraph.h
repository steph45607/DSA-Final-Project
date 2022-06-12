#ifndef _LISTGRAPH_H_
#define _LISTGRAPH_H_
#include <vector>
#include "Graph.h"
using std::vector;
using std::pair;
class ListGraph: public Graph{
	vector<vector<pair<int, int>>> adj;
	// The vector is going to like this:
	// each pair is going to be (u, w)
	// 0 [(1, 2), (2, 3)]
	// 1 [(0, 2), ]
	// 2 []
	// 3 []
	int vert_cnt; // number of vertexes in the graph[
	int edg_cnt; // number of edges in the graph

public:
	ListGraph(int vc);
	// bi_dir means does the graph connect both ways
	bool connect(int v, int u, int w, bool bi_dir = false);
	bool disconnect(int v, int u, bool bi_dir = false);
};

#endif