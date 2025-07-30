// Filename: count_good_numbers.cpp
// Problem: Count the number of good digit strings of length n
// Approach:
//  - Even-indexed positions (0, 2, 4, ...) can take 5 values: {0, 2, 4, 6, 8}
//  - Odd-indexed positions (1, 3, 5, ...) can take 4 values: {2, 3, 5, 7}
//  - For a string of length n:
//      * number of even positions = (n + 1) / 2
//      * number of odd positions = n / 2
//  - Total good strings = (5 ^ even_positions) * (4 ^ odd_positions) % mod
//  - To compute this efficiently for large n, we use exponentiation by squaring
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion

class Solution {
    const int mod = 1e9 + 7;

   
    long long power(long long x, long long n) {
        if (n == 0) return 1;

        long long half = power(x, n / 2);               
        long long result = (half * half) % mod;       

        if (n % 2 == 1)                                  
            result = (result * x) % mod;

        return result;
    }

public:
    int countGoodNumbers(long long n) {
        long long odd = n / 2;             
        long long even = (n + 1) / 2;   

        return (power(5, even) * power(4, odd)) % mod;
    }
};
