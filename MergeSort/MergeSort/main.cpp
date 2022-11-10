#include<iostream>
#include<random>

using namespace std;

void combine(int A[], int l, int m, int r) {
	int i = l, j = m + 1, k = 0;
	int N = r - l + 1;
	int* B = new int[N];
	while (i <= m && j <= r) {
		if (A[i] <= A[j]) {
			B[k] = A[i++];
		}
		else {
			B[k] = A[j++];
		}
		k++;
	}

	while (i <= m) {
		B[k] = A[i++];
		k++;
	}

	while (j <= r) {
		B[k] = A[j++];
		k++;
	}

	for (size_t i = 0; i < N; ++i) {
		A[l++] = B[i];
	}

	delete[] B;
}

void mergesort(int A[], int l, int r) {
	if (l >= r) {
		return;
	}
	int m = (l + r) / 2;
	mergesort(A, l, m);
	mergesort(A, m + 1, r);
	combine(A, l, m, r);
}


void mergesort(int A[], int N) {
	mergesort(A, 0, N - 1);
}

int main() {

    // @source:  https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
/*	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 1000);*/ // distribution in range [1, 6]

	//for (auto t = 0; t < 10; ++t) {
	//	int N = 10*(pow(2, t));
	//	cout << N << endl;
	//	int* a = new int[N];
	//	for (int i = 0; i < N; ++i) {
	//		a[i] = dist6(rng);
	//	}

	//	mergesort(a, N);
	//	if (!is_sorted(a, a + N)) {
	//		cerr << "Failed Test!" << endl;
	//		return EXIT_FAILURE;
	//	}
	//}

	int a[]{ 2, 5, 8, 7, 3, 1 };
	mergesort(a, 0, 5);
	for (int i = 0; i < 6; ++i) {
		cout << a[i] << ", ";
	}
}
