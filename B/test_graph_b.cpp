#include <iostream>
#include <vector>
#include <cstdint>
// #include <stack>

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
	// auto result = graph.Flyory_algorithm(5);
	// // graph.print_graph();
	// // graph.Flyory_algorithm(0);
	// cout << result.size() << endl;
	// for (int i = 0; i < result.size(); ++i){
	// 	cout << result[i].__first_v__ << " " << result[i].__end_v__ << endl;
	// }

	// vector<uint32_t> result_eulerPath; 
	// graph.FindEulerPathLauncher(5, result_eulerPath);
	// for (int i = 0; i < result_eulerPath.size(); ++i)
	// {	
	// 	/* code */
	// 	cout << result_eulerPath[i] << " ";
	// }
	// cout << "New\n";
	// cout << "Test Tarjans algorithm:" << endl;
	// auto stack = graph.Tarjans_algorithm();
	// for (auto i = stack.rbegin(); i != stack.rend(); ++i)
	// {
	// 	cout << *i << endl;
	// }
	vector<vector<uint32_t>> graph_Kosarayu = {
												{0, 0, 0, 1, 0, 0, 0, 0},
												{1, 0, 0, 0, 0, 0, 0, 0},
												{0, 1, 0, 0, 1, 0, 1, 0},
												{1, 0, 0, 0, 1, 0, 0, 0},
												{0, 1, 0, 0, 0, 0, 0, 0},
												{0, 0, 1, 0, 1, 0, 0, 0},
												{0, 1, 1, 0, 0, 1, 0, 0},
												{0, 0, 0, 0, 1, 0, 1, 0}

												};

	Graph<uint32_t> for_Kosarayu(graph_Kosarayu);
	auto result_Kosarayu = for_Kosarayu.Kosarayu_algorithm();

	cout << result_Kosarayu.size() << endl;

	for (int i = 0; i < result_Kosarayu.size(); ++i)
	{
		for (int j = 0; j < result_Kosarayu[i].size(); ++j)
		{
			/* code */
			cout << result_Kosarayu[i][j] << " ";
		}
		cout << endl;
	}

	// for (auto x: result_Kosarayu)
	// {
	// 	for (auto z: *x){
	// 		cout << z << " ";
	// 	}
	// 	// cout << x << " ";
	// 	cout << endl;
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