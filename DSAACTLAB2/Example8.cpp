#include <iostream>
using namespace std;

void showArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int values[3] = {7, 14, 21};
    showArray(values, 3);
    return 0;
}
