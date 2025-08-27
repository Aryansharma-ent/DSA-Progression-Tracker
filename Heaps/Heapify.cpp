 
// Problem Statement:
// Implement heapify function and build a max heap from an array.
//
// Approach:
// - We use the "heapify" method to maintain the max-heap property.
// - For any node `i`, check its left and right child.
// - If either child is larger than the current node, swap and recursively heapify the affected subtree.
// - Start heapifying from the last non-leaf node down to the root to build the heap.
//
// Time Complexity:
// - Heapify: O(log n) (in the worst case, we may traverse from root to leaf).
// - Building Heap: O(n) (heapify is called for n/2 nodes, each taking O(log n) but amortized analysis shows O(n)).
//
// Space Complexity:
// - O(1), as we are working in-place on the array (ignoring recursion stack).


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

int main() {
    int arr[6] = {-1, 54, 53, 55, 52, 50}; // 1-based indexing
    int n = 5;

    // Build heap
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    // Print heap
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
