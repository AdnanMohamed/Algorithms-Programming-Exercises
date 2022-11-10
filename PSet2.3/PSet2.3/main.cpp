#include<iostream>
#include"median_maintenance.h"
#include <numeric>
#include <fstream>

using namespace std;


bool test1() {
	median_maintenance obj = median_maintenance({ 3, -6, 20, 11, 13, 16, 3, 7, -7});
	auto medians = obj.get_medians();
	int expected = 50;
	int actual = std::accumulate(medians.begin(), medians.end(), 0);

	return expected == actual;
}

bool test2() {
	median_maintenance obj = median_maintenance({ 1, 2, 3, 4, 5 });
	auto medians = obj.get_medians();
	int expected = 9;
	int actual = std::accumulate(medians.begin(), medians.end(), 0);

	return expected == actual;
}

void testSuit() {
	const char* test_suit_name = "Test Suit 1";
	int total_tests = 2, passed_tests = 0;
	vector<int> failedTests;
	printf("========= %s ===========\n", test_suit_name);
	
	// Running tests.
	if (test1() == true) passed_tests++;
	else failedTests.push_back(1);
	if (test2() == true) passed_tests++;
	else failedTests.push_back(2);

	printf("Total Tests: %i\n", total_tests);
	printf("Passed tests: %i \n", passed_tests);
	printf("Failed tests: %i \n", failedTests.size());

	if (!failedTests.empty()) {
		printf("Failing Tests: ");
		for (auto testNum : failedTests) {
			cout << testNum << ", ";
		}
		cout << endl;
	}
	printf("========== END OF %s =========\n\n", test_suit_name);
}

int get_result(vector<int> medians) {
	long sum = std::accumulate(medians.begin(), medians.end(), 0);
	return sum % 10000;
}

int main() {
	string fileName = "Medians.txt";
	ifstream file(fileName);
	if (file.fail()) {
		cerr << "Failed opening the file: " << fileName << endl;
		return EXIT_FAILURE;
	}

	vector<int> nums;
	int num;
	while (file >> num) {
		nums.push_back(num);
	}
	file.close();

	median_maintenance solver = median_maintenance(nums);

	cout << "The answer is: " << get_result(solver.get_medians());
}