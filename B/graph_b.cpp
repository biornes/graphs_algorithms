#ifndef FUNCTIONS
#define FUNCTIONS = 1

using namespace std;


template <typename T>
struct adjacent_vertex
{
	size_t num;
	T length;
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
	vector<T>& operator[](uint32_t index)
	{
		return graph_[index];
	}
	void optimize()
	{
		size_t size = graph_.size();
		// временный массив для хранения оптимизированного вектора
		vector<vector<T>> temp(size, {});
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (graph_[i][j] != 0){
					temp[i].push_back()
				}
			}
		}
		// graph_
	}
};




template <typename T>
const auto Tarjans_algorithm(const Graph<T> &graph)
{
	// массив посещенных вершин
	size_t size = graph.size();
	vector<bool> visited(size, false);
	for (int i = 0; i < size; ++i){
		if (visited[i] == false)
		{
			// dfs_inv(i);
		}
	}
}

template <typename T>
const auto dfs_inv(vector<size_t> &stack, vector<bool> &visited, size_t vertex, const Graph<T> &graph)
{
	size_t size = graph[vertex].size();
	visited[vertex] = true;
	for (int i = 0; i < size; ++i){
		// if 
	}
}

#endif