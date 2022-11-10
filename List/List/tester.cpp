#include<iostream>
#include"NodeList.h"


using namespace std;

void printList(const NodeList& lst) {
	for (auto elem : lst) {
		cout << elem << " | ";
	}
}

void fnc(NodeList& n){}

int main() {
	NodeList list1;
	
	for (auto x : { 1, 2, 5, 6 }) {
		list1.insertBack(x);
	}

	
	NodeList list2(list1);
	NodeList list3 = list2;

	for (auto x : { 1, 2, 3, 4 }) list3.insertBack(x * 3);
	cout << "List1: "; printList(list1);cout<< endl;
	cout << "List2: "; printList(list2);cout<< endl;
	cout << "List3: "; printList(list3);cout<< endl;
}