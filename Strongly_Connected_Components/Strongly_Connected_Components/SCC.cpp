#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
#include"SCC.h"

Graph::Graph(std::istream& fin, const int N) {
	unsigned int vertex;

	for (int i = 1; i <= N; ++i) adj_list[i] = std::vector<int>();

	std::string line;

	// loop through the lines to create the graph.
	while (getline(fin, line)) {
		std::istringstream iss(line);
		std::string num;
		iss >> num;
		vertex = std::stoi(num);  // first vertex in the line/row read from the file.
		// Add the rest of the vertices in the line
		// to the neighbors of vertex.
		while (iss >> num) {
			adj_list[vertex].push_back(std::stoi(num));
		}
	}
	std::cout << "I am done!";
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

void Graph::reverse() {
	std::unordered_map<int, std::vector<int>> rAdj;

	// initialize empty neighbor lists.
	for (int i = 1; i <= vertices_size(); ++i) rAdj[i] = std::vector<int>();

	for (auto pair : adj_list) {
		for (auto v : neighbors(pair.first)) {
			rAdj[v].push_back(pair.first);
		}
	}

	adj_list = rAdj;
}



void SCC::DFS1(const Graph& G) {
	int time = 0;
	for (auto key : G.vertices()) {
		if (!vertices_list[key].is_visited) {
			DFS_visit1(G, vertices_list[key], time);
		}
	}
}

void SCC::DFS_visit1(const Graph& G, Vertex& u, int& time) {
	u.is_visited = true;
	
	for (auto v : G.neighbors(u.key)) {
		if (!vertices_list[v].is_visited) {
			DFS_visit1(G, vertices_list[v], time);
		}
	}
	time++;
	u.finish_time = time;
	vertices_stack.push(u.key);
}

void SCC::DFS2(const Graph& G) {

	while (!vertices_stack.empty()) {
		auto v = vertices_stack.top();
		vertices_stack.pop();
		if (!vertices_list[v].is_visited) {
			int time = 0;
			DFS_visit2(G, vertices_list[v], time);
			_components_size.push(time);
		}
	}
}

void SCC::DFS_visit2(const Graph& G, Vertex& u, int& time) {
	u.is_visited = true;

	for (auto v : G.neighbors(u.key)) {
		if (!vertices_list[v].is_visited) {
			DFS_visit2(G, vertices_list[v], time);
		}
	}
	time++;
	u.finish_time = time;

}

SCC::SCC(Graph G) {
	for (int i = 0; i <= G.vertices_size(); ++i) {
		Vertex v;
		v.key = i;
		v.is_visited = false;
		vertices_list.push_back(v);
	}
	DFS1(G);
	G.reverse();
	for (auto &v : vertices_list) {
		v.is_visited = false;
	}
	DFS2(G);
}

std::vector<int> SCC::components_size()const {
	std::vector<int> v;
	std::priority_queue<int> cmp_size = _components_size;
	while (!cmp_size.empty()) {
		v.push_back(cmp_size.top());
		cmp_size.pop();
	}
	return v;
}


// Returns the top n component sizes of the graph
// passed to SCC.
std::vector<int> SCC::top_component_sizes(int n) const {
	std::vector<int> v(n);
	std::priority_queue<int> cmp_size = _components_size;
	int i = 0;
	while (!cmp_size.empty() && i < n) {
		v[i]=cmp_size.top();
		cmp_size.pop();
		++i;
	}
	return v;
}