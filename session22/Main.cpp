#include <iostream>
#include <string>
#include "MatrixGraph.h"
#include <queue>
using namespace std;

template <class T>
void print(const vector<T>& vec,
	const string& pre = "",
	const string& suf = "\n") {
	cout << pre << "[";
	for (const T& x : vec) {
		cout << x << ", ";
	}
	cout << "]" << suf;
}

void test_bfs_mat() {
	MatrixGraph mg(5);
	mg.connect(0, 1, 1, true);
	mg.connect(1, 2, 1, true);
	mg.connect(2, 3, 1, true);
	mg.connect(3, 4, 1, true);
	mg.connect(4, 0, 1, true);
	auto res = mg.neighbor(1);
	print(res);
	auto dist = mg.bfs(1);
	print(dist);
}

void test_dfs_mat() {
	MatrixGraph mg(5);
	mg.connect(0, 1, 1, true);
	mg.connect(1, 2, 1, true);
	mg.connect(2, 3, 1, true);
	mg.connect(3, 4, 1, true);
	mg.connect(4, 0, 1, true);
	auto dist = mg.dfs(1);
	print(dist);
}

MatrixGraph matrix_graph0() {
	MatrixGraph mg(6);
	mg.connect(0, 1, 1, true);
	mg.connect(0, 2, 1, true);
	mg.connect(1, 2, 2, true);
	mg.connect(1, 5, 2, true);
	mg.connect(2, 3, 1, true);
	mg.connect(3, 4, 1, true);
	mg.connect(4, 5, 1, true);
	return mg;
}

MatrixGraph matrix_graph1() {
	MatrixGraph mg(5);
	mg.connect(0, 1, 1, true);
	mg.connect(1, 2, 1, true);
	mg.connect(2, 3, 1, true);
	mg.connect(3, 4, 2, true);
	mg.connect(4, 0, 3, true);
	return mg;
}

MatrixGraph matrix_graph2(){
	MatrixGraph mg(4);
	mg.connect(0, 1, 3, true);
	mg.connect(1, 2, 1, true);
	mg.connect(1, 3, 2, true);
	mg.connect(2, 3, 5, true);
	return mg;
}

void test_prims_mat() {
	MatrixGraph mg = matrix_graph0();
	auto res = mg.neighbor(1);
	print(res);
	auto prev = mg.prims(1);
	print(prev);
}

void test_kruskal_mat() {
	MatrixGraph mg = matrix_graph0();
	auto prev = mg.kruskal();
	print(prev);
}

void test_dijkstra_mat() {
	MatrixGraph mg = matrix_graph0();
	auto prev = mg.dijkstra(0);
	print(prev);
}
void test_pq() {
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	greater<Edge> f;
	Edge a = {0, 1, 3 };
	Edge b = {0, 2, 2 };
	Edge c = {0, 3, 1 };
	// f(a, b) = a > b
	cout << boolalpha << f(a, b) << endl;
	// pq.push(a);
	// pq.push(b);
	// pq.push(c);
	// while (!pq.empty()) {
	// 	cout << pq.top() << "\n";
	// 	pq.pop();
	// }
}

int main() {
	// test_bfs_mat();
	// test_dfs_mat();
	// test_pq();
	// test_prims_mat();
	test_kruskal_mat();
	// test_dijkstra_mat();
}