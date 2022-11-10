#include"Dijkstra.h"
#include<vector>
#include<sstream>
#include<string>

using std::vector; using std::string; using std::getline;
using std::istringstream;



Graph::Graph(std::istream& fin, const int N) {
	unsigned int vertex;

	/*for (int i = 1; i <= N; ++i) adj_list[i] = std::vector<int>();*/

	string line;
	int key;
	while (getline(fin, line)) {
		istringstream sstream_reader{ line };
		string tuple;
		sstream_reader >> tuple;
		
		// if no comma present then we read an integer
		// representing a new vertex.
		if (tuple.find(',') == string::npos)
			key = std::stoi(tuple);

		while (sstream_reader >> tuple) {
			auto comma_index = tuple.find(',');
			int tail_vertex = std::stoi(tuple.substr(0, comma_index));
			double edge_weight = std::stod(tuple.substr(comma_index + 1));
			adj_list[key].push_back({ tail_vertex, edge_weight });
		}
	}
}

double Graph::weight(const int& v, const int& u)const {
	for (auto tuple : adj_list.at(v)) {
		if (tuple.first == u)
			return tuple.second;
	}
}

std::vector<int> Graph::neighbors(int v) const {
	std::vector<int> adj_vertices;
	for (auto pair : adj_list.at(v)) 
		adj_vertices.push_back(pair.first);
	return adj_vertices;
}

std::vector<int> Graph::vertices() const {
	std::vector<int> vertices;
	for (auto pair : adj_list) vertices.push_back(pair.first);
	return vertices;
}

Dijkstra::Dijkstra(const Graph& G, const int& src) {
	const int N = G.vertices_size();
	_vertices = vector<Vertex>(N + 1);
	initialize(_vertices, src, N);
	_vertices[src].done = true;
	int counter = 1;
	while (counter != N) {
		auto tail = Dijkstra::NIL;
		auto head = Dijkstra::NIL;
		double min_dist = INFINITY;
		//starting from the second element becuase the first is invalid.
		for (auto u = std::next(std::begin(_vertices)); u != _vertices.end(); ++u) {
			if (u->done) {
				for (auto v : G.neighbors(u->key)) {
					if (!_vertices[v].done && (_vertices[u->key].dist + G.weight(u->key, v) < min_dist)) {
						min_dist = _vertices[u->key].dist + G.weight(u->key, v);
						tail = u->key;
						head = v;
					}
				}
			}
		}
		_vertices[head].done = true;
		_vertices[head].dist = min_dist;
		counter++;
	}
}

std::vector<double> Dijkstra::shortestDistances(std::vector<int> destinations) {
	vector<double> distances;
	for (auto v : destinations) {
		distances.push_back(_vertices[v].dist);
	}
	return distances;
}

std::vector<int> Dijkstra::shortestPath(const int& destination) { return vector<int>(); }

void Dijkstra::initialize(std::vector<Vertex>& vec, const int& src, const int& N){
	
	for (int i = 1; i <= N; i++) {
		Vertex v;
		v.key = i;
		v.dist = Dijkstra::MAX_DIST;
		v.parent = NIL;
		v.done = false;
		vec[i] = v;
	}
	vec[src].dist = 0;
}

//void Dijkstra::Relax(const Graph& G, Vertex& u, Vertex& v) {
//	if (v.dist > u.dist + G.weight(u.key, v.key)) {
//		
//	}
//}