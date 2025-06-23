/*

[[array]]
[[hash table]]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i=0; i < nums.size()-1; i++){
            for (int j=i+1; j < nums.size(); j++){
                int two_sum = nums[i] + nums[j];

                if (two_sum == target){
                    // cout << "[" <<i << "," << j << "]";
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};
