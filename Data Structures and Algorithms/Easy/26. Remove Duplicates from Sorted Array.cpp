/*

[[array]]
[[two pointer]]

I basically iterated the array and checked if the current integer is the same as the next one, and if so I delete the next integer.
Important thing was to decrement i so that in the next iteration i will be back to the 'current' element. Also ensuring that iteration is done only till `nums.size() - 1` to prevent it frmo going out of bounds.

A better approach would be using two pointers.
- if i and j are same, j will increment and keep incrementing till a different value is found
- after that i + 1 and j will be swapped and i will be incremented and j will be reset to i + 1
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i + 1);
                i--;
            }
        }

        return nums.size();

    }
};
