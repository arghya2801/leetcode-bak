/*

My first approach was obviously to go with three loops and not give a fuck about the time complexity. As expected, the larger inputs gave the time limit error. Not to mention it was more complicated.

This should be solved with the better method for the [[1. Two Sum]] question using two pointer.

Here we start with sorting the given array first, otherwise we will end up with the problem of duplicate triplets in the result vector. Then we run a for loop for the array. Here first things first, we skip the duplicates in the beginning of the array.  We do this by checking if the current and previous elements are the same (`nums[i] == nums[i - 1]`).  If so, we go to the next iteration.

Now we come to using the two pointer concept. We start a left and right pointer from both sides. We check if the sum of the current, left and right elements are zero or not. If so we put them in an array and push them to the result vector. We move this accurately by checking if the sum is more or less than the target. This is the reason we sorted first. If it is less, that means we need a bigger number, thus we move the left pointer ahead. If it is more, that means we need a smaller number, thus we move the right pointer behind.

If the sum is equal to the target however, after pushing the triplet we move the left pointer ahead because the left pointer should be 1 ahead of the iterator. We also check if the next is the same as the previous element, in which case we move it ahead again. We utilize a while loop to skip past all consecutive duplicates.

[[array]]
[[two pointer]]
[[sorting]]

#referback
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            int sum;
            while (left < right){
                sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) right -= 1;
                else if (sum < 0) left +=1;
                else {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    result.push_back(triplet);

                    left += 1;

                    while (nums[left] == nums[left - 1] && left < right){
                        left += 1;
                    }
                }
            }
        }

        return result;
    }
};
