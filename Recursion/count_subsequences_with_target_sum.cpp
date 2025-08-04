/*
    File: count_subsequences_with_target_sum.cpp

    Problem:
    Count the number of subsequences from the given array whose sum equals the target 'k'.

    Approach:
    - We use a recursive backtracking approach to explore all subsets (include/exclude choices).
    - At each index, we decide whether to take the element or skip it.
    - If we reach the end of the array and the current sum equals k, we count that subsequence.

    Time Complexity: O(2^n)
        - Each element has two choices: include or exclude → total 2^n subsequences.
    
    Space Complexity: O(n)
        - Due to recursion stack and the temporary `ans` vector storing the current path.

    Note:
    - This approach is brute-force and not optimized for large input sizes.
    - The `ans` vector is used for clarity but can be removed if not printing the subsequences.
*/
 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:    	
    int Recur(int index, vector<int> &ans, vector<int> &nums, int sum, int k) {
        if(index == nums.size()) {
            if(sum == k) {
                return 1;
            }
            return 0;
        }

        // Include current number
        ans.push_back(nums[index]);
        int left = Recur(index + 1, ans, nums, sum + nums[index], k);
        ans.pop_back();

        // Exclude current number
        int right = Recur(index + 1, ans, nums, sum, k);

        return left + right;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        vector<int> ans;
        return Recur(0, ans, nums, 0, k);
    }
};
