#include<iostream>
#include <ctime>
#include<vector>
#include<unordered_map>
#include<algorithm> // for random shuffle
#include<string>
#include<sstream>
#include"DFS.h"

Graph::Graph(std::istream& fin) {
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

std::vector<int> Graph::vertices() const {
	std::vector<int> vertices;
	for (auto pair : adj_list) vertices.push_back(pair.first);
	return vertices;
}

int rand_between(int min, int max)
{
	return rand() % max + min;
}

DFS::DFS(const Graph& G) {
	counter = G.vertices_size();
	for (auto key : G.vertices()) {
		Vertex v;
		v.key = key;
		v.parent = NIL;
		v.is_visited = false;
		vertices[key] = v;
	}
	auto vertices_list = G.vertices();
	std::random_shuffle(vertices_list.begin(), vertices_list.end());
	for (auto v : vertices_list) {
		if (!vertices[v].is_visited) {
			DFS_visit(G, v);
		}
	}
}

void DFS::DFS_visit(const Graph& G, const int& src) {
	Vertex* u = &vertices[src];
	u->is_visited = true;
	for (auto v : G.neighbors(u->key)) {
		if (!vertices[v].is_visited) {
			vertices[v].parent = u->key;
			DFS_visit(G, v);
		}
	}
	u->finish_time = counter;
	counter--;
}

std::vector<int> topological_order(const Graph& G){
	DFS dfs(G);
	std::vector<int> order(G.vertices_size());
	for (auto v : G.vertices()) {
		order[dfs.order(v) - 1] = v;
	}
	return order;
}