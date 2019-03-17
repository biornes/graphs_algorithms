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
	const size_t size()
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

	void dfs_inv(vector<size_t> &stack, vector<bool> &visited, size_t vertex)
	{
		size_t size = graph_[vertex].size();
		visited[vertex] = true;
		for (int i = 0; i < size; ++i)
		{
			if (visited[i] == true) continue;
			if (graph_[vertex][i] != 0)
			{
				dfs_inv(stack, visited, i);
			}
		}
		stack.push_back(vertex);
	}


	bool check_Euler_cycle()
	{
		uint32_t counter = 0;
		for (int i = 0; i < size(); ++i)
		{
			for (int j = 0; j < size(); ++j)
			{
				if (graph_[i][j] != 0) ++counter;
				if (graph_[j][i] != 0 and j != i) ++ counter;
			}
			if (counter % 2 == 1) return false;
			counter = 0;
		}
		return true;
	}

	auto Flyory_algorithm(size_t start_vertex)
	{
		if (check_Euler_cycle() != true)
		{
			cout << "There is no Euler cycle" << endl;
			exit(0);
		}

		vector<Edge<T>> result;
		auto edges = get_edges();
		int counter = 0;
		vector<Edge<T>> bridges;
		vector<vector<T>> copy_graph(graph_);
		for (int i = 0; i < edges.size(); ++i)
		{
			counter += edges[i].size();
		}

		
		for (int i = 0; i < counter; ++i)
		{
			for (auto j = 0; j < edges[start_vertex].size(); ++j)
			{
				auto cur_edge = edges[start_vertex][j];
				auto cur_vertex = cur_edge.__first_v__;
				vector<bool> temp1(size(), false);
				size_t cur_quantity = find_in_depth(cur_edge.__end_v__, temp1).size();
				 // auto cur_quantity = find_in_depth(cur_edge.__end_v__).size();
				graph_[cur_vertex][cur_edge.__end_v__] = 0;
				// after_delete_vertex
				vector<bool> temp2(size(), false);
				size_t afd = find_in_depth(cur_edge.__end_v__, temp2).size();
				// auto afd = find_in_depth(cur_edge.__end_v__).size();

				if (afd < cur_quantity)
				{

				}

				if (afd < cur_quantity and edges[start_vertex].size() > 1)
				{
					graph_[cur_vertex][cur_edge.__end_v__] = 1;
					continue;
				}
				result.push_back(*(edges[start_vertex].begin()+j));
				edges[start_vertex].erase(edges[start_vertex].begin()+j);
				start_vertex = cur_edge.__end_v__;
				break;

			}
		}
		swap(graph_, copy_graph);
		return result;
	}

	const auto& find_in_depth(int index, vector<bool> &visit) {
		// if (visit.size() == 0) visit = vector<bool>(size(), false);
		vector<int> stack;
		stack.push_back(index);
		int i;
		static vector<int> visit_order;
		visit_order.clear();
		// cout << "SIZE: " << visit_order.size() << endl;
		while (!stack.empty()){
			i = *stack.begin();
			// cout << i << endl;
			visit_order.push_back(i);
			stack.erase(stack.begin());
			for (int j = 0; j < graph_[0].size(); ++j)
			{
				if (visit[j] != false) continue;
				if (graph_[i][j] != 0){
					stack.push_back(j);
				}
			}
			visit[i] = true;
		}
		
		return visit_order;
	}

	auto& get_edges()
	{
		static vector<vector<Edge<T>>> edges(graph_.size(), vector<Edge<T>>());
		size_t size = graph_.size();
		uint32_t counter = 1;
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = 0; j < size; ++j)
			{
				if (graph_[i][j] == 0) continue;
				edges[i].push_back(Edge<T>(i, j, graph_[i][j]));
			}
		}
		return edges;
	}

	void FindEulerPath(size_t start_vertex, vector<size_t> &stack){
		for (int i = 0; i < graph_.size(); ++i)
		{
			if (graph_[start_vertex][i] != 1) continue;
			graph_[start_vertex][i] = 0;
			FindEulerPath(i, stack);
		}
		stack.push_back(start_vertex);
	}

	void FindEulerPathLauncher(size_t start_vertex, vector<size_t> &stack)
	{
		vector<vector<T>> copy_graph(graph_);
		FindEulerPath(start_vertex, stack);
		swap(graph_, copy_graph);
		copy_graph.clear();
	}	

	auto Kosarayu_algorithm()
	{
		vector<vector<int>> result;
		vector<bool> visit(graph_.size(), false);
		vector<size_t> stack;
		vector<vector<T>> graph_T(graph_.size(), vector<T>());
		for (int i = 0; i < graph_.size(); ++i)
		{
			for (int j = 0; j < graph_[i].size(); ++j)
			{
				graph_T[i].push_back(graph_[j][i]);
			}
		}
		swap(graph_T, graph_);
		for (int i = 0; i < graph_T.size(); ++i)
		{
			if (visit[i] == false)
			{
				dfs_inv(stack, visit, i);
			}
		}

		for (int i = 0; i < visit.size(); ++i)
		{
			visit[i] = false;
		}

		swap(graph_T, graph_);
		while(!stack.empty())
		{
			auto i = stack.back();
			stack.pop_back();
			if (visit[i] == false)
			{
				auto x = find_in_depth(i, visit);
				// for(int j = 0; j < visit.size(); ++j) cout << visit[j] << endl;
				result.push_back(x);
			}
		}

		return result; 
	}


};


#endif