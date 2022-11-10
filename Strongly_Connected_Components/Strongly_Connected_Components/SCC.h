#ifndef SCC_ADNAN_H_MOHAMED
#define SCC_ADNAN_H_MOHAMED

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<set>

struct Vertex {
	int key;
	int finish_time;
	bool is_visited;

	bool operator==(const Vertex& other) { return key == other.key; }
	bool operator!=(const Vertex& other) { return !(*this == other); }
	bool operator<(const Vertex& other) { return key < other.key; }
	bool operator<=(const Vertex& other) { return (*this == other) || (*this < other); }
	bool operator>(const Vertex& other) { return !(*this <= other); }
	bool operator>=(const Vertex& other) { return !(*this < other); }
};

class Graph {
public:
	Graph() = default;
	Graph(std::istream& fin, const int N);
	void reverse();

	std::size_t vertices_size() const { return adj_list.size(); }
	std::size_t neighbors_size(int v) const { return neighbors(v).size(); }
	/*std::size_t num_of_edges()const;*/

	std::vector<int> neighbors(int v) const;
	std::vector<int> vertices()const;

private:
	std::unordered_map<int, std::vector<int>> adj_list;
};

class SCC {
public:
	SCC(Graph G);

	std::vector<int> components_size()const;

	std::vector<int> top_component_sizes(int n) const;
private:
	void DFS1(const Graph& G);
	void DFS_visit1(const Graph& G, Vertex& src, int& time);
	void DFS2(const Graph& G);
	void DFS_visit2(const Graph& G, Vertex& src, int& time);

	std::vector<Vertex> vertices_list;
	std::priority_queue<int> _components_size = std::priority_queue<int>();
	std::stack<int> vertices_stack;
};

//std::vector<int> topological_order(const Graph& G);

#endif // !SCC_ADNAN_H_MOHAMED



