/*

A really good explanation of this problem - https://www.youtube.com/watch?v=UUaMrNOvSqg

Basically, the answer for nth stair is sum of ways from n-1 and n-2 stairs. So we calculate it and keep adding it to an array. So, for let us say n=8, the array will be like - `1 2 3 5 8 13 21 34`, thus answer is 34.

[[dynamic programming]]
[[memoization]]

#referback
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
