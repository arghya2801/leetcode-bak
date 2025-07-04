/*

Reference - https://www.youtube.com/watch?v=RyBM56RIWrM

	We use the logic of using an offset. Which is the largest place of the binary number which has a 1 (0100 has 3 for example).

[[dynamic programming]]
[[bit manipulation]]

#referback
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        int offset = 1;

        for (int i = 1; i <= n; i++){
            if (offset * 2 == i) offset = i;
            dp[i] = 1 + dp[i - offset];
        }

        return dp;

        // Different solution(bit manipulation)
        // vector<int> countBits(int n) {
        //     std::vector<int> ans(n + 1, 0);
        //     for (int i = 1; i <= n; ++i) {
        //         ans[i] = ans[i >> 1] + (i & 1);
        //     }
        //     return ans;
        // }
    }
};
