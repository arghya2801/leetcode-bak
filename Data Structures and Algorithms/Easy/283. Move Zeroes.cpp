/*
 * An easy question with brute force. Ideal solution would be to either use two pointers, or swap by keeping track of non zero elemetns.
 *
 * [[arrays]]
 * [[two pointers]]
 * */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeros++;
        }

        vector<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) temp.push_back(nums[i]);
        }

        for (int i = 0; i < zeros; i++) {
            temp.push_back(0);
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = temp[i];
        }
    }
};
