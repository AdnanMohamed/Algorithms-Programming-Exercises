#ifndef DIJKSTRA_ADNAN_H_MOHAMED
#define DIJKSTRA_ADNAN_H_MOHAMED

#include <iostream>
#include <vector>
#include <unordered_map>

struct Vertex {
	int key;
	int parent;
	double dist; // shortest distance to the source (for dijkstra's algorithm).
	bool done;  // marks that the vertex has the correct shortest distance from the source.

	//bool operator==(const Vertex& other) { return dist == other.dist; }
	//bool operator!=(const Vertex& other) { return !(*this == other); }
	bool operator<(const Vertex& other) { return dist < other.dist; }
	//bool operator<=(const Vertex& other) { return (*this == other) || (*this < other); }
	//bool operator>(const Vertex& other) { return !(*this <= other); }
	//bool operator>=(const Vertex& other) { return !(*this < other); }
};

class Graph
{
public:

	Graph(std::istream& fin, const int N);

	std::size_t vertices_size() const { return adj_list.size(); }
	//std::size_t neighbors_size(int v) const { return neighbors(v).size(); }
	/*std::size_t num_of_edges()const;*/

	std::vector<int> neighbors(int v) const;
	std::vector<int> vertices()const;
	double weight(const int& v, const int& u)const;
private:
	std::unordered_map<int, std::vector<std::pair<int, double>>> adj_list;
};



class Dijkstra {

public:
	Dijkstra(const Graph& G, const int& src);
	std::vector<double> shortestDistances(std::vector<int> destinations);
	std::vector<int> shortestPath(const int& destination);

	// The distance to unreachable vertices from src is MAX_DIST.
	static constexpr double MAX_DIST = 10000000;
private:

	int source;   // source vertex
	static constexpr int NIL = -1;
	// holds the shortest distance from the given src
	// to every other vertex in the graph (including the source itself).
	//std::vector<double> dist;

	// _vertices[i] returns the vertex with label i.
	// Note that the 0th vertex is not used.
	// _vertices[1.. G.length] are the vertices in input graph.
	std::vector<Vertex> _vertices;

	static void initialize(std::vector<Vertex>& vec, const int& src, const int& N);

	//static void Relax(const Vertex& u, Vertex& v, std::priority_queue<Vertex>& pq);
};

#endif