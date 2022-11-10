#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"DFS.h"
#include "main.h"


using namespace std;

void print_schedule(const std::vector<int>& keys, std::ostream& outFile, const std::unordered_map<int, std::string>& courses);
void print_schedule(const std::vector<int>& keys, std::ostream& outFile);

int main() {
	ifstream file("graphInput.txt");
	if (file.fail()) {
		cerr << "Cannot open the given file." << endl;
		exit(1);
	}
	Graph G(file);

	file.close();

	file.open("courses.txt");
	if (file.fail()) {
		cerr << "Cannot open the given file." << endl;
		exit(1);
	}
	unordered_map<int, string> courses;
	string line;
	while (getline(file, line)) {
		istringstream iss(line);
		int key;
		string code;
		iss >> key;
		getline(iss, code);
		courses[key] = code;
	}
	file.close();

	string fileName = "schedule.txt";
	ofstream outFile(fileName);
	auto topo_order = topological_order(G);
	print_schedule(topo_order, cout, courses);



}

void print_schedule(const std::vector<int>& keys, std::ostream& outFile, const std::unordered_map<int, std::string>& courses)
{
	int i = 1;
	const int block_size = 5;
	for (auto v : keys) {
		if (i % block_size == 1) {
			outFile << "===== COURSE #" << ceil(i / double(block_size)) << "=======" << endl;
		}
		outFile << courses.at(v) << endl;
		if (i % block_size == 0) {
			outFile << "============" << endl;
		}
		++i;
	}
}

void print_schedule(const std::vector<int>& keys, std::ostream& outFile)
{
	int i = 1;
	const int block_size = 5;
	for (auto v : keys) {
		if (i % block_size == 1) {
			outFile << "===== COURSE #" << ceil(i / double(block_size)) << "=======" << endl;
		}
		outFile << v << endl;
		if (i % block_size == 0) {
			outFile << "============" << endl;
		}
		++i;
	}
}
