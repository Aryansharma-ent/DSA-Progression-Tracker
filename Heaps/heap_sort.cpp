// File Name: heap_sort.cpp
//
// Problem Statement:
// Implement Heap Sort using array representation and Max Heap.
//
// Approach:
// 1. Build a Max Heap from the input array.
// 2. Swap the root element (maximum) with the last element.
// 3. Reduce the heap size by 1 and call heapify on the root.
// 4. Repeat until the array is sorted.
// 
// Explanation:
// - A Max Heap ensures the largest element is always at the root.
// - By moving it to the end and shrinking the heap, we place elements
//   in their correct sorted positions one by one.
//
// Time Complexity:
// - Building Heap: O(n)
// - Heapify: O(log n)
// - Heap Sort overall: O(n log n)
//
// Space Complexity:
// - O(1), since sorting is done in-place.
//
// Notes:
// - Uses 1-based indexing for easier child-parent calculations.
//
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    int size = n;
    while (size > 1) {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main() {
    int arr[6] = {-1, 54, 54, 55, 52, 50}; // 1-based indexing
    int n = 5;

    // Step 1: Build Max Heap
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Apply Heap Sort
    heapsort(arr, n);

    // Print sorted array
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
