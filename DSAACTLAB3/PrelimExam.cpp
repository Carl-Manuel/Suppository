#include <iostream>
#include <vector>
#include <chrono>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;


void Array(int arr[], int size) {
        cout << "Original Unsorted Content:" << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

void StackQueue(int arr[], int size) {

    stack<int> st;
    queue<int> q;
    
    cout << "\nInserting elements into stack and queue..." << endl;
    for (int i = 0; i < size; i++) {
        st.push(arr[i]);  
        q.push(arr[i]);  
    }
    
    cout << "Stack Numbers of Elements: " << st.size() << endl;
    cout << "Queue Numbers of Elements: " << q.size() << endl;
    

    cout << "\nPopped 3 Elements from stack:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Popped: " << st.top() << endl;
        st.pop();
    }
    

    cout << "\nPopped 3 Elements from queue:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }
    
    cout << "\nRemaining Stack Elements:" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    

    cout << "\nRemaining Queue Elements:" << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    

    cout << "\nVerify if Both Stack and Queue Still Have Elements:" << endl;
    cout << "Is Stack empty?: " << (!st.empty() ? "YES" : "NO") << endl;
    cout << "Is Queue empty?: " << (!q.empty() ? "YES" : "NO") << endl;
}

vector<int> Merge(int arr[], int size) {
    stack<int> st;
    queue<int> q;
    vector<int> merged;
    
    cout << "\n=== MERGING STACK AND QUEUE ===" << endl;
    
    cout << "\nInserting elements into stack and queue..." << endl;
    for (int i = 0; i < size; i++) {
        st.push(arr[i]);  
        q.push(arr[i]);  
    }
    
    
    cout << "Popping 3 elements from stack and queue..." << endl;
    for (int i = 0; i < 3; i++) {
        st.pop();
        q.pop();
    }
    
   
    cout << "\nMerging remaining stack elements first..." << endl;
    while (!st.empty()) {
        merged.push_back(st.top());
        st.pop();
    }
    

    cout << "Then merging remaining queue elements..." << endl;
    while (!q.empty()) {
        merged.push_back(q.front());
        q.pop();
    }
    

    cout << "\nMerged Container (Stack elements first, then Queue elements):" << endl;
    for (size_t i = 0; i < merged.size(); i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    
    return merged;
}

double BubbleSort(vector<int> arr) {
    cout << "\n=== BUBBLE SORT ===" << endl;
    auto start = chrono::high_resolution_clock::now();
    
    // Run 1000 iterations for measurable timing
    for (int iteration = 0; iteration < 1000; iteration++) {
        vector<int> temp = arr;
        int n = temp.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (temp[j] > temp[j + 1]) {
                    int swap = temp[j];
                    temp[j] = temp[j + 1];
                    temp[j + 1] = swap;
                }
            }
        }
    }
    
    auto end = chrono::high_resolution_clock::now();
    double timeUs = chrono::duration_cast<chrono::microseconds>(end - start).count();
    
    // Display final sorted array (single pass)
    vector<int> finalSorted = arr;
    int n = finalSorted.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finalSorted[j] > finalSorted[j + 1]) {
                int swap = finalSorted[j];
                finalSorted[j] = finalSorted[j + 1];
                finalSorted[j + 1] = swap;
            }
        }
    }
    
    cout << "Sorted (Bubble Sort): ";
    for (size_t i = 0; i < finalSorted.size(); i++) {
        cout << finalSorted[i] << " ";
    }
    cout << endl;
    cout << fixed << setprecision(10) << "Time Taken (1000 iterations): " << timeUs << " microseconds" << endl;
    return timeUs;
}

double SelectionSort(vector<int> arr) {
    cout << "\n=== SELECTION SORT ===" << endl;
    auto start = chrono::high_resolution_clock::now();
    
    // Run 1000 iterations for measurable timing
    for (int iteration = 0; iteration < 1000; iteration++) {
        vector<int> temp = arr;
        int n = temp.size();
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (temp[j] < temp[minIdx]) {
                    minIdx = j;
                }
            }
            int swap = temp[i];
            temp[i] = temp[minIdx];
            temp[minIdx] = swap;
        }
    }
    
    auto end = chrono::high_resolution_clock::now();
    double timeUs = chrono::duration_cast<chrono::microseconds>(end - start).count();
    
    // Display final sorted array (single pass)
    vector<int> finalSorted = arr;
    int n = finalSorted.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (finalSorted[j] < finalSorted[minIdx]) {
                minIdx = j;
            }
        }
        int swap = finalSorted[i];
        finalSorted[i] = finalSorted[minIdx];
        finalSorted[minIdx] = swap;
    }
    
    cout << "Sorted (Selection Sort): ";
    for (size_t i = 0; i < finalSorted.size(); i++) {
        cout << finalSorted[i] << " ";
    }
    cout << endl;
    cout << fixed << setprecision(10) << "Time Taken (1000 iterations): " << timeUs << " microseconds" << endl;
    return timeUs;
}

double InsertionSort(vector<int> arr) {
    cout << "\n=== INSERTION SORT ===" << endl;
    auto start = chrono::high_resolution_clock::now();
    
    // Run 1000 iterations for measurable timing
    for (int iteration = 0; iteration < 1000; iteration++) {
        vector<int> temp = arr;
        int n = temp.size();
        for (int i = 1; i < n; i++) {
            int key = temp[i];
            int j = i - 1;
            while (j >= 0 && temp[j] > key) {
                temp[j + 1] = temp[j];
                j--;
            }
            temp[j + 1] = key;
        }
    }
    
    auto end = chrono::high_resolution_clock::now();
    double timeUs = chrono::duration_cast<chrono::microseconds>(end - start).count();
    
    // Display final sorted array (single pass)
    vector<int> finalSorted = arr;
    int n = finalSorted.size();
    for (int i = 1; i < n; i++) {
        int key = finalSorted[i];
        int j = i - 1;
        while (j >= 0 && finalSorted[j] > key) {
            finalSorted[j + 1] = finalSorted[j];
            j--;
        }
        finalSorted[j + 1] = key;
    }
    
    cout << "Sorted (Insertion Sort): ";
    for (size_t i = 0; i < finalSorted.size(); i++) {
        cout << finalSorted[i] << " ";
    }
    cout << endl;
    cout << fixed << setprecision(10) << "Time Taken (1000 iterations): " << timeUs << " microseconds" << endl;
    return timeUs;
}

void QuickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pi) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int p = i + 1;
        
        QuickSortHelper(arr, low, p - 1);
        QuickSortHelper(arr, p + 1, high);
    }
}

double QuickSort(vector<int> arr) {
    cout << "\n=== QUICK SORT ===" << endl;
    auto start = chrono::high_resolution_clock::now();
    
    // Run 1000 iterations for measurable timing
    for (int iteration = 0; iteration < 1000; iteration++) {
        vector<int> temp = arr;
        QuickSortHelper(temp, 0, temp.size() - 1);
    }
    
    auto end = chrono::high_resolution_clock::now();
    double timeUs = chrono::duration_cast<chrono::microseconds>(end - start).count();
    
    // Display final sorted array (single pass)
    vector<int> finalSorted = arr;
    QuickSortHelper(finalSorted, 0, finalSorted.size() - 1);
    
    cout << "Sorted (Quick Sort): ";
    for (size_t i = 0; i < finalSorted.size(); i++) {
        cout << finalSorted[i] << " ";
    }
    cout << endl;
    cout << fixed << setprecision(10) << "Time Taken (1000 iterations): " << timeUs << " microseconds" << endl;
    return timeUs;
}

int main() {
    int arr[10] = {45, 23, 58, 32, 50, 28, 60, 20, 55, 38};

    Array(arr, 10);
    StackQueue(arr, 10);
    
    // Get the merged array from the Merge function
    vector<int> merged = Merge(arr, 10);
    
    // Display the merged array that will be sorted
    cout << "\n=== ARRAY TO BE SORTED (Merged from Stack and Queue) ===" << endl;
    cout << "Merged Array (" << merged.size() << " elements): ";
    for (size_t i = 0; i < merged.size(); i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    
    // Run each sorting algorithm individually with separate array copies
    cout << "\n==================================================================" << endl;
    cout << "|         INDIVIDUAL TIME COMPLEXITY MEASUREMENTS                |" << endl;
    cout << "==================================================================" << endl;
    
    // Bubble Sort with nanoseconds
    vector<int> bubbleArr = merged;
    double bubbleTime = BubbleSort(bubbleArr);
    
    // Selection Sort with nanoseconds
    vector<int> selectionArr = merged;
    double selectionTime = SelectionSort(selectionArr);
    
    // Insertion Sort with nanoseconds
    vector<int> insertionArr = merged;
    double insertionTime = InsertionSort(insertionArr);
    
    // Quick Sort with nanoseconds
    vector<int> quickArr = merged;
    double quickTime = QuickSort(quickArr);
    // Display summary table with microseconds
    cout << "\n" << "==================================================================" << endl;
    cout << "|      SORTING ALGORITHMS TIME COMPLEXITY SUMMARY (MICROSECONDS)  |" << endl;
    cout << "==================================================================" << endl;
    cout << "| Algorithm          | Time (microseconds)     |" << endl;
    cout << "==================================================================" << endl;
    cout << "| Bubble Sort        | " << fixed << setprecision(10) << bubbleTime << " us |" << endl;
    cout << "| Selection Sort     | " << fixed << setprecision(10) << selectionTime << " us |" << endl;
    cout << "| Insertion Sort     | " << fixed << setprecision(10) << insertionTime << " us |" << endl;
    cout << "| Quick Sort         | " << fixed << setprecision(10) << quickTime << " us |" << endl;
    cout << "==================================================================" << endl;
    
    // Find and display the fastest algorithm (all in microseconds)
    double minTime = bubbleTime;
    string fastestAlgorithm = "Bubble Sort";
    
    if (selectionTime < minTime) {
        minTime = selectionTime;
        fastestAlgorithm = "Selection Sort";
    }
    if (insertionTime < minTime) {
        minTime = insertionTime;
        fastestAlgorithm = "Insertion Sort";
    }
    if (quickTime < minTime) {
        minTime = quickTime;
        fastestAlgorithm = "Quick Sort";
    }
    
    cout << "\nFastest Algorithm: " << fastestAlgorithm << " (" << fixed << setprecision(10) << minTime << " microseconds)" << endl;

    return 0;
}

