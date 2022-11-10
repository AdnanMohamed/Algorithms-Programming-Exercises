#include<iostream>
#include<fstream>
#include"BFS.h"


using namespace std;

void print_path(std::vector<int>& path);

int main() {
	ifstream file("test2.txt");
	if (file.fail()) {
		cerr << "Cannot open the given file." << endl;
		exit(1);
	}
	Graph G(file);

	file.close();
	const int src = 6;
	BFS b(G, src);
	double dist;
	for (auto v : G.vertices()) {
		auto path = b.shortestPath(v, dist);
		print_path(path);
		cout << "(" << path.back() << ")  --";
		cout << "Distance: " << dist << endl;
	}
	
	

}

void print_path(std::vector<int>& path)
{
	for (auto it = path.begin(); it != std::prev(path.end()); ++it) {
		cout << *it << "--> ";
	}
}
