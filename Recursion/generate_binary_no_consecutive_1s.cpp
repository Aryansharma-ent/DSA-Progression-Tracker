#include <iostream>
#include <vector>
using namespace std;

/*
Approach:
- Use recursion with backtracking.
- At each index, you can place '0' always.
- You can only place '1' if the previous character is not '1'.

Time Complexity: O(2^n) in worst case
Space Complexity: O(n) due to recursive call stack
*/

void generateBinary(int n, string current, int index, vector<string>& result) {
    if (index == n) {
        result.push_back(current);
        return;
    }

 
    generateBinary(n, current + '0', index + 1, result);

    if (current.empty() || current.back() != '1') {
        generateBinary(n, current + '1', index + 1, result);
    }
}

vector<string> generateStrings(int n) {
    vector<string> result;
    generateBinary(n, "", 0, result);
    return result;
}
