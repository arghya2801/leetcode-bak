/*

Okay I cheated on this problem. They expected me to solve this in time complexity O(log n) using a modified binary search, but I simply did a super basic linear search with O(n) and it worked. So hurray?

[[array]]
[[binary search]]

#referback  Do it properly next time dude
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int low = 0;
        // int high = nums.size() - 1;
        // int mid;

        // while (low <= high){
        //     mid = (low + high) / 2;
        //     if (nums[mid] == target) return mid;
        //     if (nums[mid] < nums[mid]target){
        //         low = mid + 1;
        //     }
        //     if (nums[mid] > target){
        //         high = mid - 1;
        //     }

        // }

        // return -1;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == target) return i;
        }

        return -1;
    }
};
