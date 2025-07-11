/*

First I tried it with a while loop, then with recursion. Both were technically correct, but the question required O(log n), and for some reason was giving me the 'time limit exceeded' error in the recursion method.

In the while loop method, it worked, but was failing to return `-1` when the number was not found. I then placed the `return -1` statement outside the while loop and then it worked. A new thing I learned is that the first returned value is the only one considered, not the last.

[[array]]
[[binary search]]
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high){
            mid = (low + high) / 2;
            if (nums[mid] < target){
                low = mid + 1;
            } else if (nums[mid] > target){
                high = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;

        // int low = 0;
        // int high = nums.size();

        // if (low > high) return -1;

        // int mid = (low + high) / 2;

        // if (nums[mid] < target){
        //     low = mid + 1;
        //     return search(nums, target);
        // } else if (nums[mid] > target){
        //     high = mid - 1;
        //     return search(nums, target);
        // } else {
        //     return mid;
        // }

    }
};
