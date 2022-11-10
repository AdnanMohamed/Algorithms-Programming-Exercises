#include<iostream>
#include<fstream>
#include"SCC.h"


using namespace std;

int main() {
	ifstream file("SCC_small.txt");
	if (file.fail()) {
		cerr << "Cannot open the given file." << endl;
		exit(1);
	}
	Graph G(file, 32000);

	file.close();

	SCC scc(G);
	cout << endl;

	// display the strongly connected components sizes of the given graph
	for (auto size : scc.top_component_sizes(5)) {
		cout << size << ", ";
	}
}