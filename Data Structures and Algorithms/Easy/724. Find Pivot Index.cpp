/*
 * My first approach was to create two vectors for right sums and left sums in a histogram form, and then compare them to find the common point. A very wrong approach which didn't work at all.
 *
 * The actual solution ended up being this -
 * - Take the sum of all elements and call it right_sum
 * - Iterate through the given array, subtracting the values from right_sum, along with storing that sum as well calling it left_sum
 * - If right_sum == left_sum, we found our index
 * - Make sure the addition for left_sum is done after the comparison
 *
 * [[array]]
 * [[pivot sum]]
 *   */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // if (nums.size() == 1) return nums[0];
        // if (nums.size() == 2) return -1;
        
        int right_sum = 0;
        // vector<int> right_sums;
        for (int i = 0; i < nums.size(); i++) {
            // right_sums.push_back(right_sum);
            right_sum += nums[i];
        }

        int left_sum = 0;
        // vector<int> left_sums;
        for (int i = 0; i < nums.size(); i++) {
            // left_sums.push_back(left_sum);
            // left_sum += nums[i];
            right_sum -= nums[i];
            if (right_sum == left_sum) return i;
            left_sum += nums[i];
        }

        return -1;
    }
};
