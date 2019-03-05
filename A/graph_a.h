#ifndef PROTOTYPE
#define PROTOTYPE = 1
using namespace std;
template <typename T>
class Graph;
template <typename T>
const uint32_t min(vector<T> shwm, vector<bool> visited, uint32_t start_vertex);
template <typename T>
bool find_in_stack(T stack, int vertex);
template <typename T>
void find_in_width(Graph<T> graph, int index);
template <typename T>
void find_in_depth(Graph<T> graph, int index);
template <typename T>
bool not_visited(vector<bool> visited);
template <typename T>
auto Dijkstras_alg(Graph<T> graph, uint32_t start_vertex);
template <typename T>
auto Dijkstras_with_heap(Graph<T> graph, uint32_t start_vertex);
template <typename T>
auto Floyd_Uorshell(Graph<T> graph);
template <typename T>
auto Prims_algorithm(Graph<T> graph, int start_vertex);
template <typename T>
auto get_edges(Graph<T> graph);
template <typename T>
auto Kruskals_algortihm(Graph<T> graph);

#endif