#include"priority_queue.h"
#include<iostream>

using namespace std;

int main() {
	priority_queue min_pq;
	for (auto x : { 3, 5, -6, 4, 12, 8, 9 }) {
		min_pq.insert(x);
		if (!min_pq.isHeap()) {
			cout << "The bug occures when inserting: " << x << endl;
			return EXIT_FAILURE;
		}
	}

	for (auto x : { 66, -10, 4, 32 }) {
		min_pq.insert(x);
		if (!min_pq.isHeap()) {
			cout << "The bug occures when inserting: " << x << endl;
			return EXIT_FAILURE;
		}
	}

}