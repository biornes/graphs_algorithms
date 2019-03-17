#include <iostream>
#include <vector>
#include <cstdint>
// #include <stack>

#include "graph_b.h"
#include "graph_b.cpp"


int main()
{

	vector<char> char_vertex = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

	vector<vector<uint32_t>> Tarjans_matrix = {
												{0, 1, 1, 0, 0, 0, 0},
												{0, 0, 0, 1, 0, 0, 0},
												{0, 0, 0, 1, 0, 1, 0},
												{0, 0, 0, 0, 0, 0, 1},
												{0, 0, 0, 0, 0, 1, 0},
												{0, 0, 0, 0, 0, 0, 1},
												{0, 0, 0, 0, 0, 0, 0}
												};


	Graph<uint32_t> Tarjans_graph(Tarjans_matrix);



	cout << "Test Tarjan's algorithm:" << endl;

	auto result_Tarjan = Tarjans_graph.Tarjans_algorithm();
	for (auto i = result_Tarjan.rbegin(); i != result_Tarjan.rend(); ++i)
	{
		cout << *i << ": " << char_vertex[*i] << endl;
	}

	vector<vector<uint32_t>> Flyory_matrix = {
												{0, 1, 0, 1, 0, 0},
												{0, 0, 1, 0, 1, 0},
												{1, 0, 0, 1, 0, 0},
												{0, 1, 0, 0, 1, 0},
												{1, 0, 0, 0, 0, 1},
												{0, 0, 1, 0, 0, 0}
									  		};


	Graph<uint32_t>  Flyory_graph(Flyory_matrix);
	auto result_Flyory = Flyory_graph.Flyory_algorithm(5);
	cout << "Test Floyry's algorithm:" << endl;
	for (int i = 0; i < result_Flyory.size(); ++i){
			cout << "Edge: ";
			cout << result_Flyory[i].__first_v__ << " " << result_Flyory[i].__end_v__ << endl;
	}
	cout << "Check Euler Cycle: " << Flyory_graph.check_Euler_cycle() << endl;


	vector<vector<uint32_t>> Euler_cycle_matrix{
										{0, 1, 0, 1, 0, 0},
										{0, 0, 1, 0, 1, 0},
										{1, 0, 0, 1, 0, 0},
										{0, 1, 0, 0, 1, 0},
										{1, 0, 0, 0, 0, 1},
										{0, 0, 1, 0, 0, 0}
									  };


	Graph<uint32_t> Euler_graph(Euler_cycle_matrix);
	vector<uint32_t> result_EulerPath; 
	Euler_graph.FindEulerPathLauncher(5, result_EulerPath);
	cout << "Test for search Euler's path algorithm:" << endl;
	for (int i = 0; i < result_EulerPath.size(); ++i)
	{	
		/* code */
		cout << char_vertex[result_EulerPath[i]] << " ";
	}
	cout << endl;


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

	cout << "Test Kosarayu's algorithm:" << endl;
	for (int i = 0; i < result_Kosarayu.size(); ++i)
	{
		for (int j = 0; j < result_Kosarayu[i].size(); ++j)
		{

			cout << result_Kosarayu[i][j] << " ";
		}
		cout << endl;
	}

	cout << "QUIT" << endl;
	return 0;
}