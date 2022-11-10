// Interface for the class Graph, which represents an underected graph.
//
//
//  GRAPH DOCUMENTATION
//
// Graph(std::istream& fin);
//	Precondition: fin is a file stream of integers. Each line/row starts with
//  the vertex number followed by the adjacent vertices to that vertex.
//	Example:   3 5 6 8 1 , means that there is a vertex (3) adjacent to
//	the four following vertices (5), (6), (8), and (1).
//  Postcondition: The graph represented in the file is constructed.
//
//
//  void combine(int v1, int v2);
//		Precondition: v1, v2 are valid vertices in the graph.
//		Postcondition: Conceptually, v1 sucks-up v2 in the sense that
//		v2's neighbors becomes v1's neighbors. Consequently, the number of
//		vertices in the graph decreases by one.

#include<iostream>
#include<vector>
#include<unordered_map>

#ifndef GRAPH_ADNAN_H_MOHAMED
#define GRAPH_ADNAN_H_MOHAMED

//struct Edge;  // only to let Vertex know that Edge exists.
//
//// Vertex is the vertex/node in the graph.
//struct Vertex {
//	Vertex(int v) :_val(v) {}
//	int _val;
//	bool operator==(const Vertex& other) {
//		return this->_val == other._val;
//	}
//	bool operator!=(const Vertex& other) {
//		return !(*this == other);
//	}
//	std::vector<Edge> _edges;
//};
//
//inline void print(Vertex V) { std::cout << V._val; }
//
//
// Edge is the edge/arcs of the graph.
struct Edge {
	Edge(int v1, int v2) :_v1(v1), _v2(v2) {}
	bool operator==(const Edge& other) {
		return (this->_v1 == other._v1 && this->_v2 == other._v2) ||
				(this->_v1 == other._v2 && this->_v2 == other._v1);
	}
	bool operator!=(const Edge& other) {
		return !(*this == other);
	}
	int _v1, _v2;
};


class Graph {
public:
	Graph() = default;


	Graph(std::istream& fin);

	std::size_t vertices_size() const { return adj_list.size(); }
	std::size_t neighbors_size(int v) const { return neighbors(v).size(); }
	std::size_t num_of_edges()const;

	std::vector<int> neighbors(int v) const;

	void combine(int v1, int v2);

	friend void get_random_edge(const Graph& G, int& v1, int& v2);

	//Graph(std::vector<Vertex> V, std::vector<Edge> E);

	//void addVertex(int val) { addVertex(Vertex(val)); }
	//void addEdge(int val1, int val2) {
	//	if (!hasVertex(val1) || !hasVertex(val2)) {
	//		throw std::invalid_argument("The vertices must be in the graph.");
	//	}
	//	Vertex v1 = getVertex(val1);
	//	Vertex v2 = getVertex(val2);
	//	Edge e(v1, v2);
	//	addEdge(e);
	//	v1._edges.push_back(e);
	//	v2._edges.push_back(e);
	//	addVertex(vertex1);
	//	addVertex(vertex2);
	//}

	//bool hasVertex(int val);

	//std::vector<Vertex> getVertices();
	//std::vector<Edge> getEdges() { return _edges; }

	// FRIENDS
	//friend void print(Graph G);

private:
	std::unordered_map<int, std::vector<int>> adj_list;
	//std::vector<std::vector<int>> adj_list;
	std::size_t N;  // holds the number of vertices

	//inline void addVertex(Vertex v) { _vertices[v._val] = v; }
	//inline void addEdge(Edge e) { _edges.push_back(e); }
	//inline Vertex getVertex(int val) const { return _vertices.find(val)->second; }
};

//void print(Graph G);

#endif // !GRAPH_ADNAN_H_MOHAMED

