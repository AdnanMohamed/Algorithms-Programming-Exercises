#include<iostream>
#include<algorithm> // for std::reverse
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
#include"BFS.h"

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

BFS::BFS(const Graph& G, int src) {
	for (auto key : G.vertices()) {
		Vertex v;
		v.is_visited = false;
		v.parent = NIL;
		v.key = key;
		if (key != src) {
			v.dist = std::numeric_limits<double>::infinity();
		}
		else {
			v.dist = 0;
		}
		vertices[key] = v;
		
	}

	vertices[src].is_visited = true;
	frontier.push_back(vertices[src]);
	while (!frontier.empty()) {
		Vertex u = frontier.front();
		frontier.pop_front();
		for (auto v : G.neighbors(u.key)) {
			if (!vertices[v].is_visited) {
				vertices[v].is_visited = true;
				vertices[v].dist = u.dist + 1;
				vertices[v].parent = u.key;
				frontier.push_back(vertices[v]);
			}
		}
	}
}

std::vector<int> BFS::shortestPath(int destination)const {
	std::vector<int> path;
	path.push_back(destination);
	for (int v = vertices.at(destination).parent; v != NIL; v = vertices.at(v).parent) {
		path.push_back(v);
	}
	std::reverse(path.begin(), path.end());
	return path;
}

std::vector<int> BFS::shortestPath(int destination, double& distance) const {
	distance = shortestDistance(destination);
	return shortestPath(destination);
}

double BFS::shortestDistance(int destination)const {
	return vertices.at(destination).dist;
}
