#include<iostream>
#include<random>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;


size_t merge_and_count_splitInversions(int A[], int low, int mid, int hi) {
    int i = low, j = mid+1, count = 0;
    int N = hi - low + 1;
    int* D = new int[N];
    for (int k = 0; k < N; ++k) {
        if (j > hi || (i <= mid && A[i] <= A[j])) {
            D[k] = A[i++];
        }
        else {
            D[k] = A[j++];
            count += (mid - i + 1);
        }
    }
    for (int m = 0; m < N; ++m, ++low) {
        A[low] = D[m];
    }
    delete[] D;
    return count;
}

size_t sort_and_count_inversions(int A[], int low, int hi) {
    if (low >= hi) {
        return 0;
    }
    int mid = (hi + low) / 2;
    size_t left_inversions = sort_and_count_inversions(A, low, mid);
    size_t right_inversions = sort_and_count_inversions(A, mid + 1, hi);
    size_t split_inversions = merge_and_count_splitInversions(A, low, mid, hi);

    return left_inversions + right_inversions + split_inversions;
}

size_t sort_and_count_inversions(int A[], size_t N) {
    return sort_and_count_inversions(A, 0, N - 1);
}

int main() {

    constexpr int arr_size = 100000;
    int arr[arr_size];
    ifstream file("IntegerArray.txt");
    string str;
    int i = 0;
    while (getline(file, str)) {
        arr[i] = stoi(str);
        i++;
    }

    cout << sort_and_count_inversions(arr, arr_size) << endl;

    // %%%%%%    UNCOMMENT THE TESTS BELOW   %%%%%%

    //// @source:  https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
    //std::random_device dev;
    //std::mt19937 rng(dev());
    //std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 1000); // distribution in range [1, 6]

    //for (auto t = 0; t < 10; ++t) {
    //    int N = 10 *(pow(2, t));
    //    int* a = new int[N];
    //    for (int i = 0; i < N; ++i) {
    //        a[i] = dist6(rng);
    //    }

    //    //cout << "input array: ";
    //    //for (int i = 0; i < N; ++i) {
    //    //    cout << a[i] << " ";
    //    //}
    //    //cout << endl;
    //    auto inversions = sort_and_count_inversions(a, N);
    //    cout << "#inv. = " << inversions << endl
    //        << "===========" << endl;
    //    if (!is_sorted(a, a + N)) {
    //        cerr << "Failed Test!" << endl;
    //        return EXIT_FAILURE;
    //    }
    //}

}