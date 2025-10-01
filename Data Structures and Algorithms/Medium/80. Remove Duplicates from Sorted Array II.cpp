/*
 * Initally I obvoiusly tried the brute force method of storing the current value and checking the count if it exceeded 2. Did not work. But guess what? HASHMAP TO THE RESCUE.
 *
 * I created a hashmap, and kept pushing all into a temp vector as long as the count of the element in the map is 2 or less, the moment it exceeds 2, simply continue. A really good question which made me think.
 *
 * [[array]] [[two pointer]] [[hashmap]]
 * */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int count = 0;
        // int current = nums[0];

        vector<int> temp;
        unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]] += 1;
            if (count[nums[i]] < 3) {
                temp.push_back(nums[i]);
            }
            
        }

        // for (int i = 0; i < nums.size(); i++) {
        // }

        // // More correct approach
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == current) count++;
        //     if (count > 2) {
        //         nums.erase(nums.begin() + i);
        //         // i--;
        //     }
        //     if (nums[i] != current) {
        //         current = nums[i];
        //         count = 0;
        //     }
        // }

        nums = temp;
        return nums.size();
    }
};
