// #include <graph_a.h>
#include <iostream>
#include <vector>
#include <stack>
#include <cstdint>
using namespace std;


const uint32_t INF = 4294967295;

class Graph{
	private:
		vector<vector <int>> graph;
	public:
	Graph(vector<vector<int>> &graph){
		this->graph.swap(graph);
		// cout << graph.size() << endl;
	}
	void print_graph(){
		// cout << graph.size();
		for (int i = 0; i < graph.size(); ++i){
			for (int j = 0; j < graph[i].size(); ++j){
				cout << graph[i][j];
			}
			cout << endl;
		}
	}
	vector<int>& operator[](uint32_t index){
		return graph[index];
	}
};


// template <typename T,
//     	  template<typename, typename> class ContainerType,
//     	  typename Alloc = allocator<T>
// 		 >
template <typename T>
bool find_in_stack(T stack, int vertex){
	for (int i = 0; i < stack.size(); ++i){
		if (vertex == stack[i]) return true;
	}
	return false;
}


void find_in_width(Graph graph){
	vector<int> stack;
	stack.push_back(0);


	// массив с закрашенными индексами;
	vector<int> result(graph[0].size(), 0);
	while (stack.size() != 0){
		int i = stack[0];
		
		cout << "I: " << i << endl;
			for (int j = 0; j < graph[i].size(); ++j){

				if (result[j] != 0) continue;
				if (graph[i][j] != 0){
					cout << "J: " << j << endl;
					if (!find_in_stack(stack, j)){
				 		stack.push_back(j);
					}
				}
			}

		result[i] = 1;
		for (int k = 0; k < stack.size(); ++k){
			cout << stack[k] << endl;
		}
		cout << "**********" << endl;
		stack.erase(stack.begin());
	}
}

void find_in_depth(vector<vector<int>> graph, int index){
	stack<int> stack;
	stack.push(index);
	int i;
	vector<int> result(graph[0].size(), 0);


	cout << "Enter #1" << endl;

	while (!stack.empty()){

		i = stack.top();
		stack.pop();
		cout << "I: " << i << endl;
		for (int j = graph[0].size()-1; j > 0 ; --j){
			if (result[j] != 0) continue;
			if (graph[i][j] != 0){
				cout << "J: " << j << endl;
				stack.push(j);
			}
			
		}
		result[i] = 1;
		cout << "**********" << endl;
	}
}


void Dijkstras_alg(Graph graph, int start_vertex, int end_vertex){
	// vector< vector<int> >  shwm(7, {0, 0, 0, 0, 0, 0, 0});//shortest_way_matrix; 
	int size = graph[0].size();
	int *shwm = new int[size*size];
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j){
			shwm[i*size + j] = INF;
		}
	}
	
	// for (int i = 0; i < graph[0].size(); ++i){
	// 	vector<int> v;
	// 	// shwm[i].push_back(vector<int>);
	// }
}


int main(){
	vector<vector<int>> graph = {{0, 1, 1, 0, 0, 0, 0},
						 {1, 0, 0, 1, 1, 0, 0},
						 {1, 0, 0, 1, 0, 0, 1},
						 {0, 1, 1, 0, 1, 1, 0},
						 {0, 1, 0, 1, 0, 0, 0},
						 {0, 0, 0, 1, 0, 0, 0},
						 {0, 0, 1, 0, 0, 0, 0} };
	// vector<int> graph = {0, 1, 1, 0, 0, 0, 0,
	// 					 1, 0, 0, 1, 1, 0, 0,
	// 					 1, 0, 0, 1, 0, 0, 1,
	// 					 0, 1, 1, 0, 1, 1, 0,
	// 					 0, 1, 0, 1, 0, 0, 0,
	// 					 0, 0, 0, 1, 0, 0, 0,
	// 					 0, 0, 1, 0, 0, 0, 0 };

	// find_in_width(graph);
	// find_in_depth(graph, 0);
	// cout <<  (NULL > 12) << endl;
	Graph obj(graph);
	obj.print_graph();
	cout << "EXIT" << endl;

	return 0;
}