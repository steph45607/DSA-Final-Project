#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <climits>
#include <queue>
#include <vector>

#include "Graph.cpp"
using namespace std;

// MatrixGraph class
class MatrixGraph : public Graph{
	//declaring private data
	private:
		vector< vector<int> > mat;
		int nodeCount; // number of vertexes/nodes in the graph
		int edgeCount; // number of edges in the graph
	public:
		MatrixGraph(int n):
		nodeCount(n), edgeCount(0), mat(n, vector<int>(n)) { }

		//function to connect two nodes
		//isDirected means does the graph connect both ways
		bool connect(int from, int to, int weight, bool isDirected) {
			mat.at(from).at(to) = weight;
			if (isDirected) mat.at(to).at(from) = weight;
			return true;
		}

		//function to disconnect two nodes
		bool disconnect(int from, int to, bool isDirected) {
			mat.at(from).at(to) = 0;
			if (isDirected) mat.at(to).at(from) = 0;
			return true;
		}

		//function to return an edge's weight
		int getWeight(int from, int to){
			return mat.at(from).at(to);
		}

		//function to return an edge's neighbors
		vector<Edge> neighbor(int to) {
			vector<Edge> result;
			for (int i = 0; i < nodeCount; i++) {
				if (mat.at(to).at(i) > 0) {
					Edge a = {to, i, mat.at(to).at(i)};
					result.push_back(a);
				}
			}
			return result;
		}

		//function to run the dijkstra algorithm
		vector<int> dijkstra(int sourceNode) {
			vector<int> previousNodes(nodeCount, -1);
			vector<int> distance(nodeCount, INT_MAX);
			priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
			distance[sourceNode] = 0;
			Edge edge = {-1, sourceNode, 0};
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
							Edge toPush = {e.from, e.to, distance[e.to]};
							pq.push(toPush);
						}
					}
				}
			}
			return previousNodes;
		}
};

#endif