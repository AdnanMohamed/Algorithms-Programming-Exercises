#pragma once

#include<vector>

//template <typename E>
//class CompleteTree {                      // left-complete tree interface
//public:                                   // publicly accessible types
//	class Position;                         //  node position type
//	int size() const;                       // number of elements
//	Position left(const Position& p);       // get left child
//	Position right(const Position& p);      // get right child
//	Position parent(const Position& p);     // get parent
//	bool hasLeft(const Position& p) const;  // does node have left child?
//	bool hasRight(const Position& p) const; // does node have right child?
//	bool isRoot(const Position& p) const;   // is this the root?
//	Position root();                        // get root position
//	Position last();                        // get last node
//	void addLast(const E& e);               // add a new last node
//	void removeLast();                      //  remove the last node
//	void swap(const Position& p, const Position& q); // swap node contents
//};

template <typename E>
class VectorCompleteTree {
private:                                      // member data
	std::vector<E> V;                           // tree contents
public:                                       // publicly accessible types
	typedef typename std::vector<E>::iterator Position; // a position in the tree
protected:                                    // protected utility functions
	Position pos(int i)                         // map an index to a position
	{
		return V.begin() + i;
	}
	int idx(const Position& p) const            // map a position to an index
	{
		return p - V.begin();
	}
public:
	VectorCompleteTree() : V(1) {}            // constructor
	int size() const { return V.size() - 1; }
	Position left(const Position& p) { return pos(2 * idx(p)); }
	Position right(const Position& p) { return pos(2 * idx(p) + 1); }
	Position parent(const Position& p) { return pos(idx(p) / 2); }
	bool hasLeft(const Position& p) const { return 2 * idx(p) <= size(); }
	bool hasRight(const Position& p) const { return 2 * idx(p) + 1 <= size(); }
	bool isRoot(const Position& p) const { return idx(p) == 1; }
	Position root() { return pos(1); }
	Position last() { return pos(size()); }
	void addLast(const E& e) { V.push_back(e); }
	void removeLast() { V.pop_back(); }
	void swap(const Position& p, const Position& q)
	{
		E e = *q; *q = *p; *p = e;
	}
};


template <typename E, typename C>
class HeapPriorityQueue {
public:
	int size() const;                            // number of elements
	bool empty() const;                          // is the queue empty?
	void insert(const E& e);                     // insert element
	const E& min();                              // minimum element
	void removeMin();                            // remove minimum
private:
	VectorCompleteTree<E> T;                     // priority queue contents
	C isLess;                                    // less-than comparator
												 
	typedef typename VectorCompleteTree<E>::Position Position;  // shortcut for tree position
};


template <typename E, typename C>    // number of elements
int HeapPriorityQueue<E, C>::size() const
{
	return T.size();
}

template <typename E, typename C>    // is the queue empty?
bool HeapPriorityQueue<E, C>::empty() const
{
	return size() == 0;
}

template <typename E, typename C>    // minimum element
const E& HeapPriorityQueue<E, C> ::min()
{
	return *(T.root());
}            // return reference to root element


template <typename E, typename C>
void HeapPriorityQueue<E, C>:: insert(const E& e) {
	T.addLast(e);
	auto node = T.last();
	while (!T.isRoot(node) && isLess(*node, *(T.parent(node))))
	{
		T.swap(node, T.parent(node));
		node = T.parent(node);
	}
}

template <typename E, typename C>        // remove minimum
void HeapPriorityQueue<E, C>::removeMin() {
	if (T.size() == 1) {
		T.removeLast();
	}
	else {
		auto lastNode = T.last();
		auto v = T.root();  // the root node contains the min elem. by our def. of heap.
		T.swap(v, lastNode);   // now v has the content of the last node.
		T.removeLast();       // removing the previous root.


		while (true) {  // maintain the heap.
			auto smallest = v;
			if (T.hasLeft(v) && isLess(*(T.left(v)), *smallest)) {
				smallest = T.left(v);
			}
			if (T.hasRight(v) && isLess(*(T.right(v)), *smallest)) {
				smallest = T.right(v);
			}
			if (smallest != v) {
				T.swap(smallest, v);
				v = smallest;
				continue;
			}
			else {
				// v is in the correct position in the heap;
				// since it's less then both its children
				break;
			}
		}
	}
}