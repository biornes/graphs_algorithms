#ifndef FUNCTIONS
#define FUNCTIONS = 1

using namespace std;

const uint32_t INF = 4294967295;

template <typename T>
struct Edge
{
	size_t __first_v__;
	size_t __end_v__;
	T __weight__;
	Edge(size_t first, size_t end, T weight): __first_v__(first), __end_v__(end), __weight__(weight){}
};


template <typename T>
class Graph
{
	private:
		vector<vector<T>> graph_;
	public:
	Graph(vector<vector<T>> &graph): graph_(graph)
	{

	}
	// Graph()
	size_t size()
	{
		return graph_.size();
	}

	void print_graph()
	{
		for (int i = 0; i < graph_.size(); ++i)
		{
			for (int j = 0; j < graph_[i].size(); ++j)
			{
				cout << graph_[i][j];
			}
			cout << endl;
		}
	}
	auto & operator[](uint32_t index)
	{
		return graph_[index];
	}

	const auto& Tarjans_algorithm() 
	{
		static vector<size_t> stack;
		// массив посещенных вершин
		size_t size = graph_.size();
		vector<bool> visited(size, false);
		for (size_t i = 0; i < size; ++i){
			if (visited[i] == false)
			{
				dfs_inv(stack, visited, i);

			}
		}
		return stack;
	}
	// void optimize()
	// {
	// 	size_t size = graph_.size();
	// 	// временный массив для хранения оптимизированного вектора
	// 	// vector<adjacent_vertex<T>> temp(size);
	// 	vector<pair<size_t, T>> temp(size);
	// 	for (int i = 0; i < size; ++i)
	// 	{
	// 		for (int j = 0; j < size; ++j)
	// 		{
	// 			if (graph_[i][j] != 0){

	// 				temp[i].push_back(make_pair(j, graph_[i][j]));
	// 			}
	// 		}
	// 	}
	// 	// swap(graph_, temp)
	// }

	void dfs_inv(vector<size_t> &stack, vector<bool> &visited, size_t vertex)
	{
		size_t size = graph_[vertex].size();
		visited[vertex] = true;
		// cout << "some" << endl;
		for (int i = 0; i < size; ++i)
		{
			if (visited[i] == true) continue;
			if (graph_[vertex][i] != 0)
			{
				// cout << i << endl;
				dfs_inv(stack, visited, i);
			}
		}
		stack.push_back(vertex);
	}


	auto Flyory_algorithm(size_t start_vertex)
	{
		vector<Edge<T>> result;
		auto edges = get_edges();
		// cout << "EDGES SIZE: " << edges.size() << endl;
		int counter = 0;
		for (int i = 0; i < edges.size(); ++i)
		{
			counter += edges[i].size();
			// for (int j = 0; j < edges[i].size(); ++j)
			// {

			// }
		}

		// cout << "COUNTER" << counter << endl;
		// vector<bool> bridges(edges.size(), false);
		// Graph<T> copy_graph(graph_);
		vector<Edge<T>> bridges;
		// vector
		// int bridges_count = 0;
		vector<vector<T>> copy_graph(graph_);
		// Копия графа для поиска мостов в графе;
		// for (int i = 0; i < edges.size(); ++i)
		// {
		// 	for (int j = 0; j < edges[i].size(); ++j)
		// 	{
		// 		cout << edges[i][j].__first_v__ << " " << edges[i][j].__end_v__ << " ";
		// 	}
		// 	cout << endl;
		// }

		// int bridges_count = 0;
		for (int i = 0; i < counter; ++i)
		{
			// if (edges[i].size() == 0) continue;
			// cout << "EDGE[i].size(): " << edges[start_vertex].size() << endl;
			for (auto j = 0; j < edges[start_vertex].size(); ++j)
			{
				auto cur_edge = edges[start_vertex][j];
				auto cur_vertex = cur_edge.__first_v__;
				// cout << "CUR EDGE: "  << cur_edge.__first_v__  << " " << cur_edge.__end_v__ << endl;
				size_t cur_quantity = find_in_depth(cur_edge.__end_v__);
				// cout << "cur_quantity: " << cur_quantity << endl;

				graph_[cur_vertex][cur_edge.__end_v__] = 0;
				// after_delete_vertex
				size_t afd = find_in_depth(cur_edge.__end_v__);
				// cout << "afd_quantity: " << afd << endl;
				// cout << "edges[i].size(): " << edges[i].size() << endl;
				// cout << (afd != cur_vertex) << endl;
				// cout << "SOME SHIT: " << (afd < cur_quantity ) << endl;
				if (afd < cur_quantity and edges[start_vertex].size() > 1)
				{
					graph_[cur_vertex][cur_edge.__end_v__] = 1;
					// auto flag_bridge = true;
					// ++bridges_count;
					// ++bridges_count;
					// if (j+1 != edges[start_vertex].size())
					continue;
					// else if (bridges_count == edges[start_vertex].size()) j = 0;
				}
				result.push_back(*(edges[start_vertex].begin()+j));
				edges[start_vertex].erase(edges[start_vertex].begin()+j);
				
				
				start_vertex = cur_edge.__end_v__;
				// cout << edges[start_vertex].size() << endl;
				// cout << "START VERTEX: " << start_vertex << endl;
				
				
				break;

			}
			
			

			// if (afd != cur_vertex and edges.size() == bridges_count)

			// else
			// {

			// }


			// {

			// }
		}


		
		// for (int i = 0; i < graph_.size(); ++i)
		// {
		// 	// if ()
		// 	cout << "CYCLE i:\n" << i << endl;
		// 	for (int j = 0; j < graph_[i].size(); ++j)
		// // }
		// 	{
		// 		if (graph_[i][j] == 0) continue;
		// 		size_t counter_vertex = copy_graph.find_in_width(i);
		// 		cout << "COUNTER VERTEX: " << counter_vertex << endl;
		// 		copy_graph[i][j] = 0;
		// 		// ad_vertex = after_delete_vertex

		// 		size_t ad_vertex = copy_graph.find_in_width(i);
		// 		cout << "ad_vertex: " << ad_vertex << endl;
		// 		if (ad_vertex < counter_vertex)
		// 		{
		// 			bridges.push_back(Edge<T>(i, j, copy_graph[i][j]));
		// 		}
		// 		else
		// 		{
		// 			result.push_back(Edge<T>(i, j, graph_[i][j]));
		// 		}
		// 	}
		// }
		// for (int i = 0; i < bridges.size(); ++i)
		// {
		// 	result.push_back(bridges[0]);
		// 	bridges.erase(bridges.begin());
		// }
		return result;
	}

	auto find_in_depth(int index){
		// stack<int> stack;
		vector<int> stack;
		stack.push_back(index);
		int i;
		vector<int> result(graph_.size(), 0);
		int count = 0;
		// vector<int> visit_order(graph_.size());
		while (!stack.empty()){

			i = *stack.begin();
			// visit_order.push_back(i);
			// cout << "For the second iteration: " << graph_[i][0] << endl;
			stack.erase(stack.begin());
			// for (int j = graph_[0].size()-1; j > 0 ; --j){
			for (int j = 0; j < graph_[0].size(); ++j)
			{

				if (result[j] != 0) continue;
				if (graph_[i][j] != 0){
					stack.push_back(j);
					// cout << "I J: " << i << " " << j << endl;
					++count;
				}
			}
			result[i] = 1;
		}
		// return visit_order.size();
		return count;
	}


	auto& get_edges()
	{
		static vector<vector<Edge<T>>> edges(graph_.size(), vector<Edge<T>>());
		size_t size = graph_.size();
		uint32_t counter = 1;
		// vector<T> temp(3);
		// for (size_t i = 0; i < size; ++i){
		// 	for (size_t j = counter; j < size; ++j){
		// 		if (graph[i][j] == 0) continue;
		// 		temp[0] = i;
		// 		temp[1] = j;
		// 		temp[2] = graph[i][j];
		// 		edges.push_back(temp);
		// 	}
		// 	++counter;
		// }
		// Для варианта, если нужно считать все ребра в обе стороны
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = 0; j < size; ++j)
			{
				if (graph_[i][j] == 0) continue;
				// graph_.Kruskals
				// cout << "Push back edge: " << endl;
				edges[i].push_back(Edge<T>(i, j, graph_[i][j]));
				// temp[0] = i;
				// temp[1] = j;
				// temp[2] = graph_[i][j];
				// edges.push_back(temp);
			}
		}
		return edges;
	}



};




// template <typename T>


// template <typename T>


#endif