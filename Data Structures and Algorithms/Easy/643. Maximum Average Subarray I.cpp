/*
 * Standard sliding window problem. Subtract the first number and add the last number to the sum and keep compairing it with the max_sum for an O(n) time complexity.
 *
 * [[sliding window]]
 * [[array]]
 * */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int i = 0;
        int j = k - 1;
        
        double sum = 0;
        for (int s = 0; s < k; s++) {
            sum += nums[s];
        }

        double max_average = sum / k;

        while (j + 1 < nums.size()) {
            sum = sum - nums[i] + nums[j + 1];
            max_average = max(max_average, sum /k);
            i++;
            j++;
        }

        return max_average;
    }
};
