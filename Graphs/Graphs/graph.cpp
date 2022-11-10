// Implementation of graph.h


#include<iostream>
#include"graph.h"
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
#include<algorithm>

using std::cout; using std::endl;


//std::vector<Vertex> Graph::getVertices() {
//	std::vector<Vertex> V;
//	for (auto v : _vertices) {
//		V.push_back(v.second);
//	}
//	return V;
//}

int rand_between(int min, int max);


Graph::Graph(std::istream& fin) {
	N = 200;   // This should be computed but for now I hard coded it.

	unsigned int vertex;


	std::string line;

	// loop through the lines to create the graph.
	while (getline(fin, line)) {
		std::istringstream iss(line);
		std::string num;
		iss >> num;
		vertex = std::stoi(num);  // first vertex in the line/row read from the file.
		std::vector<int> neighbors;
		// Add the rest of the vertices in the line
		// to the neighbors of vertex.
		while (iss >> num) {
			neighbors.push_back(std::stoi(num));
		}
		adj_list[vertex] = neighbors;
	}
}

std::vector<int> Graph::neighbors(int v) const {
	std::vector<int> adj_vertices = adj_list.find(v)->second;
	return adj_vertices;
}


void Graph::combine(int v1, int v2) {
	std::vector<int> v1_neighbors = adj_list[v1];
	std::vector<int> v2_neighbors = adj_list[v2];
	
	auto v1_end = v1_neighbors.end();
	auto v2_begin = v2_neighbors.begin();
	auto v2_end = v2_neighbors.end();

	v1_neighbors.insert(v1_end, v2_begin, v2_end);  // appending v2 neighbors to v1's neighbors.

	// make vertices hold v1 as neighbor instead of v2.
	for (auto vertex : neighbors(v2)) {
		auto it = std::find(adj_list[vertex].begin(), adj_list[vertex].end(), v2);
		if(it != adj_list[vertex].end())
		*it = v1;
	}

	std::remove(v1_neighbors.begin(), v1_neighbors.end(), v1);

	adj_list.erase(v2);
	--N;
}

std::size_t Graph::num_of_edges() const {
	std::size_t length = 0;
	for (auto pair : adj_list) length += pair.second.size();
	return length;
}

void get_random_edge(const Graph& G, int& v1, int& v2) {

	int randNum = rand_between(1, G.vertices_size());
	v1 = std::next(G.adj_list.begin(), randNum)->first;
	std::vector<int> neighbors = G.neighbors(v1);
	int rand_index = rand() % neighbors.size();
	v2 = neighbors[rand_index];
}


// helpers
//
// returns a random integer between min and max (both included).
int rand_between(int min, int max) {
	int randNum = rand() % (max - min + 1) + min;
	return randNum;
}