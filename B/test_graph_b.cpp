#include <iostream>
#include <vector>
#include <cstdint>

#include "graph_b.h"
#include "graph_b.cpp"


int main()
{
	// vector<vector<uint32_t>> matrix = {{0, 2, 4, 0, 0, 0, 0},
	// 					 {2, 0, 0, 1, 1, 0, 0},
	// 					 {4, 0, 0, 1, 0, 0, 1},
	// 					 {0, 1, 1, 0, 1, 1, 0},
	// 					 {0, 1, 0, 1, 0, 0, 0},
	// 					 {0, 0, 0, 1, 0, 0, 0},
	// 					 {0, 0, 1, 0, 0, 0, 0}
	// 					 };
	vector<vector<uint32_t>> matrix = {
										// {0, 1, 0, 1},
										// {0, 0, 1, 0},
										// {1, 0, 0, 0},
										// {0, 0, 0, 0}
										{0, 1, 0, 1, 0, 0},
										{0, 0, 1, 0, 1, 0},
										{1, 0, 0, 1, 0, 0},
										{0, 1, 0, 0, 1, 0},
										{1, 0, 0, 0, 0, 1},
										{0, 0, 1, 0, 0, 0}
									  };
	Graph<uint32_t> graph(matrix);
	// graph.optimize();
	auto result = graph.Flyory_algorithm(5);

	// graph.Flyory_algorithm(0);
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); ++i){
		cout << result[i].__first_v__ << " " << result[i].__end_v__ << endl;
	}
	// cout << "New\n";
	// cout << "Test Tarjans algorithm:" << endl;
	// auto stack = graph.Tarjans_algorithm();
	// for (auto i = stack.rbegin(); i != stack.rend(); ++i)
	// {
	// 	cout << *i << endl;
	// }
	// cout << "************\n" << endl;
	// for (auto x: stack)
	// cout << stack.size() << endl;
	// for (auto i: stack)
	// {
	// 	cout << i << endl;
	// }

	// cout << *stack.begin() << endl;

	// graph.
	cout << "QUIT" << endl;
	return 0;
}