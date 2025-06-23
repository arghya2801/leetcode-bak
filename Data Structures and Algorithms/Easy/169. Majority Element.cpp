/*

I basically made a hash map with all the numbers. To be a majority, that number has to appear more than half the length of the array. So I iterate through the hash map to check if the count of any element is more than that, and if so I return that number.


[[array]]
[[hash table]]
[[divide and conquer]]
[[sorting]]
[[counting]]
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;

        int n = nums.size();

        for (int i : nums){
            count[i]++;
            if (count[i] > (n/2)){
                return i;
                break;
            }
        }

        return -1;
    }
};
