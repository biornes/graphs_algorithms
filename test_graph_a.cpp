
    
// #include <graph_a.h>
#include <iostream>
#include <vector>
#include <stack>
#include <cstdint>
using namespace std;


const uint32_t INF = 4294967295;

const uint32_t min(vector<uint32_t> shwm, vector<bool> visited, uint32_t start_vertex){
	uint32_t min = INF;
	uint32_t min_index = 0;
	for (int i = 0; i < shwm.size(); ++i){
		if (i == start_vertex) continue;
		// Ошибка здесь - visited становится короче, чем shwm
		if ((shwm[i] <= min) and (visited[i] != true))
		{
			min = shwm[i];
			min_index = i;
		}
	}
	cout << "MIN_INDEX " << min_index << endl;
	return min_index;

	// надо найти ребро с минимальным весом

}


class Graph{
	private:
		vector<vector <int>> graph;
	public:
	Graph(vector<vector<int>> &graph){
		// this->graph = graph;
		this->graph.swap(graph);
		// cout << graph.size() << endl;
	}
	size_t size(){
		return graph.size();
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


bool not_visited(vector<bool> visited){
	for (int i = 0; i < visited.size(); ++i){
		if (visited[i] == false) return true;
	}
	return false;
}


vector<uint32_t> Dijkstras_alg(Graph graph, uint32_t start_vertex){
	
	int size = graph.size();
	cout << size << endl;
	vector<uint32_t> shwm(size, INF);//shortest_way_matrix; 
	shwm[start_vertex] = 0;
	cout << shwm[start_vertex] << endl;

	for (int i = 0; i < size; ++i){
		cout << shwm[i] << endl;
	}
	for (int i = 0; i < graph[start_vertex].size(); ++i){
		if (graph[start_vertex][i] != 0){
			shwm[i] = graph[start_vertex][i];
		}
	}
	cout << "*************" << endl;
	vector<bool> visited(size, 0);
	// for (int i = 0; i < size; ++i){
	// 	visited[i][0] = i;
	// }
	visited[start_vertex] = true;
	
 	// for (int i = 0; i < size; ++i){
		// for (int j = 0; j < size; ++j){
			// shwm[i*size + j] = INF;
		// }
	// }
	int cur_v = 0;
	while (not_visited(visited)){

		cur_v = min(shwm, visited, start_vertex);
		cout << cur_v << endl;
		for (int i = 0; i < size; ++i){
			if (shwm[i] > shwm[cur_v] + graph[cur_v][i] and graph[cur_v][i] != 0){
				// cout << "hello world" << endl;
				shwm[i] = shwm[cur_v] + graph[cur_v][i];
				cout <<"Shwm " << i << " "  << shwm[i] << endl;
			}
			// cur_v = 
		}
		// visited.erase(visited.begin()+cur_v);
		visited[cur_v] = true;
	}
	cout << "SIZE BEFORE RETURN: " << shwm.size() << endl;
	return shwm;
	// for (int i = 0; i < graph[0].size(); ++i){
	// 	vector<int> v;
	// 	// shwm[i].push_back(vector<int>);
	// }
}




int main(){
	vector<vector<int>> graph = {{0, 2, 1, 0, 0, 0, 0},
						 {3, 0, 0, 1, 1, 0, 0},
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
	auto v = Dijkstras_alg(obj, 0);
	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << endl;
	}

	// obj.print_graph();
	cout << "EXIT" << endl;

	return 0;
}
