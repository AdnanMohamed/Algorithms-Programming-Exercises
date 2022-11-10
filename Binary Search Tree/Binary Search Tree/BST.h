#pragma once
template <typename K, typename V>
class Entry {                                     // a (key, value) pair
public:                                           // public types
	typedef K Key;                                   //    key type
	typedef V Value;                                 //  value type
public:                                           // public functions
	Entry(const K& k = K(), const V& v = V())        // constructor
		: _key(k), _value(v) { }
	const K& key() const { return _key; }            //  get key (read only)
	const V& value() const { return _value; }        //  get value (read only)
	void setKey(const K& k) { _key = k; }           //  set key
	void setValue(const V& v) { _value = v; }       //   set value
private:                                          // private data
	K _key;                                         //  key
	V _value;                                       //  value
};


template <typename E>
class SearchTree {                                 // a binary search tree
public:                                            // public types
	typedef typename E::Key K;                        // a key
	typedef typename E::Value V;                      // a value
	class Iterator;                                   //  an iterator/position
public:                                            // public functions
	SearchTree();                                     // constructor
	int size() const;                                 // number of entries
	bool empty() const;                               // is the tree empty?
	Iterator find(const K& k);                        // find entry with key k
	Iterator insert(const K& k, const V& x);          // insert (k,x)
	void erase(const K& k) throw(NonexistentElement); // remove key k entry
	void erase(const Iterator& p);                    // remove entry at p
	Iterator begin();                                 // iterator to first entry
	Iterator end();                                   // iterator to end entry
protected:                                         // local utilities
	typedef BinaryTree<E> BinaryTree;                // linked binary tree
	typedef typename BinaryTree::Position TPos;      // position in the tree
	TPos root() const;                               // get virtual root
	TPos finder(const K& k, const TPos& v);          // find utility
	TPos inserter(const K& k, const V& x);           // insert utility
	TPos eraser(TPos& v);                            // erase utility
	TPos restructure(const TPos& v)                  // restructure
		throw(BoundaryViolation);
private:                                           // member data
	BinaryTree T;                                    // the binary tree
	int n;                                           //  number of entries
public:
	// ...insert Iterator class declaration here
};
