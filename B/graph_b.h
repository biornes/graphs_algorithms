#ifndef PROTOTYPE
#define PROTOTYPE = 1
using namespace std;

template < typename T,
		   typename Container = vector<T>>
class Graph;
template <typename T>
const uint32_t Tarjans_algorithm (const Graph<T> &graph);
template <typename T>
auto dfs_inv(vector<size_t> &stack, vector<bool> &visited, size_t vertex, const Graph<T> &graph);
// template <typename T>
// bool find_in_stack(T stack, int vertex);


#endif