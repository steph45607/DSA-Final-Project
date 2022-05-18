// Program to shortest path from a given source vertex ‘s’ to
// a given destination vertex ‘t’. Expected time complexity
// is O(numNodes+E).
#include <iostream>
#include <list>
using namespace std;

// This class represents a directed graph using adjacency
// list representation
class Matrix
{
	int numNodes; // No. of vertices
	list<int> *adj; // adjacency lists
public:
	Matrix(int numNodes); // Constructor
	void addEdge(int originNode, int destinationNode, int cost); // adds an edge

	// finds shortest path from source vertex ‘s’ to
	// destination vertex ‘d’.
	int findShortestPath(int sourceNode, int endNode);

	// print shortest path from a source vertex ‘s’ to
	// destination vertex ‘d’.
	int printShortestPath(int parent[], int startNode, int endNode);
};

Matrix::Matrix(int numNodes)
{
	this->numNodes = numNodes;
	adj = new list<int>[2*numNodes];
}

void Matrix::addEdge(int originNode, int destinationNode, int cost)
{
	// split all edges of cost 2 into two
	// edges of cost 1 each. The intermediate
	// vertex number is maximum vertex number + 1,
	// that is numNodes.
	if (cost==2)
	{
		adj[originNode].push_back(originNode+numNodes);
		adj[originNode+numNodes].push_back(destinationNode);
	}
	else // Weight is 1
		adj[originNode].push_back(destinationNode); // Add w to v’s list.
}

// To print the shortest path stored in parent[]
int Matrix::printShortestPath(int parent[], int startNode, int endNode)
{
	static int level = 0;

	// If we reached root of shortest path tree
	if (parent[startNode] == -1)
	{
		cout << "Shortest Path between " << startNode << " and "
			<< endNode << " is " << startNode << " ";
		return level;
	}


	printShortestPath(parent, parent[startNode], endNode);

    level++;
	if (startNode < numNodes){
		cout << startNode << " ";
    }


	return level;
}

// This function mainly does BFS and prints the
// shortest path from src to dest. It is assumed
// that cost of every edge is 1
int Matrix::findShortestPath(int startNode, int endNode)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[2*numNodes];
	int *parent = new int[2*numNodes];

	// Initialize parent[] and visited[]
	for (int i = 0; i < 2*numNodes; i++)
	{
		visited[i] = false;
		parent[i] = -1;
	}

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[startNode] = true;
	queue.push_back(startNode);

	// 'i' will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		int s = queue.front();

		if (s == endNode)
			return printShortestPath(parent, s, endNode);

		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it
		// visited and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
				parent[*i] = s;
			}
		}
	}
}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	int numNodes = 4;
	Matrix g(numNodes);
	g.addEdge(0, 1, 2);
	g.addEdge(0, 2, 2);
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 1);
	g.addEdge(2, 0, 1);
	g.addEdge(2, 3, 2);
	g.addEdge(3, 3, 2);

	int start = 0, end = 3;
	cout << "\nShortest Distance between " << start << " and " << end << " is " << g.findShortestPath(start, end);

	return 0;
}
