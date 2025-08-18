/*
    Problem: Sum of Subarray Minimums (LeetCode 907)

    Approach:
    - For each element arr[i], we need to count how many subarrays it is the minimum of.
    - Using monotonic stacks, compute:
        1. PSE (Previous Smaller Element): index of the nearest smaller element on the left of arr[i].
        2. NSE (Next Smaller Element): index of the nearest smaller element on the right of arr[i].
    - Distance to left = i - PSE[i]
    - Distance to right = NSE[i] - i
    - The total number of subarrays where arr[i] is the minimum = left * right
    - Contribution of arr[i] = arr[i] * left * right
    - Sum all contributions modulo (1e9+7).

    Complexity:
    - Time: O(n), since each element is pushed/popped once in the monotonic stack.
    - Space: O(n), for storing PSE, NSE, and stack.

    Example:
    Input: arr = [3,1,2,4]
    Subarrays minimum sum = 17

    File: sum_of_subarray_mins.cpp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findNSE(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int total = 0, mod = 1e9 + 7;
        for(int i = 0; i < arr.size(); i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }
        return (int) total;
    }
};
