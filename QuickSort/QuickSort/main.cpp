#include<iostream>
#include<random>


using std::cout; using std::cin; using std::endl;
using std::size_t; using std::is_sorted;

template <typename T>
void swap(T& a, T& b);

size_t pivot(int low, int hi);

template<typename T>
int partition(T A[], int low, int hi);


template<typename T>
void quicksort(T A[], int low, int hi);

template<typename T>
void quicksort(T A[], int N);


int main() {
	// @source:  https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 1000); // distribution in range [1, 6]


	for (auto t = 0; t < 10; ++t) {
		int N = 10 * (pow(2, t));

		int* a = new int[N];
		for (int i = 0; i < N; ++i) {
			a[i] = dist6(rng);
		}

		quicksort(a, N);
		if (!is_sorted(a, a + N)) {
			std::cerr << "Failed intest!" << endl;
			return 1;
		}
	}
	return 0;
}

size_t pivot(int low, int hi) {
	return low;
}

template<typename T>
void swap(T& a, T& b) {
	if (a == b) return;

	int tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
int partition(T A[], int low, int hi) {
	int q = pivot(low, hi);  // pick a pivot index
	swap(A[q], A[hi]);  // swap the pivot with the last element
	T piv = A[hi];
	int i = low - 1;
	for (int j = low; j < hi; ++j) {
		if (A[j] <= piv) {
			i++;
			swap(A[i], A[j]);
		}

	}
	swap(A[i + 1], A[hi]);
	return i + 1;
}

template<typename T>
void quicksort(T A[], int low, int hi) {
	if (low < hi) {
		auto p = partition(A, low, hi);
		quicksort(A, low, p - 1);
		quicksort(A, p + 1, hi);
	}
}

template<typename T>
void quicksort(T A[], int N) {
	quicksort(A, 0, N-1);
}