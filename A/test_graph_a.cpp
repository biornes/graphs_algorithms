
#include <iostream>
#include <vector>
#include <stack>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <set>
#include "graph_a.h"
#include "graph_a.cpp"


    
// #include <graph_a.h>






int main(){
	vector<vector<uint32_t>> graph = {
						 {0, 2, 4, 0, 0, 0, 0},
						 {2, 0, 0, 1, 1, 0, 0},
						 {4, 0, 0, 1, 0, 0, 1},
						 {0, 1, 1, 0, 1, 1, 0},
						 {0, 1, 0, 1, 0, 0, 0},
						 {0, 0, 0, 1, 0, 0, 0},
						 {0, 0, 1, 0, 0, 0, 0}
						 };

	// find_in_width(graph, 0);
	// find_in_depth(graph, 0);
	// cout <<  (NULL > 12) << endl;




	Graph<uint32_t> obj(graph);

	// Не знаю, как показать работу алгоритма поиска в глубину/ширину




	auto v = Dijkstras_alg(obj, 0);
	cout << "Test Dijkstra's algorithm: " << endl;
	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << endl;
	}
	cout << "******************" << endl;
	cout << "Test Dijkstra's algorithm using the heap to get the max: " << endl;
	auto v1 = Dijkstras_with_heap(obj, 0);
	for (int i = 0; i < v1.size(); ++i){
		cout << v1[i] << endl;
	}
	cout << "******************" << endl;
	auto obj1 = Floyd_Uorshell(obj);
	cout << "Test Floyd-Uorshell algorithm: " << endl;
	obj1.print_graph();
	cout << "******************" << endl;
	cout << "Test Prim's algorithm: " << endl;
	auto test = Prims_algorithm(obj, 0);
	for (auto x: test){
		cout << x.first << " " << x.second << endl;
	}
	auto result = Kruskals_algortihm<uint32_t>(obj);
	cout << "Minimum spanning tree: " << endl;
	for (auto x : result){
		cout << x.first << " " << x.second << endl;
	}
	// cout << "EXIT" << endl;

	return 0;
}
