#include<iostream>
#include<vector>
#include<fstream>
#include"graph.h"
using namespace std;






unsigned int karger_algorithm(Graph G) {
	while (G.vertices_size() > 2) {
		int v1, v2;
		get_random_edge(G, v1, v2);
		G.combine(v1, v2);
	}

	return G.num_of_edges();
}


int main() {
	ifstream file("kargerMinCut.txt");

	Graph G(file);

	file.close();

	auto ans = karger_algorithm(G);
	cout << ans << endl;
}