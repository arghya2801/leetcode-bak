/*

Reference - https://www.youtube.com/watch?v=5WZl3MMT0Eg

Basically, start with the 0th element. Then iterate while adding. If the sum is less than zero, it will reset to zero, otherwise add the next on the next iteration. the `max_sub` is the bigger value between the current element and the current sum. This way we iterate through the entire array (like a window closing) and figure out the biggest array.

Since we only need the sum, we just return the max_sub variable, and that makes the question easier than if it was to return the array.

[[array]]
[[divide and conquer]]
[[dynamic programming]]

#referback
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub = nums[0];
        int current_sum = 0;

        int size = nums.size();

        for (int n = 0; n < size; n++){
            if (current_sum < 0) {
                current_sum = 0;
            }
            current_sum += nums[n];
            max_sub = max(max_sub, current_sum);
        }

        return max_sub;
    }
};
