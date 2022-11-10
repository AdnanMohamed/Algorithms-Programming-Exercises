#include "median_maintenance.h"
#include<vector>
#include<queue>
#include<cmath> // for abs

using std::vector; using std::priority_queue; using std::abs;

typedef priority_queue<int, vector<int>, std::greater<int>> MinHeap;
typedef priority_queue<int> MaxHeap;

void adjust_sizes(MaxHeap& q1, MinHeap& q2) {
	if (q1.size() > q2.size()) {
		q2.push(q1.top());
		q1.pop();
	}
	else {
		q1.push(q2.top());
		q2.pop();
	}
}

median_maintenance::median_maintenance(vector<int> seq) {
	auto left_heap = MaxHeap();
	auto right_heap = MinHeap();

	left_heap.push(seq.front());
	medians.push_back(left_heap.top());

	for (auto it = seq.begin() + 1; it != seq.end(); ++it) {
		if (*it < left_heap.top()) {
			left_heap.push(*it);
		}
		else {
			right_heap.push(*it);
		}

		if (abs((int)(left_heap.size() - right_heap.size())) > 1) {
			adjust_sizes(left_heap, right_heap);
		}
		
		if (left_heap.size() >= right_heap.size())
			medians.push_back(left_heap.top());
		else
			medians.push_back(right_heap.top());
	}
}

