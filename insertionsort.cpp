#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<int>& arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    insertionsort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}