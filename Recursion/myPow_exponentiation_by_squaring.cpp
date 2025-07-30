
// Approach: Exponentiation by Squaring (Recursive)
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursive stack

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // convert to long long to avoid overflow for INT_MIN
        if (N < 0) {
            x = 1 / x;  // handle negative power
            N = -N;
        }
        return power(x, N);
    }

private:
    double power(double x, long long n) {
        if (n == 0) return 1.0;

        double half = power(x, n / 2);

        if (n % 2 == 0)
            return half * half;      // even case
        else
            return half * half * x;  // odd case
    }
};
