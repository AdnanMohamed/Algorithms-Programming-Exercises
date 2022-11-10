

#ifndef BFS_ADNAN_H_MOHAMED
#define BFS_ADNAN_H_MOHAMED

#include<iostream>
#include<vector>
#include<deque>
#include<unordered_map>

struct Vertex {
	int key, parent;
	double dist;
	bool is_visited;

	bool operator==(const Vertex& other) { return dist == other.dist; }
	bool operator!=(const Vertex& other) { return !(*this == other); }
	bool operator<(const Vertex& other) { return dist < other.dist; }
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

class BFS
{
public:
	BFS(const Graph& G, int src);

	std::vector<int> shortestPath(int destination)const;
	std::vector<int> shortestPath(int destination, double& distance) const;
	double shortestDistance(int destination)const;

private:
	//std::vector<Vertex> vertices;
	//std::vector<Vertex> parents;
	std::unordered_map<int, Vertex> vertices;
	//std::vector<bool> is_visited;
	std::deque<Vertex> frontier;
	static const int NIL = -1;   // parent of the src.
};


#endif // !BFS_ADNAN_H_MOHAMED

