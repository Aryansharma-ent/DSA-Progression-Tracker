// File Name: heap_insertion.cpp
//
// Problem Statement:
// Implement a Max Heap using array representation with insertion operation.
//
// Approach:
// - Represent heap as a 1-based index array.
// - For insertion, place the new element at the end (bottom-most, right-most position).
// - Perform "heapify-up" (percolate up):
//      * Compare the inserted element with its parent.
//      * If parent < child, swap them.
//      * Repeat until max-heap property is satisfied or root is reached.
// - Printing simply traverses the heap array.
//
// Time Complexity:
// - Insertion: O(log n) (height of heap).
// - Print: O(n).
//
// Space Complexity:
// - O(1), since heap is stored in a fixed-size array.
//
// Note: This implementation is only for insertion and printing heap.
//
// ---------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    return 0;
}
