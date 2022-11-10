#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include"HeapPriorityQueue.h"

using namespace std;

template <typename T>
struct Comparator {
	bool operator () (T a, T b) { return a < b; }
};


void testIsEmpty(int& tests, int& passedTests) {
	HeapPriorityQueue<int, Comparator<int>> H1;

	tests = 1;
	passedTests = 0;

	if (H1.empty()) passedTests++;
}

void test2(int& tests, int& passedTests) {
	HeapPriorityQueue<int, Comparator<int>> H1;

	tests = 2;
	passedTests = 0;

	for (auto x : { 1,2,3,4,5 }) H1.insert(x);

	if (!H1.empty()) passedTests++;
	if (H1.size() == 5) passedTests++;
}

void test3(int& tests, int& passedTests) {
	HeapPriorityQueue<int, Comparator<int>> H1;

	tests = 1;
	passedTests = 0;

	for (auto x : { 1,2,3,4,5 }) H1.insert(x);
	
	vector<int> v;

	while (!H1.empty()) {
		v.push_back(H1.min());
		H1.removeMin();
		auto tmp = H1.size();
	}
	if (std::is_sorted(v.begin(), v.end())) passedTests++;

}

bool test4() {
	srand(time(NULL));
	int N = 1000;  // TEST SIZE
	HeapPriorityQueue<int, Comparator<int>> H1;
	vector<int> v;
	int insertions = 0, deletions = 0;

	for(auto _ : vector<int>(N)) {
		if (H1.empty()) {
			H1.insert(rand() % N + 1);
			insertions++;
		}
		else if (rand() % 10 < 7) {
			
			H1.insert(rand() % N + 1);
			insertions++;
		}
		else {
			H1.removeMin();
			deletions++;
		}
	}

	if (H1.size() != insertions - deletions) return false;

	while (!H1.empty()) {
		v.push_back(H1.min());
		H1.removeMin();
	}
	if (is_sorted(v.begin(), v.end())) return true;
	else return false;
}

void testSuit1() {
	const char* test_suit_name = "IsEmpty tests";
	int total_tests, passed_tests;
	printf("========= %s ===========\n", test_suit_name);
	testIsEmpty(total_tests, passed_tests);
	auto failingTests = total_tests - passed_tests;
	printf("Total Tests: %i\n", total_tests);
	printf("Passed tests: %i \n", passed_tests);
	printf("Failed tests: %i \n", failingTests);
	printf("========== END OF %s =========\n\n", test_suit_name);
}

void testSuit2() {
	const char* test_suit_name = "Test suit 2";
	int total_tests, passed_tests;
	printf("========= %s ===========\n", test_suit_name);
	test2(total_tests, passed_tests);
	auto failingTests = total_tests - passed_tests;
	printf("Total Tests: %i\n", total_tests);
	printf("Passed tests: %i \n", passed_tests);
	printf("Failed tests: %i \n", failingTests);
	printf("========== END OF %s =========\n\n", test_suit_name);
}

void testSuit3() {
	const char* test_suit_name = "Test suit 3";
	int total_tests, passed_tests;
	printf("========= %s ===========\n", test_suit_name);
	test3(total_tests, passed_tests);
	auto failingTests = total_tests - passed_tests;
	printf("Total Tests: %i\n", total_tests);
	printf("Passed tests: %i \n", passed_tests);
	printf("Failed tests: %i \n", failingTests);
	printf("========== END OF %s =========\n\n", test_suit_name);
}

void testSuit4() {
	const char* test_suit_name = "Test suit 4";
	int total_tests = 1, passed_tests = 0;
	printf("========= %s ===========\n", test_suit_name);
	if (test4() == true) passed_tests++;
	auto failingTests = total_tests - passed_tests;
	printf("Total Tests: %i\n", total_tests);
	printf("Passed tests: %i \n", passed_tests);
	printf("Failed tests: %i \n", failingTests);
	printf("========== END OF %s =========\n\n", test_suit_name);
}

int main() {
	
	testSuit1();
	testSuit2();
	testSuit3();
	testSuit4();
}