#include <iostream>
#include <vector>

#include "graph_b.h"
#include "graph_b.cpp"


int main()
{
	vector<vector<uint32_t>> matrix = {{0, 2, 4, 0, 0, 0, 0},
						 {2, 0, 0, 1, 1, 0, 0},
						 {4, 0, 0, 1, 0, 0, 1},
						 {0, 1, 1, 0, 1, 1, 0},
						 {0, 1, 0, 1, 0, 0, 0},
						 {0, 0, 0, 1, 0, 0, 0},
						 {0, 0, 1, 0, 0, 0, 0}
						 };
	Graph<uint32_t, vector<uint32_t>> graph(matrix);
	graph.optimize();
	graph.
	return 0;
}