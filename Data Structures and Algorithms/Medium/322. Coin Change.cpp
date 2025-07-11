/*

Another dynamic programming question on which I was not able to get the answer intuitively. Basically what this does is store the steps it takes to get to the amount whenever you choose a coin, and then next time you get the same combination you don't have to recompute it.

I also used that better version of the if loop for returning the final value.

Reference - https://www.youtube.com/watch?v=H9bfqozjoqs

[[array]]
[[dynamic programming]]
[[breadth first search]]

#referback
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
