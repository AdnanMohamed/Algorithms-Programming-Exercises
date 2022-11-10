// This header file contains the definition of the class priority_queue which
// represents a min priority queue datastructure.
//
// CONSTRUCTORS:
//	priority_queue();
//	 Postcondition: creates an empty priority queue.
//
//  priority_queue(std::initializer_list<int> elements);
//	 Postcondition: creates a priority queue from the given elements.
//
//	int size() const;
//	 Returns the number of elements in the priority_queue
//
//	void insert(int elem);
//	 Postcondition: elem is inserted to the priority queue.
//
//	int minimum() const;
//	 Precondition: The priority queue has at lease one element.
//	 Postcondition: returns the smallest element in the priority queue
//
//	int extract_min();
//	 Precondition: The priority queue has at lease one element.
//	 Postcondition: removes and returns the smallest element.
//
//	void decrease_key(int i, int key);
//	 COMMENT LATER...
//
#ifndef PRIORITY_QUEUE_ADNAN_H_MOHAMED
#define PRIORITY_QUEUE_ADNAN_H_MOHAMED

#include<vector>
#include<initializer_list>

class priority_queue
{
public:
	priority_queue() {}
	priority_queue(std::initializer_list<int> elem_list);

	void insert(int elem);
	void insert(std::initializer_list<int> lst);
	int minimum() const;
	int size()const { return heap.size() - 1; }
	bool empty()const { return size() == 0; }
	int extract_min();
	void decrease_key(int i, int key);
	bool isHeap();  // for debugging.
private:
	std::vector<int> heap = std::vector<int>(1);  // heap[0] is not valid, our heap starts counting from 1 for convinience.
	int INF = 100000;

	void min_heapify(std::vector<int>& H, int i);
	void build_min_heap(std::vector<int>& H);
	int left(int i) const { return 2 * i; }
	int right(int i) const { return left(i) + 1; }
	int parent(int i) const { return i / 2; }

	bool hasLeft(int i) const { return left(i) <= size(); }
	bool hasRight(int i) const { return right(i) <= size(); }
};

#endif

