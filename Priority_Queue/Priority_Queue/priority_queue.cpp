#include "priority_queue.h"
#include <stdexcept>      // std::invalid_argument

using std::vector;

// CLASS INVARIANT:
//  1- heap[1..heap_size] are the elements of the heap.
//	2- heap_size is the number of elements in the heap.
// Important Note:
//  * vector<int> heap is the array representation of the min-heap datastructure
//	  and heap[0] is not considered in the heap; as invariant 1 explicitly state.
//  * heap_size is different than heap.size() which is the size of the array/vector.
//		heap_size is the actual size of the heap, whereas heap.size() is the size of the vector.

template<typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

priority_queue::priority_queue(std::initializer_list<int> elem_list) {
	/*heap_size = elem_list.size();*/
	heap = vector<int>(1);  // the first element is discarded in our heap representation (see class invariant 1).
	heap.insert(heap.end(), elem_list);
	build_min_heap(heap);
}

void priority_queue::insert(int elem) {
	/*++heap_size;*/
	//if(heap_size < heap.size())
	//	heap[heap_size] = INF;
	//else
	//	heap.push_back(INF);
	heap.push_back(INF);
	decrease_key(size(), elem);
}

void priority_queue::insert(std::initializer_list<int> lst) {
	for (auto elem : lst) insert(elem);
}

int priority_queue::minimum() const {
	if (empty()) {
		throw std::exception("The queue is empty.");
	}
	return heap[1];
}
int priority_queue::extract_min() {
	auto min_value = minimum();
	heap[1] = heap.back();
	min_heapify(heap, 1);
	heap.pop_back();
	return min_value;
}
void priority_queue::decrease_key(int i, int key) {
	if (i < 1 || i > size()) {
		throw std::invalid_argument("Index out of bounds.");
	}
	heap[i] = key;
	while (i > 1 && heap[i] < heap[parent(i)]) {
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}




// Assumes the following:
//	1- The subtrees rooted at the right and left children of H[i]
//	   are min-heaps.
// Calling this function "sinks" H[i] to its proper position in the heap.
// So, H[i] is the root of a min-heap.
void priority_queue::min_heapify(std::vector<int>& H, int i) {
	if (i < 1) {
		throw std::invalid_argument("Index out of bounds.");
	}
	
	int l = left(i);
	int r = right(i);
	int j = i;  // j is the index of the least element between H[i] and its children.
	if (l <= size() && H[l] < H[j]) {
		j = l;
	}
	if (r <= size() && H[r] < H[j]) {
		j = r;
	}
	if (j != i) {
		swap(H[i], H[j]);
		min_heapify(H, j);
	}
}


void priority_queue::build_min_heap(std::vector<int>& H) {
	int i = ((H.size() - 1) / 2);  // the index of the last non-leaf node.
	while (i >= 1) {
		min_heapify(H, i);
		i--;
	}
}

bool priority_queue::isHeap() {
	for (int i = 1; i <= size() / 2; ++i) {
		if (hasLeft(i) && heap[i] > heap[left(i)]) return false;
		if (hasRight(i) && heap[i] > heap[right(i)]) return false;
	}
	return true;
}