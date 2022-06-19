#ifndef _LISTGRAPH_
#define _LISTGRAPH_
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#include "Graph.cpp"
using namespace std;

//ListGraph class
class ListGraph : public Graph{

	//declaring private data
	private:
		vector<vector< pair<int, int> > > adj;
		int nodeCount; // number of vertexes in the graph[
		int edgeCount; // number of edges in the graph

	public:
		ListGraph(int n):
		nodeCount(n), edgeCount(0), adj(n, vector<pair<int, int> >(n)){}

		//function to connect two nodes
		//isDirected means does the graph connect both ways
		bool connect(int from, int to, int weight, bool isDirected = false){
			adj.at(from).at(to).first = to;
			adj.at(from).at(to).second = weight;
			if(isDirected){
				adj.at(to).at(from).first = from;
				adj.at(to).at(from).second = weight;
			}
			return true;
		}

		//function to disconnect two nodes
		bool disconnect(int from, int to, bool isDirected) {
			adj.at(from).at(to).second = 0;
			if (isDirected) adj.at(to).at(from).second = 0;
			return true;
		}

		//function to return an edge's weight
		int getWeight(int from, int to){
			return adj.at(from).at(to).second;
		}

		//function to return an edge's neighbors
		vector<Edge> neighbor(int from){
			vector<Edge> result;
			for (int i = 0; i < nodeCount; i++) {
				if (adj.at(from).at(i).second > 0) {
					Edge a = {from, i, adj.at(from).at(i).second};
					result.push_back(a);
				}
			}
			return result;
		}
		
		//function to run the dijkstra algorithm
		vector<int> dijkstra(int sourceNode){
			vector<int> previousNodes(nodeCount, -1);
			vector<int> distance(nodeCount, INT_MAX);
			priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
			distance[sourceNode] = 0;
			Edge edge = { -1, sourceNode, 0 };
			pq.push(edge);
			Edge current;
			while (!pq.empty()) {
				current = pq.top();
				pq.pop();
				if (distance[current.to] == current.weight) {
					vector<Edge> edges = neighbor(current.to);
					for (Edge& e : edges) {
						if (distance[e.to] > distance[e.from] + e.weight) {
							distance[e.to] = distance[e.from] + e.weight;
							previousNodes[e.to] = e.from;
							Edge toPush = { e.from, e.to, distance[e.to] };
							pq.push(toPush);
						}
					}
				}
			}
			return previousNodes;
		}
};

#endif