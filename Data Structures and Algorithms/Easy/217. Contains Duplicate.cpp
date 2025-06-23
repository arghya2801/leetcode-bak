/*

[[array]]
[[hash table]]
[[sorting]]
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        int len = nums.size();

        for (int i = 0; i < len; i++){
            hash_table[nums[i]]++;
            if (hash_table[nums[i]] > 1) return true;
        }

        return false;
    }
};
