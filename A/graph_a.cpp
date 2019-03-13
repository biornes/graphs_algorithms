#ifndef FUNCTIONS
#define FUNCTIONS = 1

using namespace std;


const uint32_t INF = 4294967295;

template <typename T>
class Graph{
	private:
		vector<vector<T>> graph;
	public:
	Graph(vector<vector<T>> &graph){

		this->graph.swap(graph);
	}
	size_t size(){
		return graph.size();
	}

	void print_graph(){
		for (int i = 0; i < graph.size(); ++i){
			for (int j = 0; j < graph[i].size(); ++j){
				cout << graph[i][j];
			}
			cout << endl;
		}
	}
	vector<T>& operator[](uint32_t index){
		return graph[index];
	}
};

template <typename T>
// Класс для сравнения двух ребёр в сортировке, использующейся в методе Крускала
class Compare_edges{
	public:
		bool operator() (vector<T> first, vector<T> last){
			return first[2] < last[2];
		}
};

template <typename T>
class Compare{
	public:
		bool operator () (pair<T, int> first, pair<T, int> second){
			return (first.first > second.first);
		}
};
template <typename T>
const uint32_t min(vector<T> shwm, vector<bool> visited, uint32_t start_vertex){
	uint32_t min = INF;
	uint32_t min_index = 0;
	for (int i = 0; i < shwm.size(); ++i){
		if (i == start_vertex) continue;
		if ((shwm[i] <= min) and (visited[i] != true))
		{
			min = shwm[i];
			min_index = i;
		}
	}
	return min_index;


}





template <typename T>
bool find_in_stack(T stack, int vertex){
	for (int i = 0; i < stack.size(); ++i){
		if (vertex == stack[i]) return true;
	}
	return false;
}

template <typename T>
void find_in_width(Graph<T> graph, int index){
	vector<T> stack;
	stack.push_back(index);


	// массив с закрашенными индексами;
	vector<int> result(graph[0].size(), 0);
	while (stack.size() != 0){
		int i = stack[0];		
			for (int j = 0; j < graph[i].size(); ++j){
				if (result[j] != 0) continue;
				if (graph[i][j] != 0){
					if (!find_in_stack(stack, j)){
				 		stack.push_back(j);
					}
				}
			}
		result[i] = 1;
		stack.erase(stack.begin());
	}
}

template <typename T>
void find_in_depth(Graph<T> graph, int index){
	// stack<int> stack;
	vector<int> stack;
	stack.push_back(index);
	int i;
	vector<int> result(graph[0].size(), 0);
	vector<int> visit_order(graph.size());
	while (!stack.empty()){

		i = *stack.begin();
		visit_order.push_back(i);
		stack.erase(stack.begin());
		for (int j = graph[0].size()-1; j > 0 ; --j){
			if (result[j] != 0) continue;
			if (graph[i][j] != 0){
				stack.push_back(j);
			}
		}
		result[i] = 1;
	}
}


bool not_visited(vector<bool> visited){
	for (int i = 0; i < visited.size(); ++i){
		if (visited[i] == false) return true;
	}
	return false;
}

template <typename T>
auto Dijkstras_alg(Graph<T> graph, uint32_t start_vertex){
	
	int size = graph.size();
	vector<T> shwm(size, INF);//shortest_way_matrix; 
	shwm[start_vertex] = 0;
	for (int i = 0; i < graph[start_vertex].size(); ++i){
		if (graph[start_vertex][i] != 0){
			shwm[i] = graph[start_vertex][i];
		}
	}
	vector<bool> visited(size, 0);
	visited[start_vertex] = true;
	int cur_v = 0;
	while (not_visited(visited)){

		cur_v = min(shwm, visited, start_vertex);
		cout << cur_v << endl;
		for (int i = 0; i < size; ++i){
			if (shwm[i] > shwm[cur_v] + graph[cur_v][i] and graph[cur_v][i] != 0){
				shwm[i] = shwm[cur_v] + graph[cur_v][i];
			}
		}
		visited[cur_v] = true;
	}
	return shwm;
}



template <typename T>
auto Dijkstras_with_heap(Graph<T> graph, uint32_t start_vertex){
	// priority_queue<pair<T, int>, vector<pair<T, int>>, Compare<T>> queue;
	vector<uint32_t> heap_index(graph.size(), 0);
	// for (int i = 0; i < heap_index.size(); ++i){
	// 	heap_index[i] = 0;
	// }
	

	vector<T> shwm(graph.size(), INF);
	shwm[start_vertex] = 0;
	// queue.push(make_pair(0, 0));
	// vector<pair<T, vector<uint32_t>>> heap_for_max(graph.size());
	vector<pair<T, uint32_t>> heap_for_max(graph.size());
	for (int i = 0; i < graph.size(); ++i){
		// vector<uint32_t> temp = {}
		heap_for_max.push_back(make_pair(shwm[i], i));
	}
	sort_heap(heap_for_max.begin(), heap_for_max.end(), Compare<T>());

	vector<bool> visited(graph.size(), false);
	visited[start_vertex] = true;
	shwm[start_vertex] = 0;
	uint32_t min = 0;
	while(not_visited(visited)){
		// min = queue.top().second;
		// min = heap_for_max.front().second;
		heap_for_max.erase(heap_for_max.begin());
		visited[min] = true;
		// queue.pop();
		for (int i = 0; i < graph.size(); ++i){
			if (shwm[i] > shwm[min] + graph[min][i] and graph[min][i] != 0){

				shwm[i] = shwm[min] + graph[min][i];
				
				// queue.push(make_pair(shwm[i], i));
			}
		}
	}
	return shwm;
}

template <typename T>
auto Floyd_Uorshell(Graph<T> graph){
	for (int i = 0; i < graph.size(); ++i){
		for (int j = 0 ; j < graph[i].size(); ++j){
			if (i == j) continue;
			if (graph[i][j] == 0)
				graph[i][j] = INF;
		}
	}
	for (int k = 0; k < graph.size(); ++k){
		for(int i = 0; i < graph.size(); ++i){
			for (int j = 0; j < graph[i].size(); ++j){
				if (graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	return graph;
}
template <typename T>
auto Prims_algorithm(Graph<T> graph, int start_vertex){
	priority_queue<pair<T, int>, vector<pair<T, int>>, Compare<T>> queue;
	queue.push(make_pair(0, start_vertex));
	vector<T> distance(graph.size(), INF);
	distance[start_vertex] = 0;
	vector<bool> visited(graph.size(), false);
	vector<uint32_t> parents(graph.size(), NULL);
	uint32_t min = 0;
	vector<pair<uint32_t, uint32_t>> result;
	while(not_visited(visited)){
		min = queue.top().second;
		queue.pop();
		visited[min] = true;
		for (int i = 0; i < graph[min].size(); ++i){
			if (graph[min][i] < distance[i] and visited[i] == false and graph[min][i] !=0){
				distance[i] = graph[min][i];
				parents[i] = min;
				result.push_back(make_pair(i, parents[i]));
				queue.push(make_pair(distance[i], i));
			}
		}
	}
	return result; 
}
template <typename T>
auto get_edges(Graph<T> graph){
	vector<vector<T>> edges;
	size_t size = graph.size();
	uint32_t counter = 1;
	vector<T> temp(3);
	for (size_t i = 0; i < size; ++i){
		for (size_t j = counter; j < size; ++j){
			if (graph[i][j] == 0) continue;
			temp[0] = i;
			temp[1] = j;
			temp[2] = graph[i][j];
			edges.push_back(temp);
		}
		++counter;
	}
	// Для варианта, если нужно считать все ребра в обе стороны
	// for (size_t i = 0; i < size; ++i){
	// 	for (size_t j = 0; j < size; ++j){
	// 		if (graph[i][j] == 0) continue;
	// 		temp[0] = i;
	// 		temp[1] = j;
	// 		temp[2] = graph[i][j];
	// 		edges.push_back(temp);
	// 	}
	// }
	return edges;
}



template <typename T>
auto Kruskals_algortihm(Graph<T> graph){
	vector<pair<T, T>> result;
	vector<T> D;
	for (int i = 0; i < graph.size(); ++i)
	{
		D.push_back(i);
	}
	auto edges = get_edges<T>(graph);
	make_heap(edges.begin(), edges.end());
	sort_heap(edges.begin(), edges.end(), Compare_edges<T>());
	for (auto edge: edges){
		if (D[edge[0]] != D[edge[1]]){
			result.push_back(make_pair(edge[0], edge[1]));
			auto temp = D[edge[0]];
			for (int i = 0; i < graph.size(); ++i){
				if (D[i] == temp){
					D[i] = D[edge[1]];
				}
			}
		}
	}

	return result;
}



#endif