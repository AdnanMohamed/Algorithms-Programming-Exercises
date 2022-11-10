#include<iostream>
#include<fstream>
#include"Dijkstra.h"

using namespace std;

int main() {
	string fileName = "dijkstraData.txt";
	ifstream file(fileName);
	if (file.fail()) {
		cerr << "Cannot open <" << fileName << ">" << endl;
		return EXIT_FAILURE;
	}

	constexpr int GRAPH_SIZE = 200;
	constexpr int src = 1;
	vector<int> destinations{ 7, 37, 59, 82, 99, 115, 133, 165, 188, 197 };

	Graph G(file, GRAPH_SIZE);

	Dijkstra dijkstra(G, src);

	for (auto d : dijkstra.shortestDistances(destinations)) {
		cout << d << endl;
	}
}