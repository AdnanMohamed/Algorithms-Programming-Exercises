#ifndef BFS_ADNAN_H_MOHAMED
#define BFS_ADNAN_H_MOHAMED

#include<iostream>
#include<vector>
#include<unordered_map>

struct Vertex {
	int key, parent;
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
	Graph(std::istream& fin);

	std::size_t vertices_size() const { return adj_list.size(); }
	std::size_t neighbors_size(int v) const { return neighbors(v).size(); }
	/*std::size_t num_of_edges()const;*/

	std::vector<int> neighbors(int v) const;
	std::vector<int> vertices()const;

private:
	std::unordered_map<int, std::vector<int>> adj_list;
};

class DFS
{
public:
	DFS(const Graph& G);

	int order(const int& v)const { return vertices.at(v).finish_time; }

	


private:
	void DFS_visit(const Graph& G, const int& src);
	std::unordered_map<int, Vertex> vertices;
	int counter;   // used in topological order algo.
	static const int NIL = -1;   // parent of the src.
};

std::vector<int> topological_order(const Graph& G);

#endif // !BFS_ADNAN_H_MOHAMED


