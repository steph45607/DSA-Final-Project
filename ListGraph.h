#ifndef _LISTGRAPH_H_
#define _LISTGRAPH_H_
#include <vector>
#include <queue>
#include "Graph.h"
using std::vector;
using std::pair;
using std::cout;
using std::endl;
using std::priority_queue;
using std::greater;

class ListGraph: public Graph{
	
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
	ListGraph(int vc);
	
	// bi_dir means does the graph connect both ways
	bool connect(int v, int u, int w, bool bi_dir = false);
	// bool disconnect(int v, int u, bool bi_dir = false){
	// 	adj.at(v).at(u).first = u;
	// 	adj.at(v).at(u).second = 0;
	// 	if(bi_dir){
	// 		adj.at(u).at(v).first = v;
	// 		adj.at(u).at(v).second = 0;
	// 	}
	// 	return true;
	// };

	vector<Edge> neighbor(int v);

	vector<int> dijkstra(int s);

};

#endif