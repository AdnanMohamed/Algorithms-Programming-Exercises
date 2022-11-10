#pragma once
typedef int Elem;                                // list base element type
class NodeList {                                 // node-based list
private:
	struct Node {                      // a node of the list
		Elem elem;                       // element value
		Node* prev;                      // previous in list
		Node* next;                      // next in list
	};
public:
	class Iterator {                       // an iterator for the list
	public:
		Elem& operator*();                   // reference to the element
		bool operator==(const Iterator& p) const;  // compare positions
		bool operator!=(const Iterator& p) const;
		Iterator& operator ++();             // move to next position
		Iterator& operator--();              // move to previous position
		friend class NodeList;               // give NodeList access
	private:
		Node* v;                             // pointer to the node
		Iterator(Node* u);                   // create from node
	};
public:
	NodeList();                                    // default constructor
	int size() const;                              // list size
	bool empty() const;                            // is the list empty?
	Iterator begin() const;                        // beginning position
	Iterator end() const;                          // (just beyond) last position
	void insertFront(const Elem& e);               // insert at front
	void insertBack(const Elem& e);                // insert at rear
	void insert(const Iterator& p, const Elem& e); // insert e before p
	void eraseFront();                             // remove first
	void eraseBack();                              // remove last
	void erase(const Iterator& p);                 // remove p
	
	NodeList(const NodeList& original);
	NodeList& operator=(const NodeList& rhs);
	~NodeList();
private:                                        // data members
	int   n;                                       // number of items
	Node* header;                                  // head-of-list sentinel
	Node* trailer;                                 // tail-of-list sentinel
};

