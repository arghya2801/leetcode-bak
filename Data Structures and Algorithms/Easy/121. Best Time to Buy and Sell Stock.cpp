/*

My first approach was to iterate over the given vector/array twice and comparing each term with all the terms after it. This ended with a time complexity of O(N^2), which is bad and also ended with a timeout with an extremely large list

Second approach was to set a variable to track the minimum price and maximum profit. Once a high profit is received, we save it until a higher profit is achieved. Once a very low number is achieved, it means it can be sold for higher. Only exception is that there is no bigger difference.

Refer back to this question.

[[array]]
[[dynamic programming]]

#referback
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_diff {0};
        int min = prices[0];

        // // Approach 1 (timeout)
        // for (int i=0; i<prices.size(); i++){
        //     for (int j=i+1; j<prices.size(); j++){
        //         int profit = prices[j] - prices[i];
        //         if (profit > max_diff){
        //             max_diff = profit;
        //         }
        //     }
        // }

        // Approach 2
        for (int i=1; i<prices.size(); i++){
            int profit = prices[i] - min;
            if (profit > max_diff){
                max_diff = profit;
            }
            if (prices[i] < min){
                min = prices[i];
            }
        }

        // // Approach 3 (ideal)
        // for (int i=1; i<prices.size(); i++){
        //     if (prices[i] < min){
        //         int profit = min - prices[i];
        //         if (max_diff < profit){
        //             max_diff = profit;
        //         } else {
        //             min = prices[i];
        //         }
        //     }
        // }

        return max_diff;

    }
};
